標籤: #linear-algebra 

---

[TOC]

---

# Definition

A mapping $L$ from a vector space $V$ into a vector space $W$ is said to be a **linear transformation** if

$$L(\alpha{\bf v}_1 + \beta {\bf v}_2) = \alpha L({\bf v}_1) + \beta L({\bf v}_2)$$

for all ${\bf v}_1, {\bf v}_2 \in V$ and for all scalars $\alpha$ and $\beta$.

The above definition can be seperated into two parts:

1. $L({\bf v}_1 + {\bf v}_2) = L({\bf v}_1) + L({\bf v}_2) \qquad (\alpha = \beta = 1)$
2. $L(\alpha {\bf v}) = \alpha L({\bf v}) \qquad ({\bf v} = {\bf v}_1, \beta = 0)$

> $L$ is a linear transformation iff $L$ satisfies the above 2 conditions.

# Notation

A mapping $L$ from a vector space $V$ into a vector space $W$ will be denoeted

$$L: V \rightarrow W$$

If $V$ and $W$ are the same, the following is called a **linear operator**:

$$L: V \rightarrow V$$



---

參考資料:

Linear Algebra with Applications, 10th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.