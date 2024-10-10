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

## 2. Satisfy Total Probability Axiom

Do we have $\displaystyle\sum_{n = 0}^\infty P(X = n) = 1$?

---

$$
\begin{array}{l}
	& \displaystyle \sum_{n = 0}^\infty \frac{e^{-\lambda T} (\lambda T)^n}{n!} \\
    = & e^{-\lambda T} \displaystyle \sum_{n = 0}^\infty \frac{(\lambda T)^n}{n!} \\
    = & \displaystyle e^{-\lambda T} 
    \left(
        \underbrace{1 + \frac{\lambda T}{1!} + \frac{(\lambda T)^2}{2!} + \dots}_{
            \text{Taylor expansion of } e^{\lambda T}
        }
    \right) \\
    = & e^{-\lambda T} e^{\lambda T} \\
    = & 1
\end{array}
$$

## 3. Sum of Independent Poisson Random Variables

Let $N_1$ and $N_2$ be the number of total bits trasmitted by AP1 and AP2 in a time interval $T$, respectively.

- Suppose $N_1$ and $N_2$ are independent.
- $N_1 \sim \text{Poisson}(\lambda_1 T)$ and $N_2 \sim \text{Poisson}(\lambda_2 T)$.
- Let $Z$ be the total received bits. Then, what is the PMF of $Z$?

---

PMF of $Z$ is:

$$
\begin{array}{rrl}
    P(Z = n) &=& \displaystyle \sum_{m = 0}^n P(N_1 = m) P(N_2 = n - m) \\
    &=& \displaystyle \sum_{m = 0}^n \left(
        \frac{e^{-\lambda_1 T} (\lambda_1 T)^m}{m!}
    \right) \cdot \left(
        \frac{e^{-\lambda_2 T} (\lambda_2 T)^{n - m}}{(n - m)!}
    \right) \\
    && \displaystyle \text{Recall that } C^n_m = \frac{n!}{m! (n - m)!}\\
    &=& \displaystyle \frac{e^{-\lambda_1 T} e^{-\lambda_2 T}}{n!} \sum_{m = 0}^n
    \frac{
        n! (\lambda_1 T)^m (\lambda_2 T)^{n - m}
    }{
        m! (n - m)!
    } \\
    && \displaystyle
    \text{By the binomial expansion, } \\
    && \displaystyle
    (x + y)^n = \sum_{m = 0}^n C^n_m x^m y^{n - m} \\
    &=& \displaystyle 
    \frac{e^{-(\lambda_1 + \lambda_2) T} ((\lambda_1 + \lambda_2) T)^n}{n!} \\
    & \implies & Z \sim \text{Poisson}(\lambda_1 + \lambda_2, T)
\end{array}
$$

---

# Reference

1. P.-C. Hsieh, “515512: Probability Lecture 7 - Discrete Random Variables,” NYCU EC016, Sep. 27, 2024.
2. P.-C. Hsieh, “515512: Probability Lecture 8 - Discrete Random Variables, Entropy, and Expected Value,” NYCU EC016, Oct. 04, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.