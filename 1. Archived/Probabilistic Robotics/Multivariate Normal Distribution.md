Tag: #probabilistic-robotics 
Previous: [[Normal Distribution]]
Link: 

[TOC]

---

For multivariate normal distribution ($\bf x$ is a multi-dimensional vector), the distributions is:

$$p({\bf x}) = 
\det(2\pi \Sigma)^{-\frac 1 2}
\exp\left(
	-\frac 1 2 ({\bf x} - \mu)^T
	\Sigma^{-1}({\bf x} - \mu)
\right)
$$

- $\bf x$: A multi-value vector.
- $\Sigma$: Covariance matrix.

---

# Reference

1. Thrun, Sebastian, et al. Probabilistic Robotics. 1st edition, The MIT Press, 2005.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.