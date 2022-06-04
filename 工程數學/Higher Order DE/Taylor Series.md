標籤: #工程數學 

---

$$y(x) = 
y(0) + 
\frac{y'(0)}{1!}x + 
\frac{y''(0)}{2!}x^2 +
\frac{y'''(0)}{3!}x^3 +
\frac{y^{(4)}(0)}{4!}x^4 + ...$$

更一般化的型態
$$y(x) = 
y(x_0) +
\frac{y'(x_0)}{1!}(x - x_0) +
\frac{y''(x_0)}{2!}(x - x_0)^2 +
\frac{y'''(x_0)}{3!}(x - x_0)^3 +
\frac{y^{(4)}(x_0)}{4!}(x - x_0)^4 + ...$$
.
Step 1 算出 $y(x_0)$ , $y'(x_0)$ , $y''(x_0)$ , $y'''(x_0)$ , $y^{(4)}(x_0)$ , ...
.
Step 2 代回 Taylor series

# 限制

1. $y(x)$ 在 $x_0$ 的地方必須為 [[Analytic]], ( $x = x_0$ 不為 [[singular point]])
2. 在解 nth order DE 時， $y(x_0)$ , $y'(x_0)$ , $y''(x_0)$ , ... $y^{(n - 1)}(x_0)$ 的值必須皆為已知
3. 得出的解只有在 $x_0$ 附近較為正確

# Example 3

題目:
$$y'' = x + y - y^2 \quad y(0) = -1 \quad y'(0) = 1 $$
.
$$y'' = x + y - y^2$$
$$y''(0) = 0 + (-1) - 1^2 = -2$$
.
$$y''' = \frac{d}{dx}(x + y - y^2)
       = 1 + y' - 2y'y$$
$$y'''(0) = 4$$
.
$$y^{(4)} = \frac{d}{dx}(1 + y' - 2y'y)
          = y'' - 2y''y - 2(y')^2$$
$$y^{(4)}(0) = -8$$
.
$$y^{(5)} = \frac{d}{dx}(y'' - 2y''y - 2(y')^2)
          = y''' - 2y'''y - 6y'y''$$
$$y^{(5)}(0) = 24$$
.
代回 Taylor series
$$y(x) = -1 + x - x^2 + \frac{2}{3}x^3 - \frac{1}{3}x^4 + \frac{1}{5}x^5 ...$$

---

參考資料:

[Systems of Linear DEs; Nonlinear DEs](https://youtu.be/4g4Jft-3LCU)

[[Higher Order DE解法]]