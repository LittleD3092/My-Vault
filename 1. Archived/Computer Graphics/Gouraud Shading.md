Tag: #computer-graphics 
Previous: [[Polygonal Shading]]
Link: 

[TOC]

---

Gouraud shading is better than [[Flat Shading|flat shading]]. This method applies [[Phong Reflection Model|Phong reflection model]] at each vertex, and **interpolate** vertex shades across each polygon. (<u>1</u>)

![[Pasted image 20231028164823.png|300]]

Advantages and disadvantages: (<u>2</u>)

- **advantage**: Compared to [[Flat Shading|flat shading]], this method provides smoother rendering results.
- **disadvantage**: Compared to [[Flat Shading|flat shading]], this method has more computation cost.

Gouraud shading first interpolate the edges by y-axis, then interpolate x-axis. (<u>1</u>)

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

Related topics:

- [[Gouraud Shading and Fixed Pipeline Acceleration]]

---

# Reference

1. 林奕成. “Introduction to Computer Graphics, Ch5 Shading Part 2.” NYCU EC114[GF], October 18, 2023.
2. “017_Shading_in_OpenGL.Pdf.” Accessed November 5, 2023. https://teaching.csse.uwa.edu.au/units/CITS3003/lectures/017_Shading_in_OpenGL.pdf.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.