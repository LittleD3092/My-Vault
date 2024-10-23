Tag: #probability 
Previous: [[Probability]]
Link: 

---

A random variable $X$ is uniform with parameters $a, b\ (a < b)$ if its PDF is:

$$
f_X(x) = \left\{
	\begin{array}{l}
		\displaystyle \frac{1}{b - a}, & \text{if }a < x < b \\
		0, & \text{otherwise}
	\end{array}
\right.
$$

The plot:

![[Pasted image 20241022154121.png|400]]

- [[Inverse Transform Sampling]]

# Example

## 1. Uniform distribution from other random variable's CDF

Let $X$ be a random variable with CDF $F(t)$. Define another random variable $Y = F(X)$. What type of random variable is $Y$?

---

We can write the CDF of Y:

$$
\begin{array}{rl}
	F_Y(t) &=& P(Y \leq t) \\
	&=& P(\{\omega : Y(\omega) \leq t\}) \\
	&=& P(\{\omega : F(X(\omega)) \leq t\}) \\
	&=& t
\end{array}
$$

We can see that $Y$ is uniform distributed on $[0, 1]$:

$$Y \sim \text{Unif}(0, 1)$$

---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 12 - Continuous Random Variables.” NYCU EC016, October 16, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.