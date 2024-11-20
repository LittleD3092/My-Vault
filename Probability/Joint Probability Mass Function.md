Tag: #probability 
Previous: [[Joint Distributions Relationships.canvas|Joint Distributions Relationships]]
Link: 

---

Joint PMF defines a PMF of two variables.

Let $X, Y$ be two discrete random variables defined on the same sample space $\Omega$. The joint PMF $p_{XY}(x, y)$ is defined as:

$$
p_{XY}(x, y) = P(X=x, Y=y)
$$

# Examples

## 1. Joint PMF is the product of the marginal PMFs under independence

If two discrete random variables $X, Y$ are **independent**, then the joint PMF satisfies that

$$p_{XY}(x, y) = p_X(x) \cdot p_Y(y)$$

Prove the above property.

---

Choose $A \equiv \{x\}, B \equiv \{y\}$. By the independence of $X, Y$, we have:

$$
\begin{array}{rrl}
&P(X \in A, Y\in B) &=& P(X \in A) \cdot P(Y \in B) \\
\implies & p_{XY}(x, y) &=& p_X(x) \cdot p_Y(y)
\end{array}
$$

---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 14 - Joint Distributions.” NYCU EC016, November 1, 2024.
2. Hsieh, Ping-Chun. “515512: Probability Lecture 15 - Joint Distributions and Sum of Independent Random Variables.” NYCU EC016, November 6, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.