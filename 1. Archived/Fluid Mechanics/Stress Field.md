標籤: #fluid-mechanics 

---

[TOC]

---

There are two forces acting on fluid particles:

- Body forces (gravity, electromagnatic)

$$\vec F_B = \rho \vec g dV$$

- Surface forces (pressure, friction)
	- Normal stress
	$$\sigma_n = \lim_{\delta A_n \rightarrow 0} \frac{\delta F_n}{\delta A_n}$$
	- Shear stress
	$$\tau_n = \lim_{\delta A_n \rightarrow 0} \frac{\delta F_t}{\delta A_n}$$

We may represent these stresses using a matrix, this matrix is called ==stress field==.

$$\left[
	\begin{array}{}
		\sigma_{xx} & \tau_{xy} & \tau_{xz} \\
		\tau_{yx} & \sigma_{yy} & \tau_{yz} \\
		\tau_{zx} & \tau_{zy} & \sigma_{zx}
	\end{array}
\right]$$

---

參考資料:

Fluid Dynamics class

---

link:

[[Stress]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.