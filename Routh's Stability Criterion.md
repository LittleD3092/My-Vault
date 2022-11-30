標籤: #automatic-control 

---

[TOC]

---

Routh's stability criterion tells us whether there are unstable roots in a polynomial equation without actually solving for them.

The procedure in Routh's stability criterion is as follows:

1. Write the polynomial in $s$ in the following form:
$$a_0 s^n + a_1 s^{n - 1} + \dots + a_{n - 1}s + a_n = 0$$
The coefficients are real quantities. We assume $a_n \neq 0$, which means that any zero root has been removed.
2. If any of the coefficients are zero or negetive while at least one coefficient is positive, there exist imaginary root and the system is unstable.

> Step 2 checks for absolute stability analysis. If you only need to know whether the system has absolute stability, you can stop here.

3. If all the coefficients are positive, arrange the coefficients in the following pattern:
$$
\begin{array}{l}
	s^n & a_0 & a_2 & a_4 & a_6 & \dots \\
	s^{n - 1} & a_1 & a_3 & a_5 & a_7 & \dots \\
	s^{n - 2} & b_1 & b_2 & b_3 & b_4 & \dots \\
	s^{n - 3} & c_1 & c_2 & c_3 & c_4 & \dots \\
	s^{n - 4} & d_1 & d_2 & d_3 & d_4 & \dots \\
	\vdots & \vdots & \vdots \\
	s^2 & e_1 & e_2 \\
	s^1 & f_1 \\
	s^0 & g_1
\end{array}
$$
where
$$
\begin{array}{}
	\displaystyle b_1 = \frac{a_1a_2 - a_0a_3}{a_1} \\
	\displaystyle b_2 = \frac{a_1a_4 - a_0a_5}{a_1} \\
	\displaystyle b_3 = \frac{a_1a_6 - a_0a_7}{a_1} \\
	\vdots \\
\end{array}
$$
and
$$
\begin{array}{}
	\displaystyle c_1 = \frac{b_1 a_3 - a_1b_2}{a_1} \\
	\displaystyle c_2 = \frac{b_1a_5 - a_1b_3}{b_1} \\
	\displaystyle c_3 = \frac{b_1a_7 - a_1b_4}{b_1} \\
	\vdots
\end{array}
$$
This process is continued until the $n$th row has been completed. The complete array of coefficients is triangular.
4. The number of changes in sign of the coefficients in the first column means the number of roots with positive real parts.

> Special cases:
> - If a first-column term in any row is zero, and the sign of the coefficient above it is the **same** as below it, **there is a pair of imaginary root**.
> $$\begin{array}{} s^3 & 1 & 1 \\ s^2 & 2 & 2 \\ s^1 & 0 \approx \epsilon \\ s^0 & 2 \end{array}$$
> - If a first-column term in any row is zero, and the sign of the coefficient above it is the **opposite** as below it, **there is one sign change**.
> $$\begin{array}{} s^3 & 1 & -3 \\ s^2 & 0 \approx \epsilon & 2 \\ s^1 & \displaystyle -3 - \frac 2 \epsilon \\ s^0 & 2 \end{array}$$
> - The zeros are considered a very small value $\epsilon$ when constructing the array.
> - If all the coefficients in any derived **row** are **zero**, there are **two real roots with equal magnitudes** and opposite signs and/or **two conjugate imaginary roots**.
> In this case, the evaluation of the rest of the array can be formed by replacing the row with derivative of last row's [[Auxiliary Function]].
> $$\begin{array}{} s^5 & 1 & 24 & -25 \\ s^4 & 2 & 48 & -50 \\ s^3 & 0 & 0 \end{array}$$
> The $s^4$ has [[Auxiliary Function]]:
> $$P(s) = 2s^4 + 48s^2 - 50$$
> $$\implies\frac{dP(s)}{ds} = 8s^3 + 96s$$
> The $s^3$ row are replaced by $8$ and $96$. The array then becomes
> $$\begin{array}{} s^5 & 1 & 24 & -25 \\ s^4 & 2 & 48 & -50 \\ s^3 & 8 & 96 \\ s^2 & 24 & -50 \\ s^1 & 112.7 & 0 \\ s^0 & -50 \end{array}$$

# Relative Stability Analysis

Routh's stability criterion provides the answer to the question of **abslute stability**.
However, we sometimes want to know reletive stability.

A useful approach for it is substitute $s$:

$$s = \hat s - \sigma$$

Then apply Routh's stability criterion for $\hat s$.

---

參考資料:

Modern Control Engineering, 5th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.