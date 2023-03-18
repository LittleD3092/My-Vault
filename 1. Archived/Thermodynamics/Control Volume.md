標籤: #Thermodynamics #fluid-mechanics #list 

---

Control volume means a volume that is in space of interiest. There will be in and out flow.

This note shows one of the ways of examining a flowing fluid, which is control volume method.

# Basic Laws

We start by deriving the basic equations that we might need. These equations are called ==rate equations== because the equations are expressed in terms of the rates of flow in and out.

## Conservation of Mass

For a system, we have the simple result that $M = \text{ constant}$ for steady flow. Therefore, we write:

$$\left.
	\frac{dM}{dt}
\right)_{\text{system}} = 0$$

where

$$M_{\text{system}} = \int_{M(\text{system})}dm = \int_{V(\text{system})} \rho dV$$

## Newton's Second Law

Newton's Second law states that the sum of all external forces acting on the system is equal to the time rate of change of linear momentum of the system.

$$\vec F = \left.
	\frac{d\vec P}{dt}
\right)_{\text{system}}$$

where the linear momentum of the system is given by

$$\vec P_{\text{system}} = \int_{M(\text{system})}\vec Vdm = 
\int_{V(\text{system})}\vec V \rho dV$$

- $\vec V$: Velocity

## Angular-Momentum Principle

The angular-momentum priciple states that the rate of change of angular momentum is equal to the sum of all torques acting on the system.

$$\vec T = \left.
	\frac{d\vec H}{dt}
\right)_{\text{system}}$$

where the angular momentum of the system is given by

$$\vec H_{\text{system}} = 
\int_{M(\text{system})} \vec r \times \vec V dm = 
\int_{V(\text{system})} \vec r \times \vec V \rho dV$$

Torque can be produced by surface and body forces (gravity only in here) and also by shafts that cross the system boundary,

$$\vec T = 
\vec r \times \vec F_S + 
\int_{M(\text{system})} \vec r \times \vec g dm + 
\vec T_{\text{shaft}}$$

## First Law of Thermodynamics

> [[First Law of Thermodynamics]]

The first law of thermodynamics is a statement of conservation of energy for a system,

$$\delta Q - \delta W = dE$$

The equation can be written in rate form

$$\dot Q - \dot W = \left.
	\frac{dE}{dt}
\right)_{\text{system}}$$

where the total energy $E$ is

$$E_{\text{system}} = 
\int_{M(\text{system})}edm = 
\int_{V(\text{system})}e\rho dV$$

and specific energy $e$ is

$$e = u + \frac{V^2}{2} + gz$$

## Second Law of Thermodynamics

> [[Second Law of Thermodynamics]]

The second law of thermodynamics states that the change in entropy, $dS$, of the system satisfies

$$dS \geq \frac{\delta Q}{T}$$

We can write the above equation on rate basis

$$\left.
	\frac{dS}{dt}
\right)_{\text{system}} \geq \frac 1 T \dot Q$$

where the total entropy of the system is given by

$$S_{\text{system}} = 
\int_{M(\text{system})}sdm = 
\int_{V(\text{system})}s\rho dV$$

# Control Volume Equations

We have the basic rates of change equations in [[#Basic Laws]], and what we should do next is to derive the general expression control volume equations.

We have five equations evaluating $M, \vec P, \vec H, E$, and $S$. One by one, we let all of them be represented by the symbol $N$. Corresponding to this extensive property, we will also need the intensive property $\eta$.

$$N_{\text{system}} = \int_{M(\text{system})} \eta dm = 
\int_{V(\text{system})}\eta \rho dV$$

Comparing [[#Basic Laws]] and the equation above, we see that if:

$$\begin{array}{l}
	N = M ,& \text{then }\eta = 1 \\
	N = \vec P, & \text{then }\eta = \vec V \\
	N = \vec H, & \text{then }\eta = \vec r\times \vec V \\
	N = E , & \text{then }\eta = e \\
	N = S , & \text{then }\eta = s
\end{array}$$

After some derivation $\frac{dN}{dt}$ (the details are not included in this node, see Introduction to Fluid Mechanics, 10th edition), we can get the following equation which is called ==Reynolds Transport Theorem==:

$$
\underline{
	\left.
		\frac{dN}{dt}
	\right)_{\text{system}} = 
	\frac{\partial}{\partial t}\int_{CV}\eta \rho dV +
	\int_{CS}\eta\rho\vec V \cdot d\vec A
}_\#$$

- $\vec V$: Velocity

We can now substitude $N$ and $\eta$ for various of [[#Basic Laws]].

## Conservation of Mass

Using the equation we derived above, we have the control volume formulation of the conservation of mass:

$$\underline{
	\frac{\partial}{\partial t}\int_{CV}\rho dV +
	\int_{CS} \rho \vec V \cdot d\vec A = 0
}_\#$$

- $\vec V$: Velocity

### Special Cases

In special cases it is possible to simplify the equation above. When $\rho$ is constant (incompressible fluids), the above equation can be written as

$$\frac{\partial V}{\partial t} + \int_{\rm CS} \vec V\cdot d\vec A = 0 \qquad \text{for incompressible fluid}$$

And for nondeformable control volume of fixed size and shape, $V = \text{constant}$. Thus the conservation of mass for incompressible flow through a fixed control volume becomes

$$\underline{
	\int_{\text{CS}} \vec V \cdot d\vec A = 0
}_\# \qquad \text{for incompressible, nondeformable C.V.}$$

- $\vec V$: Velocity

When we have uniform velocity at each inlet and exit, the above equation becomes

$$\underline{\sum_{\text{CS}} \vec V\cdot \vec A = 0}_\# \qquad
\begin{array}{l}
	\text{for incompressible, nondeformable,} \\
	\text{and uniform velocity at} \\ 
	\text{each inlet and exit}
\end{array}$$

- $\vec V$: Velocity

For steady, compressible flow through a fixed control volume, we need to take $\rho$ into account.

$$\underline{
	\int_{\text{CS}} \rho \vec V \cdot d\vec A = 0
}_\# \qquad 
\begin{array}{}
	\text{for steady, compressible fluid}
\end{array}$$

$$\underline{
	\sum_{\text{CS}} \rho \vec V \cdot \vec A = 0
}_\# \qquad 
\begin{array}{l}
	\text{for uniform velocity and} \\
	\text{steady, compressible fluid}
\end{array}$$

## Momentum Equation

From the control volume equation, we substitude $N$ with $\vec P$ and $\eta$ with $\vec V$.

$$\underline{
	\left.
		\vec F = \vec F_S + \vec F_B = \frac{d\vec P}{dt}
	\right)_{\text{system}} = 
	\frac{\partial}{\partial t}\int_{\rm CV}\vec V \rho dV +
	\int_{\rm CS}\vec V\rho \vec V \cdot d\vec A
}_\#$$

$$\underline{
	\left\{
		\begin{array}{}
			F_x & = & F_{S_x} + F_{B_x} & = & 
			\frac{\partial}{\partial t} \int_{\text{CV}} u\rho dV 
			+ \int_{\text{CS}} u\rho \vec V \cdot d \vec A \\
			
			F_y & = & F_{S_y} + F_{B_y} & = & 
			\frac{\partial}{\partial t} \int_{\text{CV}} v\rho dV 
			+ \int_{\text{CS}} v\rho \vec V \cdot d \vec A \\
			
			F_z & = & F_{S_z} + F_{B_z} & = & 
			\frac{\partial}{\partial t} \int_{\text{CV}} w\rho dV 
			+ \int_{\text{CS}} w\rho \vec V \cdot d \vec A
		\end{array}
	\right.
}_\#$$

- $u, v, w$: Vector components of $\vec V$.

For cases when we have uniform flow at each inlet and exit, we can use

$$
\underline{
	\vec F = \vec F_S + \vec F_B = 
	\frac{\partial}{\partial t}\int_{\text{CV}}\vec V \rho dV +
	\sum_{\text{CS}} \vec V \rho \vec V \cdot \vec A
}_\#$$

$$\underline{
	\left\{
		\begin{array}{}
			F_x & = & F_{S_x} + F_{B_x} & = & 
			\frac{\partial}{\partial t} \int_{\text{CV}} u\rho dV 
			+ \sum_{\text{CS}} u\rho \vec V \cdot d \vec A \\
			
			F_y & = & F_{S_y} + F_{B_y} & = & 
			\frac{\partial}{\partial t} \int_{\text{CV}} v\rho dV 
			+ \sum_{\text{CS}} v\rho \vec V \cdot d \vec A \\
			
			F_z & = & F_{S_z} + F_{B_z} & = & 
			\frac{\partial}{\partial t} \int_{\text{CV}} w\rho dV 
			+ \sum_{\text{CS}} w\rho \vec V \cdot d \vec A
		\end{array}
	\right.
}_\#$$

- $u, v, w$: Vector components of $\vec V$.

### Rectilinear Acceleration

The rectilinear acceleration introduced acceleration into the equation we derived above.

$$
\underline{
	\vec F_S + \vec F_B - \int_{\rm CV} \vec a_{rf} \rho dV = 
	\frac{\partial}{\partial t} \int_{\rm CV} \vec V_{xyz} \rho dV + \int_{\rm CS} \vec V_{xyz} \rho \vec V_{xyz} \cdot d\vec A
}_\#$$

The vector equation can be written in the scalar component equations form:

$$\underline{
	\begin{array}{}
		F_{S_x} + F_{B_x} - \int_{\text{CV}} a_{rf_x}\rho dV = 
		\frac{\partial}{\partial t} \int_{\text{CV}} u_{xyz} \rho dV + \int_{\text{CS}} u_{xyz}\rho\vec V_{xyz} \cdot d\vec A \\

		F_{S_y} + F_{B_y} - \int_{\text{CV}} a_{rf_y}\rho dV = 
		\frac{\partial}{\partial t} \int_{\text{CV}} v_{xyz} \rho dV + \int_{\text{CS}} v_{xyz}\rho\vec V_{xyz} \cdot d\vec A \\
		
		F_{S_z} + F_{B_z} - \int_{\text{CV}} a_{rf_z}\rho dV = 
		\frac{\partial}{\partial t} \int_{\text{CV}} w_{xyz} \rho dV + \int_{\text{CS}} w_{xyz}\rho\vec V_{xyz} \cdot d\vec A
	\end{array}
}_\#$$

# Differential Control Volume Analysis

The [[#Control Volume Equations]] are very useful. Now, we can apply these equations to a differential control volume.

![[Pasted image 20221028190126.png]]

The process is not included in this note. See Introduction to "Fluid Mechanics, 10th edition" for full process of deriving the equation. The equation derived is called [[Bernoulli's Equations]]:

$$\underline{\frac p \rho + \frac{V_S^2}{2} + gz = \text{constant}}_\#$$

This equation is subject to the restrictions:

1. Steady flow.
2. No friction.
3. Flow along a streamline.
4. Incompressible flow.

---

參考資料:

熱力學 Ch3 OCW
Introduction to Fluid Mechanics, 10th edition

---

link:

[[Thermodynamic System]]
[[First Law of Thermodynamics]]
[[Second Law of Thermodynamics]]