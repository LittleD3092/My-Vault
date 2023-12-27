Tag: #computer-graphics 
Previous: [[Two-part Mapping]]
Link: 

[TOC]

---

The texture is mapped onto a sphere. A single point on a sphere can be determined by $\theta$ and $\phi$: (<u>1</u>)

![[Pasted image 20231224172355.png|300]]

$$
\left\{
	\begin{array}{l}
		\theta &=& 2\pi v \\
		\phi &=& 2\pi u
	\end{array}
\right.
$$

- $u, v$: The texture coordinate.

And the $x-y-z$ coordinate has the expression: (<u>1</u>)

$$
\left\{
	\begin{array}{l}
		x &=& r\sin \phi \cos \theta &=& r\sin 2\pi u \cos 2\pi v\\
		y &=& r\sin \phi \sin \theta &=& r\sin 2\pi u \sin 2\pi v \\
		z &=& r\cos \phi &=& r \cos 2\pi u
	\end{array}
\right.
$$

---

# Reference

1. 林奕成, “Introduction to Computer Graphics, Chapter 9: Buffers and Mapping Techniques,” NYCU EC114[GF], Nov. 20, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.