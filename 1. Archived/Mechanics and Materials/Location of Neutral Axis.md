標籤: #Mechanics-and-Materials 

---

![[Location of Neutral Axis 1.jpg]]

# $\sum F_x = 0$

$$\int_A \sigma_x dA = 0$$

> [[Stress - Strain Relationship of Bending]]:
> $$\sigma_x = -E \kappa y$$

$$-\int_A E \kappa y dA = 0$$

> $$E, \; \kappa \text{ is constant }$$

$$\int_A ydA = 0 \quad \text{ (First moment of area with respect to z-axis) }$$

# $\sum M_z = 0$

![[Location of Neutral Axis 2.jpg]]

$$dM + \sigma_x y dA = 0$$
$$dM = -\sigma_x y dA$$
$$M = -\int_A \sigma_x y dA$$

> From [[Stress - Strain Relationship of Bending]]:
> $$\sigma_x = -E \kappa y$$

$$M = \int_A E \kappa y^2 dA$$
$$ = E \kappa \underbrace{ \int_A y^2 dA }_{ 
I \equiv 
\begin{array}{}
\text{ Area Moment of Inertia } \\
\text{ (Second moment of area) }
\end{array}
}$$
$$M = E \kappa I \quad \text{ (Moment Curvature Relationship) }$$

> [[Beam Bending]]:
> $$\kappa = \frac{ 1 }{ \rho }$$

## [[Moment Curvature Relationship of Bending]]

$$\underline{ \kappa = \frac{ 1 }{ \rho } = \frac{ M }{ EI } }_{ \# }$$

- $EI$: [[Fluxtural Rigidity of Bending]]

---

參考資料:

Mechanics and Materials online course - coursera

---

link:

[[First Moment of Area]]