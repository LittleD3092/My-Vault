Tag: #statistics 
Previous: [[Poisson Process]]
Link: 

---

Exponential distribution describes the length of time between two random events in [[Poisson Process]]. The [[Probability Density Function]] is: (<u>1</u>)

$$
f(x) = \lambda e^{-\lambda x} \qquad \text{for } 0\leq x < \infty
$$

- $f(x)$: The probability of the length of time $x$ occurs between two random events.
- $\lambda$: The expected number of events in an unit.

The mean and variance of $X$ are:

$$
\begin{array}{}
	E(X) &=& \displaystyle \frac 1 \lambda \\
	V(X) &=& \displaystyle \frac{1}{\lambda^2}
\end{array}
$$

![[Pasted image 20240417210240.png|200]]

It is useful to know that there is also a formula about $P(X > x)$ for exponential distribution:

$$
P(X > x) = e^{-\lambda x}
$$

---

# Reference

1. Tseng, Yi-Ju. “Statistics, Chapter 3: Random Variables and Probability Distributions.” n.d. Accessed April 16, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.