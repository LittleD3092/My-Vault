Tag: #probability 
Previous: [[Expected Value]]
Link: 

---

Let $X$ be a discrete random variable with

- the set of possible values $S$
- PMF of $X$ is $p_X(x)$

And $g(x)$ is a real-valued function, then the expected value of $g(x)$ is

$$
E[g(x)] = \sum_{X \in S} g(x) \cdot p_X(x)
$$

# Example

## 1. Prove

### 1.1. Why do we need proof? Isn't it intuitive?

At first glance the law is intuitive, but let's try calculating the expected value anyway.

We define $Y = g(X)$.

The expected value of $Y$ is:

$$
E[Y] = \sum(y)(p_Y(y))
$$

Looking at the above expression, $P_Y(y)$ might be different to $P_X(x)$. Therefore, we need a proof.

### 1.2. Proof of LOTUS

We define $Y = g(X)$ is a random variable.

$$
\begin{array}{rl}
	E[g(X)] &=& E[Y] \\
	&=& \displaystyle 
	\sum_{y \in S_Y} (y) (P_Y(y)) \\
	&& S_Y: \text{The set of possible values of }Y \\
	P_Y(y) &=& \displaystyle \sum_{x:g(x) = y} P_X(x) \\
	&=& \displaystyle \sum_{y\in S_Y} \sum_{x:g(x) = y} y \cdot P_X(x) \\
	&=& \displaystyle \sum_{(x, y): g(x) = y, y \in S_Y} y \cdot P_X(x) \\
	&=& \displaystyle \sum_{x \in S} g(x) \cdot P_X(x)
\end{array}
$$

---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 10 - Expected Value and Moments.” NYCU EC016, October 11, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.