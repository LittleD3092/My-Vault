import matplotlib.pyplot as plt
import numpy as np

# constants
S_e = 208.6
S_y = 490
S_ut = 590
sigma_a = 0.162096
sigma_m = 0.162096

# x-axis
x_max = 700
x_min = 0
x = np.linspace(x_min, x_max, 1000)

# y-axis
y_max = 300
y_min = 0
# Goodman
goodman = (1 - (x / S_ut)) * S_e

# Gerber
gerber = (1 - (x / S_ut) ** 2) * S_e

# ASME-elliptic
asme_elliptic = 1 - (x / S_y) ** 2
for ele in asme_elliptic:
    if ele < 0:
        ele = 0
asme_elliptic = np.sqrt(asme_elliptic) * S_e

# langer static yield
langer_static_yield = -x + S_y

# load line
load_line = x * sigma_a / sigma_m

# plot
# locus
plt.plot(x, goodman, label='Goodman')
plt.plot(x, gerber, label='Gerber', linestyle='--')
plt.plot(x, asme_elliptic, label='ASME-elliptic', linestyle='-.')
# plt.plot(x, langer_static_yield, label='Langer static yield', linestyle=':')

# von Mises stress
plt.plot(sigma_m, sigma_a, 'ro', label='von Mises stress')

# load line
plt.plot(x, load_line, label='Load line', linestyle='-')

# chart
plt.legend()
plt.xlabel('Mean stress (kpsi)')
plt.ylabel('Alternating stress (kpsi)')
plt.ylim(y_min, y_max)
plt.xlim(x_min, x_max)
plt.show()