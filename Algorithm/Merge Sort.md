標籤: #algorithm

---

[TOC]

---


# Code

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

---

參考資料:

Notes from Algorithm Class

---

link:

