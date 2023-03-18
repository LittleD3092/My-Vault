標籤: #algorithm 

---

[TOC]

---

Sleep sort is a sorting way that uses multithreading. As you can see in [[Sort]], most sorting algorithms have a time complexity of $n\log n$. This is because these algorithms are comparison based. Sleep sort doesn't use comparison, therefore it can theoretically break the $n\log n$ time complexity limit.

Sleep sort has a pseudo-code as follows:

```cpp
SleepSort(A, n)
{
	for(i in [1, n])
	{
		fork a child thread to do
		{
			sleep A[i] * U seconds;
			print A[i];
		}
	}
}
```

For example, if we have an array `[1, 2, 3]`, the program will wait `1` second and output `1`; wait `2` seconds and output `2`; wait `3` seconds and output `3`. The total time used is `3` seconds.

What if we reduce the interval? What if we use `1` milisecond instead of `1` second? The whole process can be faster and faster, therefore break the $n\log n$ time complexity limit.

In theory, it works perfectly, but in real life, our computer cannot handle, say 1 million threads, because a common computer only have at most 16 cores!

Therefore, this algorithm may be good when the size of array is small enough, but when the size of the array become infinitely large, it is not ideal to run this on a computer.

---

參考資料:

Algorithm class

---

link:

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.