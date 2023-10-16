Tag: #network-science 
Previous: [[Network Science]]
Link: 

[TOC]

---

The density of a graph can be determined by the **maximum edges a graph can have** and **edges a graph actually have**.

The number of maximum edges is defined by the number of nodes $n$:

$$m_{\rm max} = \left(
	\begin{array}{}
		n \\
		2
	\end{array}
\right) = 
\frac 1 2 n (n - 1)$$

- $m_{\rm max}$: Number of maximum edges.
- $n$: Number of nodes.

The density $\rho$ can be written as:

$$\rho = \frac{m}{m_{\rm max}} = \frac{c}{n - 1}$$

- $m$: Number of edges.
- $m_{\rm max}$: Number of maximum edges.
- $c$: Average degree.
- $n$: Number of nodes.

---

# Reference

Network Science Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.