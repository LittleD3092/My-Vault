Tag: #network-science 
Previous: [[Power Law Distribution]]
Link: 

[TOC]

---

The power law distribution can be represented by two values, $\alpha$ and standard deviation $\sigma$. Their formula is written below (<u>1</u>):

$$
\left\{
	\begin{array}{}
		\alpha &=& 
		\displaystyle
		1 + N
		\left(\sum_i \ln \frac{k_i}{k_{\min} - 1/2}
		\right)^{-1} \\
		\sigma &=& 
		\displaystyle
		\sqrt{N}
		\left(
			\sum_i
			\ln
			\frac{k_i}{k_\min - 1/2}
		\right)^{-1} &=& 
		\displaystyle
		\frac{\alpha - 1}{\sqrt N}
	\end{array}
\right.
$$

- $k_\min$: The minimum degree that power law holds. Should be determined by seeing the graph plotted (<u>1</u>).
- $N$: Number of nodes with degree $\geq 1$.

---

# Reference

1. Lou, Yang. “Network Science, Lecture 6: Scale-Free Networks, Part 2.” NYCU ED102[GF], October 24, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.