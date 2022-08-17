標籤: #Mechanics-and-Materials 

---

# Stress Mohr's Circle

from [[Normal Stress]] and [[Shear Stress]]

$$
\left\{
	\begin{array}{l}
		\sigma_n & = & \frac{\sigma_x + \sigma_y}{2} + \frac{\sigma_x - \sigma_y}{2}\cos2\theta + \tau_{xy}\sin2\theta \\
		\tau_{nt} & = & -(\frac{\sigma_x - \sigma_y}{2}\sin2\theta + \tau_{xy}\cos2\theta)
	\end{array}
\right.
$$

$$
\left\{
	\begin{array}{rml}
		\sigma_n - \frac{\sigma_x + \sigma_y}{2} & = & \frac{\sigma_x - \sigma_y}{2}\cos2\theta + \tau_{xy}\sin2\theta \\
		\tau_{nt} & = & -(\frac{\sigma_x - \sigma_y}{2})\sin2\theta + \tau_{xy}\cos2\theta
	\end{array}
\right.
$$

兩者平方相加

$$(\sigma_n - \frac{\sigma_x - \sigma_y}{2})^2 + \tau_{nt}^2 = (\frac{\sigma_x - \sigma_y}{2})^2\cos^22\theta + (\frac{\sigma_x - \sigma_y}{2})^2\sin^22\theta + \tau_{xy}\sin^22\theta + \tau_{xy}^2\cos^22\theta$$
.
$$(\sigma_n - \frac{\sigma_x - \sigma_y}{2})^2 + \tau_{nt}^2 = (\frac{\sigma_x - \sigma_y}{2})^2 + \tau_{xy}^2 \qquad \dots \text{the mohr's circle}$$

$$\text{Radius:}\; \sqrt{(\frac{\sigma_x - \sigma_y}{2})^2 + \tau_{xy}^2}$$

$$\text{Center:}\; \left(\frac{\sigma_x + \sigma_y}{2},\; 0\right) = (\sigma_{\text{avg}}\;,\; 0)$$

![[mohr's circle.jpg]]

# Strain Mohr's Circle

$$(\varepsilon_n - \frac{\varepsilon_x + \varepsilon_y}{2})^2 + (\frac{\gamma_{xy}}{2} - 0)^2 = (\frac{\varepsilon_x - \varepsilon_y}{2})^2+(\frac{\gamma_{xy}}{2})^2$$

$$\text{Radius:}\; \sqrt{(\frac{\varepsilon_x - \varepsilon_y}{2})^2 + (\frac{\gamma_{xy}}{2})^2}$$

$$\text{Center:}\; (\frac{\varepsilon_x + \varepsilon_y}{2},\; 0) = (\varepsilon_{\text{avg}},\; 0)$$

---

參考資料:

Mechanics and Materials online course - coursera

---

link:

[[Shear Stress]]
[[Normal Stress]]
[[Shear Strain]]
[[Normal Strain]]