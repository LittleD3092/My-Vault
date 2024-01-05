Tag: #network-science 
Previous: [[Small-world Network]]
Link: [[Clustering Coefficient]], [[Newman-Watts Small-world Model]]

[TOC]

---

If not specified, when people say [[Small-world Network|small-world model]], they mean this model.

The **clustering coefficient**:

$$C = \frac{3(c - 1)}{2(2c - 1)}(1 - \beta)^3$$

- $c$: The degree of each node when generating lattice graph.
- $\beta$: The probability of rewiring.

# Generating Procedure

The WS network follows the steps below to generate:

1. Each note is connected to $c$ closest neighbors, forming regular graph (also called lattice graph):

![[Pasted image 20231028125403.png|200]]

The graph above is $c = 6$ lattice graph.

2. For each edge, cut and rewire each end with probability $\beta$, forming shortcuts:

![[Pasted image 20231028125511.png|200]]

# Adjusting Randomness

We can obtain a **regular graph** if we define the randomness $\beta = 0$. We can obtain a **pure random** graph if $\beta = 1$. The Watts-Strogatz model is somewhere between.

![[Pasted image 20231028003057.png]]

# Comparison with NW Model

|                     | WS Model                                                    | NW Model                                                       |
| ------------------- | ----------------------------------------------------------- | -------------------------------------------------------------- |
| Generating          | Start with lattice network, then rewire with a probability. | Start with lattice network, then add links with a probability. |
| Degree distribution | [[Poisson Distribution]]                                    | [[Binomial Distribution]]                                      |

---

# Reference

- Lou, Yang. “Network Science, Lecture 5: Small-World Models.” NYCU ED102[GF], October 17, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.