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

![[Pasted image 20230106171650.png]]

### Along Streamline Direction

Apply Newton's second law:

$$
\underbrace{
	\left(
		p - \frac{\partial p}{\partial s}
		\frac{ds}{2}
	\right)dn dx - 
	\left(
		p + \frac{\partial p}{\partial s}\frac{ds}{2}
	\right)dndx
}_{\displaystyle F_s \text{ (surface force)}} - 
\underbrace{
	\rho g \sin \beta ds dn dx
}_{\displaystyle F_B \text{ (body force)}} = \underbrace{\rho a_s ds dn dx}_{M a}
$$

- $p$: Pressure at center.
- $dsdndx$: The volume of the particle.

Simplifying:

$$\implies -\frac{\partial p}{\partial s} - 
\rho g \sin \beta = \rho a_s$$

Substitute $\displaystyle \sin\beta = \frac{\partial z}{\partial s}$:

$$-\frac 1 \rho\frac{\partial p}{\partial s} - g \frac{\partial z}{\partial s} = a_s$$

> For acceleration along a streamline, 
> $$a_s = \frac{DV}{Dt} = \frac{\partial V}{\partial t} + V\frac{\partial V}{\partial s}$$

Substitute $a_s$:

$$\underline{-\frac 1 \rho \frac{\partial p}{\partial s} - g\frac{\partial z}{\partial s} = \frac{\partial V}{\partial t} + V\frac{\partial V}{\partial s}}_\#$$

For steady flow, $\displaystyle\frac{\partial V}{\partial t} = 0$

$$\underline{
	\frac{1}{\rho}\frac{\partial p}{\partial s} = -g\frac{\partial z}{\partial s} - V\frac{\partial V}{\partial s} \qquad \text{for steady flow}
}_\#$$

In some cases that there is no gravity (or the flow is in $xy$ plane):

$$\underline{
	\frac 1 \rho\frac{\partial p}{\partial s} = -V\frac{\partial V}{\partial s} \qquad \text{for steady flow, no gravity}
}_\#$$

### Normal to Streamline Direction

Similar in [[#Along Streamline Direction]] section, we apply Newton's second law in normal direction:

$$
\left(
	p - \frac{\partial p}{\partial n}
	\frac{dn}{2}
\right)dsdx - 
\left(
	p + \frac{\partial p}{\partial n}
	\frac{dn}{2}
\right)dsdx - 
\rho g \cos\beta dndxds = \rho a_n dndxds
$$

Simplify:

$$-\frac{\partial p}{\partial n} - \rho g \cos \beta = \rho a_n$$

Substitute $\displaystyle\cos\beta = \frac{\partial z}{\partial n}$:

$$-\frac 1 \rho \frac{\partial p}{\partial n} - g\frac{dz}{\partial n} = a_n$$

> Using the radius of curvature $R$, $a_n$ is:
> $$a_n = -\frac{V^2}{R}$$

Substitute $a_n$:

$$
\underline{
	\frac 1 \rho \frac{\partial p}{\partial n} +
	g \frac{\partial z}{\partial n} = 
	\frac{V^2}{R} \qquad
	\text{for steady flow}
}_\#
$$

For horizontal plane (no gravity):

$$\underline{\frac 1 \rho \frac{\partial p}{\partial n} = \frac{V^2}{R} \qquad \text{for no gravity} }_\#$$

# Example

The flow rate of air at standard conditions in a flat duct is to be determined by installing pressure taps across a bend. The duct is $0.3\ \text m$ deep and $0.1\ \text m$ wide. The inner radius of the bend is $0.25\text{ m}$. If the measured pressure difference between the taps is $40 \text{ mm}$ of water, compute the approximate flow rate.

![[Pasted image 20230107154805.png|300]]

---

For the taps installed on position $1$ and $2$, the direction is **normal** to the streamline. Also, the flow is on a horizontal plane, so there is no gravity.

$$\frac 1 \rho \frac{\partial p}{\partial n} = \frac{V^2}{R} \qquad \text{for no gravity}$$

$$\implies \frac{dp}{dr} = \frac{\rho V^2}{r}$$

$$\implies dp = \frac{\rho V^2 dr}{r}$$

Integrating each side:

$$p_2 - p_1 = \rho V^2\left.\ln r\right\vert_{r = r_1}^{r_2}$$

$$\implies V = 
\left(
	\frac{p_2 - p_1}{\rho \ln (r_2/r_1)}
\right)^{1/2}$$

Substitute the pressure difference given:

$$V = 
\left(
	\frac{\rho_{\text H_2\text O} g \Delta h}{\rho \ln(r_2/r_1)}
\right)^{1/2}$$

Substituting numerical values:

$$V = \left(
	999 \frac{\rm kg}{\rm m^3} \times 9.81 \frac{\rm m}{\rm s^2} \times 0.04 {\ \rm m} \times \frac{m^3}{1.23{\ \rm kg}} \times \frac{1}{\ln(0.35{\ \rm m} / 0.25{\rm \ m})}
\right)^{1/2} = 30.8 {\ \rm m/s}$$

For uniform flow:

$$Q = VA = 30.8 \frac{\rm m}{\rm s} \times 0.1 {\ \rm m} \times 0.3 {\rm \ m} = \underline{0.924 {\rm \ m^3/s}}_\#$$

---

參考資料:

Introduction to Fluid Mechanics, 10th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.