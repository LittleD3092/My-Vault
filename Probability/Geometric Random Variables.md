Tag: #probability 
Previous: [[Probability]]
Link: 

---

Geometric random variables are similar to [[Bernoulli Random Variables]]. It repeats the same Bernoulli experiment and find the number of trials until the 1st success.

A random variable $X$ is Geometric with parameters $p$ if its PMF is given by:

$$
P(X = k) = (1 - p)^{k - 1}p, \qquad k = 1, 2, 3, \dots
$$

The [[Cumulative Distribution Function|CDF]] is:

$$
\begin{array}{rl}
    \text{Case 1: } t < 1 & F(t) = 0 \\
    \text{Case 2: } t \geq 1 & F(t) = 
    \displaystyle
    \sum_{k = 1}^{\lfloor t \rfloor} (1 - p)^{k - 1}p
\end{array}
$$

# Examples

## 1. Satisfy Total Probability Axiom

Do we have $\displaystyle\sum_{k = 1}^\infty P(X = k) = 1$?

---

$$
\begin{array}{rrl}
    \displaystyle \sum_{k = 1}^\infty P(X = k) &=& 
    \displaystyle \sum_{k = 1}^\infty (1 - p)^{k - 1}p \\
    &=& p \displaystyle \sum_{k = 1}^\infty (1 - p)^{k - 1} \\
    && \text{Geometric series: } \displaystyle \sum_{k = 0}^\infty ar^k = \frac{a}{1 - r} \\
    &=& p \displaystyle \frac{1}{1 - (1 - p)} \\
    &=& p \displaystyle \frac{1}{p} \\
    &=& 1
\end{array}
$$

## 2. Memoryless Property

Suppose $X \sim \text{Geometric}(p), p \in (0, 1)$.

- What is $P(X = n + m \vert X > m)$? ($n, m \in \mathbb{N}$)

---

$$
\begin{array}{rl}
    P(X = n + m \vert X > m) &= \displaystyle \frac{P(X = n + m, X > m)}{P(X > m)} \\
    &= \displaystyle \frac{P(X = n + m)}{P(X > m)} \\
    &= \displaystyle 
    \frac{(1 - p)^{n + m - 1}p}{\displaystyle \sum_{k = m + 1}^\infty (1 - p)^{k - 1}p} \\
    & \text{By the geometric series: } \\
    & \displaystyle \sum_{k = 0}^\infty ar^k = \frac{a}{1 - r} \\
    & \displaystyle \sum_{k = m + 1}^\infty (1 - p)^{k - 1}p = \frac{(1 - p)^m p}{1 - (1 - p)} = (1 - p)^m \\
    &= \displaystyle \frac{(1 - p)^{n + m - 1}p}{(1 - p)^m} \\
    &= (1 - p)^{n - 1}p \\
    & \equiv P(X = n)
\end{array}
$$

We can see that the first $m$ trials do not affect the probability of the next $n$ trials, meaning that the Geometric random variable has the memoryless property.

---

# Reference

1. P.-C. Hsieh, “515512: Probability Lecture 8 - Discrete Random Variables, Entropy, and Expected Value,” NYCU EC016, Oct. 04, 2024.
2. P.-C. Hsieh, “515512: Probability Lecture 9 - Discrete Random Variables, Entropy, and Expected Value,” NYCU EC016, Oct. 09, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.