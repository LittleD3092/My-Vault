Tag: #computer-graphics 
Previous: [[Hidden Surface Removal]]
Link: 

[TOC]

---

We can render the polygons in a back to front order so that polygons behind others are simply painted over. (<u>1</u>)

![[Pasted image 20231113175106.png]]

This method has some problems: (<u>1</u>)

- If the objects overlap too much, it will be time consuming.
- Two objects can cover each other.
- Ordering the polygons is hard.

---

# Reference

1. 林奕成. “Introduction to Computer Graphics, Chapter 7: Rasterization, Part 2.” NYCU EC114[GF], November 13, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.