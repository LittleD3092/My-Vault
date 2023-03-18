標籤: #fluid-mechanics #list 

---

[TOC]

---

# Basic Static Equations

The fluid has two general types of forces:

1. Body force
2. Surface force

## Body Force

The only body force that must be considered in most engineering problems is due to gravity.

$$d\vec F_B=\vec g dm=\vec g \rho dV$$

- $\vec g$: local gravity vector
- $\rho$: density
- $dV$: volume of the element

In Cartesian coordinates $dV = dxdydz$:

$$d\vec F_B=\rho\vec gdxdydz$$

## Surface Force

In static fluid, there are no shear stresses, so the only surface force the pressure force.

$$
\begin{array}{}
	d\vec F_S & = & 
	\left(
		p - \frac{\partial p}{\partial x}\frac{dx}{2}
	\right)(dydz)(\hat i) & + &
	\left(
		p + \frac{\partial p}{\partial x}\frac{dx}{2}
	\right)(dydz)(-\hat i) \\
	& + &
	\left(
		p - \frac{\partial p}{\partial y}\frac{dy}{2}
	\right)(dxdz)(\hat j) & + &
	\left(
		p + \frac{\partial p}{\partial y}\frac{dy}{2}
	\right)(dxdz)(-\hat j) \\
	& + &
	\left(
		p - \frac{\partial p}{\partial z}\frac{dz}{2}
	\right)(dxdy)(\hat k) & + &
	\left(
		p + \frac{\partial p}{\partial z}\frac{dz}{2}
	\right)(dxdy)(-\hat k) \\
\end{array}
$$

$$\implies d\vec F_S = -\left(
	\frac{\partial p}{\partial x}\hat i +
	\frac{\partial p}{\partial y}\hat j +
	\frac{\partial p}{\partial z}\hat k
\right)dxdydz$$

Using [[Field#Gradient|gradient]]:

$$\implies d\vec F_S = -\nabla pdxdydz$$

## Total Force

We combine the formulations for surface and body forces that we have developed to obtain the total force acting on a fluid element.

$$d\vec F = d\vec F_S + d\vec F_B = (-\nabla p + \rho\vec g)dV$$

On a per unit volume basis

$$\frac{d\vec F}{dV} = -\nabla p + \rho \vec g$$

For equilibrium, $\vec F$ should be $0$:

$$-\nabla p + \rho \vec g = 0$$

Note that this is a vector equation, and can be divided to 3 equations:

$$
\left\{
	\begin{array}{}
		-\frac{\partial p}{\partial x} + \rho g_x = 0 & x\text{ direction} \\
		-\frac{\partial p}{\partial y} + \rho g_y = 0 & y \text{ direction} \\
		-\frac{\partial p}{\partial z} + \rho g_z - 0 & z \text{ direction}
	\end{array}
\right.
$$

Suppose the coordinate system is chosen with $z$ axis directed vertically upward, $g_x = g_y = 0$, $g_z = g$:

$$\underline{
	\frac{dp}{dz} = -\rho g \equiv -\gamma
}_\#$$

- $\gamma$: specific weight

> Restrictions:
> 1. Static fluid.
> 2. Gravity is the only body force.
> 3. The $z$ axis is vertical and upward.

# Pressure

![[Pressure#Static Fluid]]

# Hydrostatic Force

![[Hydrostatic Force]]

# Buoyancy

![[Buoyancy]]

# Fluids in Rigid-Body Motion

Fluids in rigid-body motion is motion in which the entire fluid moves as if it were a rigid body, individual fluid particles, although they may be in motion, are not deforming.

To start, we recall from [[#Total Force]], we derived that

$$d\vec F = (-\nabla p + \rho \vec g)dV$$

or

$$\frac{d\vec F}{dV} = -\nabla p + \rho \vec g$$

Another equation we need is Newton's second law.

$$d\vec F = \vec a dm = \vec a \rho dV \quad\text{ or } \quad \frac{d\vec F}{dV} = \rho \vec a$$

Using the two equations above, we obtain

$$-\nabla p + \rho \vec g = \rho \vec a$$

$$\implies -\nabla p + \rho (\vec g - \vec a) = 0$$

If the acceleration $\vec a$ is constant, we can combine it with $\vec g$ and obtain an effective "acceleration of gravity", $\vec g_{\text{eff}} = \vec g - \vec a$, so that the equation has the same form as our basic equation for pressure distribution in a static fluid.  

$$-\nabla p + \rho \vec g_{\text{eff}} = 0$$

$$\underline{\vec g_{\rm eff} = \vec g - \vec a}_\#$$

==This means that we can use the results of previous sections of this note as long as we use $\vec g_{\text{eff}}$ in place of $\vec g$.==

---

參考資料:

Introdection to Fluid Mechanics, 10th edition

---

link:

[[Rigid Body]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.