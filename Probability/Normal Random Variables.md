Tag: #probability 
Previous: [[Probability]]
Link: 

---

A random variable $X$ is called normal with parameters $\mu, \sigma$ if its PDF is

$$
f_X(x) = \frac{1}{\sigma\sqrt{2\pi}} \exp\left(
	\frac{-(x - \mu)^2}{2\sigma^2}
\right)
$$

The notation for normal random variable $X$:

$$
X \sim \mathcal{N}(\mu, \sigma^2)
$$

# Example

## 1. General linear transformation

$X$ is a continuous random variable with CDF and PDF:

$$
\begin{array}{l}
	\text{CDF:} & F_X(t) \\
	\text{PDF:} & f_X(t) = \displaystyle \frac{dF_X(t)}{dt}
\end{array}
$$

Consider $Y = aX + b,\ a,\ b \in \mathbb R,\ a \neq 0$.

- What is CDF $F_Y(t)$?
- What is PDF $f_Y(t)$?

---

$$
\begin{array}{rl}
	F_Y(t) &=& P(Y \leq t) \\
	&=& P(aX + b \leq t) \\
	&=& \left\{
		\begin{array}{}
			\displaystyle P\left(
				X \leq \frac{t - b}{a}
			\right), & \text{if } a > 0 \\
			\displaystyle P\left(
				X \geq \frac{t - b}{a}
			\right), & \text{if } a < 0
		\end{array}
	\right. \\
	&=& \left\{
		\begin{array}{l}
			\displaystyle 
			F_X\left(
				\frac{t - b}{a}
			\right), & \text{if } a > 0 \\
			\displaystyle 1 - F_X\left(
				\frac{t - b}{a}
			\right), & \text{if } a < 0
		\end{array}
	\right.
\end{array}
$$

$$
\begin{array}{rl}
	f_Y(t) &=& \displaystyle
	\frac{d}{dt} F_Y(t) \\
	&=& \left\{
		\begin{array}{l}
			\displaystyle
			\frac{1}{a} \cdot f_X\left(
				\frac{t - b}{a}
			\right) & , \text{ if }a > 0 \\
			\displaystyle
			\frac 1 a \cdot \left(
				-f_X\left(
					\frac{t - b}{a}
				\right)
			\right) & , \text{ if } a < 0
		\end{array}
	\right.
\end{array}
$$

## 2. Normal & Linear Transformation

Let $X \sim \mathcal N(0, 1)$. Define another random variable $Y$ as

$$
Y = \left\{
	\begin{array}{l}
		2X + 3, & \text{if } X > 1 \\
		X - 5, & \text{otherwise}
	\end{array}
\right.
$$

What is the CDF of $Y$?

---

By calculating the boundary at $x = 1$, we can see that the transformed range is at $x > 5$ and $x < -4$.

![[Pasted image 20241023195255.png|200]]

Therefore there are 3 cases.

Case 1. $y \leq -4$:

$$
\begin{array}{l}
	F_Y(t) &=& P(Y \leq t) \\
	&& \text{By total probability theorem:} \\
	&=& P(Y \leq t \text{ and } X > 1) + P(Y \leq t \text{ and } X \leq 1) \\
	&=& 0 + P(Y \leq t \text{ and } X \leq 1) \\
	&=& P(Y \leq t \text{ and } X \leq 1) \\
	&=& P(X - 5 \leq t) \\
	&=& P(X \leq 5 + t) \\
	&=& F_X(5 + t) \\
	&=& \Phi(5 + t)
\end{array}
$$

$$
\begin{array}{}
	f_Y(y) &=& \Phi'(5 + t) \\
	&=& f_X(5 + t)
\end{array}
$$

Case 2. $-4 < t \leq 5$:

$$
\begin{array}{l}
	F_Y(t) &=& P(Y \leq t) \\
	&& \text{By total probability theorem:} \\
	&=& P(
		\underbrace{Y \leq t \text{ and } X > 1}_{\phi}
	) + P(Y \leq t \text{ and } X \leq 1) \\
	&=& P(Y \leq t \text{ and } X \leq 1) \\
	&=& P(Y \leq -4) \\
	&=& P(X - 5 \leq -4) \\
	&=& P(X \leq 1) \\
	&=& \Phi(1)
\end{array}
$$

$$
f_Y(y) = 0
$$

Case 3. $t > 5$:

$$
\begin{array}{l}
	F_Y(t) &=& P(Y \leq t) \\
	&=& P(Y \leq t \text{ and } X > 1) +
	P(\underbrace{Y \leq t \text{ and } X \leq 1}_{X \leq 1}) \\
	&=& P(5 < Y \leq t) + P(X \leq 1) \\
	&=& P(5 < 2X + 3 \leq t) + P(X \leq 1) \\
	&=& \displaystyle P\left(
		1 < X \leq \frac{t - 3}{2}
	\right) + P(X \leq 1) \\
	&=& \Phi \left(
		\displaystyle 
		\frac{t - 3}{2}
	\right)
\end{array}
$$

$$
f_Y(y) = \frac 1 2 \Phi' \left(\frac{t - 3}{2}\right)
$$

---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 12 - Continuous Random Variables.” NYCU EC016, October 16, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.