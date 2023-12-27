Tag: #sustainable-energy 
Previous: [[Betz's Law]]
Link: [[Bernoulli's Equations]]

[TOC]

---

Betz limit is the factor $16/27$ that is stated in the [[Betz's Law|Betz's law]]. A windmill can't extract more than this portion of kinetic energy from the wind. (<u>1</u>)

# Derivation of Betz limit

![[Pasted image 20231227211345.png]]

There are few equations below: (<u>2</u>)

- The power developed by the wind turbine.
- The volume flow continuity.
- The momentum change.
- Bernoulli's equation applied upstream.
- Bernoulli's equation applied downstream.

$$
\left\{
	\begin{array}{l}
		\text{Power} = (P_1 - P_2) A_t U_t & \text{(power)}\\
		A_uU_u = A_dU_d = A_tU_t & \text{(volume flow continuity)} \\
		(P_1 - P_2)A_t = \underbrace{\rho A_u U_u}_{\text{mass}} \cdot \underbrace{(U_u - U_d)}_{\text{velocity}} & \text{(momentum conservation)} \\
		\displaystyle
		P_\infty + \frac 1 2\rho U_u^2 = P_1 + \frac 1 2 \rho U_t^2 & \text{(Bernoulli's equation upstream)} \\
		\displaystyle
		P_\infty + \frac 1 2 \rho U_d^2 = P_2 + \frac 1 2 \rho U_t^2 & \text{(Bernoulli's equation downsream)}
	\end{array}
\right.
$$

- $P_1$: The ambient pressure of the air before entering the turbine.
- $P_2$: The ambient pressure of the air after entering the turbine.
- $A_t$: The area of the disc turbine.
- $U_t$: The speed of the wind passing through the turbine.
- $A_u$: The area of wind before.
- $U_u$: The speed of wind before.
- $A_d$: The area of wind after.
- $U_d$: The speed of wind after.

Starting from the subtraction of two Bernoulli's equations, and apply momentum conservation, then apply volume flow continuity: (<u>2</u>)

$$
\begin{array}{l}
	(P_1 - P_2) &=& 
	\displaystyle
	\frac 1 2 \rho(U_u^2 - U_d^2) & \text{(subtraction of 2 Bernoulli's equations)} \\
	&=& 
	\displaystyle
	\rho \frac{A_u}{A_t} U_u(U_u - U_d) & \text{(momentum conservation)} \\
	&=& \rho U_t(U_u - U_d) & \text{(volume flow continuity)}
\end{array}
$$

Using the equation above, power developed by the turbine, and momentum conservation, we can get the efficiency: (<u>2</u>)

$$\begin{array}{l}
	\eta &=& \displaystyle 
	\frac{\text{power}}{\displaystyle\frac 1 2 \rho A_t U_u^3} \\
	&=& \displaystyle
	\underline{\frac{1}{2}\left(1 - \frac{U_d}{U_u}\right)
	\left(1 + \frac{U_d}{U_u}\right)^2}
\end{array}$$

By differentiating the efficiency, we can find the maximum $\eta$ appears to be $16/27$, with $U_d / U_u = 1/3$.

---

# Reference

1. “Betz’s law,” Wikipedia. Oct. 21, 2023. Accessed: Dec. 27, 2023. [Online]. Available: https://en.wikipedia.org/w/index.php?title=Betz%27s_law&oldid=1181236850
2. “The Betz limit and the Maximum Efficiency for Horizontal Axis Wind Turbines - TheRoundup.” Accessed: Dec. 27, 2023. [Online]. Available: https://theroundup.org/betz-limit/

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.