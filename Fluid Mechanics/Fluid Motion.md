標籤: #fluid-mechanics #list 

---

[TOC]

---

# Conservation of Mass

In this section, we shall derive the differential equation for

## Rectangular Coordinate System

Consider a small cube of control volume:

![[Pasted image 20221126155017.png]]

- The density at the center is $\rho$.
- The velocity at the center is $\vec V = \hat i u + \hat j v + \hat k w$.

For the density on the right face, we use [[Taylor Series]]:

$$\left.
	\rho
\right)_{x + dx / 2} = 
\rho + 
\left(
	\frac{\partial \rho}{\partial x}
\right)\frac{dx}{2} + 
\left(
	\frac{\partial^2 \rho}{\partial x^2}
\right)\frac{1}{2!}
\left(
	\frac{dx}{2}
\right)^2 + \dots$$

Neglecting higher-order terms:

$$
\implies 
\left.
	\rho
\right)_{x + dx / 2} = 
\rho + 
\left(
	\frac{\partial \rho}{\partial x}
\right)\frac{dx}{2}
$$

Also, we can calculate for velocity component $u$ and $u, \rho$ for left surface:

$$
\implies
\left\{
	\begin{array}{}
		\displaystyle
		\left.
			\rho
		\right)_{x + dx / 2} = 
		\rho + 
		\left(
			\frac{\partial \rho}{\partial x}
		\right)\frac{dx}{2} \\
		\displaystyle
		\left.
			u
		\right)_{x + dx/2}=u + \left(
			\frac{\partial u}{\partial x}
		\right)\frac{dx}{2} \\
		\displaystyle
		\left.
			\rho
		\right)_{x - dx / 2} = 
		\rho -
		\left(
			\frac{\partial \rho}{\partial x}
		\right)\frac{dx}{2} \\
		\displaystyle
		\left.
			u
		\right)_{x - dx/2}=u - \left(
			\frac{\partial u}{\partial x}
		\right)\frac{dx}{2}
	\end{array}
\right.
$$

By the procedure above, we can calculate properties for all surfaces. Now we have to calculate control surface $\displaystyle\int_{CS}\rho\vec V \cdot d\vec A$.

> In [[Control Volume#Conservation of Mass]]:
> $$\underline{\frac{\partial}{\partial t}\int_{CV}\rho dV +\int_{CS} \rho \vec V \cdot d\vec A = 0}_\#$$

The control surface for each surface:

$$
\begin{array}{}
	\text{Left} & = & 
	\displaystyle
	-\left[
		\rho - \left(
			\frac{\partial \rho}{\partial x}
		\right)\frac{dx}{2}
	\right]
	\left[
		u - \left(
			\frac{\partial u}{\partial x}
		\right)\frac{dx}{2}
	\right]dydz & = & 
	\displaystyle
	-\rho udydz + \frac 1 2 \left[
		u \left(
			\frac{\partial\rho}{\partial x}
		\right) + \rho\left(
			\frac{\partial u}{\partial x}
		\right)
	\right]dxdydz \\
	\text{Right} & = & 
	\displaystyle
	\left[
		\rho + \left(
			\frac{\partial \rho}{\partial x}
		\right)\frac{dx}{2}
	\right]
	\left[
		u + \left(
			\frac{\partial u}{\partial x}
		\right)\frac{dx}{2}
	\right]dydz & = & 
	\displaystyle
	\rho udydz + \frac 1 2 \left[
		u \left(
			\frac{\partial\rho}{\partial x}
		\right) + \rho\left(
			\frac{\partial u}{\partial x}
		\right)
	\right]dxdydz \\
	\text{Bottom} & = & 
	\displaystyle
	-\left[
		\rho - \left(
			\frac{\partial \rho}{\partial y}
		\right)\frac{dy}{2}
	\right]
	\left[
		v - \left(
			\frac{\partial v}{\partial y}
		\right)\frac{dy}{2}
	\right]dxdz & = & 
	\displaystyle
	-\rho vdxdz + \frac 1 2 \left[
		v \left(
			\frac{\partial\rho}{\partial y}
		\right) + \rho\left(
			\frac{\partial v}{\partial y}
		\right)
	\right]dxdydz \\
\end{array}
$$

## Cylindrical Coordinate System

---

參考資料:

Introduction to Fluid Mechanics, 10th edition

---

link:

[[極座標]]
[[Fluid Mechanics Basics]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.