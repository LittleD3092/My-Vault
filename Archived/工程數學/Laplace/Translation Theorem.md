標籤: #工程數學 

---

>First Translation Theorem
> $$L\{e^{at}f(t)\} = F(s - a)$$
> Second Translation Theorem
> $$L\{f(t - a)u(t - a)\} = e^{-as}F(s)$$
> > $u(t)$ : [[Step Function]]

這兩個 Translation Theorem 很相似，只是前後反過來
不同處:
1. $e^{at}$ 變成 $e^{-as}$ ，多了負號
2. 多了 $u(t)$

這兩個 Translation Theorem 可以簡化 [[Laplace Transform]] 性質

# First Translation Theorem 證明

$$L\{e^{at}f(t)\} = F(s - a)$$

Proof:
$$L\{e^{at}f(t)\} = \int_0^{\infty}e^{-st}e^{at}f(t)dt$$
$$ = \int_{0}^\infty e^{-(s - a)t}f(t)dt$$
$$ = F(s - a)$$

# Second Translation Theorem 證明

$$L\{f(t - a)u(t - a)\} = \int_0^\infty e^{-st}f(t - a)u(t - a)dt$$
$$ = \int_{a}^{\infty}e^{-st}f(t - a)dt$$
$$ = \int_{0}^{\infty}e^{-s(t_1 + a)}f(t_1)dt_1 \qquad \text{令} \; t_1 = t - a,\; dt_1 = dt$$
$$ = e^{-as}\int_{0}^\infty e^{-st_1}f(t_1)dt_1$$
$$ = e^{-as}F(s)$$

# Example (First Translation Theorem)

$$(a)\quad L\{e^{5t}t^3\}$$
.
$$ = \left.L\{t^3\}\right\vert_{s \rightarrow s - 5}$$
$$ = \left.\frac{3!}{s^4}\right\vert_{s \rightarrow s - 5}$$
$$ = \frac{6}{(s - 5)^4}$$

---

$$(b)\quad L\{e^{-2t}\cos 4t\}$$
.
$$ = \left. L\{\cos 4t\}\right\vert_{s\rightarrow s - (-2)}$$
$$ = \left. \frac{s}{s^2 + 16}\right\vert_{s \rightarrow s + 2}$$
$$ = \frac{s + 2}{(s + 2)^2 + 16}$$

# Example (Second Translation Theorem)

$$L^{-1}\left\{\frac{1}{s - 4}e^{-2s}\right\}$$
.
$$L^{-1}\left\{\frac{1}{s - 4}\right\} = e^{4t}$$
$$L^{-1}\left\{ \frac{1}{s - 4}e^{-2s} \right\} = e^{4(t - 2)}u(t - 2)$$

---

參考資料:

[工數OCW - Class 21 - youtube](https://youtu.be/0sAa2XUDXMs)
[[Laplace Transform]]
[[Laplace Transform 解法]]