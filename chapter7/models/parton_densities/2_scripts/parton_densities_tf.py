# JUE260613

# Toy PDF fit: minimal TensorFlow implementation.
# Architecture mirrors NNPDF n3fit (Fig.1, Eq.1 of arXiv:1907.05075)

# Truth PDF: f(x) = x^{-alpha} * (1-x)^{beta}
# Toy FK: sigma = integral_0^1 f(x) * K(x) dx; being K(x) = x^2

# Network: (x, log x) -> [8] -> [4] -> [1], sigmoid hidden, linear output
# Loss: chi2 = sum_i (D_i - P_i)^2 / sigma_i^2
# Replicas: N noise-perturbed copies of data -> N fits -> uncertainty band



# Import libraries ................................................................................

import time
import numpy as np
import keras
import tensorflow as tf
import matplotlib.pyplot as plt



# Truth PDF and toy FK convolution ................................................................

# Preprocessing exponents (fixed, as in NNPDF3.1)
ALPHA = 0.3
BETA = 3.0

# Hyperparameters
N_REPLICAS = 20
N_EPOCHS = 500
LR = 0.5

def truth_pdf(x):
    """True PDF: f(x) = x^{-alpha} * (1-x)^{beta}"""
    return x**(-ALPHA) * (1 - x)**BETA

def fk_kernel(x):
    """Toy fastkernel: K(x) = x^2"""
    return x**2

def convolute(pdf_vals, x_grid):
    """Numerical convolution: sigma = integral f(x)*K(x) dx via trapezoid"""
    return np.trapezoid(pdf_vals * fk_kernel(x_grid), x_grid)



# Generate toy data ...............................................................................

# Version 0: pure simulation
# x_grid = np.logspace(-4, -0.01, 50).astype(np.float32)
# x_cuts = np.linspace(0.01, 0.5, 20).astype(np.float32)

# Version 1: load from disk
x_grid = np.load("data/fk_tables/x_grid.npy")
x_cuts = np.load("data/fk_tables/x_cuts.npy")
FK = np.load("data/fk_tables/FK.npy") # simulated toy example with shape (20, 50)

# Generate N_data "experimental" observables at different x cuts
# Each observable is sigma above x_min: int_{x_min}^1 f(x) * K(x) dx
data_true = np.array([convolute(truth_pdf(x_grid[x_grid > xc]), x_grid[x_grid > xc]) for xc in x_cuts], dtype = np.float32)
noise_level = 0.05 # 5% experimental uncertainty
sigma_exp = (data_true * noise_level).astype(np.float32)

# # Explore data
# print(f"x_grid\n{x_grid[0:5]}")
# print(f"x_cuts\n{x_grid[0:5]}")
# print(f"Partonic FK\n{FK[0:5, ]}")
# print(f"Hadronic obs\n{sigma_exp[0:5, ]}")

# import pdb
# pdb.set_trace()



# Neural network ..................................................................................

# Keras functional API: mirrors n3fit graph structure (Fig. 1 of paper)
# Architecture (x, log x) -> [8] -> [4] -> [1] (input preprocessing, sigmoid hidden, linear output)
def build_model():

    # Input: single x value
    x_input = tf.keras.Input(shape = (1,), name = 'x_input')

    # Fixed preprocessing layer: (x, log x):as in NNPDF Eq.1
    x_log = tf.keras.layers.Lambda(lambda x: tf.math.log(x), name = 'log_x')(x_input)
    x_pre = tf.keras.layers.Concatenate(name = 'preprocessing')([x_input, x_log])

    # Hidden layers: sigmoid activation, Glorot normal init (Table 4)
    h = tf.keras.layers.Dense(8, activation = 'sigmoid', kernel_initializer = 'glorot_normal', name = 'hidden1')(x_pre)
    h = tf.keras.layers.Dense(4, activation = 'sigmoid', kernel_initializer = 'glorot_normal', name = 'hidden2')(h)

    # Output: linear, one flavour
    nn_out = tf.keras.layers.Dense(1, activation = 'linear', kernel_initializer = 'glorot_normal', name = 'nn_output')(h)

    # Preprocessing factor: x^{-alpha} * (1-x)^{beta}  (Eq. 1 of paper)
    preproc = tf.keras.layers.Lambda(lambda x: x**(-ALPHA) * (1 - x)**BETA, name = 'pdf_preproc')(x_input)

    # PDF output: NN * preprocessing
    pdf_out = tf.keras.layers.Multiply(name = 'pdf_output')([nn_out, preproc])

    return tf.keras.Model(inputs = x_input, outputs = pdf_out, name = 'PDFNet')



# FK convolution as TF operation ..................................................................

# This is what the custom C++ op will replace
def fk_convolute_tf(pdf_vals, x_grid_tf, x_cuts):
    """
    Toy FK convolution using tf.numpy_function.
    For each x_cut: sigma_i = integral_{x_cut}^1 f(x)*K(x) dx
    In the real n3fit this is: O^n = FK^n_{ialpha jbeta} L_{ialpha jbeta} (Eq. 4)
    """
    x_grid_np = x_grid_tf.numpy()

    def convolute_np(pdf_np):
        
        # Initalize empty
        result = []
        for xc in x_cuts:
            mask = x_grid_np > xc
            if mask.sum() > 1:
                val = np.trapezoid(pdf_np[mask] * fk_kernel(x_grid_np[mask]), x_grid_np[mask])
            else:
                val = 0.0
            result.append(val)
        return np.array(result, dtype = np.float32)

    return tf.numpy_function(convolute_np, [pdf_vals], tf.float32)



# Chi2 loss .......................................................................................

def chi2_loss(data, pred, sigma):
    """chi2 = sum_i (D_i - P_i)^2 / sigma_i^2  (Eq. 2 of paper)"""
    return tf.reduce_sum(((data - pred) / sigma)**2)



# Single replica fit ..............................................................................

# Fit one PDF replica to noise-perturbed data. Returns f(x) predictions
def fit_replica(data_noisy, x_grid, x_cuts, sigma_exp, n_epochs = N_EPOCHS, lr = LR):

    # Generate model
    model = build_model()
    optimizer = tf.keras.optimizers.Adadelta(learning_rate = lr)

    # Prepare for training
    x_t = tf.constant(x_grid[:, None], dtype = tf.float32)
    data_t = tf.constant(data_noisy, dtype = tf.float32)
    sigma_t = tf.constant(sigma_exp, dtype = tf.float32)
    x_grid_t = tf.constant(x_grid, dtype = tf.float32)

    # Train model
    for epoch in range(n_epochs):

        # # OLD
        # with tf.GradientTape() as tape:

        #     # Forward pass: PDF on x_grid
        #     pdf_pred = model(x_t, training=True)   # shape (N_x, 1)
        #     pdf_flat = tf.squeeze(pdf_pred)         # shape (N_x,)

        #     # FK convolution (the expensive step — future custom op)
        #     pred_t = fk_convolute_tf(pdf_flat, x_grid_t, x_cuts)
        #     pred_t.set_shape([len(x_cuts)])

        #     # Chi2 loss
        #     loss = chi2_loss(data_t, pred_t, sigma_t)

        # # Backprop through network weights
        # grads = tape.gradient(loss, model.trainable_variables)
        # optimizer.apply_gradients(zip(grads, model.trainable_variables))


        with tf.GradientTape() as tape:

            pdf_pred = model(x_t, training = True)
            pdf_flat = tf.squeeze(pdf_pred)

            # FK convolution in pure TF: keeps gradient graph intact
            kernel_t = tf.constant(fk_kernel(x_grid), dtype = tf.float32)
            integrand = pdf_flat * kernel_t # elementwise

            # Initialize empty
            pred_list = []
            for xc in x_cuts:
                mask = x_grid > xc
                if mask.sum() > 1:
                    y = tf.boolean_mask(integrand, mask)
                    x_m = tf.constant(x_grid[mask], dtype = tf.float32)
                    # trapezoid rule in pure TF
                    dx = x_m[1:] - x_m[:-1]
                    val = tf.reduce_sum(0.5 * (y[:-1] + y[1:]) * dx)
                else:
                    val = tf.constant(0.0)
                pred_list.append(val)

            pred_t = tf.stack(pred_list)
            loss = chi2_loss(data_t, pred_t, sigma_t)

        grads = tape.gradient(loss, model.trainable_variables)
        optimizer.apply_gradients(zip(grads, model.trainable_variables))

    # Return final PDF
    pdf_final = model(x_t, training = False).numpy().squeeze()
    print(f"PDF final: {pdf_final[0:5]} ...")
    return pdf_final



