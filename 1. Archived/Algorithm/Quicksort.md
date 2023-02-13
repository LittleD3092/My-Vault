標籤: #algorithm 

---

[TOC]

---

The algorithm `Quicksort` is for sorting an array `A` with size `n`. This method uses an element in an array, which is called "pivot", to split the array into a subarray which is smaller than or equal to pivot, and a subarray which is bigger than pivot. 

The pseudo-code is as follows:

```cpp
Quicksort(A, n)
{
	pick an arbitrary integer k (called pivot) from A;
	partition A into two subarrays S and L so that
		(1) S contains all element in A less than or equal to k;
		(2) L contains the rest;
	Quicksort(S, |S|); Quicksort(L, |L|);
}
```

# Partition

The key to the algorithm is the $\text{PARITION}$ procedure, which rearranges the subarray $A[p, r]$ inplace.

$$
\begin{array}{l}
	& \text{PARTITION}(A, p, r) \\
	1 & x = A[r] \\
	2 & i = p - 1 \\
	3 & \textbf{for } j = p \textbf{ to } r - 1 \\
	4 & \qquad \textbf{if } A[j] \leq x \\
	5 & \qquad \qquad i = i + 1 \\
	6 & \qquad \qquad \text{exchange } A[i] \text{ with } A[j] \\
	7 & \text{exchange } A[i + 1] \text{ with } A[r] \\
	8 & \textbf{return }i + 1
\end{array}
$$

# Time Complexity

If the array is extremely unbalanced, meaning that we always choose the biggest or smallest element as pivot:

$$
T(n) = 
\left\{
	\begin{array}{ll}
		T(n - 1) + O(n) & \text{if } n \geq 2 \\
		O(1) & \text{if } n = 1
	\end{array}
\right.
$$

$$
\begin{array}{l}
	\implies & T(n) & \leq & T(n - 1) + cn \\
	& & \leq & T(n - 2) + c(n - 1) + cn \\
	& & \leq & \dots \\
	&& \leq & c[n + (n - 1) + \dots + 1] \\
	&& = & c\sum_{i = 1}^n i \\
	&& = & c \frac{n(n + 1)}{2} \\
	&& = & O(n^2)
\end{array}	
$$

If the array is extremly balanced, we split and get two subarrays that have approximately equal sizes. One may have $\lfloor n / 2 \rfloor$, another one may have $\lceil n / 2 \rceil$.

$$T(n) = 
\left\{
	\begin{array}{l}
	T(\lfloor n /2\rfloor) + T(\lceil n / 2 \rceil) + O(n) & \text{if } n \geq 2 \\
	O(1) & \text{if } n = 1
	\end{array}
\right.$$

by master theorem, we get $T(n) = O(n\log n)$.

If almost unbalanced (we assume $\vert S\vert : \vert L\vert$ is always $9:1$)

$$O(n\log n)$$

## Average Case

We have seen the previous cases, and obviously quicksort algorithm have a time complexity of $O(n^2)$. But does the worst case occurs frequently? Let's see the average case.

We use $\sum$ to average all the cases.

$$T(n) = \left\{
	\begin{array}{l}
		\frac 1 n \sum_{i = 0}^{n - 1} (T(i) + T(n - i - 1)) + O(n) & \text{if } n\geq 2 \\
		1 & \text{if } n = 1
	\end{array}
\right.$$

$$\implies O(n\log n)$$

You can see that in the average case, the time complexity is $n\log n$. This property make quicksort fast in many cases, and therefore, it is useful.

---

參考資料:

Algorithm class

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.