標籤: #algorithm 

---

[TOC]

---

# Conventions

- Use indentation to show block structure like `for`, `while` and `if`.
- We use keywords `to` when a `for` loop increments its loop counter in each iteration, and we use keyword `downto` when a `for` loop decrements its loop counter. When the for loop counter changes by an amount greater than `1`, the amount of change follows the optional keyword `by`.
```
for i = 1 to 5 by 2
    print i
```
The code above will print `1 3 5`.
- `//` indicates comment.
- Multiple assignment, `i = j = e` means `j = e`, then `i = j`.
- Variables are local to the given procedure. We shall not use global variables without explicit indication.
- `A[i]` denotes the $i$th element of the array. `A[1..j]` indicates the subarray of $A$.
- When object or array are passed, the pointers are passed. Sometimes, a pointer points to nothing. In this case, we give it the special value `NIL`.
- `return` statement allow multiple return values.
- The keyword `error` indicates that an error occurred. The pseudocode does not need to handle error.

---

參考資料:

Introduction to Algorithms, third edition

---

link:

