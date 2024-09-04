Tag: #probabilistic-robotics 
Previous: [[Probabilistic Robotics]]
Link: 

[TOC]

---

Conditional independence implies that when a condition (a random variable $Z = z$) occurs, $X$ and $Y$ are independent.

$$p(x, y\vert z) = p(x \vert z) p(y\vert z)$$

Note that even if $X$ and $Y$ are independent, they may not have conditional independence, and vise versa.

$$
\left\{
	\begin{array}{rl}
		p(x, y) = p(x)p(y) &\cancel \implies & p(x, y\vert z) = p(x\vert z)p(y\vert z) \\
		p(x, y\vert z) = p(x\vert z)p(y\vert z) &\cancel\implies& p(x, y) = p(x)p(y)
	\end{array}
\right.
$$

---

# Reference

1. Thrun, Sebastian, et al. Probabilistic Robotics. 1st edition, The MIT Press, 2005.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.