Tag: #probability 
Previous: [[Uniform Random Variables]]
Link: 

---

We can generate **any** random variable with CDF $F(t)$ from a uniform random variable following the steps: (<u>1</u>)

1. Generate a random variable $U \sim \text{Unif}(0, 1)$
2. Let $X = F^{-1}(U)$, where $F^{-1}(u) := \text{inf}\{z : F(z) \geq u\}$

# Example

## 1. Proof that inverse transform sampling works

Demonstrate that if $U \sim \text{Unif}(0, 1)$ and $X = F^{-1}(U)$, then $X$ has the cumulative distribution function $F$. (<u>2</u>)

---

We aim to find:

$$
P(X \leq x)
$$

First, we substitute $X$ with $F^{-1}(U)$:

$$P(X \leq x) = P(F^{-1}(U) \leq x)$$

Since $F$ is strictly increasing, applying it preserves the inequality. We may apply $F$ to both sides of inequality:

$$
P(F(F^{-1}(U)) \leq F(x)) = P(U \leq F(x))
$$

Since $U$ is uniformly distributed over $[0, 1]$, the probability that any number $u \geq U$ is $u$:

$$\begin{array}{l}
	&P(U \leq u) = u, \qquad \text{for }u \in [0, 1] \\
	\implies &P(U \leq F(x)) = F(x)
\end{array}$$

Combining the above steps, we find out that:

$$P(X \leq x) = F(x)$$

- $P(X \leq x)$: CDF.
- $F(x)$: The CDF of the target distribution.

## 2. Applying inverse transform sampling

Generate a random variable $X$ with CDF

$$
F_X(t) = \left\{
	\begin{array}{l}
		1 - \exp(-t^2), & t \geq 0 \\
		0, & \text{otherwise}
	\end{array}
\right.
$$

---

Step 1: Generate $U \sim \text{Unif}(0, 1)$.

Step 2: Let $X = F_X^{-1}(U)$.

$$
\begin{array}{}
	& y = 1 - e^{-t^2} \\
	\implies & e^{-t^2} = 1 - y \\
	\implies & -t^2 = \ln(1 - y) \\
	\implies & t = \sqrt{-\ln (1 - y)} \\
\end{array}
$$

Therefore,

$$
F_X^{-1}(y) = \sqrt{-\ln(1 - y)}
$$

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 12 - Continuous Random Variables.” NYCU EC016, October 16, 2024.
2. ChatGPT o1-preview. “What Is Inverse Transform Sampling? Can You Prove It?,” October 22, 2024. https://chatgpt.com/share/67175db2-6c64-8004-85b8-e97a62b98433.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.