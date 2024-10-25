Tag: #statistics #probability 
Previous: [[Discrete Random Variables]]
Link: 

---

The cumulative distribution function of a discrete random variable $X$ is defined as: (<u>1</u>)

$$F_X(t) = P(X \leq t) = \sum_{t)i \leq t}f(t_i) \quad\text{, for all } t \in \mathbb R$$

# CDF with Equal Excluded

We can exclude the equal sign and write CDF as: (<u>2</u>)

$$F_X(t^-) = P(X < t)$$

# Probability Written in CDF

There are some events and the probability of the events written in CDF: (<u>2</u>)

| Event      | Probability of the event |
| ---------- | ------------------------ |
| $X \leq a$ | $F_X(a)$                 |
| $X > a$    | $1 - F_X(a)$             |
| $X < a$    | $F_X(a^-)$               |
| $X \geq a$ | $1 - F_X(a^-)$           |
| $X = a$    | $F_X(a) - F_X(a^-)$      |

| Event             | Probability of the event |
| ----------------- | ------------------------ |
| $a < X \leq b$    | $F_X(b) - F_X(a)$        |
| $a < X < b$       | $F_X(b^-) - F_X(a)$      |
| $a \leq X \leq b$ | $F_X(b) - F_X(a^-)$      |
| $a \leq X < b$    | $F_X(b^-) - F_X(a^-)$    |

# Properties

Here are some properties of CDF: (<u>2</u>)

1. $F_X(t)$ is non-decreasing.
2. $\displaystyle \lim_{t \rightarrow \infty} F_X(t) = 1$.
3. $\displaystyle \lim_{t \rightarrow -\infty} F_X(t) = 0$.
4. $F_X(t)$ is right-continuous, $F_X(t^+) = F_X(t)$.

---

# Reference

1. Tseng, Yi-Ju. “Statistics, Chapter 3: Random Variables and Probability Distributions.” n.d. Accessed April 16, 2024.
2. Hsieh, Ping-Chun. “515512: Probability Lecture 6 - Random Variables.” NYCU EC016, September 25, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.