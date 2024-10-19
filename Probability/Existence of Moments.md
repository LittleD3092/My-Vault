Tag: #probability 
Previous: [[Probability]]
Link: 

---

Let $X$ be a random variable. Then, the $n$-th moment of $X$ (i.e. $E[X^n]$) is said to exist if $E[\vert X^n \vert] < \infty$.

- [[Riemann Rearrangement Theorem]]

# Examples

## 1. Why moments might not exist?

Suppose $X$ is a random variable with PMF $p_X(x)$:

$$
p_X(k) = \left\{
	\begin{array}{rl}
		\displaystyle \frac{1}{2k(k + 1)}, & k = 1, 2, 3, \dots \\
		\displaystyle \frac{1}{2k(k - 1)}, & k = -1, -2, -3, \dots
	\end{array}
\right.
$$

Does $E[X]$ exist?

---

The expected value is written as:

$$
E[X] = \sum_{x\in S} (x)(P_X(x))
$$

According to [[Riemann Rearrangement Theorem]], we can rearrange the summation and get any expected value. In the concept of probability, in this case, it does not exist.

## 2. Example that first moment exists, but the second does not

Let $z_n = (-1)^n \sqrt n$, for $n = 1, 2, 3, \dots$. Let $Z$ be a random variable with the set of possible values $\{z_n : n = 1, 2, 3, \dots\}$ and the PMF $p_Z(z)$ as

$$
p_Z(z_n) = \frac{6}{(\pi n)^2}
$$

What is $\text{Var}[Z]$?

---

The variance is given by:

$$
\text{Var}[Z] = E[Z^2] - (E[Z])^2
$$

To calculate the variance, we need to first find out the existence of $E[Z^2]$ and $E[Z]$:

$$
\begin{array}{rl}
	E[\vert Z \vert] &=& \displaystyle
	\sum_{n = 1}^\infty \vert Z_n \vert \cdot P_Z(z_n) \\
	&=& \displaystyle \sum_{n=1}^\infty \sqrt n \cdot \frac{6}{(\pi n)^2} \\
	&=& \displaystyle \sum_{n=1}^\infty \frac{6}{\pi^2 n^{\frac 3 2}} \\
	&<& \infty \\
	E[\vert Z^2 \vert] &=& \displaystyle \sum_{n=1}^\infty \vert Z_n^2 \vert \cdot P_Z(z_n) \\
	&=& \displaystyle \sum_{n=1}^\infty n \cdot \frac{6}{(\pi n)^2} \\
	&=& \displaystyle \sum_{n=1}^\infty \frac 6 {\pi^2 n} \\
	&=& \infty
\end{array}
$$

The first moment exist, but the second moment does not exist. The variance does not exist because of it.

## 3. If higher moment exists, lower moment also exists

If $E(\vert X \vert^{n + 1}) < \infty$, then does $E(\vert X \vert^n) < \infty$?

---

$$
\begin{array}{rl}
	E[\vert X \vert^n] &=& \displaystyle \sum_{x \in S} \vert x \vert^n \cdot P_X(x) \\
	&=& \displaystyle \left(
		\sum_{x \in S: x \leq 1} \vert x \vert^n \cdot P_X(x)
	\right) + \left(
		\sum_{x\in S: x > 1}
		\vert x \vert^n \cdot P_X(x)
	\right)
\end{array}
$$

The left side:

$$
\begin{array}{rl}
	\displaystyle 
	\sum_{x \in S: x \leq 1} \vert x \vert^n \cdot P_X(x) &\leq& 
	\displaystyle 
	1 \cdot \sum_{x \in S: x \leq 1} P_x(X) \\
	&\leq& 1 \cdot 1
\end{array}
$$

The right side:

$$
\begin{array}{}
	\displaystyle
	\sum_{x\in S: x > 1}
	\vert x \vert^n \cdot P_X(x) &\leq & 
	\displaystyle
	\sum_{x\in S, x > 1} \vert x\vert^{n + 1} \cdot P_X(x)
\end{array}
$$

Because the left side is finite, we can see that if $E(\vert X \vert^{n + 1}) < \infty$, then $E(\vert X \vert^n) < \infty$.

---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 11 - Moments and Continuous Random Variables.” NYCU EC016, October 16, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.