# MC replica loop .................................................................................

print(f"Fitting {N_REPLICAS} MC replicas (TensorFlow)...")

# Prepare replicas for uncertainty quantification
replicas = []
times = []
for i in range(N_REPLICAS):

    # Generate noise-perturbed data for this replica (MC approach, Section 2.1)
    print(f"\nReplica {i+1}/{N_REPLICAS}")
    data_noisy = (data_true + np.random.normal(0, sigma_exp)).astype(np.float32)

    # Time training
    start = time.perf_counter()
    f_fit = fit_replica(data_noisy, x_grid, x_cuts, sigma_exp)
    end = time.perf_counter()

    # Append result and time
    replicas.append(f_fit)
    times.append(end - start)

print(f"\nTraining time (avg per replica): {np.mean(times):.4f} s")
replicas = np.array(replicas)
f_mean = replicas.mean(axis = 0)
f_std = replicas.std(axis = 0)



# Plot ............................................................................................

# Prepare figure
fig, axes = plt.subplots(1, 2, figsize = (12, 5))

# Left: PDF replicas + truth (mirrors Fig. 6 of paper)
ax = axes[0]
for i, rep in enumerate(replicas):
    ax.plot(x_grid, x_grid * rep, color = '#1D9E75', lw = 0.8, alpha = 0.4, label = 'replicas' if i == 0 else None)

ax.plot(x_grid, x_grid * f_mean, color='#0F6E56', lw = 2, label = 'mean')
ax.fill_between(x_grid, x_grid * (f_mean - f_std), x_grid * (f_mean + f_std), color = '#1D9E75', alpha = 0.2, label = ' 1σ band')
ax.plot(x_grid, x_grid * truth_pdf(x_grid),  color = '#D85A30', lw = 2, ls = '--', label = 'truth')
ax.set_xscale('log')
ax.set_xlabel('x')
ax.set_ylabel('x f(x)')
ax.set_title(f'{N_REPLICAS} PDF replicas with architecture: (x, log x) → 8 → 4 → 1', fontsize = 9)
ax.legend(fontsize = 8)

# Right: chi2 per replica (mirrors Table 5 / Fig. 5 of paper)
chi2_per_replica = []
for rep in replicas:
    pred = np.array([convolute(rep[x_grid > xc], x_grid[x_grid > xc]) for xc in x_cuts])
    chi2 = np.sum(((data_true - pred) / sigma_exp)**2) / len(x_cuts)
    chi2_per_replica.append(chi2)

ax = axes[1]
ax.hist(chi2_per_replica, bins = 10, color='#1D9E75', alpha = 0.7, edgecolor = 'black')
ax.axvline(np.mean(chi2_per_replica), color = '#D85A30', lw = 2, label = f'mean χ²/n = {np.mean(chi2_per_replica):.2f}')
ax.set_xlabel('χ²/n per replica')
ax.set_ylabel('count')
ax.set_title('χ² of fit per replica (good fit: χ²/n ≈ 1)', fontsize = 9)
ax.legend(fontsize = 8)

# Set figure titles and save
fig.suptitle('Toy PDF fit with TF: NNPDF/n3fit methodology (arXiv:1907.05075)', fontsize = 10)
plt.tight_layout()
plt.savefig(f'results/pdf_toy_tf_{N_REPLICAS}replicas_{N_EPOCHS}epochs_{LR}lr.png', dpi = 150, bbox_inches = 'tight')
print("Saved TF results")
