Tag: #linear-algebra 
Previous: [[Spanning Set]]
Link: 

---

[TOC]

---

# Definition

A minimum [[Spanning Set]] is called a **basis**.

# Change of Basis

- For change of basis, we can use a graph.

For example, if we wish to change basis from $\{{\bf v}_1, {\bf v}_2\}$ to $\{{\bf u}_1, {\bf u}_2\}$:

![[Pasted image 20230101161502.png]]

> Note that matrix $V = [{\bf v}_1\quad {\bf v}_2]$ and $U = [{\bf u}_1 \quad {\bf u}_2]$.

1. From $\{{\bf v}_1, {\bf v}_2\}$ to standard basis $\{{\bf e}_1, {\bf e}_2\}$, we need transition matrix $V$.
2. From standard basis $\{{\bf e}_1, {\bf e}_2\}$ to $\{{\bf u}_1, {\bf u}_2\}$, we need transition matrix $U^{-1}$.

Therefore, the transition matrix from $\{{\bf v}_1, {\bf v}_2\}$ to $\{{\bf u}_1, {\bf u}_2\}$ is $U^{-1}V$.

---

參考資料:

Linear Algebra with Applications, 10th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.