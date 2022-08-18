# Math Application Project 1

| ID number | Name   |
| --------- | ------ |
| 109611066 | 吳典謀 |
| 109611004 | 張瀚元 |
| 109611030 | 陳柏文 | 

## 1. Draw Vector Graph

![[vector graph math project 1.png]]

## 2. Scaling

2.a.

$$S = 
\left[
	\begin{array}{}
		s_x & 0 \\
		0 & s_y
	\end{array}
\right]$$

2.b. Find scaling matrix $S$

$$\vec{ v }_{ out } = S \vec{ v }_{ in }$$

$$S = 
\left[
	\begin{array}{}
		3 & 0 \\
		0 & 5
	\end{array}
\right]$$

2.c. List output vectors of $\vec{ v }_{ out }$

| $x_{ in }$ | $y_{ in }$ | $x_{ out }$ | $y_{ out }$ |
| ---------- | ---------- | ----------- | ----------- |
| 1.0        | 0.0        | 3.0         | 0.0         |
| 1.0        | 0.25       | 3.0         | 1.25        |
| 1.0        | 0.5        | 3.0         | 2.5         |
| 1.0        | 0.75       | 3.0         | 3.75        |
| 1.0        | 1.0        | 3.0         | 5.0         |
| 0.75       | 1.0        | 2.25        | 5.0         |
| 0.5        | 1.0        | 1.5         | 5.0         |
| 0.25       | 1.0        | 0.75        | 5.0         |
| 0.0        | 1.0        | 0.0         | 5.0         |

2.d. Plot the graph of $\vec{ v }_{ out }$

![[Scaling math project 1.png]]

2.e. The matrix transformation stretches the vector by $3$ and $5$ in x and y axis, so we expect $(1, 0)$ and $(0, 1)$ to be our eigenvectors and the eigenvalues are $3$ and $5$.

2.f.

Eigenvalues:

$$\det
\left[
	\begin{array}{}
		3 - \lambda & 0 \\
		0 & 5 - \lambda
	\end{array}
\right]\vec{ v }_{ in } = \vec{ v }_{ out }$$

$$(3 - \lambda)(5 - \lambda) = 0$$

