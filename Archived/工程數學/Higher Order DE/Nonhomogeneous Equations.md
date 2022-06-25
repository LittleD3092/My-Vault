標籤: #工程數學 

---

可以和 [[First Order Differential Equation]] 中的線性解法做比較

當有一個 [[Differential Equation]] 長得像這樣

$$a_n(x)y^{(n)}(x) + a_{n-1}(x)y^{(n-1)}(x) + ... + a_1(x)y'(x) + a_0(x)y = g(x)$$

如果 $g(x) \neq 0$ ，他就是 [[Nonhomogeneous Equations]]

# 解法

它的解法分成兩個part，[[#part 1 Associated homogeneous DE]] 和 [[#part 2 particular solution]]

$$a_n(x)y^{(n)}(x) + a_{n-1}(x)y^{(n-1)}(x) + ... + a_1(x)y'(x) + a_0(x)y = g(x)$$
.
## part 1 (Associated homogeneous DE):
假設 $g(x) = 0$
$$a_n(x)y^{(n)}(x) + a_{n-1}(x)y^{(n-1)}(x) + ... + a_1(x)y'(x) + a_0(x)y = 0$$
接著根據條件找到 $n$ 個線性獨立的解
$$y_1(x), y_2(x),...,y_n(x)$$
> 1. 用 [[Wronskian]] 可以測驗線性獨立
> 2. 這些線性獨立的解叫做 Complementary Function

.
## part 2 (particular solution)
根據 [[Superposition Principle]] ，可以把所有的 particular solution 加起來
$$y_p(x) = y_{p_1}(x) + y_{p_2}(x) + ... + y_{p_k}(x)$$
.
## 整合 part 1 和 part 2

最後可以得到一個 general solution
$$y(x) = c_1y_1(x) + c_2y_2(x) + ... + c_ny_n(x) + y_p(x)$$

---

[[Higher Order DE解法]]
[[Auxiliary Function]]
[[Superposition Approach]]