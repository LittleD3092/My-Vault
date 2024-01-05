Tag: #computer-graphics 
Previous: [[Circle Drawing Algorithm]]
Link: 

[TOC]

---

First, an circle can be divided into 8 sections each with $45\degree$. Using symmetry, we can draw points on other 7 sections, therefore, we only need to draw one of them. (<u>2</u>)

![[Pasted image 20231113153934.png|300]]

We start at the point $(0, r)$, and draw the section clockwise. For each current point $(x_k, y_k)$, we will have two possible points $\rm E$ and $\rm SE$. We select the midpoint $\rm M$: (<u>1</u>)

![[Pasted image 20231113155222.png|300]]

And use the function $f$: (<u>1</u>)

$$P_k = f_{\rm circ}\left(x_k + 1, y_k - \frac{1}{2}\right)$$

To determine whether the midpoint $\rm M$ is in the circle: (<u>1</u>)

$$
\left\{
	\begin{array}{l}
		\text{if } P_k < 0, & \text{draw E} \\
		\text{if } P_k > 0, & \text{draw SE}
	\end{array}
\right.
$$

After drawing either $\rm E$ or $\rm SE$, do the next point $(x_{k + 1}, y_{k + 1})$ until the section is drawn. Then, use symmetry to draw other 7 sections. (<u>1</u>)

---

# Reference

1. 林奕成. “Introduction to Computer Graphics, Chapter 7: Rasterization, Part 2.” NYCU EC114[GF], November 13, 2023.
2. GeeksforGeeks. “Mid-Point Circle Drawing Algorithm,” June 15, 2017. https://www.geeksforgeeks.org/mid-point-circle-drawing-algorithm/.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.