標籤: #Mechanical-Engineering-Design 

---

[TOC]

---

It turns out that the fatigue strength of a notched specimen is often not affected as much as would be expected from applying the stress-concentrated maximum stress.

Concequently, for fatigue purposes, a *fatigue stress-concentration factor* $K_f$ is defined.

$$K_f = \frac{\text{Fatigue strangth of notch-free specimen}}{\text{Fatigue strength of notched specimen}}$$

$$\sigma_{\rm max} = K_f\sigma_0 \qquad \tau_{\rm max} = K_{fs}\tau_0$$

# Notch Sensitivity

To quantify the sensitivity of materials to notches, a *notch sensitivity* $q$ is defined as follows. $q$ is usually between zero and $1$.

$$q = \frac{K_f - 1}{K_t - 1} \qquad \text{or} \qquad 
q_s = \frac{K_{fs} - 1}{K_{ts} - 1}$$

Notch sensitivities are obtained experimentally, and then solve for $K_f$ from the equation.

$$K_f = 1 + q(K_t - 1) \qquad \text{or} \qquad K_{fs} = 1 + q_s(K_{ts} - 1)$$

![[Pasted image 20221117231208.png]]

![[Pasted image 20221117231358.png]]

## Formula

Neuber and Kuhn describes the above diagrams as a function of the notch radius $r$ and a material characteristic length dimension $a$.

$$q = \frac{1}{\displaystyle 1 + \frac{\sqrt{a}}{\sqrt{r}}}$$

- $q$: Notch sensitivity.
- $a$: Material characteristic length dimension.
- $r$: Notch radius.
- $\sqrt{a}$: Neuber constant.

For convenience, we can combine the formula above with the representation of $K_f$.

$$K_f = 1 + \frac{K_t - 1}{\displaystyle 1 + \frac{\sqrt{a}}{\sqrt{r}}}$$

Neuber constant $\sqrt{a}$ is experimentally determined. For steels, it correlates with the ultimate strength, and can be represented with the following equations.

Bending or axial:

$$
\begin{array}{}
	\sqrt{a} = 0.246 - 3.08(10^{-3})S_{ut} +
	1.51(10^{-5})S_{ut}^2 - 2.67(10^{-8})S_{ut}^3 &
	50 \leq S_{ut} \leq 250 \text{ kpsi} \\
	\sqrt{a} = 1.24 - 2.25(10^{-3})S_{ut} + 
	1.60(10^{-6})S_{ut}^2 - 4.11(10^{-10})S_{ut}^3 & 340 \leq S_{ut} \leq 1700\text{ MPa}
\end{array}
$$

Torsion:

$$
\begin{array}{}
	\sqrt{a} = 0.190 - 2.51(10^{-3})S_{ut} + 1.35(10^{-5})S_{ut}^2 - 2.67(10^{-8})S_{ut}^3 & 50 \leq S_{ut} \leq 220 \text{ kpsi} \\
	\sqrt{a} = 0.958 - 1.83(10^{-3})S_{ut} + 1.43(10^{-6})S_{ut}^2 - 4.11(10^{-10})S_{ut}^3 & 340 \leq S_{ut} \leq 1500 \text{ MPa}
\end{array}$$

- $S_{ut}$: In kpsi or MPa.
- $\sqrt{a}$: In $(\text{inch})^{1/2}$ or $(\text{mm})^{1/2}$.

---

參考資料:

Mechanical Engineerign Design, 11th edition

---

link:



---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.