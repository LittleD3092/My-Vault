標籤: #DataStructure 

---

From those integers that are currently unsorted, find the smallest and place it next in the sorted list.

```c
For(i = 0; i< n; i++)
{
	Examine list[i] to list[n-1] and
		suppose that smallest integer is list[min]
	Interchange list[i] & list[min]
}
```

```c
void sort(int list[], int n)
{
	for(i = 0; i < n - 1; i++)
	{
		min = i;
		for(j = i + 1; j < n; j++)
		{
			if(list[j] < list[min])
				min = j;
		}
			SWAP(list[i], list[min], temp);
	}
}
```

---

參考資料:

[Lec01 資料結構 第一週課程](https://youtu.be/3503j2L6qNA)

---

link:

[[Array]]