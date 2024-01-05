Tag: #network-science 
Previous: [[Centrality]]
Link: 

[TOC]

---

PageRank is similar to [[Eigenvector Centrality]], but added few factors to account for some random transactions. This formula is from google.

$$
\left\{
	\begin{array}{}
		x_i & = & 
		\displaystyle
		\alpha
		\sum_{j} A_{ij} \frac{x_j}{k_{j, \rm out}} + \beta \\
		{\bf x} &=& \alpha{\bf AD}^{-1}{\bf x + \beta {\bf 1}}
	\end{array}
\right.
$$

- ${\bf x}$: PageRank vector.
- $x_i$: PageRank of a node $i$.
- $\alpha$: A damping factor. Often set to 0.85, the possibility that a user link to another web page on purpose.
- $\bf A$: Adjacency matrix of graph.
- $A_{ij}$: The $ij$th element of ${\bf A}$.
- ${\bf D}$: The degree matrix. The main diagonal is the degree of each node, other elements are $0$.
- $k_{j, \rm out}$: The out degree of node $j$.
- $\beta$: A factor. Often set to $1 - \alpha$, the possibility that a user link to another web page by random.
- ${\bf 1}$: A vector with all $1$s.

---

# Reference

Network Science Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.