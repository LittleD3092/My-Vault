標籤: #Mechanical-Engineering-Design 

---

[TOC]

---

Also known as ==DE theory==.

> *Yielding occurs when the distortion strain energy per unit volume reaches or exceeds the distortion strain energy per unit volume for yield in simple tension or compression of the same material.*

This theory claims that yielding was not a simple tensile or compressive phenomenon, but was related somehow to the angular distortion of the stressed element.

The stress state can be splitted into $\sigma_{av}$ and other stresses:

![[Pasted image 20221016210314.png]]

Where $\sigma_{av}$ is given by:

$$\sigma_{av} = \frac{\sigma_1 + \sigma_2 + \sigma_3}{3}$$

The above split process seperate pure volume change and angular distortion without volume change.

The strain energy is given by:

$$u = \frac 1 2 \varepsilon \sigma$$

$$\implies u = \frac{1}{2E} [\sigma_1^2 + \sigma_2^2 + \sigma_3^2 - 2\nu (\sigma_1\sigma_2 + \sigma_2\sigma_3 + \sigma_3\sigma_1)]$$

If we use $\sigma_{av}$, we can get strain energy for producing only volume change $u_v$:

$$\implies u_v = \frac{3\sigma_{av}^2}{2E}(1 - 2\nu)$$

$$\implies u_v = \frac{1 - 2\nu}{6E}(\sigma_1^2 + \sigma_2^2 + \sigma_3^2 + 2\sigma_1\sigma_2 + 2\sigma_2\sigma_3 + 2\sigma_3\sigma_1)$$

Thus the distortion energy $u_d$ can be given by:

$$u_d = u - u_v = \frac{1 + \nu}{3E}
\left[
	\frac{(\sigma_1 - \sigma_2)^2 + (\sigma_2 - \sigma_3)^2 + (\sigma_3 - \sigma_1)^2}
	{2}
\right]$$

For simple tensile test, at yield, $\sigma_1 = S_y$ and $\sigma_2 = \sigma_3 = 0$:

$$u_d = \frac{1 + \nu}{3E}S_y^2$$

Using above two equations, the first one should exceed second one to yield:

$$
\left[
	\frac{(\sigma_1 - \sigma_2)^2 + (\sigma_2 - \sigma_3)^2 + (\sigma_3 - \sigma_1)^2}
	{2}
\right]^{1/2} \geq S_y
$$

Therefore, we use $\sigma'$ to represent the expression on the left side, which is called von Mises stress.

$$\underline{\sigma' = 
\left[
	\frac{(\sigma_1 - \sigma_2)^2 + (\sigma_2 - \sigma_3)^2 + (\sigma_3 - \sigma_1)^2}
	{2}
\right]^{1/2}}_\#$$

The von Mises stress can be represented by principal stresses $\sigma_A$ and $\sigma_B$:

$$
\underline{
\sigma' = (\sigma_A^2 - \sigma_A\sigma_B + \sigma_B^2)^{1/2}
}_\#$$

Using $xyz$ components of three-dimensional stress, the von Mises stress can be written as:

$$
\underline{
\sigma' = \frac{1}{\sqrt 2}
[
	(\sigma_x - \sigma_y)^2 +
	(\sigma_y - \sigma_z)^2 +
	(\sigma_z - \sigma_x)^2 +
	6(\tau_{xy}^2 + \tau_{yz}^2 + \tau_{zx}^2)
]^{1/2}
}_\#
$$

For plane stress, only $xy$ components are used:

$$
\underline{
	\sigma' = 
	(\sigma_x^2 - \sigma_x\sigma_y + \sigma_y^2 + 3\tau_{xy}^2)^{1/2}
}_\#
$$

# Yield Envelope

![[Pasted image 20221019210515.png|400]]

---

參考資料:

Mechanical Engineering Design, 11th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.