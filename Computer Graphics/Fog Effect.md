Tag: #computer-graphics 
Previous: [[Computer Graphics]]
Link: 

[TOC]

---

To apply fog effect, we can compose the original color with a fixed color: (<u>1</u>)

$$
{\bf C}'_s = f {\bf C}_s + (1 - f) {\bf C}_f
$$

- ${\bf C}_s'$: Result color.
- ${\bf C}_s$: Original color.
- ${\bf C}_f$: The fixed fog color.
- $f$: Fog factor. Often a function depending on $z$.

The fog factor can be: (<u>1</u>)

- Exponential.
- Gaussian.
- Linear.

![[Pasted image 20231224190200.png]]

---

# Reference

1. 林奕成, “Introduction to Computer Graphics, Chapter 9: Buffers and Mapping Techniques, part 3,” NYCU EC114[GF], Dec. 04, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.