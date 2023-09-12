標籤: #fluid-mechanics #heat-transfer 
link: [[Boundary Layer]]

---

[TOC]

---

# Basics

When you turn on a faucet at a very low rate, the water will flow out very smoothly. This is ==laminar==.
When you turn on a faucet at a very high rate, the water will flow out like a chaos. This is ==turbulent==.

![[Pasted image 20221001225819.png]]

A laminar flow is the flow which the fluid particles move in smooth layers. 
A turbulent flow is one in which the fluid particles rapidly mix as they move along due to random three-dimensional velocity fluctuations.

For example, when we design the pipe, we wish to have laminar flow because turbulent flow has greater friction.
But in the blood vessels case, we wish to have turbulant flow to randomly mix the blood and exchange oxygen and other nutrients.

- Laminar: [[Reynolds Number]] below 2300.
- Turbulent: [[Reynolds Number]] above 4000.

# Flow through Plate

## Position of Transition

![[Pasted image 20230613160831.png]]

- The flow goes through a transition and become turbulent.

The transition depends on [[Reynolds Number|Reynolds number]], which in this case is 

$$Re_x = \frac{\rho u_\infty x}{\mu}$$

- $x$: Characteristic length, the distance from the leading edge.
- $\rho$: Fluid density.
- $u_\infty$: Free flow speed.
- $\mu$: [[Viscosity]].
- The [[Reynolds Number|Reynolds number]] shows the ratio of the inertia to the viscous force.

The transition occurs at **critical** [[Reynolds Number|Reynolds number]], $Re_{x, c}$. An approximate number:

$$Re_{x, c} = \frac{\rho u_\infty x_c}{\mu} = 5 \times 10^5$$

## Effect of Transition

![[Pasted image 20230613162401.png]]

---

參考資料:

Introduction to Fluid Mechanics, 10th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.