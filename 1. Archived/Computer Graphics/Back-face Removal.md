Tag: #computer-graphics 
Previous: [[Hidden Surface Removal]]
Link: 

[TOC]

---

Back-face removal is a technique that uses normal vector $\bf n$ and viewer vector $\bf v$: (<u>1</u>)

![[Pasted image 20231113173932.png|200]]

A face is visible if the angle of the vectors $90\degree \geq \theta \geq -90$. This is equivalent to ${\bf v} \cdot {\bf n} \geq 0$. (<u>1</u>)

This method has a problem that it only works for single object. For multiple objects, the surface that is blocked by the other object is not removed. (<u>1</u>)

---

# Reference

1. 林奕成. “Introduction to Computer Graphics, Chapter 7: Rasterization, Part 2.” NYCU EC114[GF], November 13, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.