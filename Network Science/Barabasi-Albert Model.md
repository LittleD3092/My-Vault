Tag: #network-science 
Previous: [[Scale-free Network]]
Link: 

[TOC]

---

To **generate** BA Model, we follow the steps below (<u>1</u>):

1. Start with a connected network of $c_0 \geq c$ nodes.
2. Each time, **add a node** with $c$ edges connected to existing nodes with **preferential attachment**.

The **probability** of attaching to an existing node can be written as (<u>1</u>):

$$p = \frac{k_i}{\sum_i k_i}$$

The **[[Calculate Power Law Distribution|power law exponent]]** of Barabasi-Albert model is $\alpha = 3$.

# Difference Between Price's Model

The chart below (<u>2</u>) shows the difference between Barabasi-Albert model and [[Price's Model]].

|           | Barabasi-Albert Model                  | Price's Model                  |
| --------- | -------------------------------------- | ------------------------------ |
| Direction | Undirected                             | Directed                       |
| Add nodes | Exact $c$ connections                  | On average $c$ connections     |
| Degree    | Smallest degree among all nodes is $c$ | Some nodes have degree $k < c$ | 

---

# Reference

1. Lou, Yang. “Network Science, Lecture 6: Scale-Free Networks.” NYCU ED102[GF], October 17, 2023.
2. Lou, Yang. “Network Science, Lecture 6: Scale-Free Networks, Part 2.” NYCU ED102[GF], October 24, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.