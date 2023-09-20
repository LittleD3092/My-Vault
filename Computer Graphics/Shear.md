Tag: #computer-graphics 
Previous: [[Computer Graphics]]
Link: 

[TOC]

---

![[Pasted image 20230920110443.png|200]]

For a shear transformation along $x$ axis:

$$
\left\{
	\begin{array}{l}
		x' &=& x + y\cot\theta \\
		y' &=& y \\
		z' &=& z
	\end{array}
\right.
$$

The corresponding shear [[Transformation Matrix|transformation matrix]]:

$$
{\bf H}(\theta) = 
\left[
	\begin{array}{}
		1 & \cot\theta & 0 & 0 \\
		0 & 1 & 0 & 0 \\
		0 & 0 & 1 & 0 \\
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