# JUE260613

# Benchmark FK convolution — four implementations:
# 0. Python loop (baseline)
# 1. NumPy matmul (FK @ pdf)
# 2. C++ op (subprocess, reads timing from stdout)
# 3. PyTorch matmul



# Import libraries ................................................................................

import numpy as np
import torch
import time
import subprocess
import matplotlib.pyplot as plt



# Load data .......................................................................................

FK = np.load("data/fk_tables/FK.npy").astype(np.float32)
x_grid = np.load("data/fk_tables/x_grid.npy").astype(np.float32)
ALPHA, BETA = 0.3, 3.0
pdf = (x_grid**(-ALPHA) * (1 - x_grid)**BETA).astype(np.float32)
N_rep = 10000 # repetitions for timing



# 0. Python loop ..................................................................................

def python_loop(FK, pdf):

    N_obs, N_x = FK.shape
    pred = np.zeros(N_obs, dtype = np.float32)
    
    for n in range(N_obs):
        for i in range(N_x):
            pred[n] += FK[n, i] * pdf[i]
    
    return pred

# Time performance
t0 = time.perf_counter()
for _ in range(N_rep):
    pred_loop = python_loop(FK, pdf)
t1 = time.perf_counter()
time_loop = (t1 - t0) / N_rep * 1e6 # us per call
print(f"0. Python loop:    {time_loop:.2f} us")



# 1. NumPy matmul .................................................................................

# Time performance
t0 = time.perf_counter()
for _ in range(N_rep):
    pred_np = FK @ pdf
t1 = time.perf_counter()
time_np = (t1 - t0) / N_rep * 1e6
print(f"1. NumPy matmul:   {time_np:.2f} us")



# 2. C++ op .......................................................................................

# Run the compiled binary and parse its timing output

result = subprocess.run(["./2_scripts/fk_convolution", 
    "data/fk_tables/FK.bin", 
    "data/fk_tables/pdf.bin", 
    "data/fk_tables/pred.bin"], 
    capture_output = True, text = True)

# Parse "per call: X us" from stdout
time_cpp = None
for line in result.stdout.split("\n"):
    if "per call:" in line and "us" in line:
        time_cpp = float(line.strip().split()[-2])
        break

print(f"2. C++ op:         {time_cpp:.2f} us")



# 3. PyTorch matmul ...............................................................................

FK_t = torch.tensor(FK, dtype = torch.float32)
pdf_t = torch.tensor(pdf, dtype = torch.float32)

# Warmup
for _ in range(100):
    _ = FK_t @ pdf_t

t0 = time.perf_counter()
for _ in range(N_rep):
    pred_torch = FK_t @ pdf_t
t1 = time.perf_counter()
time_torch = (t1 - t0) / N_rep * 1e6
print(f"3. PyTorch matmul: {time_torch:.2f} us")



# Sanity check  ...............................................................................

print(f"\nSanity check — max diff loop vs numpy:  {np.max(np.abs(pred_loop - pred_np)):.2e}")
print(f"Sanity check — max diff torch vs numpy: {np.max(np.abs(pred_torch.numpy() - pred_np)):.2e}")



# Speedup table ...................................................................................

print(f"\nSpeedup over Python loop:")
print(f"  NumPy:   {time_loop/time_np:.1f}x")
print(f"  C++:     {time_loop/time_cpp:.1f}x")
print(f"  PyTorch: {time_loop/time_torch:.1f}x")



# Plot ............................................................................................

labels = ['Python\nloop', 'NumPy\nmatmul', 'C++\nop', 'PyTorch\nmatmul']
times = [time_loop, time_np, time_cpp, time_torch]
colors = ['#D85A30', '#185FA5', '#1D9E75', '#0C447C']
fig, axes = plt.subplots(1, 2, figsize = (11, 4))

# Left: absolute times
ax = axes[0]
bars = ax.bar(labels, times, color = colors, alpha = 0.85, edgecolor = 'black', linewidth = 0.5)
ax.set_ylabel('time per call (μs)')
ax.set_title('FK convolution — absolute time\npred = FK @ pdf,  shape (20,50)@(50,)')
for bar, t in zip(bars, times):
    ax.text(bar.get_x() + bar.get_width()/2, bar.get_height() + 0.05, f'{t:.2f}μs', ha = 'center', va = 'bottom', fontsize = 8)

# Right: speedup over Python loop
speedups = [time_loop/t for t in times]
ax = axes[1]
bars = ax.bar(labels, speedups, color = colors, alpha = 0.85, edgecolor = 'black', linewidth = 0.5)
ax.axhline(1, color = '#888780', lw = 0.8, ls = '--')
ax.set_ylabel('speedup over Python loop')
ax.set_title('FK convolution — speedup\n(higher is better)')
for bar, s in zip(bars, speedups):
    ax.text(bar.get_x() + bar.get_width()/2, bar.get_height() + 0.01, f'{s:.1f}x', ha = 'center', va = 'bottom', fontsize = 8)

fig.suptitle('FK convolution benchmark — pred = FK @ pdf', fontsize = 11)
plt.tight_layout()
plt.savefig('results/benchmark.png', dpi = 150, bbox_inches = 'tight')
print("\nsaved results/benchmark.png")
plt.show()
