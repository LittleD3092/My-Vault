標籤: #Thermodynamics #heat-transfer #list 

---

- 傳導
- Transfer of heat between molecules
- Governed by [[Fourier's Law]]
	- Heat rate: $\displaystyle q_x = -kA \frac{dT}{dx}$
	- Heat flux: $\displaystyle q_x'' = -k \frac{dT}{dx}$
- Direction: Always perpendicular to the isothermal surface.
	- Isothermal surface: A surface of constant temperature.

# General Heat Flux

In 3D:

$$q'' = -k \nabla T = -k 
\left(
	{\bf i} \frac{\partial T}{\partial x} +
	{\bf j} \frac{\partial T}{\partial y} +
	{\bf k} \frac{\partial T}{\partial z}
\right)$$

- $k$: [[Thermal Conductivity]] (${\rm W/m \cdot K}$)
- $T$: Temperature gradient
- ${\bf i, j, k}$: Unit vectors in $x, y, z$ directions

By direction:

$$
\left\{
	\begin{array}{}
		\displaystyle
		q_x'' = -k \frac{\partial T}{\partial x} \\
		\displaystyle
		q_y'' = -k \frac{\partial T}{\partial y} \\
		\displaystyle
		q_z'' = -k \frac{\partial T}{\partial z}
	\end{array}
\right.
$$

> In this section, we assume the medium is isotropic.
> - Isotropic: The thermal conductivity is independent of the coordinate direction.

# Thermal Properties

- The **transport property** shows how well a material transfer heat.
- Properties:
	- [[Thermal Conductivity]] $k$
	- [[Thermal Diffusivity]] $\alpha$

# Heat Diffusion Equation

- [[Heat Diffusion Equation]]

# Thermal Resistance

Similar to electrical resistance, we can use the concept of [[Thermal Resistance]].

- [[Thermal Resistance]]

# Conduction Analysis

For convenience, the chart is listed below.

One-dimensional, steady-state solutions to the heat equation with no heat generation:

|                                        | Plane Wall                                    | Cylindrical Wall                                                            | Spherical Wall                                                                           |
| -------------------------------------- | --------------------------------------------- | --------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------- |
| Heat equation                          | $\displaystyle \frac{d^2 T}{dx^2} = 0$        | $\displaystyle \frac{1}{r} \frac{d}{dr} \left( r \frac{dT}{dr} \right) = 0$ | $\displaystyle \frac{1}{r^2}\frac{d}{dr}\left( r^2 \frac{dT}{dr} \right) = 0$            |
| Temperature distribution               | $\displaystyle T_{s, 1} - \Delta T \frac x L$ | $\displaystyle T_{s, 2} + \Delta T \frac{\ln(r / r_2)}{\ln(r_1 / r_2)}$     | $\displaystyle T_{s, 1} - \Delta T \left[ \frac{1 - (r_1 / r)}{1 - (r_1 / r_2)} \right]$ |
| Heat flux ($q''$)                      | $\displaystyle k \frac{\Delta T}{L}$          | $\displaystyle \frac{k \Delta T}{r\ln (r_2 / r_1)}$                         | $\displaystyle \frac{k \Delta T}{r^2[(1 / r_1) - (1 / r_2)]}$                            |
| Heat rate ($q$)                        | $\displaystyle k A \frac{\Delta T}{L}$        | $\displaystyle \frac{2 \pi L k \Delta T}{\ln(r_2 / r_1)}$                   | $\displaystyle \frac{4 \pi k \Delta T}{(1 / r_1) - (1 / r_2)}$                           |
| Thermal resistance ($R_{t, \rm cond}$) | $\displaystyle \frac{L}{kA}$                  | $\displaystyle \frac{\ln (r_2 / r_1)}{2\pi L k}$                            | $\displaystyle \frac{(1 / r_1) - (1 / r_2)}{4 \pi k}$                                    | 

## Varying area through x

We assume that the following condition is satisfied:

- Steady state.
- One-dimensional transfer with no heat generation.

![[Pasted image 20230418213943.png|400]]

Step 1: Recall [[Fourier's Law]] and apply condition:

$$
\begin{array}{l}
	& \displaystyle
	\frac{q_x}{A} = -k\frac{dT}{dx} \\
	\implies & \displaystyle
	q_x \frac{dx}{A} = -kdT \\
	\implies & \displaystyle
	q_x\int_{x_0}^x \frac{dx}{A(x)} = 
	-\int_{T_0}^T k(T)dT \\
\end{array}
$$

Step 2: Integral.

$$\implies \frac{q_x \Delta x}{A} = -k \Delta T$$

- $\Delta x = x_1 - x_0$
- $\Delta T = T_1 - T_0$

## Cylinder

Assume:

- No heat generation.
- Steady-state conditions.

![[Pasted image 20230418220915.png|500]]

Step 1: Use the [[Heat Diffusion Equation]] and substitute values:

$$
\begin{array}{l}
	& \displaystyle \frac 1 r \frac{\partial}{\partial r} \left( kr \frac{\partial T}{\partial r} \right) + \frac{1}{r^2} \frac{\partial }{\partial \phi} \left( k \frac{\partial T}{\partial \phi} \right) + \frac{\partial }{\partial z}\left( k \frac{\partial T}{\partial z} \right) + \dot q = \rho c_p \frac{\partial T}{\partial t} \\
	\implies & \displaystyle
	\frac 1 r \frac{d}{dr}\left(
		kr \frac{dT}{dr}
	\right) = 0
\end{array}
$$

Step 2: Use fourier's law to obtain $q_r$:

$$\underline{q_r = -kA\frac{dT}{dr} = -k(2\pi rL) \frac{dT}{dr}}_\#$$

Since step 1 suggests that $kr dT/dr$ is a constant, $q_r$ is also a constant in radial direction.

Step 3: Use boundary condition $T(r_1) = T_{s, 1}$ and $T(r_2) = T_{s, 2}$ to get $T(r)$ from equation in step 1:

$$\begin{array}{cl}
	& \displaystyle
	\frac 1 r \frac{d}{dr}\left(
		kr \frac{dT}{dr}
	\right) = 0 \\
	\implies & T(r) = C_1 \ln r + C_2 \\
	\overset{\text{apply B.C.}}{\implies} & 
	\displaystyle
	\underline{
		T(r) = \frac{T_{s, 1} - T_{s, 2}}{\ln(r_1/r_2)}
		\ln\left( \frac{r}{r_2} \right) + T_{s, 2}
	}_\#
\end{array}$$

Step 4: Substitute result of step 3 into step 2, we can obtain the following expression for the heat transfer rate $q_r$:

$$\implies\underline{
	q_r = \frac{2\pi Lk(T_{s, 1} - T_{s, 2})}{\ln(r_2/r_1)}
}_\#$$

Step 5: The thermal resistance can be obtained by $(T_{s, 1} - T_{s, 2}) / q_r$:

$$
\begin{array}{}
	R_{t, \rm cond} & = & \displaystyle
	\frac{(T_{s, 1} - T_{s, 2})}{q_r} \\
	& = & \displaystyle
	\underline{
		\frac{\ln (r_2 / r_1)}{2\pi Lk}
	}_\#
\end{array}
$$

> We only derive one layer. But the result can be applied to composite cylindrical wall by cascading the thermal resistance. For example:
> ![[Pasted image 20230418224543.png]]

## Sphere

| Name                                 | Formula                                                                                          |
| ------------------------------------ | ------------------------------------------------------------------------------------------------ |
| Heat transfer rate $q_r$             | $q_r = \displaystyle \frac{4\pi k(T_{s, 1} - T_{s, 2})}{(1 / r_1) - (1 / r_2)}$                  |
| Thermal resistance $R_{t, \rm cond}$ | $\displaystyle R_{t, \rm cond} = \frac{1}{4 \pi k} \left( \frac{1}{r_1} - \frac{1}{r_2} \right)$ | 

---

參考資料:

熱力學 Ch3 OCW
Incropera's Principles of Heat and Mass Transfer

---

link:

