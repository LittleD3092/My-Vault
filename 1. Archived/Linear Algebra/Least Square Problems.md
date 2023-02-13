Tag: #linear-algebra 
Previous: 
Link: 

---

[TOC]

---

# Description

If we have a $m \times n$ system

$$A{\bf x} = {\bf b}$$

with $m > n$, we cannot expect to find a [[Vector]] ${\bf x} \in R^n$ because it may be inconsistent.

Instead, we look for a [[Vector]] ${\bf x}$ which makes $A{\bf x}$ *closest* to ${\bf b}$.

# Residual

We define residual as

$$r({\bf x}) = {\bf b} - A{\bf x}$$

So that the distance between ${\bf b}$ and $A{\bf x}$ is

$$\vert\vert {\bf b} - A{\bf x}\vert\vert = \vert\vert r({\bf x})\vert\vert$$

# Finding Projection

![[Pasted image 20230101235245.png]]

- It is obvious that the closest point to ${\bf b}$ is the projection ${\bf p}$ on column space $R(A)$.
- The distance vector is $r(\hat{\bf x})$.

> From [[Fundamental Subspaces Theorem]], 
> $$R(A)^\perp = N(A^T)$$

$r(\hat{\bf x})$ must be [[Orthogonal]] to $R(A)$:

$$r(\hat{\bf x}) \in R(A)^\perp$$

$$\implies r(\hat{\bf x}) \in N(A^T)$$

> Note that if ${\bf x}\in N(A)$, 
> $$A{\bf x} = {\bf 0}$$
> Since [[Null Space]] $N(A)$ is the set of solutions to the homogeneous systems.

Since $r(\hat{\bf x}) \in N(A^T)$, 

$$A^T r(\hat {\bf x}) = {\bf 0}$$

$$\implies A^T({\bf b} - {\bf p}) = {\bf 0}$$

$$\implies A^T({\bf b} - A\hat{\bf x}) = {\bf 0}$$

$$\implies \underline{A^TA\hat{\bf x} = A^T{\bf b}}_\#$$

We learn from above that *to find least square solution, simply times $A^T$ to each side and solve for ${\bf x}$*.

> The above underlined equation is called **normal equations**.

# Example

## Find Least Squares Solution for a System

Find the least squares solution of the system

$$
\begin{array}{}
	x_1 & + & x_2 & = & 3 \\
	-2x_1 & + & 3x_2 & = & 1 \\
	2x_1 & - & x_2 & = & 2
\end{array}
$$

---

The normal equations for the system are

$$
\left[
	\begin{array}{}
		1 & -2 & 2 \\
		1 & 3 & -1
	\end{array}
\right]
\left[
	\begin{array}{}
		1 & 1 \\
		-2 & 3 \\
		2 & -1
	\end{array}
\right]
\left[
	\begin{array}{}
		x_1 \\
		x_2
	\end{array}
\right] = 
\left[
	\begin{array}{}
		1 & -2 & 2 \\
		1 & 3 & -1
	\end{array}
\right]
\left[
	\begin{array}{}
		3 \\
		1 \\
		2
	\end{array}
\right]
$$

The solution is $\underline{(83/50, 71/50)^T}_\#$.

## Find Least Squares Linear Function

Given the data

| variables | point 1 | point 2 | point 3 | 
| --------- | ------- | ------- | ------- |
| x         | 0       | 3       | 6       |
| y         | 1       | 4       | 5       |

Find the best least squares fit by a linear function

---

A linear function is in the form

$$y_i = c_0 + c_1 x_i$$

Therefore the system is 

$$
\left[
	\begin{array}{}
		1 & x_1 \\
		1 & x_2 \\
		\vdots & \vdots \\
		1 & x_m
	\end{array}
\right]
\left[
	\begin{array}{}
		c_0 \\
		c_1
	\end{array}
\right] = 
\left[
	\begin{array}{}
		y_1 \\
		y_2 \\
		\vdots \\
		y_m
	\end{array}
\right]
$$

In our case, the system is

$$A{\bf c} = {\bf y}$$

where

$$A = \left[
	\begin{array}{}
		1 & 0 \\
		1 & 3 \\
		1 & 6
	\end{array}
\right] \qquad {\bf c} = \left[
	\begin{array}{}
		c_0 \\
		c_1
	\end{array}
\right] \qquad 
{\bf y} = \left[
	\begin{array}{}
		1 \\
		4 \\
		5
	\end{array}
\right]$$

The normal equations 

$$A^TA{\bf c} = A^T {\bf y}$$

simplify to

$$
\left[
	\begin{array}{}
		3 & 9 \\
		9 & 45
	\end{array}
\right]
\left[
	\begin{array}{}
		c_0 \\
		c_1
	\end{array}
\right] = 
\left[
	\begin{array}{}
		10 \\
		42
	\end{array}
\right]
$$

The solution set is

$$(\frac 4 3 , \frac 2 3)$$

Thus, the best linear least squares fit is given by

$$\underline{y = \frac 4 3 + \frac 2 3 x}_\#$$

---

參考資料:

Linear Algebra with Applications, 10th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.