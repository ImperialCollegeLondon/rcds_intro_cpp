# JUE260613
# Reads CSVs written by fire_heat_simulation.cpp and plots the three ODE solutions.
# Row 1: Euler numerical solution
# Row 2: Analytical solution overlaid on Euler
# Usage: python plot_solutions.py results 4_runcards/default.json



# Import libraries ................................................................................

import sys
import json
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt



# Prepare input / output paths and read data ......................................................

results_dir  = sys.argv[1] if len(sys.argv) > 1 else "results"
runcard      = json.load(open(sys.argv[2]))

fourier   = pd.read_csv(f"{results_dir}/data/fourier.csv")
arrhenius = pd.read_csv(f"{results_dir}/data/arrhenius.csv")
advection = pd.read_csv(f"{results_dir}/data/advection.csv")

t = fourier.t.values



# Compute analytical solutions ....................................................................

# Fourier: T(t) = T_amb + (T0 - T_amb) * exp(-k * t)
k_cool  = runcard["k_cool"]
T0_f    = runcard["T0_fourier"]
T_amb   = runcard["T_amb"]
T_exact = T_amb + (T0_f - T_amb) * np.exp(-k_cool * t)

# Arrhenius: C(t) = C0 * exp(-k(T) * t)
k_arr   = runcard["A_pre"] * np.exp(-runcard["Ea"] / (runcard["R"] * (runcard["T_rxn"] + 273.15)))
C_exact = runcard["C0"] * np.exp(-k_arr * t)

# Advection: T(t) = T_cold + (T0 - T_cold) * exp(-alpha * t)
alpha       = runcard["alpha"]
T0_adv      = runcard["T0_advection"]
T_cold      = runcard["T_cold"]
T_adv_exact = T_cold + (T0_adv - T_cold) * np.exp(-alpha * t)



# Plot ............................................................................................

fig, axes = plt.subplots(2, 3, figsize=(13, 8))

# ── Row 1: Euler only ─────────────────────────────────────────────────────────────────────────

ax = axes[0, 0]
ax.plot(fourier.t, fourier.state, color='#185FA5', lw=2)
ax.set_xlabel('time (s)')
ax.set_ylabel('T (deg C)')
ax.set_title('Fourier\ndT/dt = -k (T - T_amb)')

ax = axes[0, 1]
ax.plot(arrhenius.t, arrhenius.state, color='#D85A30', lw=2)
ax.set_xlabel('time (s)')
ax.set_ylabel('concentration C')
ax.set_title('Arrhenius\ndC/dt = -k(T) C')

ax = axes[0, 2]
ax.plot(advection.t, advection.state, color='#1D9E75', lw=2)
ax.set_xlabel('time (s)')
ax.set_ylabel('T (deg C)')
ax.set_title('Advection\ndT/dt = -alpha (T - T_cold)')

# ── Row 2: Euler + analytical ─────────────────────────────────────────────────────────────────

ax = axes[1, 0]
ax.plot(fourier.t, fourier.state, color='#185FA5', lw=2,   label='Euler')
ax.plot(t,         T_exact,       color='black',   lw=1.5, ls='--', label='analytical')
ax.set_xlabel('time (s)')
ax.set_ylabel('T (deg C)')
ax.set_title('Fourier — Euler vs analytical')
ax.legend(fontsize=9)

ax = axes[1, 1]
ax.plot(arrhenius.t, arrhenius.state, color='#D85A30', lw=2,   label='Euler')
ax.plot(t,           C_exact,         color='black',   lw=1.5, ls='--', label='analytical')
ax.set_xlabel('time (s)')
ax.set_ylabel('concentration C')
ax.set_title('Arrhenius — Euler vs analytical')
ax.legend(fontsize=9)

ax = axes[1, 2]
ax.plot(advection.t, advection.state, color='#1D9E75', lw=2,   label='Euler')
ax.plot(t,           T_adv_exact,     color='black',   lw=1.5, ls='--', label='analytical')
ax.set_xlabel('time (s)')
ax.set_ylabel('T (deg C)')
ax.set_title('Advection — Euler vs analytical')
ax.legend(fontsize=9)

fig.suptitle('Explicit Euler — three ODE solutions', fontsize=12)
plt.tight_layout()

# Save figure
outpath = f"{results_dir}/figures/simulation.png"
plt.savefig(outpath, dpi=150, bbox_inches='tight')
print(f"saved {outpath}")
