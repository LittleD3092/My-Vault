標籤: #工程數學 #probability 
link: [[Higher Order DE解法]]

---

# Differential Equation

For any equation $y(x)$: (<u>1</u>)

$$y(x) = 
y(0) + 
\frac{y'(0)}{1!}x + 
\frac{y''(0)}{2!}x^2 +
\frac{y'''(0)}{3!}x^3 +
\frac{y^{(4)}(0)}{4!}x^4 + ...$$

更一般化的型態: (<u>1</u>)

$$y(x) = 
y(x_0) +
\frac{y'(x_0)}{1!}(x - x_0) +
\frac{y''(x_0)}{2!}(x - x_0)^2 +
\frac{y'''(x_0)}{3!}(x - x_0)^3 +
\frac{y^{(4)}(x_0)}{4!}(x - x_0)^4 + ...$$

要算出一個解，可以依照以下步驟：(<u>1</u>)

1. Step 1 算出 $y(x_0)$ , $y'(x_0)$ , $y''(x_0)$ , $y'''(x_0)$ , $y^{(4)}(x_0)$ , ...
2. Step 2 代回 Taylor series

## 限制

使用 Taylor series 來解微分方程有幾個限制：(<u>1</u>)

1. $y(x)$ 在 $x_0$ 的地方必須為 [[Analytic]], ( $x = x_0$ 不為 [[singular point]])
2. 在解 nth order DE 時， $y(x_0)$ , $y'(x_0)$ , $y''(x_0)$ , ... $y^{(n - 1)}(x_0)$ 的值必須皆為已知
3. 得出的解只有在 $x_0$ 附近較為正確

# Exponential

An exponential can be expanded like this: (<u>2</u>)

$$
e^x = 1 + \frac{1}{1!}x^1 + \frac{1}{2!}x^2 + \dots
$$

# Examples

## 1. Solving an ODE using Taylor series

Calculate: (<u>1</u>)
$$y'' = x + y - y^2 \quad y(0) = -1 \quad y'(0) = 1 $$

---

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

代回 Taylor series
$$y(x) = -1 + x - x^2 + \frac{2}{3}x^3 - \frac{1}{3}x^4 + \frac{1}{5}x^5 ...$$

---

參考資料:

1. [Systems of Linear DEs; Nonlinear DEs](https://youtu.be/4g4Jft-3LCU)
2. Hsieh, Ping-Chun. “515512: Probability Lecture 16 - Moment Generating Functions.” NYCU EC016, November 8, 2024.