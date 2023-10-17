Tag: #computer-graphics 
Previous: [[Viewing Volume]]
Link: 

[TOC]

---

The perspective viewing volume is different from [[Orthogonal Viewing Volume]]. In [[Orthogonal Viewing Volume]], you have a block shape. But in perspective viewing volume, you have a pyramid shape.

![[Pasted image 20231016143858.png]]

As you can see in the above figure, the objects are distorted, but the depth information is retained for [[Hidden Surface Removal|hsr]].

# Normalization

The perspective normalization matrix can be written as:

![[Pasted image 20231016144755.png]]

$$
M_{\rm pers} = 
\left[
	\begin{array}{}
		-z_{\rm near} & 0 & 0 & 0 \\
		0 & -z_{\rm near} & 0 & 0 \\
		0 & 0 & \displaystyle 
		\frac{z_{\rm near} + z_{\rm far}}{z_{\rm near} - z_{\rm far}} & \displaystyle
		\frac{-2z_{\rm near}z_{\rm far}}{z_{\rm near} - z_{\rm far}} \\
		0 & 0 & -1 & 0
	\end{array}
\right]
$$

For further normalization:

![[Pasted image 20231016150325.png]]

$$
M_{\rm normpers} = \left[
	\begin{array}{}
		\displaystyle 
		-z_{\rm near} \frac{2}{xw_{\rm max} - xw_{\rm min}} &
		0 & 0 & 0 \\
		0 & \displaystyle 
		-z_{\rm near} \frac{2}{yw_{\rm max} - yw_{\min}} &
		0 & 0 \\
		0 & 0 & \displaystyle
		\frac{z_{\rm near} + z_{\rm far}}{z_{\rm near} - z_{\rm far}} & \displaystyle
		\frac{-2z_{\rm near} z_{\rm far}}{z_{\rm near} - z_{\rm far}} \\
		0 & 0 & -1 & 0
	\end{array}
\right]
$$

---

# Reference

Computer Graphics Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.