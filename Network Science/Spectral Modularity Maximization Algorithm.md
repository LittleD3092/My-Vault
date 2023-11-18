Tag: #network-science 
Previous: [[Modularity Maximization]]
Link: 

[TOC]

---

This method uses [[Eigenvalue|eigenvalues]] and [[Eigenvector|eigenvectors]] to rapidly find a good approximation to modularity maximization. (<u>1</u>)

According to [[Simplification of Assortative Mixing with Unordered Features|simplification of assortative mixing with unordered features]], the [[Assortative Mixing|assortative mixing]] can be written as: (<u>1</u>)

$$
\begin{array}{l}
	& Q &=& 
	\displaystyle
	\frac 1 {4m} \sum_{ij} B_{ij} s_i s_j \\
	\implies & Q &=& 
	\displaystyle
	\frac{1}{4m} {\bf s}^{\rm T} {\bf B} {\bf s}
\end{array}
$$

- $\bf s$: $n$-dimensional vector with elements $s_i$.
- $\bf B$: $n \times n$ matrix with element $B_{ij}$.

The equation above can be written as the form of solving [[Eigenvalue|eigenvalue]]: (<u>1</u>)

$$
{\bf Bs} = \beta {\bf s}
$$

Since $s_i = \pm 1$, we can't expect elements in eigenvectors $\bf s$ to be $\pm 1$. So we substitute $\bf s$ with $\bf u$, in which elements are $\mathbb{R}$. (<u>1</u>)

$$\implies{\bf Bu} = \beta {\bf u}$$

- $\bf u$: Eigenvector. We make an assumption: $$\left\{\begin{array}{l} s_i = 1 & \text{if } u_i > 0 \\ s_i = -1 & \text{if } u_i < 0 \end{array}\right.$$
- $\beta$: Eigenvalue.

Solving for eigenvector $\bf u$, we can determine $\bf s$. (<u>1</u>)

This method has a **time complexity**:

$$O(n \log n)$$

for calculating the eigenvectors. It is fast and easy to implement.

---

# Reference

1. Lou Yang. “Network Science, Lecture 7: Community Structure, part 2.” NYCU ED102[GF], November 14, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.