Tag: #computer-graphics 
Previous: [[Hidden Surface Removal]]
Link: 

[TOC]

---

We can combine the [[Shading|shading]] part with this.

For the example below, there are two cases.

![[Pasted image 20231118151202.png|250]]

- Scan line $i$: Only one polygon scanned, no need for depth information.
- Scan line $j$: Polygons overlap, need depth information when $A$ and $B$ overlap.

---

# Reference

1. 林奕成. “Introduction to Computer Graphics, Chapter 8: Hidden Surface.” NYCU EC114[GF], November 18, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.