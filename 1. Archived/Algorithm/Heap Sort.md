標籤: #algorithm 

---

[TOC]

---

It is recommended that you first understand [[Heap]] before studying this note.

The heap sort contains the following concepts:

- [[#Heapification]]
- [[#Building a Max Heap]]
- [[#Extracting the Max]]

After you understand these concepts, go to [[#Heap Sort]]. You will find out that the heap sort depend on the functions you studied earlier.

# Heapification

```cpp
Max_Heapify(A, i)
```

The $\text{MAX-HEAPIFY}$ process assumes that the binary trees rooted at $\text{LEFT}(i)$ and $\text{RIGHT}(i)$ are max-heaps, but that $A[i]$ might be smaller than its children. It uses the following process:

> If the root is greater than two of its children, it's done. Otherwise, swap the bigger child with parent.

$$
\begin{array}{l}
	& \text{MAX-HEAPIFY}(A, i) \\ 
	1 & l = \text{LEFT}(i) \\
	2 & r = \text{RIGHT}(i) \\
	3 & \textbf{if } l \leq A.heap\text-size \text{ and } A[l] > A[i] \\
	4 & \qquad largest = l \\
	5 & \textbf{else } largest = i \\
	6 & \textbf{if } r \leq A.heap\text-size \text{ and } A[r] > A[largest] \\
	7 & \qquad largest = r \\
	8 & \textbf{if } largest \neq i \\
	9 & \qquad \text{exchange } A[i] \text{ with } A[largest] \\
	10 & \qquad \text{MAX-HEAPIFY}(A, largest)
\end{array}
$$

This method lets the value at $A[i]$ "float down" in the max-heap so that the subtree rooted at index $i$ obeys the max-heap property.

The time complexity of it is equal to the height of the tree:

$$O(\log n)$$

# Building a Max Heap

To build a max heap, we use the following process:

```cpp
Build_Max_Heap(A, i)
{
	Build_Max_Heap(A, Left(i));
	Build_Max_Heap(A, Right(i));
	Max_Heapify(A, i);
}
```

For the time complexity, we guess that it is

$$2T(n/2) + O(\log n)$$

By master theorem, the guess implies that $T(n) = O(n)$.

# Extracting the Max

To remove the max node, we use the following process:

```cpp
Extract_Max(A, int& n)
{
	int ret = A[1];
	A[1] = A[n--];
	Max_Heapify(A, 1);
	return ret;
}
```

Because max heapify takes $O(\log n)$ time, the algorithm `extract_max` takes $O(\log n)$ time.

# Heap Sort

- Input: an array $A$ of $n$ integers.
- Output: the same array with the $n$ integers ordered nondecrementally.

```cpp
Heapsort(A, n)
{
	Build_Max_Heap(A, 1);
	while(n > 1)
	{
		k = Extract_Max(A, n);
		A[n + 1] = k;
	}
}
```

There are $O(n)$ loop iterations, and each needs $O(\log n)$ time. In total, the running time is $O(n\log n)$.

---

參考資料:

Algorithm class

---

link:

[[Heap]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.