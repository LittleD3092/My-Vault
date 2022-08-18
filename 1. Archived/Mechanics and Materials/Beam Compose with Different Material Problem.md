標籤: #Mechanics-and-Materials 

---

# Solution Step

1. get $n$, $A_{ semicircular }$, $\bar{ y }_{ semicircular }$
2. get neutral axis $$\bar{ y }_{ composite } = \frac{ \sum nA \bar{ y } }{ \sum nA }$$
3. get $I$ for each material $$I = n(I_{ semicircle } + A_{ semicircle } d^2)$$
4. calculate maximum stress $$\sigma = \frac{ nMy }{ I }$$

# Example 4.57

> The composite beam shown is formed by bonding together a brass rod and an aluminum rod of semicircular cross sections. The modulus of elasticity $E_{ brass }$ is $100GPa$ and $E_{ aluminum }$ is $70GPa$. The beam is bent about a horizontal axis $M = 900N\cdot m$, determine $\sigma_{ max }$ in 
> (a) brass 
> (b) aluminum
> ![[Mechanics and Materials Beam composed with different materials.jpg]]
> $$r = 20mm$$

$$E_{ brass } = 100GPa$$
$$E_{ aluminum } = 70GPa$$
$$M = 900N\cdot m$$

## step 1 get $n$, $A_{ semicircular }$, $\bar{ y }_{ semicircular }$

$$n = \frac{ E_{ brass } }{ E_{ aluminum } } = \frac{ 10 }{ 7 }$$

$$A_{ semicircular } = \frac{ \pi }{ 2 } \times 0.02^2 = 6.2832 \times 10^{ -4 }$$

$$\bar{ y }_{ semicircular } = \frac{ 4 }{ 3\pi } \times 0.02 = 8.4883 \times 10^{ -3 }$$

## step 2 get neutral axis and $I$

$$nA(brass) = \frac{ 10 }{ 7 } \times 6.2832 \times 10^{ -4 } = 8.976 \times 10^{ -4 }(m^2)$$

$$nA(aluminum) = 6.2832 \times 10^{ -4 }(m^2)$$

$$\bar{ y }_{ composite } = \frac{ \sum nA \bar{ y } }{ \sum nA }$$

$$ = \frac{ 8.976 \times 10^{ -4 } \times 8.4883 \times 10^{ -3 } + 6.2832 \times 10^{ -4 } \times (-8.4883 \times 10^{ -3 }) }{ 8.976 \times 10^{ -4 } + 6.2832 \times 10^{ -4 } }$$

$$ = 1.4979 \times 10^{ -3 }(m)$$

$$I_{ semicircle } = \frac{ \pi }{ 8 } \times 0.02^4 = 6.2832 \times 10^{ -4 }(m^4)$$

## step 3, step 4

### (a) brass

$$
\left\{
	\begin{array}{l}
		\sigma = -\frac{ nMy }{ I } = -\frac{ \frac{ 10 }{ 7 } \times 900 \times 0.018502 }{ 1.3362 \times 10^{ -7 } } = -178.03 \times 10^{ 6 }(Pa) = \underline{ -178.03(MPa) }_{ \# } \\
		n = \frac{ 10 }{ 7 } \\
		M = 900 \\
		y = 0.02 - 1.4979 \times 10^{ -3 } = 0.018502(m) \\
		I = n(I_{ semicircle } + A_{ semicircle }d^2) = 1.3362 \times 10^{ -7 }(m^4) \\
		d = \bar{ y }_{ semicircle } - \bar{ y }_{ composite } = 6.9904 \times 10^{ -3 }(m)
	\end{array}
\right.
$$

### (b) aluminum

$$
\left\{
	\begin{array}{l}
		\sigma = -\frac{ nMy }{ I } = 154.18 \times 10^6(Pa) = \underline{ 154.18(MPa) }_{ \# } \\
		n = 1 \\
		M = 900(N\cdot m) \\
		y = -0.02 - \bar{ y }_{ composite } = -0.021498(m) \\
		I = n(I_{ semicircle } + A_{ semicircle }d^2) = 1.2549 \times 10^{ -7 }(m^4) \\
		d = -\bar{ y }_{ semicircle } - \bar{ y }_{ composite } = -9.9862 \times 10^{ -3 } (m)
	\end{array}
\right.
$$

---

參考資料:

材料力學作業4 題目4.57

---

link:

