標籤: #電工學 

---

![[Ideal Transformer.png]]

$N_p$, $N_s$ are Turns

$$a = \frac{ N_p }{ N_s } \quad \text{ (turn ratio) }$$

$$\text{ Faraday's Law } \left\{
\begin{array}{}
	v_p = N_p\frac{ d\phi_B }{ dt } \\
	v_s = N_s\frac{ d\phi_B }{ dt }
\end{array}
\right.$$

$$\implies \underbrace{ \frac{ v_p }{ v_s } }_{ \text{ must be A.C. } } = \frac{ N_p }{ N_s } = a$$

Due to the power conservation assumed

![[transformer schematic diagram.png]]

$$P = v_p\cdot i_p = v_s\cdot i_s$$

$$\frac{ v_p }{ v_s } = \frac{ i_s }{ i_p } = a$$

e.g.

![[example of transformer.png]]

$$R_o = \frac{ v_s }{ i_s } = \frac{ \frac{ 1 }{ a } v_p }{ a i_p }$$

$$ = \frac{ 1 }{ a^2 } R_o'$$

$R_o'$: 上面電路的 impedance

---

參考資料:

電工學上課

---

link:

[[Inductor]]