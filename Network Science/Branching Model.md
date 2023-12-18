Tag: #network-science 
Previous: [[Cascading Failure]]
Link: 

[TOC]

---

Branching model uses the following initial state:

- A single failure node as its initial condition.
- It generates $k$ edges. 
	- $k$: Chosen randomly from a $p_k$ distribution.

In each time step:

- Each edge generate a failure node, and generate $k$ edges.
	- $k$: Chosen rendomly from a $p_k$ distribution.
- If $k = 0$, the branch stops propagating.
- If $k > 0$, the branch keeps propagating.

Related topics:

- [[Subcritical and Supercritical of Branching Model]]

# Example

![[410117035_736848408337054_8255813772055977708_n.jpg|450]]

1. Top node generates $k=1$ edge.
2. Second node generates $k = 2$ edges.
3. Third node generates $k = 2$ edges.
4. Fourth node has $k = 0$ and the branch dies out.
5. Fifth node has $k = 0$ and the branch dies out.
6. Sixth node has $k = 0$. Now all branches dies out.

---

# Reference

1. Y. Lou, “Network Science, Lecture 8: Robust and Resilience, part 2,” NYCU ED102[GF], Nov. 21, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.