Tag: #probability 
Previous: [[Joint Distributions Relationships.canvas|Joint Distributions Relationships]]
Link: 

---

Let $X$ and $Y$ be two continuous random variables. Then, $f_{XY}(x, y)$ is the joint PDF of $X$ and $Y$ if for every subset $B$ of $\mathbb R^2$, we have

$$
P((X, Y) \in B) = \int\int_B f_{XY}(x, y)dxdy
$$

# Examples

## 1. Proof from Joint CDF to Joint PDF

Prove that

$$
f_{XY}(x, y) = \frac{\partial^2}{\partial x \partial y} F_{XY}(x, y)
$$

---

The area of $f_{XY}(x, y)$ is:

![[Pasted image 20241112152656.png|200]]

$$
\begin{array}{rl}
	f_{XY}(x, y) &=& \displaystyle
	\lim_{\Delta x, \Delta y \to 0}
	\frac{P(x < X \leq x + \Delta x, \quad y < Y \leq y + \Delta y)}{\Delta x \Delta y} \\
	&=& 
	\displaystyle
	\lim_{\Delta x, \Delta y \to 0} \frac{F_{XY}(x + \Delta x, y + \Delta y) - F_{XY}(x, y + \Delta y) - F_{XY}(x + \Delta x, y) + F_{XY}(x, y)}{\Delta x \Delta y} \\
	&=& \displaystyle\lim_{\Delta y \to 0} \frac{1}{\Delta y} \left(
		\lim_{\Delta x \to 0} \frac{(F_{XY}(x + \Delta x, y + \Delta y) - F_{XY}(x, y + \Delta y)) - (F_{XY}(x + \Delta x, y) - F_{XY}(x, y))}{\Delta x}
	\right) \\
	&=& \displaystyle
	\lim_{\Delta y \to 0} \frac{1}{\Delta y} \left(
		\frac{\partial}{\partial x} F_{XY}(x, y + \Delta y) - \frac{\partial }{\partial x} F_{XY}(x, y)
	\right) \\
	&=& \displaystyle
	\frac{\partial}{\partial y} \frac{\partial}{\partial x} F_{XY}(x, y)
\end{array}
$$

## 2. Joint PDF is the product of the marginal PDFs under independence

If two continuous random variables $X, Y$ are **independent**, then the joint PDF satisfies that

$$f_{XY}(t, u) = f_X(t) \cdot f_Y(u)$$

Prove the above property.

---

$$
\begin{array}{l}
	f_{XY}(t, u) &=& 
	\displaystyle
	\left.
		\frac{\partial^2}{\partial X \partial Y} F_{XY}(x, y)
	\right\vert_{x=t, y=u} \\
	&&\text{By independence of } X, Y\\
	&=& \displaystyle
	\frac{\partial^2}{\partial X\partial Y}(F_X(x)\vert_{x=t} \cdot F_Y(y)\vert_{y=u}) \\
	&=& (f_X(x) \vert_{x=t}) \cdot (f_Y(y)\vert_{y=u})
\end{array}
$$

---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 14 - Joint Distributions.” NYCU EC016, November 1, 2024.
2. Hsieh, Ping-Chun. “515512: Probability Lecture 15 - Joint Distributions and Sum of Independent Random Variables.” NYCU EC016, November 6, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.