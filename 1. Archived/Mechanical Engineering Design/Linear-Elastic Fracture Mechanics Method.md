標籤: #Mechanical-Engineering-Design 

---

[TOC]

---

- Assumes that the material is isotropic and linear elastic.
- The plastic deformation at the tip of a crack is small.

Consider the stress to be fluctuating between the limits of $\sigma_{\rm min}$ and $\sigma_{\rm max}$, the stress intensity range per cycle is

$$\Delta K_I = \beta(\sigma_{\rm max} - \sigma_{\rm min})\sqrt{\pi a} = \beta\Delta \sigma\sqrt{\pi a}$$

We can get the rate of crack growth per cycle by constructing the following graph:

![[Pasted image 20221106174248.png]]

We can also construct crack growth rate versus stress intensity factor:

![[Pasted image 20221106174329.png]]

Assuming a crack is discovered early in region II, the crack growth in region II can be approximated by ==Paris equation==:

$$\frac{da}{dN} = C(\Delta K_I)^m$$

Integrating and substituting $\Delta K_I$:

$$\underline{
\int_0^{N_f} dN = 
N_f = 
\frac 1 C \int_{a_i}^{a_f}\frac{da}{(\beta \Delta \sigma\sqrt{\pi a})^m}}_\#$$

- $a_i$: initial crack length
- $a_f$: final crack length
- $N_f$: estimated number of cycles to produce a failure after the initial crack is formed.
- Note that $\beta$ may vary in the integration variable.

---

參考資料:

Mechanical Engineering Design, 11th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.