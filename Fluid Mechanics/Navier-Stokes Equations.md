標籤: #fluid-mechanics 

---

[TOC]

---

- For a Newtonian fluid, the viscous stress is proportional to the rate of angular deformation.
- From section [[Viscosity#Newtonian-Fluid]], for one-dimensional laminar Newtonian flow, $\tau_{yx} = du / dy$.

For three-dimensional, the stresses is more complicated:

$$\left\{
	\begin{array}{}
		\displaystyle
		\tau_{xy} = \tau_{yx} = \mu
		\left(
			\frac{\partial v}{\partial x} +
			\frac{\partial u}{\partial y}
		\right) \\
		\displaystyle
		\tau_{yz} = \tau_{zy} = \mu
		\left(
			\frac{\partial w}{\partial y} +
			\frac{\partial v}{\partial z}
		\right) \\
		\displaystyle
		\tau_{zx} = \tau_{xz} = \mu
		\left(
			\frac{\partial u}{\partial z} +
			\frac{\partial w}{\partial x}
		\right) \\
		\displaystyle
		\sigma_{xx} = -p - \frac 2 3 \mu \nabla \cdot \vec V + 2\mu \frac{\partial u}{\partial x} \\
		\displaystyle
		\sigma_{yy} = 
		-p - \frac 2 3\mu\nabla \cdot \vec V +
		2\mu \frac{\partial v}{\partial y} \\
		\displaystyle
		\sigma_{zz} = 
		-p - \frac 2 3 \mu \nabla \cdot \vec V + 
		2\mu \frac{\partial w}{\partial z}
	\end{array}
\right.$$

Substitude the above expression into [[Fluid Motion#Differential Momentum Equation]]

$$
\left\{
	\begin{array}{}
		\displaystyle
		\rho\frac{Du}{Dt} = 
		\rho g_x - \frac{\partial p}{\partial x} +
		\frac{\partial}{\partial x}
		\left[
			\mu
			\left(
				2 \frac{\partial u}{\partial x} - \frac 2 3 \nabla \cdot \vec V
			\right)
		\right] + \frac{\partial}{\partial y}
		\left[
			\mu
			\left(
				\frac{\partial u}{\partial y} +
				\frac{\partial v}{\partial x}
			\right)
		\right] +
		\frac{\partial}{\partial z}
		\left[
			\mu
			\left(
				\frac{\partial w}{\partial x} +
				\frac{\partial u}{\partial z}
			\right)
		\right] \\
		\displaystyle
		\rho \frac{Dv}{Dt} = \rho g_y - \frac{\partial p}{\partial y} + 
		\frac{\partial}{\partial x}
		\left[
			\mu\left(
				\frac{\partial u}{\partial y} +
				\frac{\partial v}{\partial x}
			\right)
		\right] +
		\frac{\partial}{\partial y}
		\left[
			\mu \left(
				2 \frac{\partial v}{\partial y} - 
				\frac 2 3 \nabla \cdot \vec V
			\right)
		\right] +
		\frac{\partial}{\partial z}
		\left[
			\mu\left(
				\frac{\partial v}{\partial z} +
				\frac{\partial w}{\partial y}
			\right)
		\right] \\
		\displaystyle
		\rho \frac{Dw}{Dt} = \rho g_z - \frac{\partial p}{\partial z} + \frac{\partial}{\partial x}
		\left[
			\mu\left(
				\frac{\partial w}{\partial x} +
				\frac{\partial u}{\partial z}
			\right)
		\right] +
		\frac{\partial}{\partial y}
		\left[
			\mu\left(
				\frac{\partial w}{\partial z} +
				\frac{\partial w}{\partial y}
			\right)
		\right] +
		\frac{\partial}{\partial z}
		\left[
			\mu \left(
				2 \frac{\partial w}{\partial z} - 
				\frac 2 3 \nabla \cdot \vec V
			\right)
		\right]
	\end{array}
\right.
$$

The equations above are called the *Navier-Stokes* equations. In *incompressible flow* with *constant viscosity*.

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
			\rho g_x - \frac{\partial p}{\partial x} + \mu \left(
				\frac{\partial^2u}{\partial x^2} +
				\frac{\partial^2u}{\partial y^2} +
				\frac{\partial^2 u}{\partial z^2}
			\right) \\
			\displaystyle
			\rho
			\left(
				\frac{\partial v}{\partial t} +
				u\frac{\partial v}{\partial x} +
				v\frac{\partial v}{\partial y} +
				w\frac{\partial v}{\partial z}
			\right) = 
			\rho g_y - \frac{\partial p}{\partial y} + \mu \left(
				\frac{\partial^2 v}{\partial x^2} +
				\frac{\partial^2 v}{\partial y^2} +
				\frac{\partial^2 v}{\partial z^2}
			\right) \\
			\displaystyle
			\rho
			\left(
				\frac{\partial w}{\partial t} +
				u\frac{\partial w}{\partial x} +
				v\frac{\partial w}{\partial y} +
				w\frac{\partial w}{\partial z}
			\right) = 
			\rho g_z - \frac{\partial p}{\partial z} + \mu \left(
				\frac{\partial^2 w}{\partial x^2} +
				\frac{\partial^2 w}{\partial y^2} +
				\frac{\partial^2 w}{\partial z^2}
			\right)
		\end{array}
	\right.
}_\#
$$

---

參考資料:

Introductino to Fluid Mechanics, 10th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.