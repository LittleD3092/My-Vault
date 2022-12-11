標籤: #Mechanical-Engineering-Design 
學號: 109611066
姓名: 吳典謀

---

## 1.

Smith-Dolan locus is represented by:

$$\frac{S_a}{S_e} = \frac{1 - S_m / S_{ut}}{1 + S_m / S_{ut}}$$

For a load line of slope $r$, we substitute $S_a / r$ for $S_m$ to obtain the intersect:

$$
\begin{array}{l}
	&
	\displaystyle
	\frac{S_a}{S_e} = \frac{
		\displaystyle
		1 - \frac{S_a}{rS_{ut}}
	}{
		\displaystyle
		1 + \frac{S_a}{rS_{ut}}
	} \\
	\implies &
	\displaystyle
	\frac{S_a}{S_e} + \frac{S_a^2}{rS_eS_{ut}} = 1 - \frac{S_a}{rS_{ut}} \\
	\implies & 
	\displaystyle
	\frac{1}{rS_eS_{ut}} \cdot S_a^2 + 
	\left(
		\frac{1}{S_e} + \frac{1}{rS_{ut}}
	\right)S_a - 1 = 0 \\
	\implies &
	S_a^2 + (rS_{ut} + S_e)S_a - rS_eS_{ut} = 0
\end{array}
$$

Solving for $S_a$:

$$
S_a =
\displaystyle
\frac{-(rS_{ut} + S_e) \pm \sqrt{(rS_{ut} + S_e)^2 + 4rS_eS_{ut}}}{2}
$$

Because $S_a$ is positive,

$$
S_a =
\displaystyle
\frac{-(rS_{ut} + S_e) + \sqrt{(rS_{ut} + S_e)^2 + 4rS_eS_{ut}}}{2}
$$

Simplify:

$$
\begin{array}{l}
	\implies &
	\displaystyle
	S_a = -\frac{rS_{ut} + S_e}{2} +
	\sqrt{
		\frac{(rS_{ut} + S_e)^2}{4} + rS_eS_{ut}
	} \\
	\implies & 
	\displaystyle
	\underline{ 
		S_a = \frac{rS_{ut} + S_e}{2}
		\left[
			-1 + \sqrt{1 + \frac{4rS_eS_{ut}}{(rS_{ut} + S_e)^2}}
		\right]
	}_\#
\end{array}
$$

Since $S_m = S_a / r$, 

$$\underline{
	S_m = 
	\frac{rS_{ut} + S_e}{2r}
	\left[
		-1 + \sqrt{1 + \frac{4rS_eS_{ut}}{(rS_{ut} + S_e)^2}}
	\right]
}_\#$$

## 2.

### (a).

