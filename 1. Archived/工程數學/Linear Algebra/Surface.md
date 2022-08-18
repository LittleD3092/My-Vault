標籤: #工程數學 

---

# 求面積

![[Surface Integral]]

# Normal of Surface $S$

![[normal of surface s.png|300]]

只要找到兩條 tangent，就可以利用 [[Cross Product]] 求出 normal

我們需要找到 [[Curve]] 進而找到 tangent，所以我們簡化 $\vec r$ 來表示 $C$ (將 $u, v$ 變成只有 $t$)，讓底下的偏微分較好計算與表示

$$\vec r(u(t), v(t)) = \tilde r (t)$$

Tangent to $C$ on surface $S$

$$\frac{ d\tilde r(t) }{ dt } = 
\tilde r' (t) = 
\underbrace{ 
	\frac{ \partial \vec r }{ \partial u }
}_{ \vec r_u }\frac{ du }{ dt } + 
\underbrace{ 
	\frac{ \partial \vec r }{ \partial v }
}_{ \vec r_v } \frac{ dv }{ dt }$$

$\vec r_u$ and $\vec r_v$ are tangents to surface $S$ at the point $\tilde r(t) = \tilde r(u(t), v(t))$

$$\vec N = \vec r_u \times \vec r_v$$

$$\hat n = 
\frac{ \vec r_u \times \vec r_v }
{ \vert\vert 
	\vec r_u \times \vec r_v 
\vert\vert }$$

---

參考資料:

工程數學上課

---

link:

