Tag: #probability 
Previous: [[Probability]]
Link: 

---

For a random variable $X$, define

$$M_X(t) = E[e^{tX}], \qquad t \in \mathbb R$$

If there exists $\delta > 0$ such that $M_X(t) < \infty$ for all $t \in (-\delta, \delta)$, then $M_X(t)$ is called the moment generating function $X$.

# Examples

## 1. Moment generating function of PMF and PDF

1. If $X$ is a discrete random variable with PMF $p_X(x)$, then what is the moment generating function $M_X(t)$?
2. If $X$ is a continuous random variable with PDF $f_X(x)$, then what is the moment generating function $M_X(t)$?

---

By [[Law of the Unconscious Statistician|LOTUS]]:

For discrete random variable:

$$M_X(t) = \sum_x P_X(x) \cdot e^{tx}$$

For continuous random variable:

$$
M_X(t) = \int_{-\infty}^\infty f_X(x)\cdot e^{tx}dx
$$

## 2. MGF of normal random variables

Let random variable $Z \sim \mathcal N (\mu, \sigma^2)$. What is the MGF of $Z$, which is $M_Z(t)$?

---



---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 15 - Joint Distributions and Sum of Independent Random Variables.” NYCU EC016, November 6, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.