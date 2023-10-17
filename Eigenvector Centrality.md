Tag: #network-science 
Previous: [[Centrality]]
Link: [[Eigenvector]]

[TOC]

---

Eigenvector centrality measures the **influence** of a node based on its neighbors influence:

$$
\begin{array}{l}
	x_i & = & 
	\displaystyle
	\kappa^{-1}\sum_{j\in \mathcal N(i)}^n A_{ij} x_j \\
	& = & 
	\displaystyle
	\sum_{j = 1}^n A_{ij} x_j
\end{array}$$

- $x_i$, $x_j$: Influence of node $i$ and $j$.
- $\kappa^{-1}$: Constant of proportionality.

The relationship above is insufficient for calculating the actual eigenvector centrality $x_i$, because we don't have $x_j$. We can use [[Eigenvalue]] and [[Eigenvector]] to calculate $\kappa$ and $x_i$.

$$\kappa {\bf x} = {\bf Ax}$$

- $\kappa$: [[Eigenvalue]], also the inverse of constant of proportionality.
- ${\bf x}$: [[Eigenvector]], also the vector composed of centrality.

# Example

Consider an adjacency matrix ${\bf A}$:

$${\bf A} = \left[
	\begin{array}{}
		0 & 1 & 0 & 0 \\
		0 & 0 & 1 & 1 \\
		1 & 0 & 0 & 1 \\
		0 & 0 & 1 & 0
	\end{array}
\right]$$

We can solve the equation:

$$
\begin{array}{}
	& {\bf Ax} &=& \kappa{\bf x} \\
	\implies &
	\det({\bf A} - \kappa{\bf I}) & = & 0
\end{array}$$

Among the eigenvalues, the maximum is $\kappa = 1.7$. Now we calculate the eigenvector:

$$({\bf A} - \kappa{\bf I}){\bf x} = {\bf 0}$$

The result of $\bf x$:

$${\bf x} = \left[
	\begin{array}{}
		0.5 \\
		0.6 \\
		0.8 \\
		0.5
	\end{array}
\right]$$

From the above result, we can see that node 3 is most influential, with highest eigenvector centrality.

---

# Reference

Network Science Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.