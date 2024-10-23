Tag: #probability 
Previous: [[Probability]]
Link: 

---

A exponential random variable is a continuous counterpart of a geometric random variable.

A random variable $X$ is exponential with parameters $\lambda > 0$ if its **PDF** is:

$$
f_X(x) = \left\{
	\begin{array}{l}
		\lambda e^{-\lambda x}, & \text{if } x \geq 0 \\
		0, & \text{otherwise}
	\end{array}
\right.
$$

And its **CDF** is:

$$
F_X(t) = \left\{
	\begin{array}{l}
		0 & \text{if } t \leq 0 \\
		1 - e^{-\lambda t} & \text{if } t > 0
	\end{array}
\right.
$$

# Example

## 1. How is exponential random variable similar to geometric random variables?

Plot the PDF of $\text{Exp}(\lambda = 1)$ and $\text{Exp}(\lambda = 2)$.

---

![[Pasted image 20241023202115.png|300]]

- Blue line: $\text{Exp}(\lambda = 1)$
- Red line: $\text{Exp}(\lambda = 2)$

From the plot, we can see that the value $f_X(x)$ is exponentially decreasing, similar to [[Geometric Random Variables]].

## 2. What is the CDF and CCDF?

If the PDF of $X$ is:

$$
f_X(x) = \left\{
	\begin{array}{l}
		\lambda e^{-\lambda x} & \text{if } x \geq 0 \\
		0 & \text{otherwise}
	\end{array}
\right.
$$

What is the CDF of $X$?

---

If $t \leq 0$:

$$F_X(t) = 0$$

If $t > 0$:

$$
\begin{array}{rl}
	F_X(t) &=& P(X \leq t) \\
	&=& \displaystyle
	\int_{0}^t f_X(x) dx \\
	&=& \displaystyle
	\int_0^t \lambda \cdot e^{-\lambda x}dx \\
	&=& \left. -e^{-\lambda x} \right\vert_0^t \\
	&=& 1 - e^{-\lambda t}
\end{array}
$$

From the results, we can also see that the complementary cumulative distribution function is $e^{-\lambda t}$.

![[Pasted image 20241023203216.png|300]]

## 3. Exponential random variable also has memoryless property.

Suppose $X \sim \text{Exp}(\lambda)$. What is $P(X > s + t \vert X > t)$?

---

$$
\begin{array}{l}
	& P(X > s + t \vert X > t) \\
	=& \displaystyle
	\frac{P(X > s + t)}{P(X > t)} \\
	=& \displaystyle
	\frac{
		\displaystyle
		\int_{s + t}^\infty f_X(x)dx
	}{
		\displaystyle
		\int_{t}^\infty f_X(x)dx
	} \\
	=& \displaystyle
	\frac{e^{-\lambda (s + t)}}{e^{-\lambda t}} \\
	=& e^{-\lambda s} \\
	=& P(X > s)
\end{array}
$$

## 4. Minimum of two independent exponential random variables

Suppose $X_1 \sim \text{Exp}(\lambda_1)$ and $X_2 \sim \text{Exp}(\lambda_2)$.

- $X_1$ and $X_2$ are assumed to be independent.
- Let $X = \min(X_1, X_2)$.
- What is the CDF of $X$?

---

The CDF of $X$:

$$
\begin{array}{rl}
	F_X(t) &=& P(\{\omega : X(\omega) \leq t\}) \\
	&=& P(\{\omega : \min(X_1(\omega), X_2(\omega)) \leq t\}) \\
	&=& 1 - P(X_1(\omega) > t) \cdot P(X_2(\omega) > t) \\
	&=& 1 - e^{-\lambda_1 t} \cdot e^{-\lambda_2 t} \\
	&=& 1 - e^{-(\lambda_1 + \lambda_2)t} \\
	X &\sim & \text{Exp}(\lambda_1 + \lambda_2)
\end{array}
$$

### 4.1. Application of minimum exponential random variables

![[Pasted image 20241023210727.png|500]]

---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 13 - Continuous Random Variables, Expectation, and Joint Distributions.” NYCU EC016, October 16, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.