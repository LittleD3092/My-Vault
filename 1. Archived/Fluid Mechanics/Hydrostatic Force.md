標籤: #fluid-mechanics 

---

[TOC]

---

In order to determine completely the resultant force acting on a submerged surface, we must specify:

1. The [[#Magnitude]] of the force.
2. The [[#Direction]] of the force.
3. The [[#Line of Action]] of the force.

![[Pasted image 20221026220711.png]]

# Magnitude

The resultant force acting on the surface is found by summing the contributions of the infinitesimal forces over the entire area.

$$\underline{F_R = \int_ApdA}_\#$$

$$\text{or }\qquad \underline{ F_R = p_cA}_\#$$

- $p_c$: the absolute pressure in the liquid at the location of the centroid of area $A$.

# Line of Action

![[Pasted image 20221026222531.png]]

Our next task is to determine $(x', y')$, the location of the resultant force. Note that even though the force can be computed using the pressure at the center of the plate, this is *not* the point through which the force acts.

Taking the sum of the moments of the infinitesimal forces $dF$ about the $x$ axis we obtain

$$\underline{y' F_R = \int_A ypdA}_\#$$

$$\implies y'F_R = \int_AypdA = \int_Ay(p_0 + \rho gh)dA$$

$$= \int_A(p_0y + \rho gy^2\sin\theta)dA $$

$$= p_0\int_AydA + \rho g\sin\theta\int_Ay^2dA$$

The first integral is our familliar $y_cA$. The second integral is the [[Area Moment of Inertia|2nd moment area]] about the $x$ axis, $I_{xx}$. We can use the parallel axis theorem, $I_{xx} = I_{\hat x\hat x} + Ay_c^2$ to replace $I_{xx}$.

$$y'F_R = p_0y_cA + \rho g\sin\theta(I_{\hat x\hat x} + Ay_c^2)$$

$$ = y_c(p_0 + \rho g y_c\sin\theta)A + \rho g \sin\theta I_{\hat x\hat x}$$

$$ = y_c(p_0 + \rho g h_c)A + \rho g \sin\theta I_{\hat x\hat x}$$

$$ = y_cF_R + \rho g \sin \theta I_{\hat x\hat x}$$

Finally, we obtain for $y'$:

$$\underline{y' = y_c + \frac{\rho g\sin \theta I_{\hat x\hat x}}{F_R}
\qquad \text{for different ambient pressure on each side}}_\#$$

If we have the same ambient pressure acting on the other side of the surface we can neglect $p_0$ to compute the net force:

$$F_R = p_{c_{\rm gage}}A = \rho gh_cA = \rho g y_c \sin\theta A$$

And we substitude in the $y'$ above:

$$\underline{
	y' = y_c + \frac{I_{\hat x\hat x}}{Ay_c} \qquad
	\text{for same ambient pressure on both sides}
}_\#$$

A similar analysis can be done to compute $x'$:

$$\underline{x' F_R = \int_A xpdA}_\#$$

$$\underline{x' = x_c + \frac{\rho g\sin \theta I_{\hat x\hat y}}{F_R}
\qquad \text{for different ambient pressure on each side}}_\#$$

$$\underline{
	x' = x_c + \frac{I_{\hat x\hat y}}{Ay_c} \qquad
	\text{for same ambient pressure on both sides}
}_\#$$

# Direction

Of course, the direction is perpendicular to the plane.

# Curved Surface

![[Pasted image 20221027005645.png]]

The pressure force acting on the element of area, $d\vec A$, is given by

$$
d\vec F = -pd\vec A
$$

The resultant force is given by

$$\vec F_R = -\int_A pd\vec A$$

By investigating the horizontal force, we found out that the horizontal force and its location are the same as for an imaginary vertical plane surface of the same projected area.

$$\underline{F_H = p_c A}_\#$$

- $F_H$: Horizontal force.
- $p_c$: Absolute pressure at the location of the centroid of area $A$.
- $A$: A vertical plane surface of the same projected area.

With atmospheric pressure at the free surface and on the other side of the curved surface, the net vertical force will be equal to the weight of fluid directly above the surface.

$$\underline{F_V = \rho gV}_\#$$
![[Pasted image 20221027010750.png]]

---

參考資料:

Introduction to Fluid Mechanics, 10th edition

---

link:

[[Area Moment of Inertia]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.