Tag: #probability 
Previous: [[Expected Value]]
Link: 

---

Let $X$ be a non-negative discrete random variable with

- the set of possible values $S = \{x_1, x_2, \ldots\}$
- CDF of $X$ is $F_X(x)$

Denote $x_0 = 0$. The expected value of $X$ is: (<u>1</u>)

$$
E[X] = \sum_{i = 1}^{\infty} (x_i - x_{i - 1}) \cdot (1 - F_X(x_i^-))
$$

If $X$ is a continuous random variable with CDF $F_X(x)$, the alternative expected value is: (<u>2</u>)

$$
E[X] = \int_{0}^\infty (1 - F_X(t))dt - \int_0^\infty F_X(-t)dt
$$

# Example

## 1. How alternative expression of expected value works (for discrete random variable)

Suppose $X$ is a non-negative discrete random variable with

- the set of possible values $\{x_1, x_2, \ldots\}$ (assume $x_i < x_{i + 1}$)
- We denote $x_0 = 0$

We can draw the CDF of $X$ as follows: (<u>1</u>)

![[Pasted image 20241010154000.png]]

The left side is the normal way of calculating the expected value, but we can calculate it in another way (as shown in the right side).

## 2. Using the alternative expression (discrete random variable)

Suppose $X$ is a discrete random variable. (<u>1</u>)

- For $X$, the set of possible values $A = \{2, 4, 6, 8 \dots\}$
- The CDF of $X$ is $\displaystyle F_X(t) = 1 - \frac{1}{2^t}$, $t \in A$
- What is $E[X]$?

---

$$
\begin{array}{rll}
    E(X) &=& \displaystyle \sum_{i = 1}^\infty x_i P_X(x_i) \\
    &=& \displaystyle \sum_{i = 1}^\infty (x_i - x_{i - 1}) \cdot (1 - F_X(x_i^-)) \\
    &=& \displaystyle \sum_{i = 2}^\infty (2) \cdot 
    \left(1 - 
        \left(
            1 - \frac{1}{(2\cdot (i - 1))^2}
        \right)
    \right) \\
    &=& \displaystyle \sum_{i = 2}^\infty \frac{1}{(2\cdot (i - 1))^2} \\
    &=& \displaystyle \frac 1 2 \sum_{i = 2}^\infty \frac{1}{(i - 1)^2} \\
    &=& \displaystyle \frac 1 2 \cdot \frac{\pi^2}{6}
\end{array}
$$

## 3. Proof of the alternative expression of a continuous random variable

Proof that: (<u>2</u>)

$$
E[X] = \int_{0}^\infty (1 - F_X(t))dt - \int_0^\infty F_X(-t)dt
$$

---

The expression can be separated into two parts:

$$
E[X] = \underbrace
{\int_{0}^\infty (1 - F_X(t))dt}_{\text{A}} - 
\underbrace{\int_0^\infty F_X(-t)dt}_{\text{B}}
$$

For part $A$:

$$
\begin{array}{rl}
	\displaystyle \int_0^\infty (1 - F_X(t))dt &=& 
	\displaystyle \int_0^\infty \left(
		\int_t^\infty f_X(x)dx
	\right)dt \\
	&& \text{By swapping integration} \\
	&=& \displaystyle
	\int_{0}^\infty \left(
		\int_{0}^x f_X(x)dt
	\right)dx \\
	&=& \displaystyle \int_0^\infty xf_X(x)dx
\end{array}
$$

> Note that the "swapping integration" part is [[Fubini's Theorem]]. (<u>3</u>)

For part $B$:

$$
\begin{array}{rl}
	\displaystyle
	\int_{0}^\infty F_X(-t) dt &=& \displaystyle
	\int_{0}^\infty \int_{-\infty}^{-t} f_X(x)dx dt \\
	&=& \displaystyle
	\int_{-\infty}^0 \left(
		\int_0^{-x} f_X(x)dt
	\right)dx \\
	&=& \displaystyle
	\int_{-\infty}^0 -x f_X(x)dx
\end{array}
$$

---

# Reference

1. P.-C. Hsieh, “515512: Probability Lecture 9 - Discrete Random Variables, Entropy, and Expected Value,” NYCU EC016, Oct. 09, 2024.
2. Hsieh, Ping-Chun. “515512: Probability Lecture 10 - Expected Value and Moments.” NYCU EC016, October 11, 2024.
3. ChatGPT. “Swapping Integrals Justification.” ChatGPT, November 3, 2024. https://chatgpt.com/share/67272796-b6e8-8004-81d9-83b1aaedc62f.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.