Tag: #heat-transfer 
Previous: [[Conduction]]
Link: 

[TOC]

---

- For deriving *temperature distribution*.
	- After we know temperature distribution, we may use [[Fourier's Law]] to compute heat flux.

**Important equations**:

| Name                                 | Equation                                                                                                                                                                                                                                                                                                                                                                                     |
| ------------------------------------ | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [[#General Form]]                    | $\displaystyle \frac{\partial}{\partial x}\left(k\frac{\partial T}{\partial x}\right) + \frac{\partial}{\partial y}\left( k \frac{\partial T}{\partial y}\right) + \frac{\partial}{\partial z}\left(k \frac{\partial T}{\partial z}\right) + \dot q = \rho c_p \frac{\partial T}{\partial t}$                                                                                                |
| [[#General Form]], with constant $k$ | $\displaystyle \frac{\partial^2 T}{\partial x^2} + \frac{\partial^2 T}{\partial y^2} + \frac{\partial^2 T}{\partial z^2} + \frac{\dot q}{k} = \alpha \frac{\partial T}{\partial t}$                                                                                                                                                                                                          |
| [[#General Form]], steady state      | $\displaystyle\frac{\partial}{\partial x} \left(k \frac{\partial T}{\partial x}\right) + \frac{\partial }{\partial y}\left(k \frac{\partial T}{\partial y}\right) + \frac{\partial }{\partial z}\left( k \frac{\partial T}{\partial z} \right) + \dot q = 0$                                                                                                                                 |
| Cylindrical Coordinates              | $\displaystyle \frac 1 r \frac{\partial}{\partial r} \left( kr \frac{\partial T}{\partial r} \right) + \frac{1}{r^2} \frac{\partial }{\partial \phi} \left( k \frac{\partial T}{\partial \phi} \right) + \frac{\partial }{\partial z}\left( k \frac{\partial T}{\partial z} \right) + \dot q = \rho c_p \frac{\partial T}{\partial t}$                                                       |
| Spherical Coordinates                | $\displaystyle \frac 1 {r^2}\frac{\partial }{\partial r} \left( kr^2 \frac{\partial T}{\partial r} \right) + \frac{1}{r^2 \sin \theta} \frac{\partial }{\partial \phi}\left(k\frac{\partial T}{\partial \phi}\right) + \frac{1}{r^2\sin\theta}\frac{\partial }{\partial \theta}\left(k\sin \theta \frac{\partial T}{\partial \phi}\right) + \dot q = \rho c_p \frac{\partial T}{\partial t}$ | 

- $\displaystyle \alpha = \frac{k}{\rho c_p}$: Thermal diffusivity.
- $k$: Thermal conductivity.

---

**Boundary and Initial Conditions** for simplifying the equation:

![[Pasted image 20230312160506.png|500]]

---

Reference:

Fundamentals of Heat and Mass Transfer, 6th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.