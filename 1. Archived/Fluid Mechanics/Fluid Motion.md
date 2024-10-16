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

1. [[#Translation]].
2. [[#Rotation]].
3. [[#Linear Deformation]].
4. [[#Angular Deformation]].

![[Pasted image 20221127161949.png]]

## Translation

> For a velocity field $\vec V = \vec V(x, y, z, t)$, it might seem that acceleration field is $\vec a = \partial \vec V / \partial t$.
> This is **incorrect**, since the field describe the velocity of a **position**, not an **individual particle**.

$$\left.
	\vec V_p
\right\vert_{t} = \vec V(x, y, z, t)$$

$$\implies \left.
	\vec V_p
\right\vert_{t + dt} = \vec V(x + dx, y + dy, z + dz, t + dt)$$

Then the change of velocity of the particle $d\vec V_p$ is given by the chain rule

$$d\vec V_p = \frac{\partial \vec V}{\partial x} dx_p + \frac{\partial \vec V}{\partial y}dy_p + \frac{\partial \vec V}{\partial z}dz_p + \frac{\partial \vec V}{\partial t}dt$$

The acceleration of the particle $\vec a_p$:

$$\vec a_p = \frac{d\vec V_p}{dt} = \frac{\partial \vec V}{\partial x}\frac{d x_p}{dt} + \frac{\partial \vec V}{\partial y}\frac{dy_p}{dt} + \frac{\partial \vec V}{\partial z}\frac{dz_p}{dt} + \frac{\partial \vec V}{\partial t}$$

$$\implies \underline{
	\underbrace{
		\frac{D\vec V}{Dt}
	}_{
		\begin{array}{}
			\text{total} \\
			\text{acceleration} \\
			\text{of a particle}
		\end{array}
	} \equiv \vec a_p
	= 
	\underbrace{
		u\frac{\partial \vec V}{\partial x} + v \frac{\partial \vec V}{\partial y} + w \frac{\partial \vec V}{\partial z}
	}_{\text{convective acceleration}} +
	\underbrace{
		\frac{\partial \vec V}{\partial t}
	}_{
		\begin{array}{}
			\text{local} \\
			\text{acceleration}
		\end{array}
	}
}_\#$$

May also be written as

$$\implies \underline{
	\frac{D\vec V}{Dt} \equiv
	\vec a_p = 
	(\vec V \cdot \nabla)\vec V +
	\frac{\partial \vec V}{\partial t}
}_\#$$

The scalar components for $xyz$ coordinate system and cylindrical coordinates system can be written as

$$
\left\{
	\begin{array}{l}
		\displaystyle
		a_{x_p} = \frac{Du}{Dt} = 
		u\frac{\partial u}{\partial x} +
		v\frac{\partial u}{\partial y} +
		w\frac{\partial u}{\partial z} +
		\frac{\partial u}{\partial t} \\
		\displaystyle
		a_{y_p} = \frac{Dv}{Dt} = 
		u\frac{\partial v}{\partial x} +
		v\frac{\partial v}{\partial y} +
		w\frac{\partial v}{\partial z} +
		\frac{\partial v}{\partial t} \\
		\displaystyle
		a_{z_p} = \frac{Dw}{Dt} = 
		u\frac{\partial w}{\partial x} +
		v\frac{\partial w}{\partial y} +
		w\frac{\partial w}{\partial z} +
		\frac{\partial w}{\partial t}
	\end{array}
\right.
$$

$$
\left\{
	\begin{array}{l}
		\displaystyle
		a_{r_p} = 
		V_r\frac{\partial V_r}{\partial r} +
		\frac{V_{\theta}}{r}\frac{\partial V_r}{\partial \theta} - 
		\frac{V_{\theta}^2}{r} +
		V_z \frac{\partial V_r}{\partial z} + \frac{\partial V_r}{\partial t} \\
		\displaystyle
		a_{\theta_p} = 
		V_r\frac{\partial V_\theta}{\partial r} +
		\frac{V_{\theta}}{r}\frac{\partial V_\theta}{\partial \theta} +
		\frac{V_r V_{\theta}}{r} +
		V_z \frac{\partial V_\theta}{\partial z} + \frac{\partial V_\theta}{\partial t} \\
		\displaystyle
		a_{z_p} = 
		V_r\frac{\partial V_z}{\partial r} +
		\frac{V_{\theta}}{r}\frac{\partial V_z}{\partial \theta} +
		V_z \frac{\partial V_z}{\partial z} + \frac{\partial V_z}{\partial t} \\
	\end{array}
\right.
$$

## Rotation

The rotation and angular deformation can be decomposed into:

![[Pasted image 20221127195008.png]]

We define that

- The horizontal displacement of top surface with respect to bottom surface $\Delta \xi$.
- The vertical displacement of right surface with respect to left surface $\Delta \eta$.

$$\Delta \xi = 
\left(
	u + \frac{\partial u}{\partial y} \Delta y
\right) \Delta t - u \Delta t = 
\frac{\partial u}{\partial y}\Delta y\Delta t$$

$$\Delta \eta = \left(
	v + \frac{\partial v}{\partial x} \Delta x
\right) \Delta t - v\Delta t = 
\frac{\partial v}{\partial x}\Delta x\Delta t$$

Computing the angular velocity:

$$\omega_z = \lim_{\Delta t \rightarrow 0}
\frac{
	\displaystyle
	\frac 1 2 (\Delta\alpha - \Delta \beta)
}
{\Delta t}$$

> For small angle, 
> $$\Delta \alpha = \Delta \eta / \Delta x$$
> $$\Delta \beta = \Delta \xi / \Delta y$$

Substitude $\Delta \alpha$ and $\Delta \beta$:

$$= \lim_{\Delta t \rightarrow 0} 
\frac{
	\displaystyle
	\frac 1 2 \left(
		\frac{\Delta \eta}{\Delta x} - 
		\frac{\Delta \xi}{\Delta y}
	\right)
}
{\Delta t}$$

Substitude $\Delta \eta$ and $\Delta \xi$:

$$
= \lim_{\Delta t \rightarrow 0} 
\frac{
	\displaystyle
	\frac 1 2 \left(
		\frac{\partial v}{\partial x}
		\frac{\Delta x}{\Delta x}\Delta t - 
		\frac{\partial u}{\partial y}
		\frac{\Delta y}{\Delta y}
		\Delta t
	\right)
}
{\Delta t} = 
\frac{1}{2}\left(
	\frac{\partial v}{\partial x} - 
	\frac{\partial u}{\partial y}
\right)
$$

By considering other planes for other rotation axes:

$$
\left\{
	\begin{array}{}
		\displaystyle
		\omega_x = \frac 1 2 \left(
			\frac{\partial w}{\partial y} - 
			\frac{\partial v}{\partial z}
		\right) \\
		\displaystyle
		\omega_y = \frac 1 2 \left(
			\frac{\partial u}{\partial z} - 
			\frac{\partial w}{\partial x}
		\right) \\
		\displaystyle
		\omega_z = \frac 1 2 \left(
			\frac{\partial v}{\partial x} - 
			\frac{\partial u}{\partial y}
		\right)
	\end{array}
\right.
$$

Then $\vec \omega$ becomes

$$\vec \omega = \hat i \omega_x + \hat j \omega_y + \hat k \omega_z$$

$$ = \frac 1 2
\left[
	\hat i
	\left(
		\frac{\partial w}{\partial y} - 
		\frac{\partial v}{\partial z}
	\right) + 
	\hat j
	\left(
		\frac{\partial u}{\partial z} - 
		\frac{\partial w}{\partial x}
	\right) +
	\hat k
	\left(
		\frac{\partial v}{\partial x} - 
		\frac{\partial u}{\partial y}
	\right)
\right]$$

The term in the square brackets is [[Field#Curl]].

$$\underline{
	\vec \omega = \frac 1 2 \nabla \times \vec V
}_\#$$

### Vorticity

The *vorticity* $\vec \zeta$ is defined to be twice the rotation

$$\underline{
	\vec \zeta \equiv 2 \vec \omega = 
	\nabla \times \vec V
}_\#
$$

In cylindrical coordinates

$$\underline{
	\vec \zeta = \hat e_r
	\left(
		\frac 1 r 
		\frac{\partial V_z}{\partial \theta} - 
		\frac{\partial V_\theta}{\partial z}
	\right) +
	\hat e_\theta
	\left(
		\frac{\partial V_r}{\partial z} - 
		\frac{\partial V_z}{\partial r}
	\right) +
	\hat k
	\left(
		\frac 1 r 
		\frac{\partial (r V_\theta)}{\partial r} - 
		\frac 1 r 
		\frac{\partial V_r}{\partial \theta}
	\right)
}_\#$$

### Circulation

The *circulation* $\Gamma$ is defined as 

$$\underline{
	\Gamma = \oint_{c} \vec V \cdot d\vec s
}_\#$$

## Linear Deformation

Change in length of the sides may produce changes in volume of the element. The rate of local instantaneous *volume dilation* is given by

$$\underline{\text{Volume dilation rate} = \frac{\partial u}{\partial x} + \frac{\partial v}{\partial y} + \frac{\partial w}{\partial z} = \nabla \cdot \vec V}_\#$$

## Angular Deformation

Recall that in [[#Rotation]], 

$$\Delta \xi = \frac{\partial u}{\partial y}\Delta y\Delta t$$
$$\Delta \eta = \frac{\partial v}{\partial x} \Delta x \Delta t$$
$$\Delta \alpha = \Delta \eta / \Delta x$$
$$\Delta \beta = \Delta \xi / \Delta y$$

Rate of angular deformation in $xy$ plane is

$$\lim_{\Delta t \rightarrow 0} 
\frac{(\Delta \alpha + \Delta \beta)}{\Delta t} $$

Substitude $\Delta \alpha, \Delta \beta, \Delta \xi, \Delta \eta$ yields

$$\text{Rate of angular deformation}_{xy} = 
\frac{\partial v}{\partial x} + 
\frac{\partial u}{\partial y}$$

Using the same way, we can get similar expressions for $yz$ and $zx$ planes:

$$\text{Rate of angular deformation}_{yz} = 
\frac{\partial w}{\partial y} + 
\frac{\partial v}{\partial z}$$
$$\text{Rate of angular deformation}_{zx} = 
\frac{\partial w}{\partial x} +
\frac{\partial u}{\partial z}$$

# Momentum Equation

## Force Acting on a Particle

Note that Newton's second law is given by

$$\vec F = 
\left.
	\frac{d\vec P}{dt}
\right)_{\rm system}$$

where linear momentum $\vec P$ is given by

$$\vec P_{\rm system} = 
\int_{\text{mass(system)}} \vec V dm$$

Then, for a system of mass $dm$, Newton's second law can be written

$$d\vec F = dm 
\left.
	\frac{d\vec V}{dt}
\right)_{\text{system}}$$

$$ = dm \frac{D \vec V}{Dt} = dm
\left[
	u \frac{\partial \vec V}{\partial x} +
	v \frac{\partial \vec V}{\partial y} +
	w \frac{\partial \vec V}{\partial z} +
	\frac{\partial \vec V}{\partial t}
\right]$$

To obtain the net force in the $x$ direction, $dF_{S_x}$, we sum the forces in the $x$ direction.

$$dF_{S_x} = 
\left(
	\sigma_{xx} + 
	\frac{\partial \sigma_{xx}}{\partial x}
	\frac{dx}{2}
\right)dydz - 
\left(
	\sigma_{xx} - 
	\frac{\partial \sigma_{xx}}{\partial x}
	\frac{dx}{2}
\right)dydz +
\left(
	\tau_{yx} + 
	\frac{\partial \tau_{yx}}{\partial y}
	\frac{dy}{2}
\right)dxdz - 
\left(
	\tau_{yx} - 
	\frac{\partial \tau_{yx}}{\partial y}
	\frac{dy}{2}
\right)dxdz +
\left(
	\tau_{zx} + 
	\frac{\partial \tau_{zx}}{\partial z}
	\frac{dz}{2}
\right)dxdy - 
\left(
	\tau_{zx} - 
	\frac{\partial \tau_{zx}}{\partial z}
	\frac{dz}{2}
\right)dxdy$$

$$ = \left(
	\frac{\partial \sigma_{xx}}{\partial x} +
	\frac{\partial \tau_{yx}}{\partial y} +
	\frac{\partial \tau_{zx}}{\partial z}
\right)dxdydz$$

The force $dF_x, dF_y, dF_z$ is the sum of body force and surface force:

$$
\left\{
	\begin{array}{l}
		\displaystyle
		dF_x = dF_{B_x} + dF_{S_x} = 
		\left(
			\rho g_x + 
			\frac{\partial \sigma_{xx}}
			{\partial x} +
			\frac{\partial \tau_{yx}}
			{\partial y} +
			\frac{\partial \tau_{zx}}
			{\partial z}
		\right)dxdydz \\
		\displaystyle
		dF_y = dF_{B_y} + dF_{S_y} = 
		\left(
			\rho g_y + 
			\frac{\partial \tau_{xy}}
			{\partial x} +
			\frac{\partial \sigma_{yy}}
			{\partial y} + 
			\frac{\partial \tau_{zy}}
			{\partial z}
		\right)dxdydz \\
		\displaystyle
		dF_z = dF_{B_z} + dF_{S_z} = 
		\left(
			\rho g_z + 
			\frac{\partial \tau_{xz}}
			{\partial x} +
			\frac{\partial \tau_{yz}}
			{\partial y} +
			\frac{\partial \sigma_{zz}}
			{\partial z}
		\right)dxdydz
	\end{array}
\right.
$$

## Differential Momentum Equation

If we substitude [[#Force Acting on a Particle]]

$$
\left\{
	\begin{array}{l}
		\displaystyle
		dF_x = dF_{B_x} + dF_{S_x} = 
		\left(
			\rho g_x + 
			\frac{\partial \sigma_{xx}}
			{\partial x} +
			\frac{\partial \tau_{yx}}
			{\partial y} +
			\frac{\partial \tau_{zx}}
			{\partial z}
		\right)dxdydz \\
		\displaystyle
		dF_y = dF_{B_y} + dF_{S_y} = 
		\left(
			\rho g_y + 
			\frac{\partial \tau_{xy}}
			{\partial x} +
			\frac{\partial \sigma_{yy}}
			{\partial y} + 
			\frac{\partial \tau_{zy}}
			{\partial z}
		\right)dxdydz \\
		\displaystyle
		dF_z = dF_{B_z} + dF_{S_z} = 
		\left(
			\rho g_z + 
			\frac{\partial \tau_{xz}}
			{\partial x} +
			\frac{\partial \tau_{yz}}
			{\partial y} +
			\frac{\partial \sigma_{zz}}
			{\partial z}
		\right)dxdydz
	\end{array}
\right.
$$

to Newton's second law in section [[#Force Acting on a Particle]]

$$ = dm \frac{D \vec V}{Dt} = dm
\left[
	u \frac{\partial \vec V}{\partial x} +
	v \frac{\partial \vec V}{\partial y} +
	w \frac{\partial \vec V}{\partial z} +
	\frac{\partial \vec V}{\partial t}
\right]$$

We get 

$$
\left\{
	\begin{array}{}
		\displaystyle
		\rho g_x + 
		\frac{\partial \sigma_{xx}}{\partial x} +
		\frac{\partial \tau_{yx}}{\partial y} + 
		\frac{\partial \tau_{zx}}{\partial z} 
		&=&
		\rho \left(
			\frac{\partial u}{\partial t} +
			u\frac{\partial u}{\partial x} +
			v\frac{\partial u}{\partial y} +
			w\frac{\partial u}{\partial z}
		\right) \\
		\displaystyle
		\rho g_y + 
		\frac{\partial \tau_{xy}}{\partial x} +
		\frac{\partial \sigma_{yy}}{\partial y} +
		\frac{\partial \tau_{zy}}{\partial z} 
		&=& 
		\rho \left(
			\frac{\partial v}{\partial t} +
			u\frac{\partial v}{\partial x} +
			v\frac{\partial v}{\partial y} +
			w\frac{\partial v}{\partial z}
		\right) \\
		\displaystyle
		\rho g_z + 
		\frac{\partial \tau_{xz}}{\partial x} +
		\frac{\partial \tau_{yz}}{\partial y} +
		\frac{\partial \sigma_{xx}}{\partial z} 
		&=&
		\rho\left(
			\frac{\partial w}{\partial t} +
			u\frac{\partial w}{\partial x} +
			v\frac{\partial w}{\partial y} +
			w\frac{\partial w}{\partial z}
		\right)
	\end{array}
\right.
$$

## Navier-Stokes Equations

[[Navier-Stokes Equations]]

---

參考資料:

Introduction to Fluid Mechanics, 10th edition

---

link:

[[極座標]]
[[Fluid Mechanics Basics]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.