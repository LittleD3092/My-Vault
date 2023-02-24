標籤: #Thermodynamics #heat-transfer 

---

- 輻射
- transfer of heat due to electromagnetic waves
- All surfaces of finite temperature emit energy in this form.

# Stefan-Boltzmann Law

[[Stefan-Boltzmann Law]]

$$E_b = \sigma T_s^4$$

- $T_s$: Absilute temperature $(\rm K)$ of the surface.
- $\sigma$: Stefan-Boltzmann constant.
- $E_b$: Energy emitted from black body.

# For Real Surface

- For a surface, it absorbs and emits energy.
	- Emit: [[#Radiation]] $E$
	- Absorb: [[#Irradiation]] $G$

![[Pasted image 20230224153221.png]]

## Radiation

- The [[Stefan-Boltzmann Law]] is for [[Black Body]], an ideal radiator.
- The energy radiated by a realistic surface is the equation below:

$$E = \varepsilon \sigma T_s^4$$

- $T_s$: Absilute temperature $(\rm K)$ of the surface.
- $\sigma$: Stefan-Boltzmann constant.
- $\varepsilon$: Emissivity, a radiative property of the surface.
	- Range: $0 \leq \varepsilon \leq 1$.

## Irradiation

$$G_{\rm abs} = \alpha G$$

- $\alpha$: The portion of the irradiation absorbed by the surface.
	- $0 \leq \alpha \leq 1$
- $G$: Irradiation.
- $G_{\rm abs}$: Irradiation absorbed.

## With Surrounding Area

Taking surrounding area into account, we get

$$q_{\rm rad}'' = \frac q A = \varepsilon E_b (T_s) - \alpha G = \varepsilon \sigma (T_s^4 - T_{\rm sur}^4)$$

- $\varepsilon$: [[Surface Emissivity]] 表面放射率
- $\sigma$: Stefan Boltzmann Constant $5.67 \times 10^{ -8 } W/m^2K^4$
- $A$: [[Surface]] Area
- $T_s$: [[Surface]] Temperature
- $T_{\rm sur}$: Surrounding temperature.

---

參考資料:

熱力學 Ch3 OCW
Incropera's Principles of Heat and Mass Transfer

---

link:

