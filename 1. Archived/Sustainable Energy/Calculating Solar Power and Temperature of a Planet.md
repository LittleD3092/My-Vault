Tag: #sustainable-energy 
Previous: [[Green House Effect]]
Link: 

[TOC]

---

The solar power absorbed by the planet $P_{\rm absorbed}$ is given by: (<u>1</u>)

$$P_{\rm absorbed} = (1 - a)S\pi R^2$$

- $a$: Albedo, the fraction of radiation reflected.
- $S$: The radiation from the sun, in $\rm W/m^2$.
- $1 - a$: The fraction of radiation that is absorbed by the planet.
- $R$: The radius of the planet.
- $\pi R^2$: The "disk" area of a planet, which is exposed to the sun.

By [[Stefan-Boltzmann Law]], the power radiated into space $P_{\rm radiated}$ is: (<u>1</u>)

$$P_{\rm radiated} = 4\pi R^2\sigma T^4$$

- $R$: The radius of the planet.
- $4\pi R^2$: The surface area of the planet.
- $\sigma$: Stefan-Boltzmann constant, $5.67051 \times 10^{-8} \ \rm W \cdot m^{-2} \cdot K^{-4}$.
- $T$: The temperature of the planet.

When the temperature reaches equilibrium, the power radiated and the power absorbed must be equal $P_{\rm absorbed} = P_{\rm radiated}$. Solving for the 2 equations above: (<u>1</u>)

$$T = \left[
	\frac{(1 - a)S}{4\sigma}
\right]^{1/4}$$

- $a$: Albedo, the fraction of radiation reflected.
- $S$: The radiation from the sun, in $\rm W/m^2$.
- $\sigma$: Stefan-Boltzmann constant, $5.67051 \times 10^{-8} \ \rm W \cdot m^{-2} \cdot K^{-4}$.

# Example

The mean orbital diameter of Mars is $1.523$ times that of the earth. Calculate the mean surface temperature of Mars if its albedo is $0.25$ and there are no greenhouse effects. (<u>1</u>)

---

The solar flux at earth $S_{\rm earth} = 1.367 \rm kW/m^2$. Then at the distance of Mars it is:

$$S_{\rm Mars} = \frac{1.367 \rm kW/m^2}{(1.523)^2} = 0.589\rm kW/m^2$$

Using the equation of $T$, the temperature is calculated to be:

$$
\begin{array}{l}
	T &=& \displaystyle
	\left[
		\frac{(1 - a)S}{4\sigma}
	\right]^{1/4}
	\\
	&=&
	\displaystyle
	\left[
		\frac{
			(1 - 0.25) \times (589 {\rm W \cdot m^{-2}})
		}{
			4 \times 5.67051 \times 10^{-8} \rm W \cdot m^2 \cdot K^{-4}
		}
	\right]^{1/4} \\
	&=& 210 \rm K
\end{array}
$$

---

# Reference

1. “Chapter 4: Environmental Consequences of Fossil Fuel Use.” In Sustainable Energy, SI Edition, Second Edition. Cengage, n.d. Accessed November 1, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.