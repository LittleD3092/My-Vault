標籤: #工程數學 

---

掐頭去尾插三下

$$\vec{ a } \times \vec{ b } = \vec{ c }$$

$$
\implies
\bcancel{ \cancel{ \begin{array}{}
	a_1 \\
	b_1
\end{array} } }
\begin{array}{}
	a_2 & a_3 & a_1 & a_2 \\
	b_2 & b_3 & b_1 & b_2
\end{array}
\bcancel{ \cancel{ 
\begin{array}{}
	a_3 \\
	b_3
\end{array}
} }
$$

$$
\implies
\begin{array}{}
	a_2 && a_3 && a_1 && a_2 \\
	& \times && \times && \times \\
	b_2 && b_3 && b_1 && b_2
\end{array}
$$

$$
\implies
c_1 = 
\left\vert
	\begin{array}{}
		a_2 & a_3 \\
		b_2 & b_3
	\end{array}
\right\vert
\quad 
c_2 = 
\left\vert
	\begin{array}{}
		a_3 & a_1 \\
		b_3 & b_1
	\end{array}
\right\vert
\quad 
c_3 = 
\left\vert
	\begin{array}{}
		a_1 & a_2 \\
		b_1 & b_2
	\end{array}
\right\vert
$$

# Linear Operation Conversion

Note that cross product can also be written in linear operation form:

$${\bf a} \times {\bf b} = 
\left\vert\left\vert
	\begin{array}{}
		{\bf i} & {\bf j} & {\bf k} \\
		a_1 & a_2 & a_3 \\
		b_1 & b_2 & b_3
	\end{array}
\right\vert\right\vert = 
\left[
	\begin{array}{}
		a_2b_3 - a_3 b_2 \\
		a_3 b_1 - a_1 b_3 \\
		a_1 b_2 - a_2 b_1
	\end{array}
\right]$$

$$ = 
\left[
	\begin{array}{}
		0 & -a_3 & a_2 \\
		a_3 & 0 & -a_1 \\
		-a_2 & a_1 & 0
	\end{array}
\right]{\bf b} = {\bf a} \wedge {\bf b}$$

As the above shown, cross product can be represented by a multiplication of a [[Skew Symmetric]] [[Matrix]] and [[Vector]].

---

參考資料:

工程數學上課

---

link:

