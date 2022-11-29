標籤: #工程數學 

---

[[Laplace Transform]] 反過來算，分成兩個方法

- [[#方法一 One-to-One Relation]]
- [[#方法二 Decomposition of Fractions]]

# 方法一: One-to-One Relation

[[Laplace Transform]] 是怎麼算的，Inverse Laplace Transform 就算回去

| $$F(s)$$                 | $$L^{-1}\{F(s)\}$$                           |
| ------------------------ | -------------------------------------------- |
| $$\frac{1}{s}$$          | $$1$$                                        |
| $$\frac{n!}{s^{n + 1}}$$ | $$t^n$$                                      |
| $$\frac{1}{s - a}$$      | $$e^{at}$$                                   |
| $$\frac{k}{s^2 + k^2}$$  | $$\sin(kt)$$                                 |
| $$\frac{s}{s^2 + k^2}$$  | $$\cos(kt)$$                                 |
| $$\frac{k}{s^2 - k^2}$$  | $$\sinh(kt)$$                                |
| $$\frac{s}{s^2 - k^2}$$  | $$\cosh(kt)$$                                |
| $$e^{-t_0s}$$            | [[Dirac Delta Function]] $$\delta(t - t_0)$$ |

> if $\mathcal{ L }^{ -1 }\{ F(s) \} = f(t)$ then $$\mathcal{ L }^{ -1 }\{F(s - a)\} = e^{ at }f(t)$$
> Example:
> $$\mathcal{ L }^{ -1 }\left\{ \frac{ -32 }{ (s + 4)^2 } \right\}$$
> $$ = e^{ -4t }\mathcal{ L }^{ -1 }\left\{ \frac{ -32 }{ s^2 } \right\}$$
> $$ = -32te^{ -4t }$$

## example

$$L^{-1}\{\frac{1}{s^5}\}$$
.
$$L^{-1}\{\frac{1}{s^5}\} = \frac{1}{4!}L^{-1}\{\frac{4!}{s^5}\} = \frac{1}{4!}t^4$$

---

$$L^{-1}\{\frac{-2s + 6}{s^2 + 4}\}$$
.
$$L^{-1}\{\frac{-2s + 6}{s^2 + 4}\}
 = -2L^{-1}\{\frac{s}{s^2 + 4}\} + 3L^{-1}\{\frac{2}{s^2 + 4}\}
  = -2\cos(2t) + 3\sin(2t)$$

# 方法二: Decomposition of Fractions

將複雜的分數分解

## 通則

$$\frac
	{K(s)}
	{(s - a_1)(s - a_2)\dots (s - a_N)}
= 
	Q(s)
+
	\frac
		{A_1}
		{s - a_1}
+
	\frac
		{A_2}
		{s - a_2}
+
	\dots
+
	\frac
		{A_N}
		{s - a_N}
$$
$$\text{其中}\; a_1, \; a_2, \; a_N \; \text{互異}$$

### 第一步

用多項式除法算出 $Q(s)$

$$\frac{K(s)}
{(s - a_1)(s - a_2)\dots (s - a_N)}
=
Q(s)
+
\frac{K_1(s)}{(s - a_1)(s - a_2)\dots (s - a_N)}$$
$$\text{使}\; K_1(s) \; \text{的 order}\; < N$$

### 第二步

算出 $A_n$

$$
A_n
=
\left.
	\frac
	{K_1(s)}
	{
		(s - a_1)
		(s - a_2)
		\dots 
		(s - a_{n - 1})
		\underbrace{(s - a_n)}_{ = 1}
		(s - a_{n + 1})
		\dots
		(s - a_N)
	}
\right\vert_{s = a_n}
$$

## Example

$$
\frac{s^2 + 6s + 9}{(s - 1)(s - 2)(s + 4)} 
=
\frac{A}{s - 1} + \frac{B}{s - 2} + \frac{C}{s + 4}
$$
.
$$\text{解}\; A$$
$$
\frac{s^2 + 6s + 9}{(s - 2)(s + 4)}
=
A + \frac{(s - 1)B}{(s - 2)} + \frac{(s - 1)C}{s + 4}
$$
$$s = 1 \; \text{代入} \; \frac{-16}{5} = A$$
.
$$\text{解}\; B$$
$$
\frac{s^2 + 6s + 9}{(s - 1)(s + 4)}
=
\frac{(s - 2)A}{s - 1}
+
B
+
\frac{(s - 2)C}{s + 4}
$$
$$s = 2 \; \text{代入} \; \frac{25}{6} = B$$
.
$$\text{解} \; C$$
$$
\frac{s^2 + 6s + 9}{(s - 1)(s - 2)}
=
\frac{(s + 4)A}{s - 1}
+
\frac{(s + 4)B}{s - 2}
+
C
$$
$$s = -4 \; \text{代入} \; \frac{1}{30} = C$$

---

$$
\frac
	{s^4 - 8s^3 + 31s^2 - 36s + 20}
	{(s - 1)(s - 2)(s - 3)^2}
=
Q(s)
+
\frac
	{A_1}
	{s - 1}
+
\frac
	{A_2}
	{s - 2}
+
\frac
	{A_3 + A_4(s - 3)}
	{(s - 3)^2}
$$
.
$$
\frac
	{s^4 - 8s^3 + 31s^2 - 36s + 20}
	{(s - 1)(s - 2)(s - 3)^2}
=
1
+
\frac
	{s^3 + 2s^2 + 3s + 2}
	{(s - 1)(s - 2)(s - 3)^2}
$$
.
$$
A_1 
= 
\left. 
	\frac
		{s^3 + 2s^2 + 3s + 2}
		{\bcancel{(s - 1)}(s - 2)(s - 3)^2} 
\right\vert_{s = 1}
=
-\frac
	{8}
	{4}
=
-2
$$
$$
A_2 
=
\left. 
	\frac
		{s^3 + 2s^2 + 3s + 2}
		{(s - 1)\bcancel{(s - 2)}(s - 3)^2} 
\right\vert_{s = 2}
=
24
$$
$$
A_3
=
\left. 
	\frac
		{s^3 + 2s^2 + 3s + 2}
		{(s - 1)(s - 2)} 
\right\vert_{s = 3}
=
\frac
	{56}
	{2}
=
28
$$
$$
A_4
=
\left. 
	\frac
		{d}
		{ds}
	\frac
		{	
			s^3 
			+
			2s^2 
			+
			3s
			+
			2
		}
		{
			(s - 1)(s - 2)
		} 
\right\vert_{s = 3}
=
\left.
	\frac
		{
			(3s^2 + 4s + 3)(s - 1)(s - 2) 
			-
			(s^3 + 2s^2 + 3s + 2)(2s - 3)
		}
		{
			(s - 1)^2(s - 2)^2
		}
\right\vert_{s = 3}
=
-21
$$
.
$$
\frac
	{s^4 - 8s^3 + 31s^2 - 36s + 20}
	{(s - 1)(s - 2)(s - 3)^2}
=
1
-
\frac
	{2}
	{s - 1}
+
\frac
	{24}
	{s - 2}
+
\frac
	{28 - 21(s - 3)}
	{(s - 3)^2}
$$

---

參考資料:

[工數OCW - Class 21 - youtube](https://youtu.be/0sAa2XUDXMs)

[[Laplace Transform 解法]]