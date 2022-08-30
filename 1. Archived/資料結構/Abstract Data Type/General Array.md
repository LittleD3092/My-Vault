標籤: #DataStructure 

---

[TOC]

---

The original C++ array has some problems, therefore it is a great idea to define our own.

# Problems of C++ Array

- The index set is required to be a set of consecutive integers starting at `0`.
- C++ does not check whether the number in the array index operator `[]` is out of range.

# Code

```cpp
class GeneralArray
{
// A set of pairs <index, value> where for each value of index in 
// IndexSet, there is a value of type float. 
// IndexSet is a finite ordered set of one or more dimensions, 
// for example, {0, ..., n - 1} for one dimension, 
// {(0, 0), (0, 1), (0, 2), (1, 0), (1, 1), (1, 2)} 
// for two dimensions, etc.
public:
	GeneralArray(int j, RangeList list, 
				 float initValue = defaultValue);
	// This constructor creates a j dimensional array of floats;
	// the range of the kth dimension is given by the kth element of 
	// list. 
	// For each index i in the index set, 
	// insert <i, initValue> into the array.
	
	float Retrieve(index i);
	// If i is in the index set of the array, 
	// return the float associated with i in the array;
	// otherwise throw an exception.

	void Store(index i, float x);
	// If i is in the index set of the array,
	// replace the old value associated with i by x;
	// otherwise throw an exception.
}
```

---

參考資料:

Fundamentals of Data Structures in C++, 2nd edition

---

link:

[[Array]]
[[Exception Handling]]