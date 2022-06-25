標籤: #DataStructure 

---

In [[Time Complexity]], we used steps to determine the run time of programs. However, determining the exact step count is a difficult task and expending effort to determine exact steps is not worth, since the notion of a step is itself inexact. Therefore we use "Big-O Notation".

Big-O Notation 會考慮最糟糕的情況大約會需要多長時間執行程式

# 概念

n: The size of the input

| Time              | Big-O Notation   |
| ----------------- | ---------------- |
| Constant Time     | $O(1)$           |
| Logarithmic Time  | $O(\log(n))$     |
| Linear Time       | $O(n)$           |
| Linearithmic Time | $O(n\log(n))$    |
| Quadric Time      | $O(n^2)$         |
| Cubic Time        | $O(n^3)$         |
| Exponential Time  | $O(b^n),\ b > 1$ |
| Factorial Time    | $O(n!)$          | 

# Properties

$$O(n + c) = O(n)$$

$$O(cn) = O(n), \quad c > 0$$

- 因為 $n$ 是趨近無限大的數，因此可以忽略常數

如果 $f$ 是表達執行時間的 function ， $n$ 是輸入的大小

$$f(n) = 7\log(n)^3 + 15n^2 + 2n^3 + 8$$

$$O(f(n)) = O(n^3)$$

---

參考資料:

[Data Structures Easy to Advanced Course](https://youtu.be/RBSGKlAvoiM)

---

link:

