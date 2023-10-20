Tag: #network-science 
Previous: [[Network Science]]
Link: [[Global Clustering Coefficient]]

[TOC]

---

A random graph is not a specific graph, it is an **ensemble** of networks. A random graph is a **probability distribution** of a network set.

# Representations

A random graph can be defined by many ways. Below there are 2 ways:

- [[#Representation 1 Node, Edge]]
- [[#Representation 2 Node, Probability of Edge]]

## Representation 1: Node, Edge

A random graph can be represented by:

$$G(n, m)$$

- $n$: Number of nodes in a network.
- $m$: Number of edges in a network.

A probability of a network in a random graph can be calculated by the formula:

$$P(G) = \frac{1}{
	\left(
		\begin{array}{} 
			\left(
				\begin{array}{}
					n \\
					2
				\end{array}
			\right) \\
			m
		\end{array}
	\right)
}$$

- $\left(\begin{array}{}n \\ 2\end{array}\right)$: The number of all possible edges.
- $\left(\begin{array}{}\left(\begin{array}{}n \\ 2\end{array}\right) \\ m\end{array}\right)$: The number of possible graphs when choosing $m$ edges.

The **[[Clustering Coefficient]]** of a random graph:

$$C = \frac 1 n \frac{[\langle k^2\rangle - \langle k\rangle]}{\langle k \rangle^3}$$

- $C$: [[Clustering Coefficient]].
- $n$: Number of nodes.
- $\langle k \rangle$: Average degree.
- $\langle k^2 \rangle$: Average of degree squared.

## Representation 2: Node, Probability of Edge

A random graph can also be represented by:

$$G(n, p)$$

- $n$: Number of nodes.
- $p$: Probability of a edge connection.

Each network $G$ has probability:

$$P(G) = p^m(1 - p)^{
	\left(
		\begin{array}{}
			n \\ 2
		\end{array}
	\right) - m
}$$

- $m$: The number of edges. This is not predefined, and only has value after generation of specific graph.

The average number of **edges**:

$$\langle m \rangle = \left(
	\begin{array}{}
		n \\ 2
	\end{array}
\right)p$$

- $\langle m \rangle$: The average number of edges.
- $n$: Number of nodes.
- $p$: Probability of a edge connection.

The average **degree**:

$$
\begin{array}{}
	\langle k \rangle & = & 
	\displaystyle
	\frac{
		2\langle m \rangle
	}{
		n
	} \\
	& = & 
	\displaystyle
	\frac 2 n \left(
		\begin{array}{}
			n \\ 2
		\end{array}
	\right)p \\ 
	& = & (n - 1)p
\end{array}$$

The **degree distribution**:

$$p_k = e^{-c}\frac{c^k}{k!}$$

The distribution above is [[Poisson Distribution]] (exponential relationship), therefore this graph is also called [[Poisson Random Graph]].

![[Pasted image 20231020152119.png]]

# Properties

The properties of a random graph is determined by the properties of each graph.

$$\begin{array}{}
	\text{Property of} \\ \text{Random Graph}
\end{array}
= \sum 
\begin{array}{}
	\text{Property of} \\ \text{the Graph}
\end{array}
\times 
\begin{array}{}
	\text{Probability of} \\ \text{the Graph}
\end{array}$$

For example, the [[Diameter]] of a random graph $P(G)$:

$$\langle l\rangle
= \sum_G P(G)l(G)$$

- $\langle l\rangle$: The diameter of random graph.
- $G$: A graph in the set.
- $P(G)$: The probability of graph $G$.
- $l(G)$: The diameter of graph $G$.

---

# Reference

Network Science Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.