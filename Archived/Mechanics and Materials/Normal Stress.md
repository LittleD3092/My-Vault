標籤: #Mechanics-and-Materials

---

$$\sigma = \frac{N}{A}$$

$\sigma$: normal stress
$N$: normal force
$A$: cross area

# Normal Stress on Inclined Plane

## with angle

![[Normal Stress on Inclined Plane.jpg]]

$$\sigma = \frac{N}{A}$$
.
$$\text{Calculate non-transverse cut area} \; A = \frac{A_t}{\cos\theta}$$
.
$$\text{Calculate normal force}\; N = A \sigma$$
$$ = \frac{\sigma A_t}{\cos\theta}$$
.
$$\text{From equilibrium, calculate normal stress}$$
$$N - P\cos \theta = 0$$
$$P\cos \theta = N = \frac{\sigma A_t}{\cos\theta}$$
$$\sigma = \underline{\frac{P\cos^2\theta}{A_t}}_{\#}$$
.
$$\underline{\sigma_{\text{max}}\;\text{occurs at}\; 0\degree,\; 180\degree}_{\#}$$

## with stress (x, y)

![[convert stresses to forces.png]]

$$\sigma_n\cancel{da} - (\sigma_x \cancel{dA}\cos\theta )\cos\theta - (\sigma_y\cancel{dA}\sin\theta)\sin\theta - (\tau_{xy}\cancel{dA}\cos\theta)\sin\theta - (\tau_{yx}\cancel{dA}\sin\theta)\cos\theta = 0$$

$$\sigma_n = \sigma_x\cos^2\theta + \sigma_y\sin^2\theta + 2\tau_{xy}\sin\theta\cos\theta$$

$$\sigma_n = \sigma_x\frac{1 + \cos 2\theta}{2} + \sigma_y\frac{1 - \cos2\theta}{2} + 2\tau_{xy}\frac{\sin2\theta}{2}$$
.
$$\sigma_n = \underline{\frac{\sigma_x + \sigma_y}{2} + \frac{\sigma_x - \sigma_y}{2}\cos2\theta + \tau_{xy}\sin2\theta}_{\#}$$

# Stress Invariant

$$\sigma_1 + \sigma_2 = \sigma_x + \sigma_y$$

The sum of the normal stresses on any two perpendicular (or orthogonal) planes is constant (or invariant).

---

參考資料:

[Mechanics and Materials - Fundamentals of Stress & Strain and Axial Loading - coursera](https://www.coursera.org/learn/mechanics-1/home/week/1)
[[Shear Stress]]