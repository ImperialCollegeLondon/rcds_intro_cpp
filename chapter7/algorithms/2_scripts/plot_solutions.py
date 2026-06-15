"""
JUE260613
Reads CSVs written by main.cpp and plots the three ODE solutions.
Usage:  python plot.py <results_dir>
"""

import sys
import pandas as pd
import matplotlib.pyplot as plt

results_dir = sys.argv[1] if len(sys.argv) > 1 else "results"

fourier   = pd.read_csv(f"{results_dir}/data/fourier.csv")
arrhenius = pd.read_csv(f"{results_dir}/data/arrhenius.csv")
advection = pd.read_csv(f"{results_dir}/data/advection.csv")

fig, axes = plt.subplots(1, 3, figsize=(13, 4))

ax = axes[0]
ax.plot(fourier.t, fourier.state, color='#185FA5', lw=2)
ax.set_xlabel('time (s)')
ax.set_ylabel('T (deg C)')
ax.set_title('Fourier\ndT/dt = -k (T - T_amb)')

ax = axes[1]
ax.plot(arrhenius.t, arrhenius.state, color='#D85A30', lw=2)
ax.set_xlabel('time (s)')
ax.set_ylabel('concentration C')
ax.set_title('Arrhenius\ndC/dt = -k(T) C')

ax = axes[2]
ax.plot(advection.t, advection.state, color='#1D9E75', lw=2)
ax.set_xlabel('time (s)')
ax.set_ylabel('T (deg C)')
ax.set_title('Advection\ndT/dt = -alpha (T - T_cold)')

fig.suptitle('Explicit Euler — three ODE solutions', fontsize=12)
plt.tight_layout()
outpath = f"{results_dir}/figures/simulation.png"
plt.savefig(outpath, dpi=150, bbox_inches='tight')
print(f"saved {outpath}")