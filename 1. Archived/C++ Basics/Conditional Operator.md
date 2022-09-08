標籤: #cpp 

---

# C++

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

# Javascript

The ternary operator is an operator that takes three operands. We often use ternary operator to simplify the expression of [[Javascript Basics#If-Else]].

Below is an example of ternary operator. The ternary operator simplifies the two lines of `if-else` statement to only one line.

```js
// using if-else
if(a === b)    return true;
else           return false;

// using ternary operator
return a === b ? true : false;
```

---

參考資料:

Absolute C++, 6th edition
[javascript tutorial - youtube](https://youtu.be/PkZNo7MFNFg)

---

link:

[[Javascript Basics]]