Tag: #probability 
Previous: [[Probability]]
Link: 

---

| Random Variable                     | Expected Value   | Variance                  |
| ----------------------------------- | ---------------- | ------------------------- |
| $X \sim \text{Bernoulli}(p)$        | $E[X]=p$         | $\text{Var}[X]=p(1-p)$    |
| $X \sim \text{Binomial}(n, p)$      | $E[X]=np$        | $\text{Var}[X]=np(1-p)$   |
| $X \sim \text{Poisson}(\lambda, T)$ | $E[X]=\lambda T$ | $\text{Var}[X]=\lambda T$ |

# Examples

## 1. Bernoulli Random Variables

Prove that if $X \sim \text{Bernoulli}(p)$, then $E[X]=p$ and $\text{Var}[X]=p(1-p)$.

---

The PMF is:

$$
P_X(x) = \left\{
    \begin{array}{l}
        p, & \text{if } x=1, \\
        1-p, & \text{if } x=0. \\
        0, & \text{otherwise}.
    \end{array}
\right.
$$

Therefore:

$$
\begin{array}{rl}
    E[X] &=& p \cdot 1 + (1 - p) \cdot 0 \\
    &=& p. \\
    \text{Var}[X] &=& E[X^2] - E[X]^2 \\
    &=& p \cdot 1^2 + (1 - p) \cdot 0^2 - p^2 \\
    &=& p - p^2 \\
    &=& p(1 - p).
\end{array}
$$

## 2. Binomial Random Variables

Prove that if $X \sim \text{Binomial}(n, p)$, then $E[X]=np$ and $\text{Var}[X]=np(1-p)$.

---

The PMF is:

$$
P_X(x) = \left\{
    \begin{array}{l}
        \displaystyle
        C^n_x p^x (1-p)^{n-x}, & \text{if } x=0, 1, \ldots, n, \\
        0, & \text{otherwise}.
    \end{array}
\right.
$$

Therefore:

$$
\begin{array}{rl}
    E[X] &=& \displaystyle
    \sum_{x \in S} (x) \cdot (P_X(x)) \\
    &=& \displaystyle
    \sum_{x=0}^n x \cdot C^n_x p^x (1-p)^{n-x} \\
    &=& \displaystyle
    \sum_{x=0}^n x \cdot \frac{n!}{x!(n-x)!} p^x (1-p)^{n-x} \\
    &=& \displaystyle
    \sum_{x=1}^n \frac{n!}{(x-1)!(n-x)!} p^x (1-p)^{n-x} \\
    &=& \displaystyle
    \sum_{x=1}^n \frac{(n-1)! \cdot n}{(x - 1)!(n - x)!} p^{x-1} \cdot p (1-p)^{n-x} \\
    &=& \displaystyle
    np\sum_{x=1}^n C^{n-1}_{x-1} p^{x-1} (1-p)^{n-x} \\
    &=& \displaystyle
    np \cdot 1 \\
    &=& np. \\
    E[X^2] &=& \displaystyle
    \sum_{x \in S} (x^2) \cdot (P_X(x)) \\
    &=& \displaystyle
    \sum_{x=1}^n x^2 \cdot C^n_x p^x (1-p)^{n-x} \\
    &=& \displaystyle
    \sum_{x=1}^n (x \cdot (x - 1) + x) \cdot \frac{n!}{x!(n-x)!} p^x (1-p)^{n-x} \\
    &=& \displaystyle
    \sum_{x=1}^n x(x-1) \cdot \frac{n!}{x!(n-x)!} p^x (1-p)^{n-x} + \sum_{x=1}^n x \cdot \frac{n!}{x!(n-x)!} p^x (1-p)^{n-x} \\
    &=& \displaystyle
    \sum_{x=1}^n \frac{n!}{(x-2)!(n-x)!} p^x (1-p)^{n-x} + np \\
    &=& \displaystyle
    \sum_{x=2}^n \frac{(n-2)! \cdot n(n-1)}{(x-2)!(n-x)!} p^{x-2} \cdot p^2 (1-p)^{n-x} + np \\
    &=& \displaystyle
    n(n-1)p^2 \sum_{x=2}^n C^{n-2}_{x-2} p^{x-2} (1-p)^{n-x} + np \\
    &=& \displaystyle
    n(n-1)p^2 \cdot 1 + np \\
    &=& \displaystyle
    n(n-1)p^2 + np \\
    E[X^2] - E[X]^2 &=& \displaystyle
    n(n-1)p^2 + np - n^2p^2 \\
    &=& \displaystyle
    np((n-1)p + 1 - np) \\
    &=& \displaystyle
    np(1 - p).
\end{array}
$$

---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 11 - Moments and Continuous Random Variables.” NYCU EC016, October 16, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.