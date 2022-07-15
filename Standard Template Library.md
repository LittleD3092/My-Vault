標籤: #cpp 

---

# Iterators

## Constant and Mutable Iterators

- Constant Iterators: The dereferencing operator `*` produces a read-only version of the element. Does not allow you to change the element at its location.

```cpp
std::vector<char>::const_iterator p = container.begin();
```

- Mutable Iterators: `*p` can be assigned a value, which will change the corresponding element in the container.

```cpp
std::vector<char>::iterator p = container.begin()
```

## Reverse Iterators

A reverse iterator can be used to cycle through all elements of a container with bidirectional iterators. The elements are visited in reverse order.

```cpp
STL_container<datatype>::reverse_iterator rp;
for(rp = c.rbegin(); rp != c.rend(); rp++)
	Process_At_Location p;
```

The object `c` is a container class with bidirectional iterators.

When using `reverse_iterator`, you need to have some sort of `using` declaration or something equivalent. For example, if `c` is a `vector<int>`, the following will suffice:

```cpp
vector<int>::reverse_iterator rp;
```

---

參考資料:

Absolute C++, 6th edition

---

link:

[[Class]]