Tag: #network-science 
Previous: [[Network Science]]
Link: [[Multilayer]], [[Multiplex]]

[TOC]

---

![[Pasted image 20230920103717.png|400]]

# Mathematical Representation

## Multiplex

The graph can be represented by a set of $n \times n$ adjacency matrix ${\bf A}^\alpha$.

- $\alpha$: Index of layer.

## Multilayer

The graph can be represented by a set of adjacency matrix ${\bf A}^{\alpha \beta}$.

- The **size** of each matrix can be **different**.
- $\alpha$: Represent a layer.
- $\beta$: Represent the other layer.
- $i$: Row index of matrix. Specifies a node in layer $\alpha$.
- $j$: Column index of matrix. Specifies a node in layer $\beta$.

# Dynamic Network

When we take **multiple snapshots** of a graph, and treat each snapshot as a **layer**, we get [[Dynamic Network|dynamic network]].

> [[Dynamic Network]]

---

# Reference

Network Science Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.