Tag: #probability
Previous: [[Probability]]
Link: 

---

Poisson random variables define the number of occurrences in an observation window.

Given parameters:

- $\lambda$: Average rate.
- $T$: Duration of the observation window.

A random variable $X$ is Poisson with parameter $\lambda T$ if its probability mass function is given by:

$$
P(X = k) = \frac{(\lambda T)^k}{k!} e^{-\lambda T}
$$

# Example

## 1. Limiting Case of Binomial Random Variable

Consider $X \sim \text{Binomial}(n, p = \lambda / n)$, $\lambda$ is a constant.

- What is $P(X = k)$?
- What if $n \to \infty$?

---

The probability mass function of $X$ is:

$$
\begin{array}{l}
    P(X = k) &=& C^n_k p^k (1 - p)^{n - k} & (k = 0, 1, \dots, n) \\
    &=& \displaystyle \frac{n!}{k!(n - k)!} \left( \frac{\lambda}{n} \right)^k \frac{\left( 1 - \frac{\lambda}{n} \right)^{n}}{(1 - \frac{\lambda}{n})^k} \\
    &=& \displaystyle \frac{\lambda^k}{k!} \frac{n!}{n^k(n - k)!} \left( 1 - \frac{\lambda}{n} \right)^n \left( 1 - \frac{\lambda}{n} \right)^{-k} \\
\end{array}
$$

By letting $n \to \infty$, we have 4 parts:

1. $\displaystyle \frac{\lambda^k}{k!}$.
2. $\displaystyle \lim_{n \to \infty} \frac{n!}{n^k(n - k)!} = \frac{n \cdot (n - 1) \dots (n - k + 1)}{n^k} = 1$.
3. $\displaystyle \lim_{n \to \infty} \left( 1 - \frac{\lambda}{n} \right)^n = \left((1 - \frac{\lambda}{n})^{-\frac{n}{\lambda}}\right)^{-\lambda} = e^{-\lambda}$.
4. $\displaystyle \lim_{n \to \infty} \left( 1 - \frac{\lambda}{n} \right)^{-k} = 1$.

Therefore, when $n \to \infty$,

$$
P(X = k) = \frac{\lambda^k}{k!} e^{-\lambda}
$$

---

# Reference

1. P.-C. Hsieh, “515512: Probability Lecture 7 - Discrete Random Variables,” NYCU EC016, Sep. 27, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.