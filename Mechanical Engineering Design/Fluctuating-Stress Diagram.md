標籤: #Mechanical-Engineering-Design 

---

[TOC]

---

Recall that in [[Stress-Life Method]], we define that a constant amplitude loading has mean stress $\sigma_m$ and alternating stress $\sigma_a$.

![[Pasted image 20221116135240.png]]

To display the fluctuating-stress data, we use $\sigma_a-\sigma_m$ to plot a diagram. This is the **fluctuating-stress diagram**.

![[Pasted image 20221211104830.png]]

- Taking sets of $(\sigma_m, \sigma_a)$ of same value of life $N$, we have *constant-life curves*.
- We use a straight line between endurance limit $S_e$ and ultimate strength $S_{ut}$ to represent *infinite life boundary*.
	- It is called **Goodman line**.
	- The equation is $\displaystyle \frac{\sigma_a}{S_e} + \frac{\sigma_m}{S_{ut}} = 1$.
- Factor of safety is defined by $\displaystyle \frac{\ \overline{OB}\ }{\overline{OA}}$.
	- Applying fatigue life design factor $n_f$, 
		- Goodman line has an equation: $$\displaystyle \frac{n_f \sigma_a}{S_e} + \frac{n_f \sigma_m}{S_{ut}} = 1$$
		- The factor $n_f$ is: $$\displaystyle n_f = \left(\frac{\sigma_a}{S_e} + \frac{\sigma_m}{S_{ut}}\right)^{-1} \qquad \sigma_m \geq 0$$

We may want to take compression into account. The compressive mean stress is not detrimental to fatigue life, so the Goodman line becomes:

![[Pasted image 20221211110856.png]]

Also, we consider yield stress, and plot the yield lines. The lines are called **Langer lines**.

![[Pasted image 20221211111223.png]]

# Fatigue Failure Criteria

We saw how to draw Goodman line above. However, there are many options other than Goodman line for various purposes.

![[Pasted image 20221211112056.png]]

## Goodman

- Simple, conservative and good for design purposes.
- It is only applicable for positive mean stress, because it is *not conservative for negative mean stress*.

$$
\begin{array}{l}
	\text{Failure criterion: } & 
	\displaystyle
	\frac{\sigma_a}{S_e} + \frac{\sigma_m}{S_{ut}} = 1 \\
	\text{Design equation: } & 
	\displaystyle
	n_f = 
	\left(
		\frac{\sigma_a}{S_e} + \frac{\sigma_m}{S_{ut}}
	\right)^{-1} & 
	\sigma_m \geq 0
\end{array}
$$

## Morrow

- Identical to [[#Goodman]].
- Replace ultimate strength with true fracture strength $\tilde\sigma_f$ or the fatigue strength coefficient $\sigma_f'$.
- Disadvantage: $\tilde\sigma_f$ and $\sigma_f'$ can be hard to find.

For steels ($\text{HB}\leq 500$),

$$\sigma_f' = S_{ut} + 50 \text{ kpsi}
\qquad \text{or} \qquad 
\sigma_f' = S_{ut} + 345\text{ MPa}$$

The equations for the Morrow criterion are

$$
\begin{array}{l}
	\text{Failure criterion: } &
	\displaystyle
	\frac{\sigma_a}{S_e} + \frac{\sigma_m}{\tilde \sigma_f} = 1 & 
	\text{or} &
	\displaystyle 
	\frac{\sigma_a}{S_e} + \frac{\sigma_m}{\sigma_f'} = 1 \\
	\text{Design equation: } &
	\displaystyle
	n_f = 
	\left(
		\frac{\sigma_a}{S_e} +
		\frac{\sigma_m}{\tilde\sigma_f}
	\right)^{-1} &
	\text{or} &
	\displaystyle
	n_f = 
	\left(
		\frac{\sigma_a}{S_e} +
		\frac{\sigma_m}{\sigma_f'}
	\right)^{-1}
\end{array}
$$

## Gerber

- A parabolic equation to better pass through the middle of the fatigue points.
- Fits the data better than [[#Goodman]].
- Slightly nonconservative.
- Only applies to positive mean stress. Too conservative if applied to negative mean stress.

$$
\begin{array}{l}
	\text{Failure criterion: } &
	\displaystyle
	\frac{\sigma_a}{S_e} +
	\left(
		\frac{\sigma_m}{S_{ut}}
	\right)^2 = 1 \\
	\text{Design equation: } &
	\displaystyle
	n_f = \frac 1 2 
	\left(
		\frac{S_{ut}}{\sigma_m}
	\right)^2
	\left(
		\frac{\sigma_a}{S_e}
	\right)
	\left[
		-1 +
		\sqrt{
			1 +
			\left(
				\frac{2\sigma_m S_e}{S_{ut}\sigma_a}
			\right)^2
		}
	\right] &
	\sigma_m \geq 0
\end{array}
$$

## Soderberg

- Replace the ultimate strength in [[#Goodman]] with the yield strength.
- Makes the line *ultra-conservative*.
- Provide a simple, conservative line that *checks for infinite-life fatigue and yielding at the same time*.

$$
\begin{array}{l}
	\text{Failure criterion: } &
	\displaystyle
	\frac{\sigma_a}{S_e} +
	\frac{\sigma_m}{S_y} = 1 \\
	\text{Design equation: } &
	\displaystyle
	n = 
	\left(
		\frac{\sigma_a}{S_e} +
		\frac{\sigma_m}{S_y}
	\right)^{-1} &
	\sigma_m \geq 0
\end{array}
$$

## ASME-Elliptic



---

參考資料:

Mechanical Engineering Design, 11th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.