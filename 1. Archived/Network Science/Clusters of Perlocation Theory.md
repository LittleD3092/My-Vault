Tag: #network-science 
Previous: [[Perlocation Theory]]
Link: 

[TOC]

---

The example below illustrates clusters of different $p$: (<u>1</u>)

![[Pasted image 20231216154659.png|500]]

- $\langle s \rangle$: The average cluster size.
- $p$: Probability of placing a pebble.
- $p_c$: Perlocation threshold.
- $P_\infty$: Probability of a pebble belongs to the largest connected component.

The three critical components: (<u>1</u>)

- $\gamma_p$: Constant in [[#Average Cluster Size|average cluster size]].
- $\beta_p$: Constant in [[#Probability of Choosing the Pebble in Largest Component|probability of choosing the pebble in largest component]].
- $\nu$: Constant in [[#Correlation Length|correlation length]].

determines the system's behavior near the critical point $p_c$. (<u>1</u>)

# Average Cluster Size

The **average cluster size** follows the formula: (<u>1</u>)

$$\langle s\rangle \sim \vert p - p_c \vert^{-\gamma_p}$$

- The average cluster size $\langle s\rangle$ diverges as it approaches $p_c$.

# Probability of Choosing the Pebble in Largest Component

The **probability of choosing the pebble in largest component** $P_\infty$ follows the formula: (<u>1</u>)

$$P_\infty = 
\left\{
	\begin{array}{l}
		(p - p_c)^{\beta_p} & \text{if} & p > p_c \\
		0 & \text{if} & p < p_c
	\end{array}
\right.$$

# Correlation Length

- [[Correlation Length]]

---

# Reference

1. Y. Lou, “Network Science, Lecture 8: Robust and Resiience, part 2,” NYCU ED102[GF], Nov. 21, 2023.


---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.