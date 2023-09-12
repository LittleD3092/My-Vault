Tag: #list #heat-transfer 
Previous: [[Heat Transfer]]
Link: [[Boundary Layer]]

[TOC]

---

# Flat Plate in Parallel Flow

## Laminar, Isothermal

Assume 

- Steady
- Incompressible
- Laminar
- Constant fluid properties
- Negligible viscous dissipation
- $dp / dx = 0$

The [[Boundary Layer|boundary layer]] equations reduce to

| Name       | Equation                                                                                                                       |
| ---------- | ------------------------------------------------------------------------------------------------------------------------------ |
| Continuity | $$\frac{\partial u}{\partial x} + \frac{\partial v}{\partial y} = 0$$                                                          |
| Momentum   | $$u \frac{\partial u}{\partial x} + v \frac{\partial u}{\partial y} = v \frac{\partial ^2 u}{\partial y^2}$$                   |
| Energy     | $$u \frac{\partial T}{\partial x} + v \frac{\partial T}{\partial y} = \alpha \frac{\partial ^2 T}{\partial y^2}$$              |
| Species    | $$u \frac{\partial \rho_A}{\partial x} + v \frac{\partial \rho_A}{\partial y} = D_{AB}\frac{\partial^2 \rho_A}{\partial y^2}$$ | 

And the boundary layer thickness is

$$
\delta = \frac{5.0}{
	\sqrt{u_\infty / \nu x}
} = \frac{5x}{
	\sqrt{Re_x}
}$$

The local friction coefficient is

$$
C_{f, x} = \frac{
	\tau_{s, x}
}{
	\rho u_\infty^2 / 2
} = 0.664 Re_x^{-1 / 2}
$$

The local Nusselt number is

$$
Nu_x = \frac{h_x x}{k} = 0.332 Re_x^{1/2} Pr^{1/3} \qquad Pr \geq 0.6
$$

The local Sherwood number is

$$
Sh_x = \frac{h_{m, x} x}{D_{AB}} = 
0.332 Re_x^{1/2} Sc^{1/3} \qquad Sc \geq 0.6
$$

The average friction coefficient is

$$\overline C_{f, x} = 1.328 Re_x^{-1/2}$$

The average Nusselt number is

$$\overline{Nu}_x = \frac{\overline h_x x}{k} = 
0.664 Re_x^{1/2} Pr^{1/3} \qquad Pr \geq 0.6$$

The average Sherwood number is

$$\overline{Sh} = \frac{\overline h_{m, x}x}{D_{AB}} = 0.664 Re_x^{1/2} Sc^{1/3} \qquad Sc \geq 0.6$$

For Peclet number $Pe_x$ greater than 100, the Nusselt number can be obtained from

$$Nu_x = \frac{0.3387 Re_x^{1/2}Pr^{1/3}}{[1 + (0.0468 / Pr)^{2/3}]^{1/4}}$$

## Turbulent, Isothermal

The local friction coefficient can be obtained by the following with 15% accuracy:

$$C_{f, x} = 
0.0592 Re_x^{-1/5} \qquad
Re_{x, c} \leq Re_x \leq 10^8$$

The velocity boundary may be expressed as

$$\delta = 0.37 x Re_x^{-1/5}$$

The local Nusselt number:

$$Nu_x = St Re_x Pr = 0.0296 Re_x^{4/5} Pr^{1/3} \qquad
0.6 \leq Pr \leq 60$$

The local Sherwood number:

$$Sh_x = St_m Re_x Sc = 0.0296 Re_x^{4/5} Sc^{1/3} \qquad
0.6 \leq Sc \leq 3000$$

## Mixed, Isothermal

The Nusselt number:

$$\overline {Nu}_L = (0.037 Re_L^{4/5} - A)Pr^{1/3} \qquad
\left[
	\begin{array}{}
		0.6 \leq Pr \leq 60 \\
		Re_{x, c} \leq Re_L \leq 10^8
	\end{array}
\right]$$

The friction coefficient:

$$
\overline C_{f, L} = 0.074 Re_L^{-1/5} - 
\frac{2A}{Re_L} \qquad [Re_{x, c} \leq Re_L \leq 10^8]
$$

The Sherwood number:

