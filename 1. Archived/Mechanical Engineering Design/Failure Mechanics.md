標籤: #Mechanical-Engineering-Design 

---

[TOC]

---

The foundation of fracture mechanics was first established by Griffith in 1921 using the stress field calculations for an elliptical flaw in a plate developed by Inglist in 1913.

For the infinite plate loaded by an applied uniaxial stress $\sigma$, the maximum stress occurs at $(\pm a, 0)$

![[Pasted image 20221028225359.png]]

and is given by

$$(\sigma_y)_{\rm max} = \left(
	1 + 2 \frac a b
\right) \sigma$$

# Crack Modes

Three distinct modes of crack propagation exist:

![[Pasted image 20221028225814.png|500]]

1. [[#Mode I]]: opening crack propagation mode
2. Mode II: sliding mode
3. Mode III: tearing mode

## Mode I

Consider a mode I crack of length $2a$ in the infinite plate

![[Pasted image 20221028230407.png|250]]

The stress field on a $dx \ dy$ element in the vicinity of the crack tip is given by

$$
\begin{array}{}
	\sigma_x & = & \sigma \sqrt{
		\displaystyle
		\frac{a}{2r}
	}\cos 
	\displaystyle
	\frac{\theta}{2}
	\left(
		1 - \sin\frac{\theta}{2}\sin\frac{3\theta}{2}
	\right) \\
	\sigma_y & = & \sigma \sqrt{
		\displaystyle
		\frac{a}{2r}
	}\cos 
	\displaystyle
	\frac{\theta}{2}
	\left(
		1 + \sin\frac{\theta}{2}\sin\frac{3\theta}{2}
	\right) \\
	\tau_{xy} & = & \sigma\sqrt{
		\displaystyle
		\frac{a}{2r}
	} \displaystyle
	\sin\frac{\theta}{2} \cos\frac \theta 2 \cos \frac{3\theta}{2} \\
	\sigma_z & = & \left\{
		\begin{array}{l}
			0 & \text{(for plane stress)} \\
			\nu(\sigma_x + \sigma_y) & \text{(for plane strain)}
		\end{array}
	\right.
\end{array}
$$

It is a common practice to define a factor $K$ called the ==stress intensity factor== given by

$$K_I = \sigma\sqrt{\pi a}$$

Thus the system of equations above can be rewritten as

$$
\begin{array}{}
	\sigma_x & = & \displaystyle
	\frac{K_I}{\sqrt{2\pi r}}\cos\frac \theta 2
	\left(
		1 - \sin\frac\theta 2\sin\frac{3\theta}{2} \\
	\right) \\
	\sigma_y & = & \displaystyle
	\frac{K_I}{\sqrt{2\pi r}}\cos\frac \theta 2
	\left(
		1 + \sin\frac\theta 2\sin\frac{3\theta}{2} \\
	\right) \\
	\tau_{xy} & = & \displaystyle
	\frac{K_I}{\sqrt{2\pi r}} \sin\frac \theta 2 \cos \frac \theta 2 \cos \frac{3\theta}{2} \\
	\sigma_z & = & \left\{
		\begin{array}{l}
			0 & \text{(for plane stress)} \\
			\nu(\sigma_x + \sigma_y) & \text{(for plane strain)}
		\end{array}
	\right.
\end{array}
$$

The stress intensity factor is a function of many factors. Therefore, for various load and geometric configurations, $K_I$ can be written as

$$K_I = \beta \sigma\sqrt{\pi a}$$

- $\beta$: ==stress intensity modification factor==. Can be obtained from tables or chart like this:
![[Pasted image 20221029005305.png]]

---

參考資料:

Mechanical Engineering Design, 11th edition

---

link:



---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.