標籤: #Mechanics-and-Materials 

---

# Symmetric

> ![[Full Plastic, Symmetric.jpg]]
> $$\sigma_y = 410 \text{ MPa }$$
> $$\varepsilon_y = 0.002 \text{ mm/mm }$$
> (a) max elastic moment
> (b) $\varepsilon = 3250 \mu \text{ mm/mm }$ on top of beam, applied moment?
> (c) maximum moment of fully plastic

$$\text{ neutral axis: through center (because symmetry) }$$

.

use whole rectangle minus two small rectangle:
$$\text{ area moment of inertia } (I) = \frac{ 1 }{ 12 } (200) (325)^3 - 2\left[ \frac{ 1 }{ 12 } (93.75) (300)^3 \right] = 150 \times 10^6 \text{ mm }^4$$
![[up minus down.jpg|200]]

## (a) max elastic moment

Maximum Stress:
$$\sigma_{ \text{ max } } = \frac{ Mc }{ I }$$
$$410 \times 10^6 = \frac{ M \cdot 0.1625 }{ 150 \times 10^6 \times 10^{ -12 } }$$
$$M = \frac{ 410 \times 10^6 \times 150 \times 10^6 \times 10^{ -12 } }{ 0.1625 } = \underline{ 378461.54 \text{ (N } \cdot \text{ m) } }_{ \# }$$

## (b) $\varepsilon = 3250 \mu \text{ mm/mm }$ on top of beam, applied moment

$$\because 3250 \mu \text{ mm/mm } > \epsilon_y$$

![[plastic elastic beam.jpg]]

find where 0.002 occurs:
$$\frac{ 0.002 }{ 0.00325 } = \frac{ r }{ 162.5 }$$
$$\implies r = \frac{ 0.002 \times 162.5 }{ 0.00325 } = 100 \text{ mm }$$

![[Elastic and Plastic Stress Beam.jpg]]

Calculate Force:

![[Different Portion of beam.jpg]]

上圖分別是 $F_1$, $F_2$, $F_3$ 作用的位置

$$
\left\{
\begin{array}{l}
F_1 = 410 N/mm^2 \cdot (12.5 mm) \cdot 200 mm = 1025000 N \\
F_2 = 410 N/mm^2 (12.5 mm) 50 mm = 256250 N \\
F_3 = \frac{ 1 }{ 2 } \cdot 410 N/mm^2 \cdot 12.5 mm \cdot 100 mm = 256250 N
\end{array}
\right.
$$

Calculate Applied Moment:
$$M = (F_1 \cdot 156.25 mm + F_2 \cdot 125 mm + F_3 \cdot (\frac{ 2 }{ 3 } \cdot 100 mm)) \cdot 2 = \underline{ 418542 N \cdot m }_{ \# }$$

## (c) max moment of fully plastic

![[max moment of fully plastic.jpg]]

$$F_1 = 410 \times 10^6 \times (200 \times 12.5 \times 10^6) = 1025000 N$$
$$F_2 = 410 \times 10^6 \times (150 \times 12.5 \times 10^6) = 768750 N$$
$$M = \left( F_1 \times (156.25 \times 10^{ -3 }) + F_2 \times (75 \times 10^{ -3 }) \right)\cdot 2 = 435625 N \cdot m$$

---

# Not Symmetric

> ![[Not Symmetric Example.jpg]]
> $$\sigma_y = 250 MPa$$
> $$\varepsilon_y = 0.001 mm/mm$$
> (a) max elastic moment
> (b) max fully plastic moment

## (a) max elastic moment

locate neutral axis:
$$\frac{ (150 \times 50) \times 175 + (150 \times 50) \times 75 }{ 150 \times 50 + 150 \times 50 } = 125 mm \qquad \text{ (from bottom) }$$

moment of inertia:
$$
\begin{array}{l}
I & = & \sum \frac{ 1 }{ b h^3 } + A d^2 \\
& = & \frac{ 1 }{ 12 } \cdot (150 \times 10^{ -3 }) \times (50 \times 10^{ -3 })^3 + (150 \times 50 \times 10^{ -6 }) \cdot (50 \times 10^{ -3 })^2 \\
& & + \frac{ 1 }{ 12 } \cdot (50 \times 10^{ -3 }) \times (150 \times 10^{ -3 })^3 + (150 \times 50 \times 10^{ -6 }) \cdot (50 \times 10^{ -3 })^2 \\
& = & 53.125 \times 10^{ -6 } (m^4)
\end{array}
$$

max elastic moment:
$$\sigma_{max} = \frac{ Mc }{ I } \implies 250 \times 10^6 = \frac{ M \cdot 0.125 }{ 53.125 \times 10^{ -6 } } \implies M = 106250 N \cdot m$$

## (b) max fully plastic moment

for fully plastic, the area above the neutral axis is equal to the area below the neutral axis.

![[area above na is equal to below na.jpg]]

$$M = 1875000 \times 25 + 1875000 \times 75$$
$$ = 187500000 ( N \cdot mm ) = \underline{ 187500 ( N \cdot m ) }_{ \# }$$

---

參考資料:

Mechanics and Materials online course - coursera

---

link:

[[Plastic and Elastic of Bending]]
[[Area Moment of Inertia]]
[[Elastic Formula of Beam Bending]]
[[Location of Neutral Axis]]