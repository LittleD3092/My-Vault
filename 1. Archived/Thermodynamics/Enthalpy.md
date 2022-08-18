標籤: #Thermodynamics 

---

用 $h$ 或 $H$ 表示

$$
\left\{
	\begin{array}{}
		h = u + Pv\quad (\text{kJ/kg}) \qquad \text{open system} \\
		H = U + PV\quad (\text{kJ}) \qquad \text{close system}
	\end{array}
\right.
$$

# [[Entropy]] Change between states

> ![[Enthalpy Example.png]]
> 1. Quasi Equilibrium
> 2. $P = \text{ constant }$
> 3. $\Delta KE = 0$, $\Delta PE = 0$

from energy equation
$$Q_{ 1 \rightarrow 2 } = U_2 - U_1 + W_{ 1 \rightarrow 2 }$$

> $$W_{ 1 \rightarrow 2 } = \int_1^2 PdV$$
> $$ = P(V_2 - V_1)$$
> $$ = P_2V_2 - P_1V_1$$

$$Q_{ 1 \rightarrow 2 } = U_2 - U_1 + P_2V_2 - P_1V_1$$

$$ = \underbrace{ (V_2 + P_2V_2) }_{ \text{ state 2 } } - \underbrace{ (V_1 + P_1V_1) }_{ \text{ state 1 } }$$

$$\implies Q_{ 1 \rightarrow 2 } \implies \text{ change in the quantity }(U + PV)$$

$$\implies \text{ Let } H = U + PV \text{ or } h = u + P\nu$$

$$\implies \text{ enthalpy is a property }$$

$$\therefore \text{ Change in enthalpy } = 
\begin{array}{}
	\text{ change in internal energy } + \\
	\text{ work during this process }
\end{array}
$$

## 重要結果

解題時可能會有這兩個 case ，到時候挑適合的使用

### Case 1

If pressure is constant

$$
\left\{
	\begin{array}{}
		Q_{ 1 \rightarrow 2 } = U_2 - U_1 + W_{ 1 \rightarrow 2 } \\
		Q_{ 1 \rightarrow 2 } = H_2 - H_1
	\end{array}
\right.
$$

### Case 2

If pressure is not constant

ex.
$$\implies V = \text{ constant }$$

use
$$Q_{ 1 \rightarrow 2 } = U_2 - U_1 + W_{ 1 \rightarrow 2 }$$

---

參考資料:

熱力學上課
熱力學 Ch3 OCW

---

link:

[[Property (thermodynamic)]]
[[First Law of Thermodynamics]]