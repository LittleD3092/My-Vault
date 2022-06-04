標籤: #工程數學 

---

兩個陣列內積，或兩個函式點對點相乘後相加

$$(f_1, f_2) = \sum_n f_1[n]f_2[n]$$

$$(f_1, f_2) = \int_a^b f_1(x)f_2(x)dx \qquad (f_1, f_2 \text{ 為 real 時 })$$

當 $f_1, f_2$ 不為 real

$$(f_1, f_2) = \int_a^b f_1(x)\underbrace{ f_2^*(x) }_{ \text{ with conjugation } }dx$$

# 性質

$$1. \quad (f_1, f_2) = (f_2, f_1)^* \text{ (交換率) }$$
$$2. \quad (kf_1, f_2) = k(f_1, f_2)\text{ , } k \text{ 為 scalar (或稱為 constant) }$$
$$
3. \quad 
\begin{array}{}
(f, f) = 0 \text{ if and only if } f = 0 \\
(f, f) > 0 \text{ if and only if } f \neq 0
\end{array}
$$

$$4. \quad (f_1 + f_2, g) = (f_1, g) + (f_2, g)$$

---

參考資料:

微分方程OCW class 24

---

link:

