Tag: #probabilistic-robotics
Previous: [[Probabilistic Robotics]]
Link: 

[TOC]

---

Bayes rule defines the relationship of [[Conditional Probability]] $p(x\vert y)$ and its inverse $p(y\vert x)$. 

$$
\begin{array}{l}
	p(x\vert y) &=& 
	\displaystyle\frac{p(y \vert x)p(x)}{p(y)} &=&
	\displaystyle
	\frac{p(y\vert x)p(x)}{\sum_{x'}p(y\vert x')p(x')} & \text{for discrete} \\
	p(x\vert y) &=&
	\displaystyle
	\frac{p(y\vert x)p(x)}{p(y)} &=&
	\displaystyle
	\frac{p(y\vert x)p(x)}{\int p(y \vert x') p(x')dx'} &
	\text{for continuous}
\end{array}
$$

The $p^{-1}(y)$ in the above equations is often written as $\eta$, because it is independent from $x$.

$$p(x\vert y) = \eta p(y\vert x)p(x)$$

If random variable $X$ is discrete, the above equation can be denoted and computed as follows:

$$\begin{array}{rrl}
	& \forall x: \text{aux}_{x\vert y} &=&
	p(y\vert x)p(x) \\
	& \text{aux}_y &=& \displaystyle
	\sum_{x} \text{aux}_{x\vert y} \\
	\implies & \forall x: p(x\vert y) &=&
	\displaystyle
	\frac{\text{aux}_{x\vert y}}{\text{aux}_y}
\end{array}$$

---

# Reference

1. Thrun, Sebastian, et al. Probabilistic Robotics. 1st edition, The MIT Press, 2005.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.