$$\underline{ \lambda = 3, 5 }_{ \# }$$

Eigenvectors:

$$\implies \text{ when }
\left\{
	\begin{array}{}
		\lambda = 3, & \text{ eigenvector } = \left[\begin{array}{}1 \\ 0\end{array}\right] \\
		\lambda = 5, & \text{ eigenvector } = \left[\begin{array}{}0 \\ -1\end{array}\right]
	\end{array}
\right.$$

It is the same as we expect. Because the scalar of eigenvector does not matter, $(0, -1)$ is the same as $(0, 1)$.

## 3. Rotation

3.a.

$$R = 
\left[
\begin{array}{}
	\cos\theta & -\sin\theta \\
	\sin\theta & \cos\theta
\end{array}
\right]$$

3.b. Find the rotation matrix

$$\vec{ v }_{ out } = R\vec{ v }_{ in }$$

$$\theta = -45\degree(45\degree CW) \implies R = 
\left[
	\begin{array}{}
		\cos(-45\degree) & -\sin(-45\degree) \\
		\sin(-45\degree) & \cos(-45\degree)
	\end{array}
\right]$$

$$ = 
\underline{ \left[
	\begin{array}{}
		\frac{ \sqrt{ 2 } }{ 2 } & \frac{ \sqrt{ 2 } }{ 2 } \\
		-\frac{ \sqrt{ 2 } }{ 2 } & \frac{ \sqrt{ 2 } }{ 2 }
	\end{array}
\right]}_{ \# }$$

$$\vec{ v }_{ out } = 
\left[
	\begin{array}{}
		\frac{ \sqrt{ 2 } }{ 2 } & \frac{ \sqrt{ 2 } }{ 2 } \\
		-\frac{ \sqrt{ 2 } }{ 2 } & \frac{ \sqrt{ 2 } }{ 2 }
	\end{array}
\right]\vec{ v }_{ in }$$

3.c. List output vectors and plot graph

| $x_{ in }$ | $y_{ in }$ | $x_{ out }$ | $y_{ out }$ |
| ---------- | ---------- | ----------- | ----------- |
| 1.0        | 0.0        | 0.71        | -0.71       |
| 1.0        | 0.25       | 0.88        | -0.53       |
| 1.0        | 0.5        | 1.06        | -0.35       |
| 1.0        | 0.75       | 1.24        | -0.18       |
| 1.0        | 1.0        | 1.41        | 0.00        |
| 0.75       | 1.0        | 1.24        | 0.18        |
| 0.5        | 1.0        | 1.06        | 0.35        |
| 0.25       | 1.0        | 0.88        | 0.53        |
| 0.0        | 1.0        | 0.71        | 0.71        |

![[rotation matrix math project 1.png]]

3.d. The matrix rotated the vectors clockwise by $45\degree$.

For rotation matrix, it won't change length, but only direction. So we can set eigenvalue to be polar coordinates $(\cos\theta, \sin\theta)$, which can be regarded as $\cos\theta + i\sin\theta$. So that eigenvector could be

$$\left[
	\begin{array}{}
		\cos\theta - \cos\theta - i\sin\theta & -\sin\theta \\
		\sin\theta & \cos\theta - \cos\theta - i\sin\theta
	\end{array}
\right\vert
\left.
	\begin{array}{}
		0 \\
		0
	\end{array}
\right]$$

$$\implies \vec{ x }^{ (1) } = 
\left[
	\begin{array}{}
		1 \\
		i
	\end{array}
\right]$$

3.e.

$$
\left\vert
	\begin{array}{}
		\cos\theta - \lambda & -\sin\theta \\
		\sin\theta & \cos\theta - \lambda
	\end{array}
\right\vert = (\cos^2\theta - 2\lambda\cos\theta + \lambda^2) + \sin^2\theta
$$

$$ = \lambda^2 - 2\cos\theta \lambda + 1$$

$$\implies \lambda = \frac{ 2\cos\theta \pm \sqrt{ 4\cos^2\theta - 4 } }{ 2 } = \cos\theta \pm i\sin\theta$$

$$\lambda_1 = \cos\theta + i\sin\theta$$

$$\implies
\left[
\begin{array}{}
	-i\sin\theta & -\sin\theta \\
	\sin\theta & -i\sin\theta
\end{array}
\right\vert
\left.
	\begin{array}{}
		0 \\
		0
	\end{array}
\right]$$

$$\implies \vec{ x }^{ (1) } = 
\left[
	\begin{array}{}
		i \\
		1
	\end{array}
\right]$$

$$\lambda_2 = \cos\theta - i\sin\theta$$

$$\implies 
\left[
	\begin{array}{}
		i\sin\theta & -\sin\theta \\
		\sin\theta & i\sin\theta
	\end{array}
\right\vert
\left.
	\begin{array}{}
		0 \\
		0
	\end{array}
\right]$$

$$\vec{ x }^{ (2) } = 
\left[
	\begin{array}{}
		1 \\
		i
	\end{array}
\right]$$

## 4. Shearing

4.a.

$$H = 
\left[
	\begin{array}{}
		1 & Sh_x \\
		0 & 1
	\end{array}
\right]$$

4.b.

$$
\begin{array}{}
	x_{ out } & = & x_{ in } & + &2y_{ in } \\
	y_{ out } & = &&&y_{ in }
\end{array}
$$

$$\implies
\left[
	\begin{array}{}
		1 & 2 \\
		0 & 1
	\end{array}
\right]
\left[
	\begin{array}{}
		x_{ in } \\
		y_{ in }
	\end{array}
\right] = 
\left[
	\begin{array}{}
		x_{ out } \\
		y_{ out }
	\end{array}
\right]$$

$$\implies H = 
\left[
	\begin{array}{}
		1 & 2 \\
		0 & 1
	\end{array}
\right]$$

4.c.

| $x_{ in }$ | $y_{ in }$ | $x_{ out }$ | $y_{ out }$ |
| ---------- | ---------- | ----------- | ----------- |
| 1.0        | 0.0        | 1.00        | 0.00        |
| 1.0        | 0.25       | 1.50        | 0.25        |
| 1.0        | 0.5        | 2.00        | 0.50        |
| 1.0        | 0.75       | 2.50        | 0.75        |
| 1.0        | 1.0        | 3.00        | 1.00        |
| 0.75       | 1.0        | 2.75        | 1.00        |
| 0.5        | 1.0        | 2.50        | 1.00        |
| 0.25       | 1.0        | 2.25        | 1.00        |
| 0.0        | 1.0        | 2.00        | 1.00        |

![[shear transform math project 1.png]]

4.d. Because $H_{ 21 }$ is zero, the eigenvector can only be $\left[\begin{array}{} 1 \\ 0 \end{array}\right]$ and because $H_{ 11 } = H_{ 22 }$, the eigenvalue has the same value of $H_{ 11 }$, which is $1$.

4.e.

$$\det
\left[
	\begin{array}{}
		1 - \lambda & 2 \\
		0 & 1 - \lambda
	\end{array}
\right] = 0$$

$$\implies \lambda = 1$$

$$\implies \text{ eigenvector } = 
\left[
	\begin{array}{}
		1 \\
		0
	\end{array}
\right]$$

It is the same as we expected.

## 5. Combination

5.a. 

$$C\vec{ v }_{ in }$$

$$ = 
\left[
	\begin{array}{}
		1 & 2 \\
		0 & 1
	\end{array}
\right]
\left[
	\begin{array}{}
		\frac{ \sqrt{ 2 } }{ 2 } & -\frac{ \sqrt{ 2 } }{ 2 } \\
		\frac{ \sqrt{ 2 } }{ 2 } & \frac{ \sqrt{ 2 } }{ 2 }
	\end{array}
\right]
\left[
	\begin{array}{}
		2 & 0 \\
		0 & 2
	\end{array}
\right]\vec{ v }_{ in }$$

$$ = \sqrt{ 2 }
\left[
	\begin{array}{}
		1 & 2 \\
		0 & 1
	\end{array}
\right]
\left[
	\begin{array}{}
		1 & -1 \\
		1 & 1
	\end{array}
\right]
\left[
	\begin{array}{}
		1 & 0 \\
		0 & 1
	\end{array}
\right]\vec{ v }_{ in }$$

$$ = \sqrt{ 2 }
\left[
	\begin{array}{}
		1 & 2 \\
		0 & 1
	\end{array}
\right]
\left[
	\begin{array}{}
		1 & -1 \\
		1 & 1
	\end{array}
\right]\vec{ v }_{ in }$$

$$ = \sqrt{ 2 }
\left[
	\begin{array}{}
		3 & 1 \\
		1 & 1
	\end{array}
\right]\vec{ v }_{ in }$$

$$ = \left[
	\begin{array}{}
		3\sqrt{ 2 } & \sqrt{ 2 } \\
		\sqrt{ 2 } & \sqrt{ 2 }
	\end{array}
\right]\vec{ v }_{ in }$$

$$\implies C = 
\left[
	\begin{array}{}
		3\sqrt{ 2 } & \sqrt{ 2 } \\
		\sqrt{ 2 } & \sqrt{ 2 }
	\end{array}
\right]$$

5.b.

| $x_{ in }$ | $y_{ in }$ | $x_{ out }$ | $y_{ out }$ |
| ---------- | ---------- | ----------- | ----------- |
| 1.0        | 0.0        | 4.24        | 1.41        |
| 1.0        | 0.25       | 4.60        | 1.77        |
| 1.0        | 0.5        | 4.95        | 2.12        |
| 1.0        | 0.75       | 5.30        | 2.47        |
| 1.0        | 1.0        | 5.66        | 2.83        |
| 0.75       | 1.0        | 4.60        | 2.47        |
| 0.5        | 1.0        | 3.54        | 2.12        |
| 0.25       | 1.0        | 2.47        | 1.77        |
| 0.0        | 1.0        | 1.41        | 1.41        |

![[combination math project 1.png]]

5.c. 
The matrix transformations are as follow:
1. Scaling both $x$ axis and $y$ axis by $2$
2. Counterclockwise rotation by $45\degree$
3. Shearing using matrix $\left[\begin{array}{} 1 & 2 \\ 0 & 1 \end{array}\right]$

The eigenvectors and eigenvalues will contain $\sqrt{ 2 }$ part because there is a counterclockwise rotation for $45\degree$. And because $C$ contains a counterclockwise rotation for $45 \degree$, it's eigenvalue will be $a\sqrt{ 2 } + b$ and $a\sqrt{ 2 } - b, \; a, b \in N$.

5.d.

$$\det
\left[
	\begin{array}{}	
		3\sqrt{ 2 } - \lambda & \sqrt{ 2 } \\
		\sqrt{ 2 } & \sqrt{ 2 } - \lambda
	\end{array}
\right] = 0$$

$$\lambda^2 - 4\sqrt{ 2 }\lambda + 4 = 0$$

$$\lambda = \frac{ 4\sqrt{ 2 } \pm \sqrt{ 32 - 16 } }{ 2 } = 2\sqrt{ 2 } \pm 2$$

$$
\left\{
	\begin{array}{}
		\lambda_1 = 2 + 2\sqrt{ 2 }, & \text{ eigenvector } = \left[\begin{array}{} \sqrt{ 2 } \\ 2 - \sqrt{ 2 } \end{array}\right] \\
		\lambda_2 = -2 + 2\sqrt{ 2 }, & \text{ eigenvector } = \left[\begin{array}{} 2 - \sqrt{ 2 } \\ -\sqrt{ 2 } \end{array}\right]
	\end{array}
\right.
$$

The eigenvalues and eigenvectors are as same as we expected.

5.e.

$$\det
\left[
	\begin{array}{}
		3\sqrt{ 2 } & \sqrt{ 2 } \\
		\sqrt{ 2 } & \sqrt{ 2 }
	\end{array}
\right] = 4$$

$$C^{ -1 } = \frac{ 1 }{ 4 }
\left[
	\begin{array}{}
		\sqrt{ 2 } & -\sqrt{ 2 } \\
		-\sqrt{ 2 } & 3\sqrt{ 2 }
	\end{array}
\right] = 
\left[
	\begin{array}{}
		\frac{ \sqrt{ 2 } }{ 4 } & \frac{ -\sqrt{ 2 } }{ 4 } \\
		\frac{ -\sqrt{ 2 } }{ 4 } & \frac{ 3\sqrt{ 2 } }{ 4 }
	\end{array}
\right]$$

5.f.

$$C^{ -1 }C = \left[
	\begin{array}{}
		\frac{ \sqrt{ 2 } }{ 4 } & \frac{ -\sqrt{ 2 } }{ 4 } \\
		\frac{ -\sqrt{ 2 } }{ 4 } & \frac{ 3 \sqrt{ 2 } }{ 4 }
	\end{array}
\right]
\left[
	\begin{array}{}
		3\sqrt{ 2 } & \sqrt{ 2 } \\
		\sqrt{ 2 } & \sqrt{ 2 }
	\end{array}
\right]
$$

$$ = \frac{ 1 }{ 2 }
\left[
	\begin{array}{}
		1 & -1 \\
		\sqrt{ 2 } & \sqrt{ 2 }
	\end{array}
\right]
\left[
	\begin{array}{}
		3 & 1 \\
		1 & 1
	\end{array}
\right]
$$

$$
= \frac{ 1 }{ 2 }\left[
	\begin{array}{}
		2 & 0 \\
		0 & 2
	\end{array}
\right]
$$

$$ = 
\left[
	\begin{array}{}
		1 & 0 \\
		0 & 1
	\end{array}
\right]$$

We get identity matrix, which means we will get the original input vector with $\vec{ v }_{ out }C^{ -1 }C\vec{ v }_{ in }$