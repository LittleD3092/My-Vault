Tag: #computer-graphics 
Previous: [[Digital Differential Analyzer]]
Link: 

[TOC]

---

The previous [[Digital Differential Analyzer|digital differential analyzer]] has a problem. For steep lines, fewer pixels are drawn:

![[Pasted image 20231110161311.png|200]]

This can be solved by using symmetry. For $m > 1$, we swap roles of $x$ and $y$. In this way, we can plot closest pixel for each $y$ coordinate, and more pixels will be drawn:

![[Pasted image 20231110161536.png|200]]

---

# Reference

1. 林奕成. “Introduction to Computer Graphics, Chapter 7: Rasterization.” NYCU EC114[GF], November 8, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.