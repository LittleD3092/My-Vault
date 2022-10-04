標籤: #algorithm 

---

[TOC]

---

The heap sort contains the following concepts:

- [[#Heapification]]
- [[#Building a Max Heap]]
- [[#Extracting the Max]]

After you understand these concepts, go to [[#Heap Sort]]. You will find out that the heap sort depend on the functions you studied earlier.

# Heapification

```cpp
Max_Heapify(A, i)
```

The max heapify process changes an array into a heap. It uses the following process.

If the root is greater than two of its children, it's done. Otherwise, swap the bigger child with parent.

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