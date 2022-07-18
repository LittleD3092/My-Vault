標籤: #DataStructure #cpp 

---

[TOC]

---

# [[Asymptotic Notation|Complexity]]

| Action    | Static Array | Dynamic Array |
| --------- | ------------ | ------------- |
| Access    | $O(1)$       | $O(1)$        |
| Search    | $O(n)$       | $O(n)$        |
| Insertion | N/A          | $O(n)$        |
| Appending | N/A          | $O(1)$        |
| Deletion  | N/A          | $O(n)$        | 

# Dynamic Array

可以以 Static Array 作 Dynamic Array

1. 創建一個 static array
2. 加入數字，同時觀察存了幾個數字
3. 若再加入數字會超過 static array 的範圍，創建一個有 2 倍原始空間的 static array 並把原始的數字存進去

# New Array

There will be some situations that you want to create a new array with no identifier, and access it by pointer. You may do this to create a new array and access it by pointer:

```cpp
int* p1 = new int[5];
p1[0] = 0;
p1[1] = 1;
p1[2] = 2;
...
```

If you want to delete the array assigned to the pointer, do the following:

```cpp
delete[] p1;
```

## Example

```cpp
// operator new[] example
#include <iostream>     // std::cout
#include <new>          // ::operator new[]

struct MyClass {
  int data;
  MyClass() {std::cout << '*';}  // print an asterisk for each construction
};

int main () {
  std::cout << "constructions (1): ";
  // allocates and constructs five objects:
  MyClass * p1 = new MyClass[5];
  std::cout << '\n';

  std::cout << "constructions (2): ";
  // allocates and constructs five objects (nothrow):
  MyClass * p2 = new (std::nothrow) MyClass[5];
  std::cout << '\n';

  delete[] p2;
  delete[] p1;

  return 0;
}
```

---

參考資料:

[Data Structures Easy to Advanced Course](https://youtu.be/RBSGKlAvoiM)
[Operator new\[\] - cplusplus](https://cplusplus.com/reference/new/operator%20new%5B%5D/)

---

link:

