# JUE260613
# Toy PDF fit — TensorFlow/Keras implementation.
# Equivalent to pdf_toy.py (PyTorch) — same architecture, same physics.
#
# Truth PDF:   f(x) = x^{-alpha} * (1-x)^{beta}
# Toy FK:      sigma = integral_0^1 f(x) * K(x) dx,   K(x) = x^2
# Network:     (x, log x) -> [8] -> [4] -> [1], sigmoid hidden, linear output
# Loss:        chi2 = sum_i (D_i - P_i)^2 / sigma_i^2
# Replicas:    N noise-perturbed copies of data -> N fits -> uncertainty band
#
# Architecture mirrors n3fit (Fig.1, Table 4, Eq.1 of arXiv:1907.05075)



# Import libraries ................................................................................

import numpy as np
import tensorflow as tf
import matplotlib.pyplot as plt



# Truth PDF and toy FK convolution ................................................................

ALPHA = 0.3
BETA  = 3.0

def truth_pdf(x):
    """True PDF: f(x) = x^{-alpha} * (1-x)^{beta}"""
    return x**(-ALPHA) * (1 - x)**BETA

def fk_kernel(x):
    """Toy fastkernel: K(x) = x^2"""
    return x**2

def convolve(pdf_vals, x_grid):
    """Numerical convolution: sigma = integral f(x)*K(x) dx via trapezoid"""
    return np.trapezoid(pdf_vals * fk_kernel(x_grid), x_grid)



# Generate toy data ...............................................................................

# # OLD
# x_grid    = np.logspace(-4, -0.01, 50).astype(np.float32)
# x_cuts    = np.linspace(0.01, 0.5, 20).astype(np.float32)

# NEW — load from disk
x_grid = np.load("data/fk_tables/x_grid.npy")
x_cuts = np.load("data/fk_tables/x_cuts.npy")
FK     = np.load("data/fk_tables/FK.npy")      # shape (20, 50)


data_true = np.array([convolve(truth_pdf(x_grid[x_grid > xc]),
                               x_grid[x_grid > xc]) for xc in x_cuts],
                     dtype=np.float32)
noise_level = 0.05
sigma_exp   = (data_true * noise_level).astype(np.float32)



# Neural network ..................................................................................
# Keras functional API — mirrors n3fit graph structure (Fig. 1 of paper)

def build_model():

    # Input: single x value
    x_input = tf.keras.Input(shape=(1,), name='x_input')

    # Fixed preprocessing layer: (x, log x) — as in NNPDF Eq.1
    x_log   = tf.keras.layers.Lambda(lambda x: tf.math.log(x), name='log_x')(x_input)
    x_pre   = tf.keras.layers.Concatenate(name='preprocessing')([x_input, x_log])

    # Hidden layers: sigmoid activation, Glorot normal init (Table 4)
    h = tf.keras.layers.Dense(8, activation='sigmoid',
                               kernel_initializer='glorot_normal',
                               name='hidden1')(x_pre)
    h = tf.keras.layers.Dense(4, activation='sigmoid',
                               kernel_initializer='glorot_normal',
                               name='hidden2')(h)

    # Output: linear, one flavour
    nn_out = tf.keras.layers.Dense(1, activation='linear',
                                    kernel_initializer='glorot_normal',
                                    name='nn_output')(h)

    # Preprocessing factor: x^{-alpha} * (1-x)^{beta}  (Eq. 1 of paper)
    preproc = tf.keras.layers.Lambda(
        lambda x: x**(-ALPHA) * (1 - x)**BETA, name='pdf_preproc')(x_input)

    # PDF output: NN * preprocessing
    pdf_out = tf.keras.layers.Multiply(name='pdf_output')([nn_out, preproc])

    return tf.keras.Model(inputs=x_input, outputs=pdf_out, name='PDFNet')



# FK convolution as TF operation ..................................................................
# This is what the custom C++ op will replace.

def fk_convolve_tf(pdf_vals, x_grid_tf, x_cuts):
    """
    Toy FK convolution using tf.numpy_function.
    For each x_cut: sigma_i = integral_{x_cut}^1 f(x)*K(x) dx
    In the real n3fit this is: O^n = FK^n_{ialpha jbeta} L_{ialpha jbeta}  (Eq. 4)
    """
    x_grid_np = x_grid_tf.numpy()

    def convolve_np(pdf_np):
        result = []
        for xc in x_cuts:
            mask = x_grid_np > xc
            if mask.sum() > 1:
                val = np.trapezoid(pdf_np[mask] * fk_kernel(x_grid_np[mask]),
                                   x_grid_np[mask])
            else:
                val = 0.0
            result.append(val)
        return np.array(result, dtype=np.float32)

    return tf.numpy_function(convolve_np, [pdf_vals], tf.float32)



# Chi2 loss .......................................................................................

def chi2_loss(data, pred, sigma):
    """chi2 = sum_i (D_i - P_i)^2 / sigma_i^2  (Eq. 2 of paper)"""
    return tf.reduce_sum(((data - pred) / sigma)**2)



# Single replica fit ..............................................................................

def fit_replica(data_noisy, x_grid, x_cuts, sigma_exp,
                n_epochs=300, lr=1.0):

    model     = build_model()
    optimizer = tf.keras.optimizers.Adadelta(learning_rate=lr)

    x_t        = tf.constant(x_grid[:, None], dtype=tf.float32)
    data_t     = tf.constant(data_noisy,      dtype=tf.float32)
    sigma_t    = tf.constant(sigma_exp,       dtype=tf.float32)
    x_grid_t   = tf.constant(x_grid,          dtype=tf.float32)

    for epoch in range(n_epochs):

        # with tf.GradientTape() as tape:

        #     # Forward pass: PDF on x_grid
        #     pdf_pred = model(x_t, training=True)   # shape (N_x, 1)
        #     pdf_flat = tf.squeeze(pdf_pred)         # shape (N_x,)

        #     # FK convolution (the expensive step — future custom op)
        #     pred_t = fk_convolve_tf(pdf_flat, x_grid_t, x_cuts)
        #     pred_t.set_shape([len(x_cuts)])

        #     # Chi2 loss
        #     loss = chi2_loss(data_t, pred_t, sigma_t)

        # # Backprop through network weights
        # grads = tape.gradient(loss, model.trainable_variables)
        # optimizer.apply_gradients(zip(grads, model.trainable_variables))


        with tf.GradientTape() as tape:

            pdf_pred = model(x_t, training=True)
            pdf_flat = tf.squeeze(pdf_pred)

            # FK convolution in pure TF — keeps gradient graph intact
            kernel_t = tf.constant(fk_kernel(x_grid), dtype=tf.float32)
            integrand = pdf_flat * kernel_t   # elementwise

            pred_list = []
            for xc in x_cuts:
                mask = x_grid > xc
                if mask.sum() > 1:
                    y   = tf.boolean_mask(integrand, mask)
                    x_m = tf.constant(x_grid[mask], dtype=tf.float32)
                    # trapezoid rule in pure TF
                    dx  = x_m[1:] - x_m[:-1]
                    val = tf.reduce_sum(0.5 * (y[:-1] + y[1:]) * dx)
                else:
                    val = tf.constant(0.0)
                pred_list.append(val)

            pred_t = tf.stack(pred_list)
            loss   = chi2_loss(data_t, pred_t, sigma_t)

        grads = tape.gradient(loss, model.trainable_variables)
        optimizer.apply_gradients(zip(grads, model.trainable_variables))

    # Return final PDF
    pdf_final = model(x_t, training=False).numpy().squeeze()
    return pdf_final



# MC replica loop .................................................................................

N_REPLICAS = 5
print(f"Fitting {N_REPLICAS} MC replicas (TensorFlow)...")

replicas = []
for i in range(N_REPLICAS):
    data_noisy = (data_true + np.random.normal(0, sigma_exp)).astype(np.float32)
    f_fit = fit_replica(data_noisy, x_grid, x_cuts, sigma_exp)
    replicas.append(f_fit)
    print(f"  replica {i+1}/{N_REPLICAS}")

replicas = np.array(replicas)
f_mean   = replicas.mean(axis=0)
f_std    = replicas.std(axis=0)



# Plot ............................................................................................

fig, axes = plt.subplots(1, 2, figsize=(12, 5))

# Left: PDF replicas + truth
ax = axes[0]
for i, rep in enumerate(replicas):
    ax.plot(x_grid, x_grid * rep, color='#1D9E75', lw=0.8, alpha=0.4,
            label='replicas' if i == 0 else None)
ax.plot(x_grid, x_grid * f_mean,             color='#0F6E56', lw=2, label='mean')
ax.fill_between(x_grid,
                x_grid * (f_mean - f_std),
                x_grid * (f_mean + f_std),
                color='#1D9E75', alpha=0.2, label='1σ band')
ax.plot(x_grid, x_grid * truth_pdf(x_grid),  color='#D85A30', lw=2,
        ls='--', label='truth')
ax.set_xscale('log')
ax.set_xlabel('x')
ax.set_ylabel('x f(x)')
ax.set_title('PDF replicas — n3fit toy (TensorFlow)\n'
             f'Architecture: (x, log x) → 8 → 4 → 1, {N_REPLICAS} replicas')
ax.legend(fontsize=9)

# Right: chi2 per replica
chi2_per_replica = []
for rep in replicas:
    pred = np.array([convolve(rep[x_grid > xc], x_grid[x_grid > xc])
                     for xc in x_cuts])
    chi2 = np.sum(((data_true - pred) / sigma_exp)**2) / len(x_cuts)
    chi2_per_replica.append(chi2)

ax = axes[1]
ax.hist(chi2_per_replica, bins=6, color='#1D9E75', alpha=0.7, edgecolor='white')
ax.axvline(np.mean(chi2_per_replica), color='#D85A30', lw=2,
           label=f'mean χ²/n = {np.mean(chi2_per_replica):.2f}')
ax.set_xlabel('χ²/n per replica')
ax.set_ylabel('count')
ax.set_title('Goodness of fit per replica')
ax.legend(fontsize=9)

fig.suptitle('Toy PDF fit — NNPDF/n3fit methodology (TensorFlow)', fontsize=12)
plt.tight_layout()
plt.savefig('results/pdf_toy_tf.png', dpi=150, bbox_inches='tight')
print("saved pdf_toy_tf.png")
