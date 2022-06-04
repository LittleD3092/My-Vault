標籤: #工程數學 

| original                     | integral                                                    |
| ---------------------------- | ----------------------------------------------------------- |
| $$\frac{1}{x}$$              | $$\ln \vert x \vert+c$$                                     |
| $$\cos(x)$$                  | $$\sin(x)+c$$                                               |
| $$\sin(x)$$                  | $$-\cos(x)+c$$                                              |
| $$\tan(x)$$                  | $$\ln\vert \sec(x) \vert +c$$                               |
| $$\cot(x)$$                  | $$\ln\vert \sin(x) \vert +c$$                               |
| $$a^x$$                      | $$\frac{a^x}{\ln(a)}+c$$                                    |
| $$\frac{1}{x^2+a^2}$$        | $$\frac{1}{a}\tan^{-1}\frac{x}{a}+c$$                       |
| $$\frac{1}{\sqrt{a^2-x^2}}$$ | $$\sin^{-1}\frac{x}{a}+c$$                                  |
| $$xe^{ax}$$                  | $$\frac{e^{ax}}{a}(x-\frac{1}{a})+c$$                       |
| $$x^2e^{ax}$$                | $$\frac{e^{ax}}{a}(x^2-\frac{2x}{a}+\frac{2}{a^2})+c$$      |
| $$e^{ ax }\sin bxdx$$        | $$\frac{ e^{ ax } }{ a^2 + b^2 }(a\cos bx - b\sin bx) + c$$ |
| $$e^{ ax }\cos bx dx$$       | $$\frac{ e^{ ax } }{ a^2 + b^2 }(a\cos bx + b\sin bx) + c$$ | 

# Integration of Trigonometric Function

## Order of Trigonometric Function is Odd Number

1. 嘗試將 $\cos x$ 與 $\sin x$ 其中一種消到剩下一個 $\cos$ 或 $\sin$
2. 將 $\cos$ 或 $\sin$ 設成 $u$ ，將 $\sin dx$ 或 $\cos x dx$ （在步驟一消到剩下一個的 $\cos$ 或 $\sin$）設成 $du$
3. 積分算出答案

> $$f(x) = \cos^3 x$$

$$\int \cos^3 x dx$$

$$ = \int(\cos x)(\cos^2 x)dx$$

$$ = \int(\cos x)(1 - \sin^2 x)dx$$

$$ = \int \cos x dx - \int \cos x\sin^2 x dx$$

$$ = \sin x - \int u^2 du \qquad , u = \sin x$$

$$ = \sin x - u^3 / 3 + C$$

$$ = \sin x - \sin ^3 x / 3 + C$$

> $$f(x) = \sin^2 (x)\cos^3 (x)$$

$$\int \sin^2(x)\cos^3(x)dx$$

$$ = \int\sin^2 x(1 - \sin^2 x)\cos x dx$$

$$ = \int u^2 (1 - u^2)du \qquad du = \cos x dx$$

$$ = \int u^2 - u^4 du$$

$$ = u^3 / 3 - u^5 / 5 + C$$

## Order of Trigonometric Function is Even Number

> $$\int \sin^4 x dx$$

$$\int \sin^4 x dx$$

$$ = \int (\frac{1 - \cos 2x}{2})^2 dx$$

$$ = \frac 1 4 \times \int (1 + \cos^2(2x) - 2\cos 2x)dx$$

$$ = \frac 1 4 \times \left( x + \int \frac {(1 + \cos 4x)}{2}dx - 2 \int \cos 2x dx \right)$$

$$ = \frac 1 4 \times \left( \frac { 3x }{ 2 } + \frac{\sin 4x}{8} - \sin 2x \right) + C$$

$$ = \frac { 3x }{ 8 } + \frac{ \sin 4x }{ 32 } - \frac{ \sin 2x }{ 4 } + C$$

---

參考資料：

[wolfram online calculater](https://www.wolframalpha.com/calculators/integral-calculator/)