$$
\overline{Sh}_L = (0.037 Re_L^{4/5} - A)Sc^{1/3} \qquad
\left[
	\begin{array}{}
		0.6 \leq Sc \leq 60 \\
		Re_{x, c} \leq Re_L \leq 10^8
	\end{array}
\right]
$$

## Unheated Started Length

By "unheated started length", there is a distance that the plate isn't heated ($T_s = T_\infty$).

![[Pasted image 20230613203550.png]]

For laminar flow, the Nusselt number is

$$Nu_x = \frac{
	\left. 
		Nu_x 
	\right\vert_{\xi = 0}
}{
	[
		1 - (\xi / x)^{3/4}
	]^{1/3}
}$$

For turbulent flow, the Nusselt number is

$$
Nu_x = \frac{
	\left. 
		Nu_x
	\right\vert_{\xi = 0}
}{
	[1 - (\xi / x)^{9/10}]^{1/9}
}
$$

## Constant Heat Flux

There is also a case that a plate has a uniform surface heat flux.

For laminar flow, the Nusselt number is:

$$
Nu_x = 0.453 Re_x^{1/2}Pr^{1/3} \qquad Pr \geq 0.6
$$

For turbulent flow, the Nusselt number is:

$$
Nu_x = 0.0308 Re_x^{4/5} Pr^{1/3} \qquad 0.6 \leq Pr \leq 60
$$

The average Nusselt number is:

$$
\overline{Nu}_L = 
0.680 Re_L^{1/2} Pr^{1/3}
$$

# Cylinder in Cross Flow

![[Pasted image 20230613205136.png]]

The Nusselt number is:

$$\overline{Nu}_D = \frac{\overline h D}{k} = C Re_D^m Pr^{1/3} \qquad Pr \geq 0.7$$

![[Pasted image 20230613210330.png|300]]

![[Pasted image 20230613210342.png|500]]

The Nusselt number can also be obtained by:

$$
\begin{array}{}
	\overline{Nu}_D = 0.3 + 
	\frac{
		0.62 Re_D^{1/2} Pr^{1/3}
	}{
		[1 + (0.4 / Pr)^{2/3}]^{1/4}
	}
	\left[
		1 + \left(
			\frac{Re_D}{282000}
		\right)^{5/8}
	\right]^{4/5} \\ 
	Re_D Pr \geq 0.2
\end{array}
$$

# Sphere

The Nusselt number:

$$
\begin{array}{}
	\displaystyle
	\overline{Nu}_D = 2 + (
		0.4 Re_D^{1/2} + 0.06 Re_D^{2/3}
	) Pr^{0.4}
	\left(
		\frac{\mu}{\mu_s}
	\right)^{1/4} \\
	\left[
		\begin{array}{}
			0.71 \leq Pr \leq 380 \\
			3.5 \leq Re_D \leq 7.6 \times 10^4 \\
			1.0 \leq (\mu / \mu_s) \leq 3.2
		\end{array}
	\right]
\end{array}
$$

# Bank of Tubes

![[Pasted image 20230613211425.png]]

There are two kinds of arrangement:

![[Pasted image 20230613211552.png]]

The Nusselt number is given by

$$
\begin{array}{}
	\overline{Nu}_D = 1.13 C_1 Re_{D, \rm max}^m Pr^{1/3} \\
	\left[
		\begin{array}{}
			N_L \geq 10 \\
			2000 \leq Re_{D, max} \leq 40000 \\
			Pr \geq 0.7
		\end{array}
	\right]
\end{array}
$$

Where $C_1$ and $m$ are listed in table below, and 

$$Re_{D, \rm max} = \frac{\rho V_{\rm max} D}{\mu}$$

![[Pasted image 20230613212011.png]]

Another correlation for Nusselt number:

$$
\begin{array}{}
	\displaystyle
	\overline {Nu}_D = 
	C Re_{D, \rm max}^m Pr^{0.36} \left(
		\frac{Pr}{Pr_s}
	\right)^{1/4} \\
	\left[
		\begin{array}{}
			N_L \geq 20 \\
			0.7 \leq Pr \leq 500 \\
			1000 \leq Re_{D, \rm max} \leq 2 \times 10^6
		\end{array}
	\right]
\end{array}
$$

---

# Reference

Fundamentals of Heat and Mass Transfer, 6th edition

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.