標籤: #工程數學 

---

[[Laplace Transform]] 對於微分式子的轉換方法

---

$$
L\{f'(t)\} 
= 
\int_{0}^{\infty}
	e^{-st}f'(t)dt 
\qquad
\begin{array}{ll} 
	u = e^{-st}    &  dv = f'(t)dt \\
	du = -se^{-st} &  v = f(t)
\end{array}
$$
$$
=
\left. e^{-st}f(t) \right\vert_{0}^{\infty} 
+
s \int_{0}^{\infty} e^{-st}f(t)dt
$$
$$ = 0 - f(0) + sL\{ f(t) \}$$
$$ = \underline{sL\{ f(t) \} - f(0)}_{\#}$$

---

$$L\{f''(t)\} = sL\{f'(t)\} - f'(0)$$
$$ = s[sL\{f(t)\} - f(0)] - f'(0)$$
$$ = \underline{s^2L\{f(t)\} - sf(0) - f'(0)}_{\#}$$

---

$$L\{f'''(t)\} = sL\{f''(t)\} - f''(0)$$
$$ 
=
\underline
{
	s^3L\{f(t)\} - s^2f(0) - sf'(0) - f''(0)
}
_
{\#}
$$

---

> Theorem
> $$L\{f^{(n)}(t)\} = s^nF(s) - s^{n - 1}f(0) - s^{n - 2}f'(0) - \dots - sf^{(n - 2)}(0) - f^{(n - 1)}(0)$$

---

參考資料:

[工數OCW - Class 21 - youtube](https://youtu.be/0sAa2XUDXMs)
[[Laplace Transform 解法]]