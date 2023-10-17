Tag: #network-science 
Previous: [[Network Science]]
Link: 

[TOC]

---

A random walk is a [[Walk|walk]] that take each step randomly.

If a node $j$ has a [[Degree|degree]] $k_j$, starting from node $j$ there is a probability $1/k_j$ for each of $j$'s neighbor to be visited.

The probability of being at node $i$ on the next step:

$$p_i(t) = \sum_j \frac{A_{ij}}{k_j} p_j (t - 1)$$

The probability vector composed by $p_i(t)$:

$${\bf p}(t) = {\bf AD}^{-1}{\bf p}(t - 1)$$

- ${\bf D}$: Degree matrix, ${\bf D} = \left[ \begin{array}{}k_1 & 0 & 0 & \dots \\ 0 & k_2 & 0 & \dots \\ 0 & 0 & k_3 & \dots \\ \vdots & \vdots & \vdots & \ddots \end{array} \right]$

# Probability of Infinite Time

For an infinite amount of time, the probability of

- being at node $i$ and 
- come to node $i$ from $j$

is:

$$
\left\{
	\begin{array}{}
		p_i(\infty) & = & 
		\displaystyle
		\frac{k_i}{\sum_j^{\rm for\ each\ node} k_j} & = &
		\displaystyle
		\frac{k_i}{2m} \\
		p_{i \rightarrow j}(\infty) & = & \displaystyle\frac{k_i}{2m} \times \frac{1}{k_i} & = & 
		\displaystyle
		\frac{1}{2m}
	\end{array}
\right.
$$

- $k$: [[Degree]].
- $m$: Number of all edges.
- $p(\infty)$: Probability of $t \rightarrow \infty$.

---

# Reference

Network Science Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.