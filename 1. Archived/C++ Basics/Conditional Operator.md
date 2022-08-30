標籤: #cpp 

---

It is possible to embed a conditional inside an expression by using a ternary operator known as the conditional operator. However, its use is reminiscent of an older programming style, and is not recommended using it.

Consider the statement:

```cpp
if (n1 > n2)
	max = n1;
else
	max = n2;
```

This can be expressed using the conditional operator as follows:

```cpp
max = (n1 > n2) ? n1 : n2;
```

---

參考資料:

Absolute C++, 6th edition

---

link:

