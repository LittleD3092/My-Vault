標籤: #Mechanics-and-Materials #Mechanical-Engineering-Design 

---

# Analyze cut in non - uniform beam bending to get shear force

![[Analyze cut in non - uniform beam bending to get shear force.jpg]]

$$\sum F_x = 0$$
$$\int_y^c \sigma_2 dA = \int_y^c \sigma_1 dA + \tau b dx \qquad b = \text{ width }$$

> from [[Elastic Fluxtural Formula of Beam Bending]]
> $$\sigma = \frac{ My }{ I }$$

$$\int_y^c \frac{ ( M + dM ) y }{ I } dA = \int_y^c \frac{ My }{ I } dA + \tau b dx$$
$$\frac{ dM }{ I } \int_y^c y dA = \tau b dx$$

> [[First Moment of Outward Area]]:
> $$Q = \int_y^c y dA$$

$$\frac{ dM }{ I } Q = \tau b dx$$
$$\tau = \frac{ dM }{ dx } \frac{ Q }{ Ib }$$

> Shear Force Diagram:
> $$\frac{ dM }{ dx } = V$$

$$\underline{ \tau = \frac{ VQ }{ Ib } }_{ \# }$$

# Limitations

> $$\tau = \frac{ VQ }{ Ib }$$
> $$b = \text{ width }$$

Stress is averaged across the width. Hence, this formula is only accurate if the width, $b$, is not too great.

![[width and height of a beam.jpg]]

$$
\begin{array}{lr}
\frac{ d }{ b } > 10      & \text{ exellent accuracy } \\
\frac{ d }{ b } \approx 2 & < 3\% \text{ error } \\
\frac{ d }{ b } \approx 1 & 12 \text{ or } 13\% \text{ error }
\end{array}
$$

---

參考資料:



---

link:

