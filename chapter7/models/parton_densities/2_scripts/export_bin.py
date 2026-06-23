# JUE260613

# Export FK table and a toy pdf to flat binary for the C++ op.
# numpy .tofile() writes raw float32 — no header, C++ reads directly.

import numpy as np

FK = np.load("data/fk_tables/FK.npy").astype(np.float32)
x_grid = np.load("data/fk_tables/x_grid.npy").astype(np.float32)

# Toy pdf: truth PDF evaluated on x_grid
ALPHA, BETA = 0.3, 3.0
pdf = (x_grid**(-ALPHA) * (1 - x_grid)**BETA).astype(np.float32)

FK.tofile("data/fk_tables/FK.bin")
pdf.tofile("data/fk_tables/pdf.bin")

print(f"FK shape: {FK.shape}  -> FK.bin")
print(f"pdf shape: {pdf.shape} -> pdf.bin")

# Sanity check
pred_np = FK @ pdf
print(f"pred[:5] (numpy reference): {pred_np[:5]}")