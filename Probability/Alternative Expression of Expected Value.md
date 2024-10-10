Tag: #probability 
Previous: [[Expected Value]]
Link: 

---

Let $X$ be a non-negative discrete random variable with

- the set of possible values $S = \{x_1, x_2, \ldots\}$
- CDF of $X$ is $F_X(x)$

Denote $x_0 = 0$. The expected value of $X$ is

$$
E[X] = \sum_{i = 1}^{\infty} (x_i - x_{i - 1}) \cdot (1 - F_X(x_i^-))
$$

# Example

## 1. How alternative expression of expected value works

Suppose $X$ is a non-negative discrete random variable with

- the set of possible values $\{x_1, x_2, \ldots\}$ (assume $x_i < x_{i + 1}$)
- We denote $x_0 = 0$

We can draw the CDF of $X$ as follows:

![[Pasted image 20241010154000.png]]

The left side is the normal way of calculating the expected value, but we can calculate it in another way (as shown in the right side).

---

# Reference

1. P.-C. Hsieh, “515512: Probability Lecture 9 - Discrete Random Variables, Entropy, and Expected Value,” NYCU EC016, Oct. 09, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.