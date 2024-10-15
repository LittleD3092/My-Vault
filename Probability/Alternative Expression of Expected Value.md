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

# Example

## 1. How alternative expression of expected value works

Suppose $X$ is a non-negative discrete random variable with

- the set of possible values $\{x_1, x_2, \ldots\}$ (assume $x_i < x_{i + 1}$)
- We denote $x_0 = 0$

We can draw the CDF of $X$ as follows: (<u>1</u>)

![[Pasted image 20241010154000.png]]

The left side is the normal way of calculating the expected value, but we can calculate it in another way (as shown in the right side).

## 2. Using the alternative expression

Suppose $X$ is a discrete random variable. (<u>2</u>)

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

---

# Reference

1. P.-C. Hsieh, “515512: Probability Lecture 9 - Discrete Random Variables, Entropy, and Expected Value,” NYCU EC016, Oct. 09, 2024.
2. Hsieh, Ping-Chun. “515512: Probability Lecture 10 - Expected Value and Moments.” NYCU EC016, October 11, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.