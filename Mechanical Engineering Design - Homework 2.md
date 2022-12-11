標籤: #Mechanical-Engineering-Design 
學號: 109611066
姓名: 吳典謀

---

## 1.

Smith-Dolan locus is represented by:

$$\frac{S_a}{S_e} = \frac{1 - S_m / S_{ut}}{1 + S_m / S_{ut}}$$

For the second quadrant, we may use a straight line which has the equation

$$S_a = S_e + 
\left(
	\frac{S_e}{S_{ut}} - 1
\right)S_m$$

The load line with slope $r$ can be represented by the following equation:

$$S_m = \frac{S_a}{r}$$

By solving the two equations above,

$$
\begin{array}{l}
	\implies &
	\displaystyle
	\left[
		1 - 
		\left(
			\frac{S_e}{S_{ut}} - 1
		\right)\frac{1}{r}
	\right]S_a = S_e \\
	\implies & 
	[rS_{ut} - S_e + S_{ut}]S_a = rS_{ut}S_e \\
	\implies &
	\displaystyle
	S_a = \frac{rS_{ut}S_e}{S_{ut}(r + 1) - S_e}
\end{array}
$$

we obtain the intersection $(S_m, S_a)$:

$$\underline{(S_m, S_a) = \left(
	\frac{S_{ut}S_{e}}{S_{ut}(r + 1) - S_e}, 
	\frac{rS_{ut}S_{e}}{S_{ut}(r + 1) - S_e}
\right)}_\#$$

## 2.

- Bar of steel.
- $S_e = 40 \text{ kpsi}$
- $S_y = 60 \text{ kpsi}$
- $S_{ut} = 80 \text{ kpsi}$
- Static torsional stress $\tau = 15 \text{ kpsi}$
- Completely reversed bending stress $\sigma = 25 \text{ kpsi}$

### (a), (b), (c), (d)

Because there is no axial stress, the von Mises stresses for the two stress elements can be written as

$$
\left\{
	\begin{array}{l}
		\sigma_a' = \{
			[
				(K_f)_{\text{bending}}
				(\sigma_{a0})_{\text{bending}}
			]^2 + 3[
				(K_{fs})_{\rm torsion}
				(\tau_{a0})_{\rm torsion}
			]^2
		\}^{\frac 1 2} \\
		\sigma_m' = 
		\{
			[
				(K_f)_{\rm bending}
				(\sigma_{m0})_{\rm bending}
			]^2 + 3[(K_{fs})_{\rm torsion}(\tau_{m0})_{\rm torsion}]^2
		\}^{\frac{1}{2}}
	\end{array}
\right.
$$

Assume no stress concentration, $(K_f)_{\rm bending} = (K_{fs})_{\rm torsion} = 1$.

$$
\left\{
	\begin{array}{l}
		\sigma_a' = \{
			[
				(\sigma_{a0})_{\text{bending}}
			]^2 + 3[
				(\tau_{a0})_{\rm torsion}
			]^2
		\}^{\frac 1 2} \\
		\sigma_m' = 
		\{
			[
				(\sigma_{m0})_{\rm bending}
			]^2 + 3[(\tau_{m0})_{\rm torsion}]^2
		\}^{\frac{1}{2}}
	\end{array}
\right.
$$

Substituting $(\sigma_{a0})_{\rm bending} = 25$, $(\sigma_{m0})_{\text{bending}} = 0$, $(\tau_{a0})_{\rm torsion} = 0$, $(\tau_{m0})_{\rm torsion} = 15$.

$$
\underline{
	\left\{
		\begin{array}{l}
			\sigma_a' = 25 \text{ kpsi}\\
			\sigma_m' = 25.98 \text{ kpsi}
		\end{array}
	\right.
}_\#
$$

