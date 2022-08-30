標籤: #cpp 

---

Macro is a syntax that can be implemented like this:

```cpp
#define AREA(l,w) ((l)*(w))
```

This is a function that calculates the area of a rectangle.

You can use the macro like the following code:

```cpp
cout << AREA(4+1,3+1);
```

> It is good programming practice to enclose all macro parameters in parentheses `()` to prevent errors.

# Difference Between Function and Macro

Macro uses replacement of text to work. The replacement happens right before the compiler compiles the source file.

| Function                         | Macro                                  | If using macro                        |
| -------------------------------- | -------------------------------------- | ------------------------------------- |
| Uses function calls              | Uses "replacement of text"             | The speed of the program may increase |
| Compiler compiles function calls | Compiler compiles the replacement text | The size of programs increase         | 

---

參考資料:

[C++ Function Enhancements](https://youtu.be/VQdfD5xma0k)

---

link:

