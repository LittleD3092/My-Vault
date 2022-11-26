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
	\text{Top} & = & 
	\displaystyle
	\left[
		\rho + \left(
			\frac{\partial \rho}{\partial y}
		\right)\frac{dy}{2}
	\right]
	\left[
		v + \left(
			\frac{\partial v}{\partial y}
		\right)\frac{dy}{2}
	\right]dxdz & = & 
	\displaystyle
	\rho vdxdz + \frac 1 2 \left[
		v \left(
			\frac{\partial\rho}{\partial y}
		\right) + \rho\left(
			\frac{\partial v}{\partial y}
		\right)
	\right]dxdydz \\
	\text{Back} & = & 
	\displaystyle
	-\left[
		\rho - \left(
			\frac{\partial \rho}{\partial z}
		\right)\frac{dz}{2}
	\right]
	\left[
		w - \left(
			\frac{\partial w}{\partial z}
		\right)\frac{dz}{2}
	\right]dxdy & = & 
	\displaystyle
	-\rho wdxdy + \frac 1 2 \left[
		w \left(
			\frac{\partial\rho}{\partial z}
		\right) + \rho\left(
			\frac{\partial w}{\partial z}
		\right)
	\right]dxdydz \\
	\text{Front} & = & 
	\displaystyle
	\left[
		\rho + \left(
			\frac{\partial \rho}{\partial z}
		\right)\frac{dz}{2}
	\right]
	\left[
		w + \left(
			\frac{\partial w}{\partial z}
		\right)\frac{dz}{2}
	\right]dxdy & = & 
	\displaystyle
	\rho wdxdy + \frac 1 2 \left[
		w \left(
			\frac{\partial\rho}{\partial z}
		\right) + \rho\left(
			\frac{\partial w}{\partial z}
		\right)
	\right]dxdydz
\end{array}
$$

Adding the six surfaces, we obtain the control surface.

$$\underline{\int_{CS} \rho \vec V \cdot d \vec A = \left[
	\frac{\partial \rho u}{\partial x} +
	\frac{\partial \rho v}{\partial y} +
	\frac{\partial \rho w}{\partial z}
\right]dxdydz}$$

Also, we calculate control volume:

$$\frac{\partial}{\partial t}\int_{CV} \rho dV = \frac{\partial}{\partial t}
\left[
	\rho dxdydz
\right] = 
\underline{
	\frac{\partial \rho}{\partial t}dxdydz
}$$

Adding those together:

$$\frac{\partial}{\partial t}\int_{CV}\rho dV +\int_{CS} \rho \vec V \cdot d\vec A = \left[
	\frac{\partial \rho u}{\partial x} +
	\frac{\partial \rho v}{\partial y} +
	\frac{\partial \rho w}{\partial z}
\right]dxdydz + \frac{\partial \rho}{\partial t}dxdydz = 0$$

$$\implies \underline{
	\frac{\partial \rho u}{\partial x} + \frac{\partial \rho v}{\partial y} + \frac{\partial \rho w}{\partial z} + \frac{\partial \rho}{\partial t} = 0
}_\#$$

The equation above is called **continuity equation**.

Also, the continuity equation can be written as

$$\underline{\nabla \cdot \rho \vec V + \frac{\partial \rho}{\partial t} = 0}_\#$$

For *incompressible fluid*, the continuity equation can be simplified to:

$$\underline{
	\frac{\partial u}{\partial x} +
	\frac{\partial v}{\partial y} +
	\frac{\partial w}{\partial z} =
	\nabla \cdot \vec V = 0 \qquad \text{for incompressible fluid}
}_\#$$

For *steady flow*, all properties are independent of time. The continuity equation can be simplified to

$$
\underline{
	\frac{\partial \rho u}{\partial x} +
	\frac{\partial \rho v}{\partial y} +
	\frac{\partial \rho w}{\partial z} = 
	\nabla \cdot \rho \vec V = 0
	\qquad \text{for steady flow}
}_\# 
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