# JUE260613

# Generate toy FK table and x_grid, representing partonic cross section.
# Precomputed once before training: mirrors real n3fit FK table generation.

# FK table shape: (N_observables, N_x)
# FK[n, i] = trapezoid weight * K(x_i) if x_i > x_cut[n] else 0

# At training time: pred = FK @ pdf_flat; shape (N_obs,) = (20, 50) @ (50, )
# This replaces the per-epoch loop over x_cuts.



# Import libraries ................................................................................

import numpy as np
import os



# Grid and kernel .................................................................................

def fk_kernel(x):
    """Toy fastkernel: K(x) = x^2"""
    return x**2

# NNPDF log-spaced x grid
x_grid  = np.logspace(-4, -0.01, 50).astype(np.float32)

# Observable grid: x_cuts define integration lower limits
x_cuts  = np.linspace(0.01, 0.5, 20).astype(np.float32)



# Build FK table ..................................................................................

# FK[n, i] = trapezoid weight_i * K(x_i)  if x_i > x_cut[n] else 0

# Trapezoid weights: w_i = (x_{i+1} - x_{i-1}) / 2          (interior)
#                    w_0 = (x_1 - x_0) / 2                  (left edge)
#                    w_{N-1} = (x_{N-1} - x_{N-2}) / 2      (right edge)

N_obs = len(x_cuts)
N_x = len(x_grid)

# Trapezoid weights for x_grid
weights = np.zeros(N_x, dtype = np.float32)
weights[0] = (x_grid[1] - x_grid[0]) / 2
weights[-1] = (x_grid[-1] - x_grid[-2]) / 2
weights[1:-1] = (x_grid[2:] - x_grid[:-2]) / 2

# FK table
FK = np.zeros((N_obs, N_x), dtype = np.float32)
for n, xc in enumerate(x_cuts):
    mask       = x_grid > xc
    FK[n, mask] = fk_kernel(x_grid[mask]) * weights[mask]

print(f"FK table shape: {FK.shape}   (N_observables={N_obs}, N_x={N_x})")
print(f"x_grid shape:  {x_grid.shape}")
print(f"x_cuts shape:  {x_cuts.shape}")



# Save to disk ....................................................................................

outdir_fk = "data/fk_tables"
os.makedirs(outdir_fk, exist_ok = True)
np.save(f"{outdir_fk}/FK.npy",     FK)
np.save(f"{outdir_fk}/x_grid.npy", x_grid)
np.save(f"{outdir_fk}/x_cuts.npy", x_cuts)
print("\nsaved fk_tables/FK.npy")
print("saved fk_tables/x_grid.npy")
print("saved fk_tables/x_cuts.npy")



# Generate truth observables .....................................................................

# In reality these would be experimental measurements loaded from file.
# Here we generate them from a known truth PDF as a toy substitute.
# obs_true[n] = FK[n, :] @ f_true = int_{x_cut[n]}^1 f(x) * K(x) dx

ALPHA, BETA = 0.3, 3.0
noise_level = 0.05

f_true    = x_grid**(-ALPHA) * (1 - x_grid)**BETA   # truth PDF [shape (N_x,)]
obs_true  = (FK @ f_true).astype(np.float32)         # hadronic observables [shape (N_obs,)]
obs_noise = (obs_true * noise_level).astype(np.float32)  # experimental uncertainties [shape (N_obs,)]



# Save to disk ....................................................................................

outdir_cs = "data/cross_sections"
os.makedirs(outdir_cs, exist_ok = True)
np.save(f"{outdir_cs}/obs_true.npy",  obs_true)
np.save(f"{outdir_cs}/obs_noise.npy", obs_noise)
print("saved cross_sections/obs_true.npy")
print("saved cross_sections/obs_noise.npy")

print(f"\nobs_true shape:  {obs_true.shape}")
print(f"obs_noise shape: {obs_noise.shape}")
print(f"obs_true[:5]:    {obs_true[:5]}")



# Quick sanity check ..............................................................................

# pred = FK @ f_true should match manual trapezoid convolution

pred_fk = FK @ f_true
pred_manual = np.array([np.trapezoid(f_true[x_grid > xc] * fk_kernel(x_grid[x_grid > xc]), x_grid[x_grid > xc]) for xc in x_cuts])
max_err = np.max(np.abs(pred_fk - pred_manual))
print(f"\nSanity check — max error FK @ f vs manual trapezoid: {max_err:.2e}")
