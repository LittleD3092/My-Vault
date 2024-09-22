import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

N_val = np.arange(3, 101)
M_val = np.arange(2, 100)

# P(E_{M,N}) values
p_mat = np.zeros((len(M_val), len(N_val)))

# calculate P(E_{M,N}) values
for i, M in enumerate(M_val):
    for j, N in enumerate(N_val):
        if M < N:
            p_mat[i, j] = (
                (N - M) * (N - 1) / # numerator
                (N * (N - 2)) # denominator
            )
        else:
            p_mat[i, j] = np.nan # invalid case

# plot
plt.figure(figsize=(14, 10))
sns.heatmap(
    p_mat, cmap='viridis',
    xticklabels=N_val, yticklabels=M_val,
    mask=np.isnan(p_mat), cbar_kws={'label': 'P(E_{M,N})'}
)
plt.title('Heatmap of P(E_{M,N}) for M and N')
plt.xlabel('N (Number of Doors)')
plt.ylabel('M (Number of Empty Doors)')
plt.tight_layout()
plt.show()