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

![[Mechanical Engineering Design/Mechanical Engineering Design HW2/Figure_1.png]]

### (e)

Modified Goodman criterion.

### (f)

$$n_{\rm fos}(\sigma_a' + \sigma_m') = 60$$

$$\implies \underline{
	n_{\rm fos} = 1.18
}_\#$$

### (g)

$$n_f = \left(
	\frac{\sigma_a'}{S_e} +
	\frac{\sigma_m'}{S_{ut}}
\right)^{-1} = \underline{1.05}_\#$$

### (h)

$$n_f = \frac{1}{2}
\left(
	\frac{S_{ut}}{\sigma_m'}
\right)^2
\left(
	\frac{\sigma_a'}{S_e}
\right)
\left[
	-1 + \sqrt{
		1 +
		\left(
			\frac{2\sigma_m' S_e}{S_{ut}\sigma_a'}
		\right)^2
	}
\right] = \underline{1.31}_\#$$

### (i)

$$n_f = 
\left[
	\left(
		\frac{\sigma_a'}{S_e}
	\right)^2 +
	\left(
		\frac{\sigma_m'}{S_y}
	\right)^2
\right]^{-1/2} = \underline{1.32}_\#$$

## 3.

- Cold-drawn AISI 1040 steel bar
- $S_{ut} = 590 \text{ MPa}$
- $S_y = 490\text{ MPa}$
- $S_e = 208.6 \text{ MPa}$
- $K_f = 2.2$
- $F_\min = 0\text{ kN}$
- $F_\max = 28\text{ kN}$

### (a), (b), (c)

Since there is only axial load, the von Mises stresses for the two stress elements can be written as:

$$\left\{
	\begin{array}{l}
		\sigma_a' = (K_f)_{\rm axial}(\sigma_{a0})_{\rm axial} \\
		\sigma_m' = (K_f)_{\rm axial}(\sigma_{m0})_{\rm axial}
	\end{array}
\right.$$

The axial stresses elements can be obtained by the cross section area and axial load:

$$
\left\{
	\begin{array}{l}
		\displaystyle
		(\sigma_{a0})_{\rm axial} = \frac{14\text{ kN}}{(25\text{ mm} - 6 \text{ mm}) \cdot 10\text{ mm}} = 73.68\text{ MPa} \\
		\displaystyle
		(\sigma_{m0})_{\rm axial} = \frac{14 \text{ kN}}{(25 \text{ mm} - 6 \text{ mm}) \cdot 10 \text{ mm}} = 73.68\text{ MPa}
	\end{array}
\right.
$$

Then, we may obtain the von Mises stresses for the axial load:

$$
\left\{
	\begin{array}{l}
		\sigma_a' = 2.2 \cdot 0.07368 = 162.096 \\
		\sigma_m' = 2.2 \cdot 0.07368 = 162.096
	\end{array}
\right.
$$

![[Figure_2.png]]

### (d)

Based on modified Goodman criterion, it will have fatigue failure.

### (e)

The equivalent completely reversed stress:

$$\sigma_{ar} = \frac{192.096}{1 - 192.096 / 590} = 284.83$$

Using the Basquin's equation, 

$$
\begin{array}{l}
	\displaystyle
	a = \frac{}{}
\end{array}
$$