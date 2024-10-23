Tag: #probability 
Previous: [[Probability]]
Link: 

---

The derivative of CDF is PDF.

Let $X$ be a random variable with a CDF $F_X(\cdot)$ and a PDF $f_X(\cdot)$. If $f_X(\cdot)$. If $f_X(\cdot)$ is continuous at $x_0$, then

$$
F'_X(x_0) = f_X(x_0)
$$

# Example

## 1. Proof from CDF to PDF

The CDF is defined as:

$$
F_X(t) = P(X\leq t) = \int_{-\infty}^t f_X(x)dx
$$

Suppose PDF is continuous, then what is $F_X(t + \delta) - F_X(t)$?

---

$$
\begin{array}{rl}
	& F_X(t + \delta) - F_X(t) \\
	=& \displaystyle
	\left(
		\int_{-\infty}^{t + \delta} f_X(x)dx
	\right) - 
	\left(
		\int_{-\infty}^t f_X(x)dx
	\right) \\
	=& \displaystyle
	\int_{t}^{t + \delta}f_X(x)dx \\
	=& f_X(x)\delta \\
	\implies& f_X(t) = \displaystyle \frac{F_X(t + \delta) - F_X(t)}{\delta}
\end{array}
$$

PDF is the derivative of CDF.

## 2. Continuity is required from CDF to PDF

![[Pasted image 20241022153345.png]]

From the figure above, we can see that a CDF can have many PDFs, but a CDF can have only 1 continuous PDF.

---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 12 - Continuous Random Variables.” NYCU EC016, October 16, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.