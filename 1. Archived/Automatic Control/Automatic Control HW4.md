Tag: #automatic-control 

---

# (1)

$$G_c(s) = K_c\alpha\frac{Ts + 1}{\alpha Ts _ 1}$$

> $$K = K_c\alpha$$

$$\implies G_c(s) = K\frac{Ts + 1}{\alpha Ts + 1}$$

Open-loop transfer function equals:

$$G_c(s)G(s) = \frac{K}{s(0.1s + 1)(s + 1)}\frac{Ts + 1}{\alpha Ts + 1}$$

$$
\begin{array}{l}
	K_v & = & \displaystyle \lim_{s \rightarrow 0}s  G_c(s)G(s) \\
	 & = & \displaystyle
	 \lim_{s \rightarrow 0} \frac{sk}{s(0.1s + 1)(s + 1)} \\
	 & = & k = 4
\end{array}
$$

$$G_c(s)G(s) = \frac{4}{s(0.1s + 1)(s + 1)}$$

- Phase margin $= 17.7 \degree$
- Gain margin $= 8.79\text{ dB}$

$$\phi_m = 45\degree - 17.7\degree + 15 \degree = 42.3\degree$$

$$\sin \phi_m = \frac{1 - \alpha}{1 + \alpha}$$

$$\implies \alpha = 0.195$$

$$
\begin{array}{l}
	\displaystyle
	\left\vert
		\frac{1 + sT}{1 + \alpha sT}
	\right\vert & = &
	\displaystyle 
	\left\vert
		\frac{1 + j\omega T}{1 + \alpha j\omega T}
	\right\vert \\
	& = & 
	\displaystyle
	\left\vert
		\frac{1 + j\frac{1}{\sqrt \alpha}}{1 + j\alpha\frac{1}{\sqrt{\alpha}}}
	\right\vert \\
	 & = & 
	 \displaystyle
	 \frac{1}{\sqrt\alpha} \\
	 & = & 
	 \displaystyle
	 \frac{1}{\sqrt{0.195}} \\
	 & = & 7.08\ (\text{dB})
\end{array}
$$

$$\omega = 2.87$$

$$\implies \left\vert
	\frac{4}{s(0.1s + 1)(s + 1)}
\right\vert = -7.08$$

$$\frac 1 T = \sqrt \alpha \omega_c = 1.27$$

$$\frac{1}{\alpha T} = \frac{\omega_c}{\sqrt{\alpha}} = 6.5$$

$$G_c(s) = K_c\frac{s + 1.27}{s + 6.5}$$

$$K_c \frac K \alpha = 20.51$$

$$
\begin{array}{l}
	G_c(s)G(s) & = & 
	\displaystyle
	20.51 \frac{s + 1.27}{s + 6.5}\frac{1}{s(0.1s + 1)(s + 1)} \\
	& = & 
	\displaystyle
	\frac{20.51s + 26.05}{0.1s^4 + 1.75s^3 + 8.15s^2 + 6.5s}
\end{array}
$$

# (2)

For $G(s)$:

![[Pasted image 20230104222159.png]]

For $G_c(s)G(s)$:

![[Pasted image 20230104222242.png]]

# (3)

![[Pasted image 20230104222310.png]]