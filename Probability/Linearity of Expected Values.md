Tag: #probability 
Previous: [[Expected Value]]
Link: 

---

Let $X$ be a discrete random variable and $g(X)$, $g(X)$ be functions. Then, we have:

$$
E[g(X) + h(X)] = E[g(X)] + E[h(X)]
$$

# Example

## 1. Proof

By [[Law of the Unconscious Statistician|LOTUS]], 

$$
\begin{array}{rl}
	E[g(X) + h(X)] &=& \displaystyle
	\sum_{x \in S} (g(x) + h(x)) (P_X(x)) \\
	&=& \displaystyle 
	\sum_{x\in S} (g(x)\cdot P_X(x)) + \sum_{x\in S}(h(x) \cdot P_X(x)) \\
	&=& E[g(X)] + E[h(X)]
\end{array}
$$

---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 10 - Expected Value and Moments.” NYCU EC016, October 11, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.