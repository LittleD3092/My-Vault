Tag: #動力學 
Previous: 
Link: [[Rigid Body]], [[Basis]], [[Orthogonal Matrix]]

---

[TOC]

---

機器人的應用中，我們會需要使用到不只一種座標系。最常使用到的就是機器人有一組座標系，而環境本身也設置一個世界座標系。機器人的座標系會跟著機器移動，世界座標系則不移動。由於會使用到不只一種座標系，我們時常需要利用一個矩陣T來做轉換。此變換適用於剛體運動，稱為歐氏變換。

# Only Rotation

首先我們僅考慮旋轉，試著推導旋轉矩陣。我們假設某個單位正交基（unit orthogonal basis）$({\bf e}_1, {\bf e}_2, {\bf e}_3)$ 經過了旋轉變成 $({\bf e}'_1, {\bf e}_2', {\bf e}_3')$，而向量 ${\bf a}$ 在兩個座標系下的座標為 $[a_1, a_2, a_3]^T$ 與 $[a_1', a_2', a_3']^T$。我們可以寫下關係：

$$[{\bf e}_1, {\bf e}_2, {\bf e}_3]
\left[
	\begin{array}{}
		a_1 \\
		a_2 \\
		a_3
	\end{array}
\right] = 
[{\bf e}_1', {\bf e}_2', {\bf e}_3']
\left[
	\begin{array}{}
		a_1' \\
		a_2' \\
		a_3'
	\end{array}
\right]
$$

因為 $({\bf e}_1, {\bf e}_2, {\bf e}_3)$ 與 $({\bf e}_1', {\bf e}_2', {\bf e}_3')$ 皆為正交的基，並且[[Orthogonal Matrix|正交矩陣]]有以下性質：

$${\bf Q}^T{\bf Q} = {\bf I}$$

所以我們對兩邊同乘 $[{\bf e}_1, {\bf e}_2, {\bf e}_3]^T$：

$$
\left[
	\begin{array}{}
		a_1 \\
		a_2 \\
		a_3
	\end{array}
\right] = 
\left[
	\begin{array}{}
		{\bf e}_1^T {\bf e}_1' & {\bf e}_1^T {\bf e}_2' & {\bf e}_1^T {\bf e}_3' \\
		{\bf e}_2^T {\bf e}_1' & {\bf e}_2^T {\bf e}_2' & {\bf e}_2^T {\bf e}_3' \\
		{\bf e}_3^T {\bf e}_1' & {\bf e}_3^T {\bf e}_2' & {\bf e}_3^T {\bf e}_3'
	\end{array}
\right]
\left[
	\begin{array}{}
		a_1' \\
		a_2' \\
		a_3'
	\end{array}
\right] \overset \Delta = {\bf R}{\bf a}'
$$

我們將式中的矩陣定義為旋轉矩陣 ${\bf R}$，此矩陣代表著旋轉的動作。旋轉矩陣是一個行列式為 $1$ 的[[Orthogonal Matrix|正交矩陣]]，所以我們將旋轉矩陣的集合定義為特殊正交群（Special Orthogonal Group），用來代表三維矩陣的旋轉。

$${\rm SO}(n) = \{
	{\bf R} \in \mathbb R^{n \times n} \vert
	{\bf R}{\bf R}^T, \det({\bf R}) = 1
\}$$

# Rotation and Translation

在歐氏變換中，除了旋轉還有平移。考慮世界座標系中的向量 ${\bf a}$，經過一次旋轉和一次平移後可以得到 ${\bf a}'$：

$${\bf a}' = {\bf R}{\bf a} + {\bf t}$$

為了用一個變換矩陣 ${\bf T}$ 來表示，我們利用齊次座標將上式變為以下的式子：

$$
\left[
	\begin{array}{}
		{\bf a}' \\
		1
	\end{array}
\right] = 
\left[
	\begin{array}{}
		{\bf R} & {\bf t} \\
		{\bf 0}^T & 1
	\end{array}
\right]
\left[
	\begin{array}{}
		{\bf a} \\
		1
	\end{array}
\right] \overset \Delta = {\bf T}\left[
	\begin{array}{}
		{\bf a} \\
		1
	\end{array}
\right]
$$

如同我們上面定義了旋轉矩陣的集合，我們一樣定義變換矩陣 ${\bf T}$ 的集合為特殊歐氏群（Special Euclidean Group）：

$$
{\rm SE}(3) = 
\left\{
	{\bf T} = 
	\left[
		\begin{array}{}
			{\bf R} & {\bf t} \\
			{\bf 0}^T & 1
		\end{array}
	\right] \in 
	\mathbb R^{4 \times 4} \vert {\bf R} \in {\rm SO}(3), {\bf t} \in \mathbb R^3
\right\}
$$

---

參考資料:

視覺SLAM十四講 從理論到實踐

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.