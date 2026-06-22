# JUE260613

# Toy PDF fit: minimal PyTorch implementation.
# Architecture mirrors NNPDF n3fit (Fig.1, Eq.1 of arXiv:1907.05075)

# Truth PDF: f(x) = x^{-alpha} * (1-x)^{beta}
# Toy FK: sigma = integral_0^1 f(x) * K(x) dx; being K(x) = x^2

# Network: (x, log x) -> [8] -> [4] -> [1], sigmoid hidden, linear output
# Loss: chi2 = sum_i (D_i - P_i)^2 / sigma_i^2
# Replicas: N noise-perturbed copies of data -> N fits -> uncertainty band



# Import libraries ................................................................................

import time
import numpy as np
import torch
import torch.nn as nn
import matplotlib.pyplot as plt



# Truth PDF and toy FK convolution ................................................................

# Preprocessing exponents (fixed, as in NNPDF3.1)
ALPHA = 0.3
BETA = 3.0

# Hyperparameters
N_REPLICAS = 10
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
    return np.trapz(pdf_vals * fk_kernel(x_grid), x_grid)



# Generate toy data ...............................................................................

# Version 0: pure simulation
# x_grid = np.logspace(-4, -0.01, 50).astype(np.float32)
# x_cuts = np.linspace(0.01, 0.5, 20).astype(np.float32)

# Load FK table and grids from disk
x_grid = np.load("data/fk_tables/x_grid.npy")
x_cuts = np.load("data/fk_tables/x_cuts.npy")
FK = np.load("data/fk_tables/FK.npy") # simulated toy example with shape (20, 50)

# Load N_data experimental observables at different x cuts
obs_true  = np.load("data/cross_sections/obs_true.npy")
obs_noise = np.load("data/cross_sections/obs_noise.npy")

# # Explore data
# print(f"x_grid\n{x_grid[0:5]}")
# print(f"x_cuts\n{x_grid[0:5]}")
# print(f"Partonic FK\n{FK[0:5, ]}")
# print(f"Hadronic obs\n{obs_noise[0:5, ]}")

# import pdb
# pdb.set_trace()



# Neural network ..................................................................................

# Torch class PDFNet: mirrors n3fit graph structure (Fig. 1 of paper) 
# Architecture (x, log x) -> [8] -> [4] -> [1] (input preprocessing, sigmoid hidden, linear output)
class PDFNet(nn.Module):

    def __init__(self):
        super().__init__()
        self.hidden1 = nn.Linear(2, 8)
        self.hidden2 = nn.Linear(8, 4)
        # self.hidden2 = nn.Linear(8, 32)
        # self.hidden3 = nn.Linear(32, 4)
        self.output = nn.Linear(4, 1)
        self.sigmoid = nn.Sigmoid()

        # Glorot normal initialisation (as in n3fit, Table 4)
        nn.init.xavier_normal_(self.hidden1.weight)
        nn.init.xavier_normal_(self.hidden2.weight)
        # nn.init.xavier_normal_(self.hidden3.weight)
        nn.init.xavier_normal_(self.output.weight)

    def forward(self, x):

        # Input preprocessing: (x, log x) — fixed first layer as in NNPDF
        x_log = torch.log(x)
        x_in  = torch.cat([x, x_log], dim = 1)
        h = self.sigmoid(self.hidden1(x_in))
        h = self.sigmoid(self.hidden2(h))
        # h = self.sigmoid(self.hidden3(h))
        out = self.output(h)

        # Preprocessing factor: x^{-alpha} * (1-x)^{beta}  (Eq. 1 of paper)
        pre = x**(-ALPHA) * (1 - x)**BETA
        return out * pre



# Single replica fit ..............................................................................

# Fit one PDF replica to noise-perturbed data. Returns f(x) predictions
def fit_replica(data_noisy, x_grid, x_cuts, obs_noise, n_epochs = N_EPOCHS, lr = LR):

    # Generate model
    model = PDFNet()
    optimizer = torch.optim.Adadelta(model.parameters(), lr = lr)

    # Prepare for training
    x_t = torch.tensor(x_grid, dtype = torch.float32).unsqueeze(1)

    # Precompute FK tensor and loss tracker
    FK_t = torch.tensor(FK, dtype = torch.float32)
    losses = []

    # Train model
    for epoch in range(n_epochs):

        optimizer.zero_grad()

        # Forward: get PDF on x_grid
        f_pred = model(x_t).squeeze().detach().numpy()

        # Convolute with FK kernel at each x_cut (toy observable)
        pred = np.array([convolute(f_pred[x_grid > xc], x_grid[x_grid > xc]) for xc in x_cuts])

        # Compute chi2 loss (Eq. 2 of paper)
        residuals = (data_noisy - pred) / obs_noise
        loss_val = float(np.sum(residuals**2))

        # Manual gradient step (compute loss outside autograd here for simplicity): Use autograd-compatible version below
        f_pred_t = model(x_t).squeeze()
       
        # NEW: single matrix multiply, fully differentiable
        pred_t = FK_t @ f_pred_t

        # Prepare truth and loss for gradient
        data_t = torch.tensor(data_noisy, dtype = torch.float32)
        sigma_t = torch.tensor(obs_noise,  dtype = torch.float32)
        loss = torch.sum(((data_t - pred_t) / sigma_t)**2)

        # Backpropagation
        loss.backward()
        optimizer.step()
        losses.append(float(loss))

    # Return final PDF prediction
    with torch.no_grad():
        pdf_final = model(x_t).squeeze().numpy()

    return pdf_final, losses



# MC replica loop .................................................................................

print(f"Fitting {N_REPLICAS} MC replicas...")

# Prepare replicas for uncertainty quantification
replicas = []
times = []
losses_all = []

# Print results
for i in range(N_REPLICAS):

    # Generate noise-perturbed data for this replica (MC approach, Section 2.1)
    print(f"\nReplica {i+1}/{N_REPLICAS}")
    data_noisy = obs_true + np.random.normal(0, obs_noise)

    # Time training
    start = time.perf_counter()
    pdf_final, loss_curve = fit_replica(data_noisy, x_grid, x_cuts, obs_noise)
    end = time.perf_counter()

    print(f"PDF final: {pdf_final[0:5]} ...")

    # Append result and time
    replicas.append(pdf_final)
    times.append(end - start)
    losses_all.append(loss_curve)

print(f"\nTraining time (avg per replica): {np.mean(times):.4f} s")
replicas = np.array(replicas)
f_mean = replicas.mean(axis = 0)
f_std = replicas.std(axis = 0)



# Plot ............................................................................................

# Prepare figure
fig, axes = plt.subplots(1, 3, figsize = (12, 5))

# Subfigure: PDF replicas + truth (mirrors Fig. 6 of paper)
ax = axes[0]
for i, rep in enumerate(replicas):
    ax.plot(x_grid, x_grid * rep, color = '#378ADD', lw = 0.8, alpha = 0.4, label = 'replicas' if i == 0 else None)

ax.plot(x_grid, x_grid * f_mean, color = '#0C447C', lw = 2, label = 'mean')
ax.fill_between(x_grid, x_grid * (f_mean - f_std), x_grid * (f_mean + f_std), color = '#378ADD', alpha = 0.2, label = '1σ band')
ax.plot(x_grid, x_grid * truth_pdf(x_grid),  color = '#D85A30', lw = 2, ls = '--', label = 'truth')
ax.set_xscale('log')
ax.set_xlabel('x')
ax.set_ylabel('x f(x)')
ax.set_title(f'{N_REPLICAS} PDF replicas with architecture: (x, log x) → 8 → 4 → 1', fontsize = 9)
ax.legend(fontsize = 8)

# Subfigure: chi2 per replica (mirrors Table 5 / Fig. 5 of paper)
chi2_per_replica = []
for rep in replicas:
    pred = np.array([convolute(rep[x_grid > xc], x_grid[x_grid > xc]) for xc in x_cuts])
    chi2 = np.sum(((obs_true - pred) / obs_noise)**2) / len(x_cuts)
    chi2_per_replica.append(chi2)

ax = axes[1]
ax.hist(chi2_per_replica, bins = 10, color = '#185FA5', alpha = 0.7, edgecolor = 'black')
ax.axvline(np.mean(chi2_per_replica), color = '#D85A30', lw = 2, label = f'mean χ²/n = {np.mean(chi2_per_replica):.2f}')
ax.set_xlabel('χ²/n per replica')
ax.set_ylabel('count')
ax.set_title(r'$\chi^2$ per replica (good fit: $\frac{\chi^2}{n} ≈ 1$)', fontsize = 9)
ax.legend(fontsize = 8)

# Subfigure: loss curve per replica
ax = axes[2]
for i, lc in enumerate(losses_all):
    ax.plot(lc, color = '#1D9E75', lw = 0.8, alpha = 0.4, label = 'replicas' if i == 0 else None)
ax.plot(np.mean(losses_all, axis = 0), color = '#0F6E56', lw = 2, label = 'mean')
ax.set_yscale('log')
ax.set_xlabel('epoch')
ax.set_ylabel('chi2 loss')
ax.set_title('Loss curve per replica\n(train only — no val split yet)', fontsize = 9)
ax.legend(fontsize = 8)

# Set figure titles and save
fig.suptitle('Toy PDF fit with PyTorch: NPDF/n3fit methodology (arXiv:1907.05075)', fontsize = 10)
plt.tight_layout()
plt.savefig(f'results/pdf_toy_torch_{N_REPLICAS}replicas_{N_EPOCHS}epochs_{LR}lr.png', dpi = 150, bbox_inches = 'tight')
print("Saved PyTorch results")
plt.show()
