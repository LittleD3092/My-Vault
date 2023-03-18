標籤: #工程數學 

---

測驗線性獨立的方法

# Differential Equations

 $$W(y_1, y_2, \dots, y_n) = \text{det}\begin{bmatrix}
  y_1         & y_2         & \dots  & y_n    \\
  y_1'        & y_2'        & \dots  & y_n'   \\
  \vdots      & \vdots      & \ddots & \vdots \\
  y_1^{(n-1)} & y_2^{(n-1)} & \dots  & y_n^{(n-1)} \end{bmatrix} $$
$$W(y_1, y_2,\dots , y_n) \neq 0 \rightarrow \text{linearly independent}$$
雖然有這個方法，但是更快的還是用看的(型態不同，指數不同，則線性獨立)

---
 
## Example
$$y''' - 6y'' - 11y' - 6y = 0$$
$$y_1 = e^x, y_2 = e^{2x}, \text{and}\; y_3 = e^{3x} \;\text{are three of the solutions}$$
Since
$$\text{det} \begin{bmatrix} y_1 & y_2 & y_3 \\ y_1' & y_2' & y_3' \\ y_1'' & y_2'' & y_3'' \end{bmatrix} = \begin{bmatrix} e^x & e^{2x} & e^{3x} \\ e^x & 2e^{2x} & 3e^{3x} \\ e^x & 4e^{2x} & 9e^{3x} \end{bmatrix} = e^{x + 2x + 3x} \begin{bmatrix} 1 & 1 & 1 \\ 1 & 2 & 3 \\ 1 & 4 & 9 \end{bmatrix} = 2e^{6x} \neq 0$$
Therefore, $y_1$, $y_2$, and $y_3$ are linear independent for any $x$
general solution:
$$y = c_1e^x + c_2e^{2x} + c_3e^{3x} \qquad x \in (-\infty , \infty)$$

# Vectors

$$W({\bf v}_1, {\bf v}_2, \dots, {\bf v}_n) = 
\det\left[
	\begin{array}{}
		{\bf v}_1 &
		{\bf v}_2 &
		\dots &
		{\bf v}_n
	\end{array}
\right]$$

$$
\begin{array}{}
	W({\bf v}_1, {\bf v}_2, \dots, {\bf v}_n) = 0 & \implies & \text{linear dependent} \\
	W({\bf v}_1, {\bf v}_2, \dots, {\bf v}_n) \neq 0 & \implies & \text{linear independent}
\end{array}
$$

## Example

Determine whether the vectors $(4, 2, 3)^T$, $(2, 3, 1)^T$, $(2, -5, 3)^T$ are linearly dependent.

---

Since 

$$
\left\vert
	\begin{array}{}
		4 & 2 & 2 \\
		2 & 3 & -5 \\
		3 & 1 & 3
	\end{array}
\right\vert = 0
$$

It is *linearly dependent*.

---

參考資料:

Linear Algebra with Applications, 10th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.