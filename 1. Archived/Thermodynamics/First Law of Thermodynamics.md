標籤: #Thermodynamics

---

# 簡介

能量守恆

# 公式

$$\text{ cyclic integral of the heat (Q) } = \text{ cyclic integral of the work (W) }$$
$$\implies \oint \delta Q = \oint \delta W$$

## $\delta Q - \delta W$ is a point function

![[First Law of Thermodynamics Example.png]]

$$\oint \delta W = \oint \delta Q$$

1. $A\rightarrow B$
$$\int_1^2 \delta Q_A + \int_2^1 \delta Q_B = \int_1^2 \delta W_A + \int_2^1 \delta W_B$$

2. $C\rightarrow B$
$$\int_1^2 \delta Q_C + \int_2^1 \delta Q_B = \int_1^2 \delta W_C + \int_2^1 \delta W_B$$
.
$$1. - 2. \implies \int_1^2 \delta Q_A - \int_1^2 \delta Q_C = \int_1^2 \delta W_A - \int_1^2 \delta W_C$$

$$\implies \int_1^2 (\delta Q - \delta W)_A = \int_1^2 (\delta Q - \delta W)_C$$

$$\therefore \delta Q - \delta W \text{ is the same for } A \text{ and } C$$

$$\text{ It is the same for all the processes between 1 and 2 }$$

$$\implies \underline{ \delta Q - \delta W \text{ only depend on 1 and 2, not on path } }_{ \# }$$

$$\implies \underline{ \text{ point function } }_{ \# }$$

$$\implies \text{ Def: } \underline{ dE = \delta Q - \delta W }_{ \# }$$

## Generalized Form of Energy

$$\text{ from } \quad dE = \delta Q - \delta W$$

$$
E \text{ : energy, represents all the energy of the system }
$$

$$
= 
\left\{
	\begin{array}{}
		\text{ Internal energy } (U) \\
		+ \\
		\text{ Kinetic energy } (KE) \\
		+ \\
		\text{ Potential energy } (PE)
	\end{array}
\right.
$$

$$E = U + KE + PE$$

$$\implies dE = dU + d(KE) + d(PE)$$

$$ = \delta Q - \delta W$$

$$
\left\{
	\begin{array}{}
		KE = \frac{ 1 }{ 2 } m( V_2^2 - V_1^2 ) \\
		PE = mg(z_2 - z_1)
	\end{array}
\right.
\qquad
\text{ 代入 }
$$

$$\implies \underline{ E_2 - E_1 = Q_{ 1 \rightarrow 2 } - W_{ 1 \rightarrow 2 } }_{ \# }$$

$$\implies \underline{ E_2 - E_1 = U_2 - U_1 + \frac{ 1 }{ 2 } m(v_2^2 - v_1^2) + mg(z_2 - z_1) }_{ \# }$$

---

參考資料:

[熱力學(一) - NCTU ocw](https://ocw.nctu.edu.tw/course_detail-v.php?bgid=2&gid=0&nid=624&v5=BkyIczpA6OI)