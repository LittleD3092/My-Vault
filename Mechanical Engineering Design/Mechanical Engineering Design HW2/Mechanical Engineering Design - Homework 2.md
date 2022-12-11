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

$$\sigma_{ar} = \frac{162.096}{1 - 162.096 / 590} = 223.50$$

Using the Basquin's equation, and $f = 0.865$ from figure 6-23,

$$
\begin{array}{l}
	\displaystyle
	a = \frac{(fS_{ut})^2}{S_e} = \frac{(0.865 \cdot 590)^2}{208.6} = 1248.60 \\
	\displaystyle
	b = -\frac 1 3 \log
	\left(
		\frac{fS_{ut}}{S_e}
	\right) = -\frac 1 3 \log\left( \frac{0.865 \cdot 590}{208.6} \right) = -0.1295 \\
	\displaystyle
	N = \left(
		\frac{\sigma_{ar}}{a}
	\right)^{1 / b} = \left(
		\frac{223.50}{1248.60}
	\right)^{1 / -0.1295} = \underline{ 588119 \text{ cycles} }_\#
\end{array}
$$

## 4.

- AISI 1020 hot-rolled steel
	- $S_{ut} = 66.2\text{ kpsi}$
- $K_{ts} = 1.6$
- The length $L = 2\text{ ft}$
- Load $F$ cycles from $150 \sim 500 \text{ lbf}$

### (a)

The total torque $T$ is:

$$T = \underline{2F \text{ (inches)}}_\#$$

The nominal shear stress $\tau_{\rm nominal}$ is:

$$\tau_{\rm nominal} = \frac{T\rho}{J} = \frac{\displaystyle 2F \cdot \frac 7 {16}}{\displaystyle\frac{\pi (\frac{7}{8})^4}{32}} = \underline{ 15.2046F \text{ (1/inch}^2)}_\#$$

### (b)

To calculate $K_{fs}$, we can calculate $\sqrt{a}$ first. For torsion, $\sqrt{a}$ is

$$
\begin{array}{l}
	\sqrt{a} & = & 0.190 - 2.51(10^{-3})S_{ut} + 
	1.35(10^{-5})S_{ut}^2 - 2.67(10^{-8})S_{ut}^3 \\
	& = & 0.07525
\end{array}$$

$$
\begin{array}{l}
	K_{fs} & = & 
	\displaystyle
	1 + \frac{K_{ts} - 1}{1 + \sqrt{a} / \sqrt{r}} \\
	& = & 
	\displaystyle
	1 + \frac{1.6 - 1}{1 + 0.07525 / \sqrt{\frac 1 8}} \\
	& = & \underline{ 1.4947 }_\#
\end{array}
$$

### (c)

$\tau_m$ happens at $F = 325 \text{ lbf}$, and $\tau_a$ has an amplitude load $F = 175 \text{ lbf}$.

$$\left\{
	\begin{array}{l}
		\tau_m & = & K_{fs} \cdot \tau_{\rm nominal} \\
		& = & 1.4947 \cdot 15.2046 \cdot 325 \\
		& = & \underline{ 7386.05 \ {\rm lbf}/{\rm in}^2 }_\# \\
		\tau_a & = & K_{fs} \cdot \tau_{\rm nominal} \\
		& = & 1.4947 \cdot 15.2046 \cdot 175 \\
		 & = & \underline{ 3977.11 \ {\rm lbf}/{\rm in}^2 }_\#
	\end{array}
\right.$$

### (d)

From equation 6-10, we can see that because $S_{ut} \leq 200 {\rm\ kpsi}$, the endurance limit $S_e'$ is

$$S_e' = 0.5S_{ut} = \underline{33.1 {\ \rm kpsi}}_\#$$

### (e)

From figure 6-24, we see that for a hot rolled steel and $S_{ut} = 66.2 {\ \rm kpsi}$, $\underline{k_a = 0.7}_\#$.

### (f)

According to table 6-3, a nonrotating cylinder has equivalent diameter $d_e = 0.370d$.

$$d_e = 0.370d = 0.32375 {\ \rm inch}$$

Using the equivalent diameter, we can obtain the size factor $k_b$:

$$k_b = (d_e / 0.3)^{-0.107} = \underline{0.9919}_\#$$

### (g)

Since the load causes torsion, $\underline{k_c = 0.59}_\#$.

### (h)

The correct $S_e$ can be obtained by the product of $S_e'$ and the factors $k_a, k_b$ and $k_c$.

$$S_e = k_ak_bk_cS_e' = \underline{13.5596 {\ \rm kpsi}}_\#$$

### (i)

For a pure shear case,

$$S_{su} = 0.67S_{ut} = \underline{44.354{\ \rm kpsi}}_\#$$

### (j)

Modified Goodman fatigue failure criterion:

$$
\begin{array}{l}
	n_f & = & 
	\displaystyle
	\left(
		\frac{\tau_a}{S_e} + \frac{\tau_m}{S_{su}}
	\right)^{-1} \\
	 & = & 
	 \displaystyle
	 \left(
		 \frac{3977.11 \cdot 10^{-3}}{13.5596} +
		 \frac{7386.05 \cdot 10^{-3}}{44.354}
	 \right)^{-1} \\
	 & = & \underline{2.17}_\#
\end{array}
$$

### (k)

Gerber fatigue failure criterion:

$$
\begin{array}{l}
	n_f & = & 
	\displaystyle
	\frac 1 2 \left(
		\frac{S_{su}}{\tau_m}
	\right)^2
	\left(
		\frac{\tau_a}{S_e}
	\right)
	\left[
		-1 + \sqrt{
			1 + \left(
				\frac{2\tau_mS_e}{S_{su}\tau_a}
			\right)^2
		}
	\right] \\
	 & = & \underline{2.71}_\#
\end{array}
$$