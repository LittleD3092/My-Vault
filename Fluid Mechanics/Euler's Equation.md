Tag: #fluid-mechanics 
Previous: [[Navier-Stokes Equations]]
Link: 

---

[TOC]

---

- Derived from [[Navier-Stokes Equations]]. 
	- Added a condition: inviscid.
- *Condition*:
	- Incompressible.
	- Inviscid.


# Equation

From [[Navier-Stokes Equations]], we remove the viscous terms:

$$
\underline{
	\rho\frac{D\vec V}{Dt} = 
	\rho \vec g - \nabla p
}_\#
$$

Expressed in rectangular coordinates:

$$
\underline{
	\left\{
		\begin{array}{}
			\displaystyle
			\rho
			\left(
				\frac{\partial u}{\partial t} +
				u\frac{\partial u}{\partial x} +
				v\frac{\partial u}{\partial y} +
				w\frac{\partial u}{\partial z}
			\right) =
			\rho g_x - \frac{\partial p}{\partial x} \\
			\displaystyle
			\rho\left(
				\frac{\partial v}{\partial t} +
				u\frac{\partial v}{\partial x} + 
				v\frac{\partial v}{\partial y} +
				w\frac{\partial v}{\partial z}
			\right) = \rho g_y - \frac{\partial p}{\partial y} \\
			\displaystyle
			\rho\left(
				\frac{\partial w}{\partial t} +
				u\frac{\partial w}{\partial x} +
				v\frac{\partial w}{\partial y} +
				w\frac{\partial w}{\partial z}
			\right) = \rho g_z - \frac{\partial p}{\partial z}
		\end{array}
	\right.
}_\#
$$

Expressed in cylindrical coordinates:

$$
\underline{
	\left\{
		\begin{array}{}
			\displaystyle
			\rho a_r = \rho\left(
				\frac{\partial V_r}{\partial t} +
				V_r\frac{\partial V_r}{\partial r} +
				\frac{V_\theta}{r}\frac{\partial V_r}{\partial \theta} +
				V_z\frac{\partial V_r}{\partial z} -
				\frac{V_\theta^2}{r}
			\right) = \rho g_r - \frac{\partial p}{\partial r} \\
			\displaystyle
			\rho a_\theta = \rho
			\left(
				\frac{\partial V_\theta}{\partial t} +
				V_r\frac{\partial V_\theta}{\partial r} +
				\frac{V_\theta}{r}\frac{\partial V_\theta}{\partial \theta} + V_z \frac{\partial V_\theta}{\partial z} +
				\frac{V_rV_\theta}{r}
			\right) = \rho g_\theta - \frac 1 r \frac{\partial p}{\partial \theta} \\
			\displaystyle
			\rho a_z = \rho
			\left(
				\frac{\rho V_z}{\partial t} +
				V_r\frac{\partial V_z}{\partial r} +
				\frac{V_\theta}{r}\frac{\partial V_z}{\partial\theta} +
				V_z\frac{\partial V_z}{\partial z}
			\right) = \rho g_z - \frac{\partial p}{\partial z}
		\end{array}
	\right.
}_\#
$$

## Simplify: Equation of Motion along Streamline

- For simplicity, we sometimes wish to have a equation along a streamline.
- We assume direction $s$ as the direction *along* the streamline.
- We assume direction $n$ as the direction *normal* to the streamline.



---

參考資料:

Introduction to Fluid Mechanics, 10th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.