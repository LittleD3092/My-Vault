標籤: #cpp 

---

# The Range-Based for Loop

C++11 includes a new type of `for` loop, the range-based for loop, that simplifies iteration over every element in an array. The syntax is shown here:

```cpp
for (datatype varname : array)
{
	// varname is set to each successive element in the array
}
```

For example:

```cpp
int arr[] = {20, 30, 40, 50};
for (int x : arr)
	cout << x << " ";
cout << endl;
```

The output will be:

```
20 30 40 50 
```

Notice that the `x` variable above is pass-by-value variable, therefore changes of value to `x` do not apply to array `arr`.

But you can define `x` with `&`, which means pass-by-reference (same as the pass-by-reference `&` we use in function). Example below:

```cpp
int arr[] = {20, 30, 40, 50};
for (int& x : arr)
	x++;
for (auto x : arr)
	cout << x << " ";
cout << endl;
```

This will output:

```
21 31 41 51
```

---

參考資料:

Absolute C++, 6th edition

---

link:

