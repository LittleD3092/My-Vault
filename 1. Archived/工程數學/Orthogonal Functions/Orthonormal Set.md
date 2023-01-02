標籤: #工程數學 
Links: [[Vector]]

---

# Functions

對一個 [[Orthogonal Set]], 若更進一步滿足

$$\int_a^b \phi_n (x) \phi_n^*(x)dx = 1 \qquad \text{ for all } n$$

則被稱為 Orthonormal Set

# Vectors

## Definition

> An orthonormal set of [[Vector|vectors]] is an [[Orthogonal Set|orthogonal set]] of unit vectors.

The set $\{{\bf u}_1, {\bf u}_2, \dots, {\bf u}_n\}$ will be orthonormal if and only if 

$$<{\bf u}_i, {\bf u}_j> = \delta_{ij}$$

where

$$\delta_{ij} = 
\left\{
	\begin{array}{}
		1 & \text{if } i = j \\
		0 & \text{if } i \neq j
	\end{array}
\right.$$

## Transform from Orthogonal Set

Any orthogonal set of nonzero vectors $\{{\bf v}_1, {\bf v}_2, \dots, {\bf v}_n\}$ is possible to form an othonormal set by defining

$${\bf u}_i = 
\left(
	\frac{1}{\vert\vert {\bf v}_i \vert\vert}
\right){\bf v}_i \qquad \text{for } i = 1, 2, \dots, n$$

---

參考資料:

微分方程OCW class 24
Linear Algebra with Applications, 10th edition

---

link:

