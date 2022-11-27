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

A suitable differential control volume for cylindrical coordinates is shown in the figure below.

![[Pasted image 20221127145927.png]]

- The density at center $O$ is $\rho$.
- The velocity of $O$ is $\vec V = \hat e_r V_r + \hat e_{\theta} V_{\theta} + \hat k V_z$.

The control surface is evaluated:

![[Pasted image 20221127150255.png]]

And we can see that the net mass flux of control surface is

$$
\int_{CS}\rho \vec V \cdot d\vec A = 
\left[
	\rho V_r + 
	r\frac{\partial \rho V_r}{\partial r} +
	\frac{\partial \rho V_{\theta}}{\partial \theta} +
	r \frac{\partial \rho V_z}{\partial z}
\right]drd\theta dz$$

The mass inside the control volume is $\rho r d\theta dr dz$, and the rate of change is

$$\frac{\partial}{\partial t}\int_{CV} \rho dV = \frac{\partial \rho}{\partial t}r d\theta dr dz$$

Using [[Control Volume#Conservation of Mass]] equation and substitude the above two expression:

$$\frac{\partial}{\partial t}\int_{CV}\rho dV + \int_{CS} \rho \vec V \cdot d \vec A = 0$$

$$\implies \left[
	\rho V_r + 
	r\frac{\partial \rho V_r}{\partial r} +
	\frac{\partial \rho V_{\theta}}{\partial \theta} +
	r \frac{\partial \rho V_z}{\partial z}
\right]drd\theta dz + \frac{\partial \rho}{\partial t}r d\theta dr dz = 0$$

Divide $drd\theta dz$ for both sides:

$$\implies \rho V_r + 
r\frac{\partial \rho V_r}{\partial r} +
\frac{\partial \rho V_{\theta}}{\partial \theta} +
r \frac{\partial \rho V_z}{\partial z} + 
r \frac{\partial \rho}{\partial t} = 0$$

$$\implies \frac{\partial(r\rho V_r)}{\partial r} + \frac{\partial \rho V_{theta}}{\partial \theta} + r\frac{\partial \rho V_z}{\partial z} +
r \frac{\partial \rho}{\partial t} = 0$$

Dividing by $r$:

$$
\underline{
	\frac{1}{r}
	\frac{\partial (r \rho V_r)}{\partial r} +
	\frac 1 r 
	\frac{\partial (\rho V_{\theta})}
	{\partial \theta} +
	\frac{\partial (\rho V_z)}{\partial z} +
	\frac{\partial \rho}{\partial t} = 0
}_\#
$$

Can be represented in [[Field#Gradient]]:

$$\underline{
	\nabla \cdot \rho \vec V + 
	\frac{\partial \rho}{\partial t} = 0
}_\#$$

For *incompressible fluid*, $\rho = \text{constant}$

$$\underline{
	\frac 1 r\frac{\partial (r V_r)}{\partial r} +
	\frac 1 r
	\frac{\partial V_{\theta}}{\partial \theta} +
	\frac{\partial V_z}{\partial z} = 
	\nabla \cdot \vec V = 0
}_\# \qquad \text{for incompressible fluid}$$

For *steady flow*, 

$$\underline{
	\frac 1 r 
	\frac{\partial (r \rho V_r)}{\partial r} +
	\frac 1 r
	\frac{\partial (\rho V_\theta)}
	{\partial \theta} +
	\frac{\partial (\rho V_z)}{\partial z} = 
	\nabla \cdot \rho \vec V = 0
}_\#
\qquad \text{for steady flow}$$

# Stream Function

> Recall that in [[Continuum Lines]], streamlines are lines tangent to the velocity vectors:
> $$\left.\frac{dy}{dx}\right\vert_{\rm streamline} = \frac v u$$

We first use [[#Rectangular Coordinate System]] equation of incompressible flow:

$$\frac{\partial u}{\partial x} +
\frac{\partial v}{\partial y} = 0$$

*Stream function* will allow us to represent two entities $u$ and $v$ by one entity $\psi$. 
We define *stream function* $\psi$ as below, so that it satisfy the equation above.

$$\underline{
	\left\{
		\begin{array}{l}
			\displaystyle
			u \equiv 
			\frac{\partial \psi}{\partial y} \\
			\displaystyle
			v \equiv 
			-\frac{\partial \psi}{\partial x}
		\end{array}
	\right.
}_\#$$

> From [[Continuum Lines]]:
> $$\left.\frac{dy}{dx}\right)_{\text{streamline}} = \frac v u$$
> $$\implies udy - vdx = 0$$

Substitude $u, v$ of the above into the streamline equation:

$$\implies \frac{\partial \psi}{\partial x}dx + \frac{\partial \psi}{\partial y}dy = 0$$

> By math, we know that
> $$\left\{\begin{array}{} \partial \psi = u\partial y \\ \partial \psi = -v\partial x \end{array}\right. \implies \left\{ \begin{array}{} d\psi = udy + f(x) \\ d\psi = -vdx + f(y) \end{array} \right.$$
> $$\implies d\psi = udy + udx$$

$$\implies d\psi = \frac{\partial \psi}{\partial x}dx + \frac{\partial \psi}{\partial y}dy = 0$$

By the above result, we find out that

1. $\psi$ is a constant along a streamline.
2. We can specify individual streamlines by their stream function values $\psi = 0, 1, 2 \dots$
3. The volume flow rate between two streamlines is given by the difference between the two stream function values $\psi_2 - \psi_1$.

Using 2D incompressible flow equation in [[#Cylindrical Coordinate System]], 

$$\frac{\partial (rV_r)}{\partial r} +
\frac{\partial V_{\theta}}{\partial \theta} = 0$$

and define a stream function $\psi$ to satisfy the equation above:

$$\underline{V_r \equiv 
\frac 1 r\frac{\partial \psi}{\partial \theta}}_\#$$

$$\underline{V_\theta \equiv -\frac{\partial \psi}{\partial r}}_\#$$

# Kinematics

We can decompose the fluid particle's motion into four components:

1. Translation.
2. Rotation.
3. Linear deformation.
4. Angular deformation.

![[Pasted image 20221127161949.png]]

---

參考資料:

Introduction to Fluid Mechanics, 10th edition

---

link:

[[極座標]]
[[Fluid Mechanics Basics]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.