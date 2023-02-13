標籤: #algorithm 

---

[TOC]

---

# Problem

Input: given a rod of $n$ inches and a table of prices $p_i$ for $i=1, 2, \dots, n$ where $p_i$ denotes the price of a rod of $i$ inches.
Output: the maximum revenue obtainable by cutting up the rod and selling the prices.

Example:

Input:
```
n = 3
p = [0, 2, 5, 6]
```

Output:
```
7
```

We can split the rod to two half, one has a length of $2$, another has a length of $1$. According to the price table, we can get $5$ dollars for the $2$-inch rod, and $2$ dollars for the $1$-inch rod. This sums up to $7$ dollars, which is the maximum revenue.

# Divide and Conquer

1. Assume no cut, we sell the rod without cutting. Record the revenue as `max_revenue`.
2. Try to cut $1, 2, \dots, n - 1$ inches, and see if the revenue is bigger than the `max_revenue`.

```cpp
rod_cutting(n)
{
	int max_revenue = p[n]; // no cut

	// guess that the length of first cut is i inches
	foreach i in [1, 2, ..., n - 1]
		max_revenue = max(max_revenue, p[i] + rod_cutting(n - i));

	return max_revenue;
}
```

## Complexity

`rod_cutting(n)` will invode $\Theta(2^{n - 1})$ subproblems, but only $O(n)$ distinct ones.

# Divide and Conquer with Memorization

This is the [[#Divide and Conquer]] solution, plus the cache of the `rod_cutting` answers to make it faster.

```cpp
rod_cutting(n, cached_solution[])
{
	if(cached_solution[n] >= 0) 
	// cached_solution[] was -1 initially
		return cached_solution[n];

	int max_revenue = p[n]; // no cut
	
	// guess that the length of first cut is i inches
	foreach i in [1, 2, ..., n - 1]
		max_revenue = max(max_revenue, p[i] + rod_cutting(n - i, cached_solution[]));

	cached_solution[n] = max_revenue;
	return max_revenue;
}
```

## Complexity

$O(n)$ subproblems. Each needs $O(n)$ time to compute. In total, $O(n^2)$ time.

---

參考資料:

Introduction to Algorithm class

---

link:

[[Divide-and-Conquer Approach]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.