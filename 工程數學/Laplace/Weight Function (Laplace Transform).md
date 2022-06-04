標籤: #工程數學 

---

$$P(s)Y(s) - Q(s) = G(s)$$
$$\implies Y(s) = \frac{ Q(s) }{ P(s) } + \frac{ G(s) }{ P(s) }$$
$$\implies Y(s) = W(s)Q(s) + W(s)G(s) \qquad W(s) = \frac{ 1 }{ P(s) }$$

其中 Weight Function 為

$$w(t) = L^{ -1 }\{ W(s) \}$$

> Note:
> When $Q(s) = 0$ (no initial condition) and $G(s) = 1\quad ( g(t) = \delta(t) )$, $Y(s) = W(s), \quad y(t) = w(t)$

---

參考資料:

[工程數學 第23講、Sections 7-5 and 7-6 The Dirac Delta Function and Systems of Linear DEs](https://youtu.be/clnW8db1WaQ)

---

link:

[[Laplace Transform]]