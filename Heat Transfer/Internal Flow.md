Tag: #heat-transfer 
Previous: [[Heat Transfer]]
Link: 

[TOC]

---

# Reynolds Number

For a flow in a tube, the Reynolds number can be calculated by:

$$Re_D = \frac{\rho u_m D}{\mu} = \frac{u_m D}{\nu}$$

- $u_m$: Mean fluid velocity over the tube cross section.
- $D$: Tube diameter.

The critical Reynolds number is:

$$Re_{D, c} = 2300$$

> Larger Reynolds numbers $Re_{D} \approx 10000$ are needed to achieve fully turbulent conditions.

# Mean Velocity

The mean velocity provides the rate of mass through the tube:

$$\dot m = \rho u_m A_c$$

# Friction Factor

When determining the pressure drop, it is convenient to work with Moody friction factor $f$.

For fully developed laminar flow:

$$f = \frac{64}{Re_D}$$

For fully developed turbulent flow:

$$\frac{1}{
	\sqrt f
} = -2.0 \log \left[
	\frac{e / D}{3.7} + 
	\frac{2.51}{
		Re_D \sqrt{f}
	}
\right]$$

# Mean Temperature

We are interested in the heat $q = c_p \dot m (T_{\rm out} - T_{\rm in})$, and the $T_{\rm in}$, $T_{\rm out}$ should be mean temperature for our convenience.

Therefore, the definition of mean temperature $T_m$ should be of the same form:

$$\dot m c_p T_m = \int_{A_c} \rho u c_p T dA_c$$

or

$$T_m = \frac{
	\int_{A_c} \rho u c_p T dA_c
}{\dot m c_p}$$

---

# Reference

Incropera's Principles of Heat and Mass Transfer

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.