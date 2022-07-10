標籤: #cpp 

---

C++ support C-style type casting. Also, it introduces C++-style type casting. Although you can use both C and C++-style casting, it is recommended that you use C++-style casting because C-style casting is old and should disappear in the future.

# C-style Type Casting

- `(type)`

```cpp
(int)a
```

# C++-style Type Casting

- `static_cast`

```cpp
static_cast<int>(a)
```

- `const_cast`: for constant type casting
- `dynamic_cast`: for polymorphic type casting
- `reinterpret_cast`: for non-standard type casting

---

參考資料:

[From C to C++](https://youtu.be/pz2633b0998)

---

link:

