# JUE260613

# Plot fitted parton distribution as function of x
# Reproduce results from NNPDF n3fit (Fig.6, Fog.9 of arXiv:1907.05075)

# Network: (x, log x) -> [8] -> [4] -> [1], sigmoid hidden, linear output
# Loss: chi2 = sum_i (D_i - P_i)^2 / sigma_i^2
# Replicas: N noise-perturbed copies of data -> N fits -> uncertainty band

