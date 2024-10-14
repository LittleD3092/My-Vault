Tag: #probability 
Previous: [[Probability]]
Link: 

---

Let $X$ be a discrete random variable with the set of possible values $S$ and PMF $p_X(x)$. The variance of $X$ is:

$$
\begin{array}{rl}
	\text{Var}[X] &:=& E[(X - \mu_X)^2] \\
	&=& \displaystyle \sum_{x\in S} (x - \mu_X)^2 \cdot p_X(x)
\end{array}
$$

It can also be calculated as:

$$
\text{Var}[X] := E[X^2] - (E[X])^2
$$

> 平方的平均 - 平均的平方

# Example

## 1. Show that variance is square average - average square

$$
\begin{array}{rl}
	\text{Var}[X] &=& E[(X - \mu_X)^2] \\
	&=& E[X^2 - 2X\mu_X + \mu_X^2] \\
	&& \text{By linearity} \\
	&=& E[X^2] + E[-2X\mu_X] + E[\mu_X^2] \\
	&&
	\begin{array}{rl}
		E[-2X \mu_X] &=& -2\cdot \mu_X \cdot E[X] \\
		&=& -2\cdot \mu_X^2
	\end{array} \\
	&=& E[X^2] - \mu_X^2
\end{array}
$$

## 2. Properties of Variance

### 2.1. Offset

$\text{Var}(X + c) = \text{Var}(X)$?

---

Yes.

### 2.2. Coefficient

$\text{Var}(aX) = a \cdot \text{Var}(X)$?

---

$\text{Var}(aX) = a^2\cdot \text{Var}(X)$
No.

### 2.3. Absolute value

$\text{Var}(\vert X \vert) = \text{Var}(X)$?

---

Counter example:
Define X as PMF $\displaystyle =\left\{ \begin{array}{l} \displaystyle \frac 1 2, x = 1 \\ \displaystyle \frac 1 2, x = -1 \end{array} \right.$
By simple calculation we get:
$\text{Var}(X) = 1$
$\text{Var}(\vert X\vert) = 0$
No.

### 2.4. Square

$E(X^2) \geq (E(X))^2$?

---

By the fact that variance is always $\geq 0$:
Yes.

---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 10 - Expected Value and Moments.” NYCU EC016, October 11, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.