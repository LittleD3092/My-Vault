Tag: #network-science 
Previous: [[Small-world Network]]
Link: [[Clustering Coefficient]], [[Watts-Strogatz Small-world Model]]

[TOC]

---

This network is similar to [[Watts-Strogatz Small-world Model]], but instead of rewire, it **adds an edge**. The figure below shows the difference of them.

![[Pasted image 20231028125930.png]]

The [[Watts-Strogatz Small-world Model]] reduces degree and adds degree at the same time, and forms a small-world network. This model's purpose is to **eliminate the reduce degree part**, to see whether adding degree yields small-world network.

The **clustering coefficient**:

$$C = \frac{3(c - 1)}{2(2c - 1) + 4c\beta(\beta + 2)}$$

- $c$: The degree of each node when generating lattice graph.
- $\beta$: The probability of rewiring.

# Comparison with WS Model

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