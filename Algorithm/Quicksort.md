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

# Time Complexity

If the array is extremely unbalanced, meaning that we choose the biggest or smallest element as pivot:

$$
T(n) = 
\left\{
	
\right.
$$

---

參考資料:

Algorithm class

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.