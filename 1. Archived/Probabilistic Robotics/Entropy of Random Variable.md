Tag: #probabilistic-robotics 
Previous: [[Probabilistic Robotics]]
Link: 

[TOC]

---

The entropy $H$ of a random variable $X$ is the uncertainty of $X$. 

> For example, when flipping a coin, $p(x) = 0.5$ for both head and tails. The entropy $H(P)$ will be maximum. But if we modify the probability $p(\text{heads}) = 1$, the entropy $H(P) = 0$, meaning that the outcomes have no uncertainty.

The entropy can be calculated using the following formula:

$$
\begin{array}{l}
	H(P) &=& E[-\log_2p(x)] \\
	&=& 
	\displaystyle
	-\sum_{x} p(x) \log_2 p(x)
\end{array}
$$

---

# Reference

1. Thrun, Sebastian, et al. Probabilistic Robotics. 1st edition, The MIT Press, 2005.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.