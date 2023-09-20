Tag: #computer-graphics 
Previous: [[Computer Graphics]]
Link: 

[TOC]

---

# 2D

Below is a figure showing the rotation of a point:

![[Pasted image 20230918184858.png|400]]

We can see that:

$$
\begin{array}{l}
	& \left\{
		\begin{array}{}
			x' &=& r \cos (\phi + \theta) \\
			y' &=& r \sin (\phi + \theta)
		\end{array}
	\right. \\
	\implies & \left\{
		\begin{array}{}
			x' &=& r\sin\theta\cos\phi + r\cos\theta\sin\phi \\
			y' &=& r\cos\theta\cos\phi + r\sin\theta\sin\phi
		\end{array}
	\right. \\
	\implies & \left\{
		\begin{array}{}
			x' &=& x\sin\theta + y\cos\theta \\
			y' &=& x\cos\theta + y\sin\theta
		\end{array}
	\right.
\end{array}
$$

By the result above, we can see that the rotation about $z$ axis has transformation matrix:

$${\bf R} = {\bf R}_z(\theta) = 
\left[
	\begin{array}{}
		\cos\theta & -\sin\theta & 0 & 0 \\
		\sin\theta & \cos\theta & 0 & 0 \\
		0 & 0 & 1 & 0 \\
		0 & 0 & 0 & 1
	\end{array}
\right]$$

Similarly, the rotation about $x$ and $y$ axis has the following transformation matrix:

![[Pasted image 20230918193557.png|200]]

$$
\begin{array}{}
	{\bf R} = {\bf R}_x(\theta) = \left[
		\begin{array}{}
			1 & 0 & 0 & 0 \\
			0 & \cos\theta & -\sin\theta & 0 \\
			0 & \sin\theta & \cos\theta & 0 \\
			0 & 0 & 0 & 1
		\end{array}
	\right] \\
	{\bf R} = {\bf R}_y(\theta) = \left[
		\begin{array}{}
			\cos\theta & 0 & \sin\theta & 0 \\
			0 & 1 & 0 & 0 \\
			-\sin\theta & 0 & \cos\theta & 0 \\
			0 & 0 & 0 & 1
		\end{array}
	\right]
\end{array}
$$

---

# Reference

Computer Graphics Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.