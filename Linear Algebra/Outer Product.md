Tag: #linear-algebra 
Previous: 
Link: 

---

[TOC]

---

$${\bf a} \times {\bf b} = 
\left\vert
	\left\vert
		\begin{array}{}
			\hat i & \hat j & \hat k \\
			a_1 & a_2 & a_3 \\
			b_1 & b_2 & b_3
		\end{array}
	\right\vert
\right\vert = 
\left[
	\begin{array}{}
		a_2b_3 -a_3 b_2 \\
		a_3 b_1 - a_1 b_3 \\
		a_1 b_2 - a_2 b_1
	\end{array}
\right] = 
\left[
	\begin{array}{}
		0 & -a_3 & a_2 \\
		a_3 & 0 & -a_1 \\
		-a_2 & a_1 & 0
	\end{array}
\right] {\bf b} \overset{\Delta}{=}{\bf a^\wedge b}$$

---

參考資料:

視覺SLAM十四講 從理論到實踐

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.