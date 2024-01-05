Tag: #computer-graphics 
Previous: [[Hidden Surface Removal]]
Link: 

[TOC]

---

This method is for [[Hidden Surface Removal|hidden surface removal]].

This method uses a [[Z-Buffer]] besides the color buffer for display.

Method:

1. As rendering each polygon, we can compare the depth of the pixel to depth in [[Z-Buffer]]. 
2. If the current pixel has less depth, we can put the shade of the pixel in the color buffer and store depth information to the [[Z-Buffer]].

![[Pasted image 20231118151911.png|300]]

# Improve Efficiency by Scan Line

To get the $z$ value of a pixel, we need to do interpolation, which is time consuming.

If we work by using scanning line, the depth changes will satisfy

$$a\Delta x + b\Delta y + c\Delta z = 0$$

Along the scanning line, 

$$
\left\{
	\begin{array}{}
		\Delta x &=& 1 \\
		\Delta y &=& 0 \\
		\Delta z &=& -\displaystyle\frac{a}{c}\Delta x
	\end{array}
\right.
$$

![[Pasted image 20231118152634.png|400]]

Using similar method as [[Bresenham's Algorithm|Bresenham's algorithm]], we can speed up the process of evaluating depth.

---

# Reference

1. 林奕成. “Introduction to Computer Graphics, Chapter 8: Hidden Surface.” NYCU EC114[GF], November 18, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.