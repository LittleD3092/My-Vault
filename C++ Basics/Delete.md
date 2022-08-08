標籤: #cpp 

---

[TOC]

---

In C++, we often use `new` to generate objects. The object generated this way is stored in a special memory section and will not automatically disappear when out of scope. Since the object won't delete itself no matter what, we have to use `delete` to delete them.

This keyword is useful in any linked structures, such as [[Linked Lists]] and [[Tree]].

If you want to delete the object which the pointer is pointed, use the following:

```cpp
delete ptr;
```

If you want to delete the array assigned to the pointer, do the following:

```cpp
delete[] p1;
```

---

參考資料:

self

---

link:

[[Linked Lists]]