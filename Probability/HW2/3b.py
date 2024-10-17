import numpy as np

import matplotlib.pyplot as plt
import matplotlib

# Define the entropy function
def entropy(p):
    return -(p * np.log(p) + (1 - p) * np.log(1 - p))

matplotlib.use('Agg')

# Generate values for p_1
p_values = np.linspace(0.01, 0.99, 100)

# Calculate H(X) for each p_1
H_values = entropy(p_values)

# Plot the function
plt.plot(p_values, H_values, label='H(X)')
plt.xlabel('p_1')
plt.ylabel('H(X)')
plt.title('Entropy H(X) as a function of p_1')
plt.legend()
plt.grid(True)
plt.savefig('entropy_plot.png')