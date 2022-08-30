標籤: #cpp 

---

# nullptr

`nullptr` is a special constant value that is used the same way as `NULL`, but it can only be assigned to a pointer. It is not the number `0`. Use `nullptr` to differentiate between a null pointer and the number `0`. `nullptr` was introduced in C++11.

# Type Definitions

You can assign a name to a type definition and then use the type name to declare variables. This is done with the keyword `typedef`. These type definitions are normally placed outside the body of the `main` part of your program and outside the body of other functions, typically near the start of a file. We will use type definitions to define names for pointer types, as shown in the example here.

## Syntax

```cpp
typedef Known_Type_Definition New_Type_Name;
```

## Example

```cpp
typedef int* IntPtr;
```

The type name `IntPtr` can then be used to declare pointers to dynamic variables of type `int`, as in the following example:

```cpp
IntPtr pointer1, pointer2;
```

---

參考資料:

Absolute C++, 6th edition

---

link:

[[Type]]