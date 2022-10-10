標籤: #algorithm

---

[TOC]

---

# Concept

This sorting algorithm is a classic example of [[Divide-and-Conquer Approach]]. It operates as follows:

1. Divide: Divide the $n$-element sequence to be sorted into two subsequences of $n / 2$ elements each.
2. Conquer: Sort the two subsequences recursively using merge sort.
3. Combine: Merge the two sorted subsequences to produce the sorted answer.

# Merge

The key operation of the merge sort algorithm is the merging of two sorted sequences in the "combine" step. We use `MERGE(A, p, q, r)` to do the job, where $A$ is an array and $p, q$, and $r$ are indices into the array such that $p \leq q < r$.

The `MERGE(A, p, q, r)` assumes that the subarrays $A[p..q]$ and $A[q + 1.. r]$ are sorted subarrays. It merges them to form a single sorted subarray that replaces the current subarray $A[p..r]$.

The following [[Pseudocode]] implements the idea. Note that we use $\infty$ as the sentinel value, if this value is exposed, it cannot be the smaller card. This procudure simplifies our code.

$$
\begin{array}{l}
	1 & n_1 = q - p + 1 \\
	2 & n_2 = r - q \\
	3 & \text{let } L[1..n_1 + 1] \text{ and } R[1..n_2 + 1] \text{ be new arrays} \\
	4 & \text{\bf for } i = 1 \text{\bf  to } n_1 \\
	5 & \qquad L[i] = A[p + i - 1] \\
	6 & \text{\bf for } j = 1 \text{ \bf to } n_2 \\
	7 & \qquad R[j] = A[q + j] \\
	8 & L[n_1 + 1] = \infty \\
	9 & R[n_2 + 1] = \infty \\
	10 & i = 1 \\
	11 & j = 1 \\
	12 & \text{\bf for } k = p \text{ \bf to } r \\
	13 & \qquad \text{\bf if } L[i] \leq R[j] \\
	14 & \qquad \qquad A[k] = L[i] \\
	15 & \qquad \qquad i = i + 1 \\
	16 & \qquad \text{\bf else } A[k] = R[j] \\
	17 & \qquad \qquad j = j + 1
\end{array}
$$

## Correctness

We must show that this [[Loop Invariants]] holds to show correctness when the loop terminates:

1. Initialization: The subarray $A[p..k - 1]$ is empty due to $p = k$. Also, the $L[i]$ and $R[j]$ are the smallest elements of their arrays.
2. Maintenance: Suppose $L[i]\leq R[j]$. $i$ and $k$ are incremented, which reestablishes the loop invariant for the next iteration. If $L[i] < R[j]$, then the else case perform the appropriate action to maintain the loop invariant.
3. Termination: At termination, $k = r + 1$. By the [[Loop Invariants]], the subarray $A[p..k - 1]$ (which is equivalent to $A[p..r]$) are in sorted order. All but the two largest have been copied back into $A$, and these two largest elements are the sentinels.

# Merge Sort

After we have [[#Merge]] procedure, we may use it as a subroutine in the merge sort algorithm. The [[Pseudocode]] is as follows:

$$
\begin{array}{l}
1 & \text{\bf if } p < r \\
2 & \qquad q = \left\lfloor (p + r) / 2 \right\rfloor \\
3 & \qquad \text{MERGE-SORT}(A, p, q) \\
4 & \qquad \text{MERGE-SORT}(A, q + 1, r) \\
5 & \qquad \text{MERGE}(A, p, q, r)
\end{array}
$$

The code block below is the C++ code of merge sort.

```cpp
void merge_sort(int *s, int n)
{
    if(n == 1)    return;
    
    int k = n / 2;
    merge_sort(s, k);
    merge_sort(s + k, n - k);

	int *r = merge(s, k, s + k, n - k);
	memcpy(s, r, sizeof(int) * n);
}
```

## Analyze

Recall that in [[Divide-and-Conquer Approach]], the analyze process has the following equation:

![[Divide-and-Conquer Approach#Analyze]]

Therefore, we break down the running time as follows:

- Divide: The divide step computes the middle of the subarray, which takes $D(n) = \Theta(1)$ time.
- Conquer: The algorithm recursively solve $2$ subproblems with each take $T(n / 2)$ time.
- Combine: The [[#Merge]] procedure takes $\Theta(n)$ time.

Based on the above, we rewrite the equations:

$$T(n) = 
\left\{
	\begin{array}{l}
		\Theta(1) & \text{if } n = 1, \\
		2T(n / 2) + \Theta(n) & \text{if }n > 1.
	\end{array}
\right.$$

Using the [[Recursion#Recursion Tree Method]]:

![[Pasted image 20221009020047.png]]

We find out that the [[Recursion#Recursion Tree Method|recursion tree]] has a total [[Tree#Level|level]] of $\lg n + 1$, and each [[Tree#Level|level]] has a cost of $cn$. Therefore the total time complexity would be $O(n\log n)$.

---

參考資料:

Notes from Algorithm Class

---

link:

