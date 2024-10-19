Tag: #probability 
Previous: [[Existence of Moments]]
Link: 

---

Let $\{a_n\}$ be a sequence of numbers. If $\{a_n\}$ satisfies that

1. $\displaystyle \sum_{n=1}^\infty a_n$ converges.
2. $\displaystyle \sum_{n=1}^\infty \vert a_n \vert = \infty$.

Then for any $B \in \mathbb{R} \cup \{\infty\}$, there exists a rearrangement $\{b_n\}$ of $\{a_n\}$ such that $\displaystyle \sum_{n=1}^\infty b_n = B$.

# Examples

## 1. Rearrangement of series can get different results

1. Consider a series $$\{a_n\}: 1, -1, \frac 1 2, -\frac 1 2, \frac 1 3, -\frac 1 3, \dots$$ What is $\displaystyle \sum_{n=1}^\infty a_n$?
2. Let's rearrange $\{a_n\}$ as $\{b_n\}$: $$1, \frac 1 2, \dots, \frac 1 M, -1, \frac{1}{M+1}, \dots, \frac{1}{2M}, -\frac 1 2, \frac{1}{2M+1}, \dots, \frac 1{3M}, -\frac 1 3, \dots, -\frac 1 k$$ What is $\displaystyle \sum_{n=1}^\infty b_n$?

---

**First question:**

$$
\begin{array}{rl}
	\displaystyle \sum_{n=1}^\infty a_n &=&
	\displaystyle 
	\lim_{N \to \infty} \sum_{n=1}^N a_n \\
	&=& 0
\end{array}
$$

**Second question:**

We first calculate the negative part.

$$
\begin{array}{rl}
	\displaystyle -1 - \frac 1 2 - \frac 1 3 - \dots-\frac 1 k &=& -\displaystyle \int_1^n \frac{dx}{x} \\
	&=& -\ln n
\end{array}
$$

Then we try to calculate the positive part:

$$
\begin{array}{rl}
	\displaystyle 
	1 + \frac 1 2 + \dots + \frac 1 M &\approx& \ln M \\
	\displaystyle
	\frac{1}{M + 1} + \dots + \frac{1}{2M} &\approx& \ln2M - \ln M \\
	\displaystyle
	\frac{1}{2M + 1} + \dots + \frac 1{3M} &\approx& \ln 3M - \ln2M \\
	& \vdots
\end{array}
$$

Therefore the summation of $\{b_n\}$ is:

$$
\begin{array}{rl}
	\displaystyle \sum_{n=1}^{KM} &\approx& (\ln KM) - (\ln k) \\
	&=& \ln M
\end{array}
$$

From the result of the two questions:

1. 0
2. $\ln M$

It turns out that you can get different limit sum by rearranging the series.

## 2. Using Riemann rearrangement theorem

Does the series

$$\{a_n\}: 1, -1, \frac 1 2, -\frac 1 2, \frac 1 3, -\frac 1 3, \dots$$

satisfy the Riemann rearrangement theorem?

---

From the example 1.1. we know that it converges, so it satisfies the first condition.

Second condition:

$$
\begin{array}{l}
	\displaystyle \sum_{n = 1}^\infty \vert a_n \vert &=& 1 + 1 + \frac 1 2 + \frac 1 2 + \frac 1 3 + \frac 1 3 + \dots \\
	&=& \displaystyle 2 \cdot \sum_{k=1}^\infty \frac 1 k \\
	&=& \infty
\end{array}
$$

Both conditions are satisfied, so the Riemann rearrangement theorem can be applied to this.

---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 11 - Moments and Continuous Random Variables.” NYCU EC016, October 16, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.