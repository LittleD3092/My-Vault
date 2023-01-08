Tag: #fluid-mechanics 
Previous: [[Fluid Mechanics Basics]]
Link: 

---

[TOC]

---

# Characteristics

## The Entrance Region

- When a laminar flow with uniform velocity $U_0$ enters a pipe, because of the no-slip condition, the velocity at the wall must be zero.
- The speed of the fluid in the neighborhood of the surface is reduced.
- At a distance along the pipe in the entry region, the effect of the solid surface is felt farther out into the flow.

![[Pasted image 20230108140230.png]]

- When the profile shape no longer changes with increasing distance $x$, the flow is **fully developed**.
- The distance between the entrance and the fully developed place is **entrance length**.
	- For laminar flow, the entrance length is $$\frac L D \simeq 0.06\frac{\rho \bar V D}{\mu}$$where $$\bar V = \frac Q A$$

# Fully Developed Laminar Flow

## Between Parallel Plates

### Both Plates Stationary

![[Pasted image 20230108154712.png]]

#### Velocity Profile

> Recall the basic equation in [[Control Volume#Momentum Equation]]:
> $$F_{S_x} + F_{B_x} = \frac{\partial }{\partial t}\int_{\rm CV}u \rho dV + \int_{\rm CS} u\rho \vec V \cdot d \vec A$$

Assumptions:

1. Steady flow
2. Fully developed flow
3. $F_{B_x} = 0$

For fully developed flow, there is no change in momentum.

$$\implies F_{S_x} = 0$$

The forces acting on the surfaces:

$$
\left\{
	\begin{array}{}
		dF_L & = & 
		\displaystyle
		\left(
			p - \frac{dp}{dx}\frac{dx}{2}
		\right)dydz \\
		dF_R & = & 
		\displaystyle
		-\left(
			p + \frac{dp}{dx}\frac{dx}{2}
		\right)dydz \\
		dF_B & = & 
		\displaystyle
		-\left(
			\tau_{yx} - \frac{d\tau_{yx}}{dy}\frac{dy}{2}
		\right)dxdz \\
		dF_T & = & 
		\displaystyle
		\left(
			\tau_{yx} + \frac{d\tau_{yx}}{dy}\frac{dy}{2}
		\right)dxdz
	\end{array}
\right.
$$

- $F_L$: Force acting on the left surface.
- $F_R$: Force acting on the right surface.
- $F_B$: Force acting on the bottom surface.
- $F_T$: Force acting on the top surface.
- $p$: Pressure at the center.
- $\tau_{yx}$: Shear stress at the center of the element.

Adding the forces $F_L, F_R, F_B, F_T$ and substitute $F_{S_x}$:

$$\frac{dp}{dx} = \frac{d\tau_{yx}}{dy}$$

Integrating:

$$\tau_{yx} = \left(\frac{dp}{dx}\right)y + c_1$$

> Recall that for [[Viscosity#Newtonian-Fluid]]:
> $$\tau_{yx} = \mu \frac{du}{dy}$$

Substitute $\tau_{yx}$:

$$\mu \frac{du}{dy} = \left( \frac{dp}{dx} \right)y + c_1$$

Integrate again:

$$u = \frac{1}{2\mu}\left(
	\frac{dp}{dx}
\right)y^2 + \frac{c_1}{\mu}y + c_2$$

Using the boundary conditions:

- At $y = 0, u = 0$
- At $y = a, u = 0$

We find that

$$\left\{
	\begin{array}{l}
		c_1 & = & 
		\displaystyle
		-\frac 1 2\left(
			\frac{dp}{dx}
		\right)a \\
		c_2 & = & 0
	\end{array}
\right.$$

Substitute $c_1, c_2$:

$$\underline{
	u = \frac{1}{2\mu}
	\left(
		\frac{dp}{dx}
	\right)y^2 - \frac{1}{2\mu}
	\left(
		\frac{dp}{dx}
	\right)ay = 
	\frac{a^2}{2\mu}
	\left(
		\frac{dp}{dx}
	\right)
	\left[
		\left(
			\frac y a
		\right)^2 - 
		\left(
			\frac y a
		\right)
	\right]
}_\#$$

- $y$: $y = 0$ at the bottom line.

We can substitute $\displaystyle y = y' + \frac a 2$ for convenience where $y' = 0$ is the channel centerline.

$$\underline{u = \frac{a^2}{2\mu}
\left(
	\frac{dp}{dx}
\right)
\left[
	\left(
		\frac{y'}{a}
	\right)^2 - \frac 1 4
\right]
}_\#$$

#### Volume Flow Rate

The volume flow rate is given by

$$Q = \int_A \vec V \cdot d\vec A$$

For a depth $l$ in the $z$ direction,

$$Q = \int_0^a ul dy$$

Substitute $u$:

$$
\begin{array}{l}
	\displaystyle
	\frac Q l &=& 
	\displaystyle
	\int_0^a \frac{1}{2\mu}
	\left(
		\frac{dp}{dx}
	\right)(y^2 - ay)dy \\
	 & = & 
	 \displaystyle
	 -\frac{1}{12\mu}
	 \left(
		 \frac{dp}{dx}
	 \right)a^3
\end{array}
$$

> Since $dp/dx$ is constant,
> $$\frac{dp}{dx} = \frac{-\Delta p}{dx}$$

$$\underline{
	\frac Q l = -\frac{1}{12\mu}
	\left[
		\frac{-\Delta p}{L}
	\right]a^3 = \frac{a^3 \Delta p}{12\mu L}
}_\#$$

### Upper Plate Moving with Constant Speed

- The upper plate is moving with constant speed $U$.

#### Velocity Profile

$$
\underline{
	u = \frac{Uy}{a} +
	\frac{a^2}{2\mu}
	\left(
		\frac{dp}{dx}
	\right)
	\left[
		\left(
			\frac{y}{a}
		\right)^2 - 
		\left(
			\frac y a
		\right)
	\right]
}_\#
$$

#### Volume Flow Rate

$$\underline{
	\frac Q l = 
	\frac{Ua}{2} - \frac{1}{12\mu}
	\left(
		\frac{dp}{dx}
	\right)a^3
}_\#$$

# Flows in Pipes and Ducts

# Flow Measurement

---

參考資料:

Introduction to Fluid Mechanics, 10th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.