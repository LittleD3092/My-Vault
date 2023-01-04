標籤: #工程數學 #linear-algebra 
Previous: [[Orthogonal]]

---

# Definition

An $n \times n$ matrix $Q$ is said to be an **orthogonal matrix** if the column vectors of $Q$ form an [[Orthonormal Set|orthonormal set]] in $\text R^n$.

Also, an $n \times n$ matrix $Q$ is orthogonal if and only if 

$$Q^TQ = I$$

# Properties

![[a vector b vector.jpg|100]]

$$\theta = \cos^{ -1 }\left( \frac{ \vec{ a } \cdot \vec{ b } }{ \vert \vec{ a } \vert \vert \vec{ b } \vert } \right)$$

$$\vert \vec{ a } \vert = \sqrt{ a_1^2 + a_2^2 + \dots + a_n^2 }$$

- For an $n \times n$ orthogonal matrix $A$ and $\vec{ a }, \vec{ b }$
$$
\left.
\begin{array}{}
	\vec{ u } = A \vec{ a } \\
	\vec{ v } = A \vec{ b }
\end{array}
\right\}
\implies \vec{ u } \cdot \vec{ v } = \vec{ a } \cdot \vec{ b }
$$
- Orthogonal transform preserve length of any vector $\vec{ a }$ in $R^n$
- Orthogonal transform in 2D or 3D is a rotation (with perhaps a reflection)
- For an orthogonal matrix $A$:

$$A^T = A^{ -1 } \quad (A^T A = I)$$

- A matrix is orthogonal if and only if its column vectors $\vec{ a }_{ 1 }, \vec{ a }_{ 2 }, \dots, \vec{ a }_n$ (and row vectors form an orthogonal system)

$$\vec{ a }_j \cdot \vec{ a }_{ k } = a_j^T a_k = \left\{ \begin{array}{} 0 & \text{ if } & j \neq k \\ 1 & \text{ if } & j = k \end{array} \right.$$

---

參考資料:

工程數學上課

---

link:

