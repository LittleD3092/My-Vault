標籤: #fluid-mechanics 

---

[TOC]

---

# Static Fluid

## Incompressible Liquids

We know from [[Fluid Statics]]:

$$
\frac{dp}{dz} = -\rho g \equiv -\gamma
$$

For an incompressible fluid, $\rho = \text{constant}$. Then for constant gravity:

$$\frac{dp}{dz} = -\rho g = \text{constnat}$$

To find out the pressure, we integrate both sides:

$$\int_{p_0}^p dp = -\int_{z_0}^z \rho gdz$$

Therefore we obtain ==the pressure for incompressible liquids==:

$$\underline{p - p_0 = \Delta p = \rho gh}_\#$$

## Gas

The density of gas depends on pressure and temperature. By the [[Ideal Gas]] equation:

$$p = \rho RT$$

and [[Fluid Statics]] equation:

$$\frac{dp}{dz} = -\rho g$$

Also, from US Standard Atmosphere the temperature decreases linearly with altitude up to an elevation of $11.0 \text{ km}$. This means $T = T_0 - mz$. We can get

$$dp = -\rho g dz = -\frac{pg}{RT}dz = -\frac{pg}{R(T_0 - mz)}dz$$

By [[Separable Variables]]:

$$\int_{p_0}^p \frac{dp}{p} = -\int_0^z\frac{gdz}{R(T_0 - mz)}dz$$

$$\implies \ln\frac{p}{p_0} = \frac{g}{mR}\ln\left(
	\frac{T_0 - mz}{T_0}
\right) = 
\frac{g}{mR}\ln\left(
	1 - \frac{mz}{T_0}
\right)$$

Therefore, in a gas whose temperature varies linearly with elevation, is given by

$$
\underline{
	p = p_0 \left(
		1 - \frac{mz}{T_0}
	\right)^{g/mR} = 
	p_0 \left(
		\frac{T}{T_0}
	\right)^{g/mR}
}_\#
$$

---

參考資料:

Introduction to Fluid Mechanics, 10th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.