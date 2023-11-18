Tag: #computer-graphics 
Previous: [[Hidden Surface Removal]]
Link: 

[TOC]

---

We can perform hidden surface removal by depth sorting the polygons. (<u>1</u>)

![[Pasted image 20231118150236.png|300]]

This method has a time complexity of $O(n\log n)$ for sorting.

The method has a problem that polygons may have complex overlap. For example, cyclic overlap or penetration.

| Cyclic Overlap                       | Penetration                          | 
| ------------------------------------ | ------------------------------------ |
| ![[Pasted image 20231118150527.png]] | ![[Pasted image 20231118150630.png]] |

---

# Reference

1. 林奕成. “Introduction to Computer Graphics, Chapter 8: Hidden Surface.” NYCU EC114[GF], November 18, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.