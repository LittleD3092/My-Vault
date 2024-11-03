Tag: #probability 
Previous: [[Joint Cumulative Distribution Function]]
Link: 

---

Marginal CDF is a special case of joint CDF. 

Let $X$ and $Y$ be two random variables defined on the same sample space $\Omega$, and the joint CDF is $F_{XY}(t, u)$. The marginal CDF of $X$ and $Y$ are:

$$
\begin{array}{l}
	F_X(t) &= P(X \leq t) &= F_{XY}(t, \infty) \\
	F_Y(t) &= P(Y \leq t) &= F_{XY}(\infty, t)
\end{array}
$$

---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 14 - Joint Distributions.” NYCU EC016, November 1, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.