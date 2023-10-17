Tag: #computer-graphics 
Previous: [[Viewing Volume]]
Link: 

[TOC]

---

The orthogonal viewing volume can be defined by 6 planes forming a block:

![[Pasted image 20231016142348.png]]

# Normalization

To determine whether a point is in an orthogonal viewing volume or not, we can find a [[Transformation Matrix|transformation matrix]] to convert the original viewing volume into a norm viewing volume. This process is called **normalization**.

![[Pasted image 20231016142909.png]]

Then, the points can be converted as well and easily determine whether they are in the viewing volume, following the two steps:

1. $\bf T$: Translation. Move the volume center to the origin.
2. $\bf S$: Scale to have sides of length 2.

The normalization matrix can be written as:

$$
{\bf P} = {\bf ST} = 
\left[
	\begin{array}{}
		\displaystyle
		\frac{2}{xw_{\rm max} - xw_{\rm min}} &
		0 & 0 & \displaystyle
		-\frac{xw_{\rm max} + xw_{\rm min}}{xw_{\rm max} - xw_{\rm min}} \\
		0 & \displaystyle
		\frac{2}{yw_{\rm max} - yw_{\rm min}} & 0 & \displaystyle
		-\frac{yw_{\rm max} + yw_{\rm min}}{yw_{\rm max} - yw_{\rm min}} \\
		0 & 0 & \displaystyle
		\frac{2}{z_{\rm near} - z_{\rm far}} & \displaystyle
		\frac{z_{\rm near} + z_{\rm far}}{z_{\rm near} - z_{\rm far}} \\
		0 & 0 & 0 & 1
	\end{array}
\right]
$$

---

# Reference

Computer Graphics Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.