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
			\right) = \rho g_y - \frac{\partial p}{\partial y}
		\end{array}
	\right.
}_\#
$$

---

參考資料:

Introduction to Fluid Mechanics, 10th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.