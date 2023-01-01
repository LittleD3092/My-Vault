Tag: #linear-algebra 
Previous: 
Link: 

---

[TOC]

---

# Description

If we have a $m \times n$ system

$$A{\bf x} = {\bf b}$$

with $m > n$, we cannot expect to find a [[Vector]] ${\bf x} \in R^n$ because it may be inconsistent.

Instead, we look for a [[Vector]] ${\bf x}$ which makes $A{\bf x}$ *closest* to ${\bf b}$.

# Residual

We define residual as

$$r({\bf x}) = {\bf b} - A{\bf x}$$

So that the distance between ${\bf b}$ and $A{\bf x}$ is

$$\vert\vert {\bf b} - A{\bf x}\vert\vert = \vert\vert r({\bf x})\vert\vert$$



---

參考資料:

Linear Algebra with Applications, 10th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.