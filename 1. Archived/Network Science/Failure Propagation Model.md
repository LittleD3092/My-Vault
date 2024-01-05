Tag: #network-science 
Previous: [[Cascading Failure]]
Link: 

[TOC]

---

Failure propagation model has following initial state: (<u>1</u>)

- A node initially can be in state $0$ (healthy) or state $1$ (failed).
- Each node $i$ has a breakdown threshold $\phi_i = \phi$.

At each time step, we pick a random node $i$ and update its state: (<u>1</u>)

- If the selected node $i$ is in state $0$:
	- If at least a $\phi$ fraction of its $k_i$ neighbors are in state $1$ (failed), it change to state $1$.
	- Otherwise, it remains state $0$.
- If the selected node $i$ is in state $1$, it remains its state.

Related topics:

- [[Subcritical and Supercritical of Failure Propagation Model]]

# Example

![[Pasted image 20231218193042.png|400]]

- Initially, $A$ is failing. The breakdown threshold $\phi$ is $0.4$.
- Its neighbors $B, E$ have $f > \phi$, therefore fails too.

---

# Reference

1. Y. Lou, “Network Science, Lecture 8: Robust and Resilience, part 2,” NYCU ED102[GF], Nov. 21, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.