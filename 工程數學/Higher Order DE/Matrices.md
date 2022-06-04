標籤: #工程數學 #list 

---

Most linear systems consist of multiple linear ODEs, with unknown function $y_1( t ),\; y_2( t ),\; \dots$

> Two linear ODE:
> $$
> \begin{array}{}
> y_1' = a_{ 11 }y_1 + a_{ 12 }y_2 \\
> y_2' = a_{ 21 }y_1 + a_{ 22 }y_2
> \end{array}
> $$
> example:
> $$
> \begin{array}{}
> y_1' = -5y_1 + 2y_2 \\
> y_2' = 13y_1 + \frac{ 1 }{ 2 }y_2
> \end{array}
> $$

> Multiple linear ODE:
> $$
> \begin{array}{}
> y_1' = a_{ 11 }y_1 + a_{ 12 }y_2 + \dots + a_{ 1n }y_n \\
> y_2' = a_{ 21 }y_1 + a_{ 22 }y_2 + \dots + a_{ 2n }y_n \\
> \dots \dots \dots \dots \dots \dots \dots \dots \dots \dots \\
> y_n' = a_{ n1 }y_1 + a_{ n2 }y_2 + \dots + a_{ nn }y_n
> \end{array}
> $$

# Matrices

矩陣，上面的 ODE 可以分別寫成 $2 \times 2$ 和 $n \times n$ 的矩陣

> $2 \times 2$ matrix $A$:
> $$A = [a_{ jk }] = 
> \left[ 
> \begin{array}{}
> a_{ 11 } & a_{ 12 } \\
> a_{ 21 } & a_{ 22 }
> \end{array}
> \right]$$
> example:
> $$A = 
> \left[
> \begin{array}{}
> -5 & 2 \\
> 13 & \frac{ 1 }{ 2 }
> \end{array}
> \right]$$

> $n \times n$ matrix $A$:
> $$A = [a_{ jk }] = 
> \left[
> \begin{array}{}
> a_{ 11 } & a_{ 12 } & \dots & a_{ 1n } \\
> a_{ 21 } & a_{ 22 } & \dots & a_{ 2n } \\
> .        & .        & \dots & .        \\
> a_{ n1 } & a_{ n2 } & \dots & a_{ nn }
> \end{array}
> \right]$$

## [[Entries]], [[Rows]], [[Columns]]

- $a_1, \; a_2, \; \dots$ 被稱為 [[Entries]]
- 橫的被稱為列 [[Rows]]
- 直的被稱為行 [[Columns]]

> example:
> 在 $2 \times 2$ 的矩陣中，第一列和第二列分別是
> $$
> \left[
> \begin{array}{}
> a_{ 11 } & a_{ 12 }
> \end{array}
> \right]
> 
> \text{ and }
> 
> \left[
> \begin{array}{}
> a_{ 21 } & a_{ 22 }
> \end{array}
> \right]
> $$
> 第一行和第二行分別是
> $$
> \left[
> \begin{array}{}
> a_{ 11 } \\
> a_{ 21 }
> \end{array}
> \right]
> 
> \text{ and }
> 
> \left[
> \begin{array}{}
> a_{ 12 } \\
> a_{ 22 }
> \end{array}
> \right]
> $$

## [[Main Diagonal]]

左上到右下的 [[Entries]]

$$a_{ 11 }, \; a_{ 22 }, \; \dots , \; a_{ nn }$$

# Matrix Calculations

> content:
> - [[Matrix Multiplication]]
> - [[Matrix Transposition]]
> - [[Inverse of Matrix]]

---

參考資料:

工程數學課本

---

link:

[[Matrix Multiplication]]