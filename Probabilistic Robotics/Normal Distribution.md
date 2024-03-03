Tag: #probabilistic-robotics #statistics 
Previous: [[Probabilistic Robotics]], [[Continuous Random Variables]]
Link: 

[TOC]

---

A normal distribution is a bell-shaped and symmetrical distribution. (<u>2</u>)

![[Pasted image 20240303171143.png|200]]

A normal distribution has parameters mean $\mu$ and variance $\sigma^2$. The [[Probability Density Function|PDF]] can be represented as:

$$p(x) = (2\pi \sigma^2)^{-\frac 1 2} \exp\left(-\frac{1}{2}\frac{(x - \mu)^2}{\sigma^2}\right)$$

- $x$: A scalar.
- $\mu$: [[Mean of Continuous Random Variables|Mean]].
- $\sigma^2$: [[Variance of Continuous Random Variables|Variance]].

The distribution can be represented as $\mathcal{N}(x; \mu, \sigma^2)$.

- [[Multivariate Normal Distribution]]

---

# Reference

1. Thrun, Sebastian, et al. Probabilistic Robotics. 1st edition, The MIT Press, 2005.
2. Y.-J. Tseng, “Statistics, Chapter 1: The Role of Statistics, Chapter 3: Random Variables and Probability Distributions,” NYCU ED302, Feb. 29, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.