Tag: #heat-transfer 
Previous: [[Conduction]]
Link: 

---

[TOC]

---

- The heat equation of [[Conduction]].
- Equation:
	- Heat rate: $\displaystyle q_x = -kA \frac{dT}{dx}$
	- Heat flux: $\displaystyle q_x'' = -k \frac{dT}{dx}$
		- $q_x''$: Heat flux. ${\rm W}/{\rm m^2}$.
		- $dT/dx$: Temperature gradient.
		- $k$: Thermal conductivity. ${\rm W/m \cdot K}$.

# For Steady State Conditions

Under steady state conditions, the temperature distribution is linear

$$\frac{dT}{dx} = \frac{T_2 - T_1}{L}$$

![[Pasted image 20230222193958.png]]

Therefore the heat flux can be simplified to

$$
\underline{q_x'' = k \frac{T_1 - T_2}{L} = 
k\frac{\Delta T}{L}}_\#
$$

---

參考資料:

Incropera's Heat and Mass Transfer

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.