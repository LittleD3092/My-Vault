Tag: #computer-graphics 
Previous: [[Two-part Mapping]]
Link: 

[TOC]

---

Cylindrical mapping maps the texture to a cylinder: (<u>1</u>)

![[Pasted image 20231224171613.png|200]]

$$
\left\{
	\begin{array}{l}
		x &=& r \cos 2\pi u \\
		y &=& r \sin 2\pi u \\
		z &=& vh
	\end{array}
\right.
$$

- $r$: Radius of the cylinder.
- $h$: Height of the cylinder.
- $u, v$: The coordinate of the texture.

---

# Reference

1. 林奕成, “Introduction to Computer Graphics, Chapter 9: Buffers and Mapping Techniques,” NYCU EC114[GF], Nov. 20, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.