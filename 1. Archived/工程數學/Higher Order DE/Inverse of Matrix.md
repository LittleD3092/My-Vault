標籤: #工程數學 #linear-algebra 

---

[TOC]

---

如果有矩陣 $A$, 並且它的反矩陣為 $B$

$$AB = BA = I$$

> [[Unit Matrix]]:
> $$I$$

也可以把反矩陣寫成

$$AA^{ -1 } = A^{ -1 }A = I$$

# $A^{ -1 }$ 計算

## Gauss-Jordan Elimination

$$\det A = 
\left\vert
\begin{array}{}
a_{ 11 } & a_{ 12 } \\
a_{ 21 } & a_{ 22 }
\end{array}
\right\vert = 
a_{ 11 } a_{ 22 } - a_{ 12 } a_{ 21 }$$

如果 $\det A \neq 0$ ，代表反矩陣存在

## Formula

除了 [[#Gauss-Jordan Elimination]] 以外，還有公式解（雖然很醜，除了 $n = 2$ 的情況可以背以外幾乎不會用到）

$$A^{ -1 } = \frac{ 1 }{ \det A }\text{adj}(A)$$

> $\text{adj}(A)$: [[Adjoint]].Transpose of cofactor matrix.
> $$\text{adj}A = C^T$$
> ---
> $C$: cofactor matrix
> $$c_{ ij } = (-1)^{ i + j } \times \text{ minor of }a_{ ij }$$
> ---
> minor of $a_{ ij }$
> $$\text{ for a matrix }A = \left[ \begin{array}{} a_{ 11 } & a_{ 12 } & a_{ 13 } \\ a_{ 21 } & a_{ 22 } & a_{ 23 } \\ a_{ 31 } & a_{ 32 } & a_{ 33 } \end{array} \right]$$
> $$\text{ minor of }a_{ 11 } = \left\vert \begin{array}{} a_{ 22 } & a_{ 23 } \\ a_{ 32 } & a_{ 33 } \end{array} \right\vert$$

### n = 2

$$A^{ -1 } = \frac{ 1 }{ \text{ det } A } 
\left[
\begin{array}{}
a_{ 22 }  & -a_{ 12 } \\
-a_{ 21 } & a_{ 11 }
\end{array}
\right]$$

---

參考資料:

工程數學課本

---

link:

