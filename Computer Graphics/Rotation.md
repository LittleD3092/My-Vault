Tag: #computer-graphics 
Previous: [[Computer Graphics/Computer Graphics]]
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

# 3D

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

## Rotation about an Arbitrary Axis

![[Pasted image 20230920110850.png|300]]

We want to derive a form for rotation about an arbitrary axis $v$. $v$ is represented by a vector:

$$v = [\alpha_x, \alpha_y, \alpha_z]^T$$

Getting a general form directly is hard, so we follow the steps:

1. Rotate the vector to match $z$ axis.
2. Rotate around $z$ axis.
3. Use inverse of step 1 to rotate the axis vector back.

Step 1 is usually represented by a transformation matrix ${\bf R}_{\rm axis}$:

![[Pasted image 20230920111501.png|300]]

$${\bf R}_{\rm axis} = {\bf R}_y(\theta_y) {\bf R}_{x}(\theta_x)$$

The whole procedure can be written as [[Transformation Matrix|transformation matrix]] ${\bf M}$:

$$
\begin{array}{l}
	{\bf M} &=& {\bf R}_{\rm axis}^{-1} {\bf R}_z(\theta) {\bf R}_{\rm axis} \\
	&=& {\bf R}_x(-\theta_x)
	{\bf R}_y(-\theta_y)
	{\bf R}_z(\theta) 
	{\bf R}_y(\theta_y)
	{\bf R}_x(\theta_x)
\end{array}
$$

---

# Reference

Computer Graphics Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.