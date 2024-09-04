import matplotlib.pyplot as plt
import numpy as np

# Range data for P_load and V_out
R_load = 100
P_load = np.arange(2.25, 20, 0.25)
V_out = np.sqrt(P_load * R_load)

# Plotting P_load and V_out
plt.plot(P_load, V_out)
plt.xlabel('P_load')
plt.ylabel('V_out')
plt.title('P_load vs V_out')
plt.grid(True)

# Save the plot
plt.savefig('P_load_vs_V_out.png')