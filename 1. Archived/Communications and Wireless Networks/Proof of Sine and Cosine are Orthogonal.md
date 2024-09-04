Tag: #communications-and-wireless-networks 
Previous: [[Orthogonal]]
Link: 

---

For two functions $f_1, f_2$ to be orthogonal, the following equation must be satisfied:

$$\int_{-L}^L f_1(x) f_2(x) dx = 0$$

Therefore, we should try to calculate the result of $f_1(x) = \sin(x), f_2(x) = \cos(x)$:

$$
\begin{array}{l}
	\int_{-L}^L \sin(x) \cos(x)dx & 
	\begin{array}{l}
		u = \sin x & dv = \cos x dx \\
		du = \cos x dx & v = \sin x
	\end{array} \\
	\displaystyle
	= \left.
		\sin^2x 
	\right\vert_{x = -L}^L - 
	\int_{-L}^L \sin x \cos x dx
\end{array}
$$

Moving the integrals to one side, we get:

$$
\begin{array}{l}
	\implies \displaystyle
	\int_{-L}^L \sin x \cos x dx &=&
	\displaystyle
	\left.\frac 1 2 \sin^2 x \right\vert_{x = -L}^L \\
	&=& 
	\displaystyle
	\frac 1 2\left(
		\sin^2 L - \sin^2(-L)
	\right) \\
	&=& \displaystyle
	\frac 1 2 (\sin^2L - \sin^2 L) \\
	&=& 0
\end{array}
$$

Therefore, $\sin(x)$ and $\cos(x)$ are orthogonal.

---

# Reference

1. 

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.