Tag: #heat-transfer #list 
Previous: [[Convection]]
Link: 

[TOC]

---

# Velocity Boundary Layer

![[Pasted image 20230613145108.png]]

## Local Friction Coefficient

We define the **local friction coefficient**:

$$C_f = \frac{\tau_s}{\rho u_\infty^2 / 2}$$

- $\tau_s$: surface shear stress
- $\rho$: density of fluid
- $u_\infty$: free stream velocity

For [[Newtonian Fluid|Newtonian fluid]], the surface shear stress is:

$$\tau_s = \left .
	\mu \frac{\partial u}{\partial y}
\right\vert_{y = 0}$$

> [[Viscosity#Newtonian and Non-Newtonian]]:
> For Newtonian fluid, the [[#Shear Stress]] is proportional to [[#Deformation Rate]]. This means that we may write the relationship as the following equation:
> $$\tau_{yx} = \mu \frac{du}{dy}$$

## Velocity Boundary Layer Thickness

Boundary layer thickness $\delta$ is defined as the value of $y$ for which

$$u = 0.99u_{\infty}$$

# Thermal Boundary Layer

![[Pasted image 20230613145636.png]]

## Thermal Boundary Layer

Thermal boundary layer thickness $\delta_t$ is defined as the value $y$ for which the ratio

$$
\frac{T_s - T}{T_s - T_\infty} = 0.99
$$

## Local Surface Heat Flux

The local surface heat flux may be obtained by applying [[Fourier's Law]] to the fluid at $y = 0$:

$$
q''_s = 
\left.
	-k_f \frac{\partial T}{\partial y}
\right\vert_{y = 0}
$$

- $k_f$: Thermal conductivity of fluid.

Recall [[Newton's Law of Cooling]]:

$$q''_s = h(T_s - T_\infty)$$

Combining above two equations, we get convection coefficient:

$$h = \frac{-k_f \partial T / \partial y \vert_{y = 0}}{T_s - T_\infty}$$

# Concentration Boundary Layer

- Molar concentration: $\text{kmol/m}^3$
- $C_{A, s}$: The molar concentration of species $A$ at the surface.
- $C_{A, \infty}$: The molar concentration of species $A$ at free stream.
- If $C_{A, s}$ and $C_{A, \infty}$ are not same, transfer by convection will occur.

![[Pasted image 20230613151321.png]]

## Concentration Boundary Layer Thickness

Concentration boundary layer thickness $\delta$ is defined as the value $y$ for which

$$\frac{
	C_{A, s} - C_A
}{
	C_{A, s} - C_{A, \infty}
} = 0.99$$

## Molar Flux

The molar flux $N_A''$ is defined by [[Fick's Law]]:

$$N_A'' = -D_{AB} \frac{\partial C_A}{\partial y}$$

- $D_{AB}$: Binary diffusion coefficient, a property of the binary mixture.

For $y = 0$ (at surface), the molar flux is

$$N_{A, s}'' = \left. 
	-D_{AB} \frac{\partial C_A}{\partial y}
\right\vert_{y = 0}$$

Analogous to [[Newton's Law of Cooling|Newton's law of cooling]], an equation can be written:

$$N_{A, s}'' = h_m(C_{A, s} - C_{A, \infty})$$

- $h_m \text{(m/s)}$: Convection mass transfer coefficient.

Combining previous two equations, we get:

$$
h_m = \frac{
	-D_{AB} \partial C_A / \partial y \vert_{y = 0}
}{
	C_{A, s} - C_{A, \infty}
}
$$

## Mass Flux

The transfer of species may also be expressed as mass flux $n_A'' \text{(kg/s} \cdot \text{m}^2\text{)}$ or mass transfer rate $n_A \text{(kg/s)}$.

$$
\left\{
	\begin{array}{}
		n_A'' &=& h_m(\rho_{A, s} - \rho_{A, \infty}) \\
		n_A &=& \overline h_m A_s (\rho_{A, s} - \rho_{A, \infty})
	\end{array}
\right.
$$

- $\overline h_m$: Average mass transfer coefficient. $\displaystyle \overline h_m = \frac{1}{A_s} \int_{A_s} h_m dA_s$.
- $\rho_A \text{(kg/m)}^3$: Mass density of species $A$.

[[Fick's Law]] can also be written on a mass basis:

$$n_{A, s}'' = 
\left.
	-D_{AB} \frac{\partial \rho_A}{\partial y}
\right\vert_{y = 0}
$$

An alternative expression for $h_m$:

$$h_m = \frac{
	-D_{AB}\partial \rho_A / \partial y \vert_{y = 0}
}{
	\rho_{A, s} - \rho_{A, \infty}
}$$

# Similarity Parameters and Equations

The boundary layer equations are normalized by the variables:

$$
\left\{
	\begin{array}{}
		x^* &=& \displaystyle \frac x L \\
		y^* &=& \displaystyle \frac y L \\
		u^* &=& \displaystyle \frac u V \\
		v^* &=& \displaystyle \frac v V \\
		T^* &=& \displaystyle \frac{T - T_s}{T_\infty - T_s} \\
		C_A^* &=& \displaystyle \frac{C_A - C_{A, s}}{C_{A, \infty} - C_{A, s}}
	\end{array}
\right.
$$

- $L$: Characteristic length. (e.g. the length of a flat plate)
- $V$: Velocity upstream of the surface.

The chart of boundary layer equations:

![[Pasted image 20230613164408.png]]

# Dimensionless Parameters

The chart above used many dimensionless parameters:

- $Nu$: [[Nusselt Number|Nusselt number]]
- $Sh$: [[Sherwood Number|Sherwood number]]

| Group                                 | Definition                                      | Interpretation                                                                                          |
| ------------------------------------- | ----------------------------------------------- | ------------------------------------------------------------------------------------------------------- |
| Biot number ($Bi$)                    | $$\frac{h L}{k_s}$$                             | Ratio of the internal thermal resistance of a solid to the boundary layer thermal resistance.           |
| Mass transfer Biot number ($Bi_m$)    | $$\frac{h_m L}{D_{AB}}$$                        | Ratio of the internal species transfer resistance to the boundary layer species transfer resistance.    |
| Bond number ($Bo$)                    | $$\frac{g(\rho_1 - \rho_v) L^2}{\sigma}$$       | Ratio of gravitational and surface tension forces.                                                      |
| Coefficient of friction ($C_f$)       | $$\frac{\tau_s}{\rho V^2 / 2}$$                 | Dimensionless surface shear stress.                                                                     |
| Eckert number ($Ec$)                  | $$\frac{V^2}{c_p (T_s - T_\infty)}$$            | Kinetic energy of the flow relative to the boundary layer enthalpy difference.                          |
| Fourier number ($Fo$)                 | $$\frac{\alpha t}{L^2}$$                        | Ratio of the heat conduction rate to the rate of thermal energy storage in a solid. Dimensionless time. |
| Mass transfer Fourier number ($Fo_m$) | $$\frac{D_{AB}t}{L^2}$$                         | Ratio of the species diffusion rate to the rate of species storage. Dimensionless time.                 |
| Friction factor ($f$)                 | $$\frac{\Delta p}{(L / D)(\rho u_m^2 / 2)}$$    | Dimensionless pressure drop for internal flow.                                                          |
| Grashof number ($Gr_L$)               | $$\frac{g \beta (T_s - T_\infty)L^3}{\nu^2}$$   | Measure of the ratio of buoyancy forces to viscous forces.                                              |
| Colburn $j$ factor ($j_H$)            | $$St Pr^{2/3}$$                                 | Dimensionless heat transfer coefficient.                                                                |
| Colburn $j$ factor ($j_m$)            | $$St_m Sc^{2/3}$$                               | Dimensionless mass transfer coefficient.                                                                |
| Jakob number ($Ja$)                   | $$\frac{c_p (T_s - T_{\rm sat})}{h_{fg}}$$      | Ratio of sensible to latent energy absorbed during liquid-vapor phase change.                           |
| Lewis number ($Le$)                   | $$\frac{\alpha}{D_{AB}}$$                       | Ratio of the thermal and mass diffusivities.                                                            |
| Nusselt number ($Nu_L$)               | $$\frac{hL}{k_f}$$                              | Ratio of convection to pure conduction heat transfer.                                                   |
| Peclet number ($Pe_L$)                | $$\frac{VL}{\alpha} = Re_L Pr$$                 | Ratio of advection to conduction heat transfer rates.                                                   |
| Prandtl number ($Pr$)                 | $$\frac{c_p \mu}{k} = \frac{\nu}{\alpha}$$      | Ratio of the momentum and thermal diffusivities.                                                        |
| Reynolds number ($Re_L$)              | $$\frac{VL}{\nu}$$                              | Ratio of the inertia and viscous forces.                                                                |
| Schmidt number ($Sc$)                 | $$\frac{\nu}{D_{AB}}$$                          | Ratio of the momentum and mass diffusivities.                                                           |
| Sherwood number ($Sh_L$)              | $$\frac{h_m L}{D_{AB}}$$                        | Dimensionless concentration gradient at the surface.                                                    |
| Stanton number ($St$)                 | $$\frac{h}{\rho V c_p} = \frac{Nu_L}{Re_L Pr}$$ | Modified Nusselt number.                                                                                |
| Mass transfer Stanton number ($St_m$) | $$\frac{h_m}{V} = \frac{Sh_L}{Re_L Sc}$$        | Modified Sherwood number.                                                                               |
| Weber number ($We$)                   | $$\frac{\rho V^2 L}{\sigma}$$                   | Ratio of inertia to surface tension forces.                                                             | 

- Assume there are two scenario.
	- If you can prove that $Re_1 = Re_2$ and $Pr_1 = Pr_2$, you can use the property that $Nu_1 = Nu_2$.

## Example: Dimensionless Parameters

Experiments have shown that, for airflow at $T_\infty = 35\degree \text C$ and $V_1 = 100\text{m/s}$, the rate of heat transfer from a turbine blade of characteristic length $L_1 = 0.15 \text m$ and surface temperature $T_{s, 1} = 300 \degree \text C$ is $q_1 = 1500 \text W$. What would be the heat transfer rate from a second turbine blade of characteristic length $L_2 = 0.3 \text m$ operating at $T_{s, 2} = 400 \degree \text C$ in airflow of $T_{\infty} = 35\degree \text C$ and $V_2 = 50 \text{m/s}$? The surface area of the blade may be assumed to be directly proportional to its characteristic length.

---

| Properties          | Scenario 1                         | Scenario 2                         |
| ------------------- | ---------------------------------- | ---------------------------------- |
| Substance           | Air                                | Air                                |
| Ambient Temperature | $$T_\infty = 35 \degree \text C$$  | $$T_\infty = 35\degree \text C$$   |
| Inlet Speed         | $$V_1 = 100\text{m/s}$$            | $$V_2 = 50 \text{m/s}$$            |
| Plate Length        | $$L_1 = 0.15 \text m$$             | $$L_2 = 0.3 \text m$$              |
| Surface Temperature | $$T_{s, 1} = 300 \degree \text C$$ | $$T_{s, 2} = 400 \degree \text C$$ |
| Heat Transfer       | $$q_1 = 1500 \text W$$             | $$q_2 = \ ?$$

If we can prove that $Re_1 = Re_2$ and $Pr_1 = Pr_2$, we can use the property that $Nu_1 = Nu_2$.

$$\begin{array}{l}
	Re_1 &=& 
	\displaystyle
	\frac{VL}{\nu} &=& 
	\displaystyle
	\frac{100 \times 0.15}{\nu} \\
	Re_2 &=&
	\displaystyle
	\frac{50 \times 0.3}{\nu} \\
	Pr_1 &=& Pr_2 && \because \text{both air, 35} \degree \text C
\end{array}$$

$$
\begin{array}{rrl}
	\implies & \overline{Nu}_1 &=& \overline{Nu}_2 \\
	\implies & 
	\displaystyle
	\frac{\overline h_1 L_1}{k_f} &=& 
	\displaystyle
	\frac{\overline h_2 L_2}{k_f} \\
	\implies & \overline h_2 &=& 
	\displaystyle 
	\frac 1 2 \overline h_1
\end{array}$$

$$
\begin{array}{rrll}
	& \displaystyle
	\frac{q_1}{
		A_1 (
			T_{\infty, 1} - T_{s, 1}
		)
	} \times \frac 1 2 &=& 
	\displaystyle
	\frac{q_2}{
		A_2 (
			T_{\infty, 2} - T_{s, 2}
		)
	} \\
	\implies &
	\displaystyle
	\frac{1500}{
		0.15 \times (35 - 300)
	}
	\times \frac 1 2 &=&
	\displaystyle
	\frac{q_2}{
		0.3 (35 - 400)
	} \\
	\implies & q_2 &=& \underline{
		2066.04 \text {
			(W)
		}
	}
\end{array}
$$

# Laminar and Turbulent Transition

![[Pasted image 20230613160831.png]]

For [[Laminar and Turbulent|laminar and turbulent]] transition, see [[Laminar and Turbulent#Flow through Plate]].

# Reynolds Analogy

Reynolds analogy can be used to relate velocity, thermal, and concentration boundary layers.

Original Reynolds analogy requires:

- $Pr \approx 1, Sc\approx 1$
- $dp^* / dx^* \approx 0$

and has the form:

$$\frac{C_f}{2} = St = St_m$$

> The restriction makes this not useful.
> We often use **modified Reynolds analogy**, as below. 

Modified Reynolds analogy is better, since it has larger restriction bound:

$$\frac{C_f}{2} = St Pr^{2/3} = j_H \qquad 0.6 < Pr < 60$$

$$\frac{C_f}{2} = St_m  Sc^{2/3} = j_m \qquad 0.6 < Sc < 3000$$

- $j_H, j_m$: Colburn j factors for heat or mass transfer.

## Example: Reynolds Analogy

A circuit board with a dense distribution of integrated circuits (ICs) and dimensions of $120 \text{mm} \times 120 \text{mm}$ on a side is cooled by the parallel flow of atmospheric air with a velocity of $2 \text{m/s}$.

From wind tunnel tests under the same flow conditions, the average frictional shear stress on the upper surface is determined to be $0.0625 \text{N/m}^2$. What is the allowable power dissipation from the upper surface of the board if the average surface temperature of the ICs must not exceed the ambient air temperature by more than $25\degree \text C$?

Evaluate the thermophysical properties of air at $300 \text K$.

---

- IC dimension: $120 \times 120 \text{mm}$
- air, $u_\infty = 2 \text{m/s}$, $T_\infty = 300 \text K$
- $\tau = 0.0625 \text{N/m}^2$
- If $T_s - T_\infty \leq 25 \degree \text C$, $q_s'$?

From chart, air@$300\text K$:

- $\rho = 1.1614 \text{(kg/m}^3 \text{)}$
- $c_p = 1.007 \text{(kJ/kg} \cdot \text{K)}$
- $\mu = 184.6 \times 10^{-7} \text{(N} \cdot \text{s/m}^2 \text{)}$
- $\nu = 15.89 \times 10^{-6} \text{(m}^2\text{/s)}$
- $k = 26.3 \times 10^{-3} \text{(W/m}\cdot \text{K)}$
- $\alpha = 22.5 \times 10^{-6} \text{(m}^2\text{/s)}$
- $Pr = 0.707$

$$
\begin{array}{l}
	& St &=& 
	\displaystyle
	\frac{h}{\rho V c_p} \\
	& &=& \displaystyle
	\frac{Nu_L}{Re_L Pr} \\
	\implies & St &=&
	\displaystyle
	\frac{h}{1.1614 \times 2 \times 1.007 \times 1000} \\
	& &=& 4.2752 \times 10^{-4} h
\end{array}
$$

$$
\begin{array}{l}
	C_f &=& 
	\displaystyle
	\frac{\tau_s}{\rho u_\infty^2 / 2} \\
	&=&
	\displaystyle
	\frac{0.0625}{1.1614 \times 2^2 / 2} \\
	&=& 0.02691
\end{array}
$$

$$
\begin{array}{l}
	& 
	\displaystyle
	\frac{0.02691}{2} = 
	4.2752 \times 10^{-4} h \times 0.707^{
		2/3
	} \\
	\implies & h = 39.6565 
\end{array}
$$

$$
\begin{array}{l}
	q_s' &=& hA (T_s - T_\infty) \\
	&=& 39.6565 \times 0.12^2 \times 25 \\
	&=& 14.2763 \text{(W)}
\end{array}
$$

# Reference

Fundamentals of Heat and Mass Transfer, 6th edition

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.