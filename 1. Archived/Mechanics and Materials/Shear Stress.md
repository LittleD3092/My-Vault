標籤: #Mechanics-and-Materials #Mechanical-Engineering-Design 

---

$$\tau = \frac{V}{A}$$

$\tau$: shear stress
$V$: shear force
$A$: cross area

We often represent shear stress with subscript. For example, a shear stress that is on $y-z$ plane will be $\tau_{yz}$. Note that $\tau_{yz} = \tau_{zy}$ so the system can reach equilibrium.

# Shear Stress on Inclined Planes

## with angle

![[Shear Stress on Inclined Planes.jpg|200]]

$$\tau = \frac{V}{A}$$
.
$$\text{calculate non-transverse area}$$
$$A = \frac{A_t}{\cos\theta}$$
.
$$\text{calculate shear force}$$
$$V = A\tau$$
$$= \frac{A_t\tau}{\cos\theta}$$
.
$$\text{calculate shear stress}$$
$$V - P\sin\theta = 0$$
$$P\sin\theta = V = \frac{A_t\tau}{\cos\theta}$$
$$\tau = \frac{P\sin\theta\cos\theta}{A_t}$$
$$\tau = \underline{\frac{P\sin2\theta }{2A_t}}_{\#}$$
.
$$\underline{\tau_{\text{max}}\;\text{occurs at}\; 45\degree ,\; 135\degree}_{\#}$$

## with stress

![[convert stresses to forces.png]]

$$\tau_{nt}dA - (\tau_{xy}dA\cos\theta)\cos\theta + (\tau_{yx}dA\sin\theta)\sin\theta + (\sigma_xdA\cos\theta)\sin\theta - (\sigma_ydA\sin\theta)\cos\theta = 0$$

$$\tau_{nt} = -(\sigma_x - \sigma_y)\sin\theta\cos\theta + \tau_{xy}(\cos^2\theta - \sin^2\theta)$$

$$ = -(\sigma_x - \sigma_y)(\frac{\sin2\theta}{2}) + \tau_{xy}(\frac{1 + \cos2\theta}{2} - \frac{1 - \cos2\theta}{2})$$

$$\tau_{nt} = \underline{-(\frac{\sigma_x - \sigma_y}{2})\sin2\theta + \tau_{xy}\cos2\theta}_{\#}$$

---

參考資料:

[Mechanics and Materials - Fundamentals of Stress & Strain and Axial Loading - coursera](https://www.coursera.org/learn/mechanics-1/home/week/1)