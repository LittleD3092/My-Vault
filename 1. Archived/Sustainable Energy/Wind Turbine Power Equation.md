Tag: #sustainable-energy 
Previous: [[Sustainable Energy]]
Link: 

[TOC]

---

The equation that calculates the power of the turbine: (<u>1</u>)

$$P = (0.602 \text{kg/m}^3)\eta A v^3$$

- $P$: Power in Watts.
- $0.602 \text{kg/m}^3$: The density of the air.
- $\eta$: The efficiency.
- $A$: The area of the turbine in $\text{m}^2$.
- $v$: The speed of wind in $\text{m/s}$.

# Example

## 1

The construction of a wind turbine with an efficiency of $40\%$ is planned. It is anticipated that the turbine will produce $1\text{ MW}$ in a wind of $10 \text{ m/s}$. What is the diameter? (<u>2</u>)

---

Using the equation of the power of the turbine:

$$
\begin{array}{rrl}
	& P &=& 0.602 \cdot \eta A v^3 \\
	\implies & 1,000,000 & = & 
	\displaystyle
	0.602 \cdot 0.4 \cdot \frac{d^2}{4}\pi \cdot 10^3 \\
	\implies & d &=& 72.7155 \text{ m}
\end{array}
$$

## 2

A wind farm is constructed from turbines with a rotor diameter of $50\text{ m}$ and $40\%$ efficiency that are spaced at a distance of $500\text{ m}$ apart in the prevailing downwind direction $150 \text{ m}$ apart in the crosswind direction. In a wind of $10\text{ m/s}$ what is the output of the wind farm per $\text{km}^2$? (<u>2</u>)

---

There are:

$$
\begin{array}{l}
	n &=& \displaystyle 
	\frac{1 \text{ km}}{500 \text{ m}} \times \frac{1 \text{ km}}{150 \text{ m}} \\
	&=& 2 \times 6.67 \\
	&=& 13.33
\end{array}
$$

approximately 14 wind turbines in the $1 \text{ km}^2$ field.

Calculating the power of one turbine:

$$
\begin{array}{rrl}
	& P &=& 0.602 \cdot \eta A v^3 \\
	\implies & P &=& 
	\displaystyle
	0.602 \cdot 0.4 \cdot \frac{50^2}{4}\pi \cdot 10^3 \\
	\implies & P &=& 473 \text{ kW}
\end{array}
$$

Multiply to get the total power:

$$P_{\text{total}} = 473\text{ kW} \cdot 14 = 6.62\text{ MW}$$

---

# Reference

1. R. A. Dunlap, “10.3 Obtaining Energy from the Wind,” in Sustainable Energy, 2nd Edition, 2nd Edition., Cengage, 2017.
2. “Energy Technology: Final Exam (2022/1/6).” Jan. 06, 2022.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.