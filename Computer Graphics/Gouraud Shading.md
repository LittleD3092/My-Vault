Tag: #computer-graphics 
Previous: [[Polygonal Shading]]
Link: 

[TOC]

---

Gouraud shading is better than [[Flat Shading|flat shading]]. This method applies [[Phong Reflection Model|Phong reflection model]] at each vertex, and **interpolate** vertex shades across each polygon.

![[Pasted image 20231028164823.png|300]]

Gouraud shading first interpolate the edges by y-axis, then interpolate x-axis.

$$
\left\{
	\begin{array}{}
		I_a &=& 
		\displaystyle
		\frac{1}{y_1 - y_2}[
			I_1(y_s - y_2) +
			I_2(y_1 - y_s)
		] \\
		I_b &=&
		\displaystyle
		\frac{1}{y_1 - y_4}[
			I_1(y_s - y_4) +
			I_4(y_1 - y_s)
		] \\
		I_s &=&
		\displaystyle
		\frac{1}{x_b - x_a}[
			I_a(x_b - x_s) + I_b(x_s - x_a)
		]
	\end{array}
\right.
$$

![[Pasted image 20231028165326.png]]

---

# Reference

- 林奕成. “Introduction to Computer Graphics, Ch5 Shading Part 2.” NYCU EC114[GF], October 18, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.