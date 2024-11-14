Tag: #probability 
Previous: [[Joint Distributions Relationships.canvas|Joint Distributions Relationships]]
Link: 

---

Let $X$ and $Y$ be two continuous random variables, and $f_{XY}(x, y)$ is the joint PDF of $X$ and $Y$. The marginal PDF of $X$ and $Y$ are

$$
\begin{array}{rl}
	f_X(x) &=& \displaystyle \int_{-\infty}^\infty f_{XY}(x, y)dy \\
	f_Y(y) &=& \displaystyle \int_{-\infty}^\infty f_{XY} (x, y) dx
\end{array}
$$

# Examples

## 1. Joint PDF to Marginal PDF

Let random variables $X$ and $Y$ be

$$
f(x, y) = \left\{
	\begin{array}{l}
		\displaystyle
		\frac 3 2 (x^2 + y^2), & \text{if } 0 < x < 1 \text{ and } 0 < y < 1 \\
		0, & \text{otherwise}
	\end{array}
\right.
$$

What is the marginal PDF of $X$?

---

$$
\begin{array}{l}
	f_X(x) &=& 
	\displaystyle
	\int_{-\infty}^\infty f(x, y) dy \\
	&=& \left\{
		\begin{array}{l}
			\displaystyle \int_0^1 \frac 3 2 (x^2 + y^2) dy, & \text{if } 0 < x < 1 \\
			0, & \text{otherwise}
		\end{array}
	\right. \\
	&=& \left\{
		\begin{array}{l}
			\displaystyle \left.
				\frac 3 2 x^2 y + \frac 1 2 y^3
			\right\vert_0^1, & \text{if 0 < x < 1}  \\
			0, & \text{otherwise}
		\end{array}
	\right. \\
	&=& \left\{
		\begin{array}{l}
			\displaystyle \frac{3}{2}x^2 + \frac 1 2, & \text{if } 0 < x < 1 \\
			0, & \text{otherwise}
		\end{array}
	\right.
\end{array}
$$

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 14 - Joint Distributions.” NYCU EC016, November 1, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.