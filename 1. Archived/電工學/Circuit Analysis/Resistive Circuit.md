標籤: #電工學 

---

# Series and Parallel Connections

![[Series Solution.png]]

$$v_1 = \frac{ R_1 }{ R_1 + R_2 } \cdot v_R \qquad \text{ voltage diveder }$$

$v_R$: 1 跟 2 的等效電阻

---

![[Parallel Connections.png]]

$$i_1 = \frac{ R_2 }{ R_1 + R_2 } \cdot i_R \qquad \text{ current divider }$$

> ## Parallel Connection how
> $$R_1 \vert\vert R_2 = \frac{ R_1 R_2 }{ R_1 + R_2 }$$
> $$i_R = v_R \cdot \frac{ 1 }{ R_1 \vert\vert R_2 }$$
> $$i_1 = \frac{ v_R }{ R_1 }$$
> 
> 從上述兩式
> 
> $$i_1 = \frac{ R_2 }{ R_1 + R_2 } i_R$$

# Series / Parallel Reduction

![[Series Parallel Reduction.png]]

灰色框框是可以簡化的部份，簡化過後變成下圖

![[Wheatstone bridge.png]]

上面的是 Wheatstone Bridge

$$
\begin{array}{l}
\text{ if } x = 0 \text{ : } & R_{ eq } & = & (10 \vert\vert 6 + 2) \vert\vert 4 \\
& & = & 2.4 \\
\text{ if } x = \infty \text{ : } & R_{ eq } & = & ((6 + 4) \vert\vert 2) + 10 \\
& & = & \frac{ 5 }{ 3 } + 10 & = & \frac{ 35 }{ 3 } & = & 11.6
\end{array}
$$
.
$$
\begin{array}{l}
\text{ 3KCL } & \text{ Node 1: } & i_a = i_b + i_d \\
& \text{ Node 2: } & i_b - i_c - i_f = 0 \\
& \text{ Node 3: } & i_d + i_f = i_e \\
\\
\text{ 3KVL } & L_1:\  & v - i_b x - 4i_c = 0 \\
& L_2:\  & -10i_d + 6i_f + x i_b = 0 \\
& L_3:\  & 4i_c - 6i_f - 2i_e = 0
\end{array}
$$

將上面的六個等式寫成矩陣

$$
\left[
\begin{array}{}
& (a) & (b) & (c) & (d) & (e) & (f) \\
\text{ (Node 1) } & 1 & -1 & 0 & -1 & 0 & 0 \\
\text{ (Node 2) } & 0 & 1 & -1 & 0 & 0 & -1 \\
\text{ (Node 3) } & 0 & 0 & 0 & 1 & -1 & 1 \\
(L_1) & 0 & -x & -4 & 0 & 0 & 0 \\
(L_2) & 0 & x & 0 & -10 & 0 & 6 \\
(L_3) & 0 & 0 & 4 & 0 & -2 & -6
\end{array}
\right]
\left[
\begin{array}{}
i_a \\
i_b \\
i_c \\
i_d \\
i_e \\
i_f
\end{array}
\right] = 
\left[
\begin{array}{}
0 \\
0 \\
0 \\
-v \\
0 \\
0
\end{array}
\right]
$$

---

參考資料:

電工學上課 2022-02-21

---

link:

[[Kirchhoff's Law]]