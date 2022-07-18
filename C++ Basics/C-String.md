標籤: #cpp 

---

[toc]

# Variable Declaration

A C-string variable is the same thing as an array of characters, but it is used differently. A C-string variable is declared to be an array of characters in the usual way.

## Syntax

```cpp
char Array_Name[Maximum_C-string_size + 1];
```

## Example

```cpp
char myCstring[11];
```

The `+ 1` allows for the null character `'\0'`, which terminates any C-string stored in the array. For example, the C-string variable `myCstring` in the previous example can hold a C-string that is ten or fewer characters long.

# Initializing

A C-string variable can be initialized when it is declared, as illustrated by the following example:

```cpp
char yourString[11] = "Do Be Do";
```

# Inupt and Output

C-strings can be output using the insertion operator `<<`.

```cpp
cout << news << "Wow.\n";
```

Also it is possible to fill a C-string variable using the input operator `>>`, but all whitespace are skipped when C-strings are read this way. Moreover, each reading of input stops at the next space or line break.

```cpp
char a[80], b[80];
cout << "Enter some input:\n";
cin >> a >> b;
cout << a << b << "END OF OUTPUT\n";
```

The program has a dialogue like the following:

```
Enter some input:
Do be do to you!
DobeEND OF OUTPUT
```

## cin.getline

Beside cin, you can use `cin.getline()` to input one line at a time. 

### Syntax

```cpp
cin.getline(String_Var, Max_Characters + 1);
```

One line of input is read from the stream `Input_Stream` and the resulting C-string is placed in `String_Var`. If the line is more than `Max_Characters` long, only the first `Max_Characters` on the line are read.

The `+1` is needed because every C-string has the null character `'\0'` added to the end of the C-string and thus the string stored in `String_Var` is one longer than the number of characters read in.

### Example

```cpp
char a[80];
cout << "Enter some input:\n";
cin.getline(a, 80);
cout << a << "END OF OUTPUT\n";
```

This code produces a dialogue like the following:

```
Enter some input:
Do be do to you!
Do be do to you!END OF OUTPUT
```

## cin.get

The function `get` can be used to read one character of input. Unlike the extraction operator `>>`, `get` reads the next input character, including blank or newline character.

### Example

```cpp
char nextSymbol;
cin.get(nextSymbol);
```

## cin.putback

This function takes a `char` parameter and put it back to the input stream. This is useful when you input a `char` but decide to process it later.

```cpp
cin.putback(temp_char);
```

## cin.peek

This function returns the next character in input stream, but not remove the character like `cin.get` does. This let you "peek" the next character and decide to actually input or not.

```cpp
cin.peek()
```

## cin.ignore

This function ignores (remove) characters in input stream. It removes characters until desired number of characters are removed or a specific character is removed.

```cpp
cin.ignore(1000, '\n');
```

The `1000` is the maximum number of characters to ignore. The `'\n'` means that it will skip over all input characters up to and including the newline character.

# The \<cstring\> Library

You do not need any `include` directive or `using` statement to declare and initialize C-strings. However, when processing C-strings you inevitably will use some of the predefined string functions in the library `<cstring>`. Thus, when using C-strings, you will normally give the following `include` directive near the beginning of the file containing your code:

```cpp
#include <cstring>
```

The definitions in `<cstring>` are placed in the global namespace, not in the `std` namespace, and so no `using` statement is required.

## strcpy

C-strings and C-string variables are arrays, therefore assigning a value to a C-string variable is not as simple as it is for other kinds of variables. The following is illegal:

```cpp
char aString[10];
aString = "Hello"; // illegal
```

If you want to assign a value to a C-string variable, you must do something else. There are a number of different ways to assign a value to a C-string variable. The easiest way is to use the predefined function `strcpy` as shown here:

```cpp
strcpy(aString, "Hello");
```

## strncpy

Unfortunately, the `strcpy` function does not check whether the string given exceeds the array size. 

Many, but not all, versions of C++ also have a version of `strcpy` called `strncpy` that takes a third argument which gives the maximum number of characters to copy.

```cpp
char anotherString[10];
strncpy(anotherString, aStringVariable, 9);
```

With this version of `strncpy`, at most nine characters (leaving room for `'\0'`) will be copied from the C-string variable `aStringVariable` no matter how long the string in `aStringVariable` may be.

## strcmp

You also cannot use the operator `==` in an expression to test whether two C-strings are the same. To test whether two C-strings are the same, you can use the predefined function `strcmp`.

```cpp
if (strcmp(cString1, cString2))
	cout << "The strings are NOT the same.";
else
	cout << "The strings are the same.";
```

## C-String Functions

| Function                                        | Description                                                                                                                                                                                                     | Cautions                                                                                                                                                    |
| ----------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `strcpy(Target_String_Var, Src_String)`         | Copies the C-string value `Src_String` into the C-string variable `Target_String_Var`.                                                                                                                          | Does not check to make sure `Target_String_Var` is large enough to hold the value `Src_String`.                                                             |
| `strncpy(Target_String_Var, Src_String, Limit)` | The same as the two-argument `strcpy` except that at most `Limit` characters are copied.                                                                                                                        | If `Limit` is chosen carefully, this is safer than the two-argument version of `strcpy`. Not implemented in all versions of C++.                            |
| `strcat(Target_String_Var, Src_String)`         | Concatenates the C-string value `Src_String` onto the end of the C-string in the C-string variable `Target_String_Var`.                                                                                         | Does not check to see that `Target_String_Var` is large enough to hold the result of the concatenation.                                                     |
| `strncat(Target_String_Var, Src_String, Limit)` | The same as the two-argument `strcat` except that at most `Limit` characters are appended.                                                                                                                      | If `Limit` is chosen carefully, this is safer than the two-argument version of `strcat`. Not implemented in all versions of C++.                            |
| `strlen(Src_String)`                            | Reterns an integer equal to the length of `Src_String`. (The null character, `'\0'`, is not counted in the length.)                                                                                             |                                                                                                                                                             |
| `strcmp(String_1, String_2)`                    | Returns `0` if `String_1` and `String_2` are the same. Reterns a value `< 0` if `String_1` is less than `String_2`. Returns a value `> 0` if `String_1` is greater than `String_2`. The order is lexicographic. | If `String_1` equals `String_2`, this function returns `0`. Note that this is the reverse of what you might expect it to return when the strings are equal. |
| `strncmp(String_1, String_2, Limit)`            | The same as the two-argument `strcat` except that at most `Limit` characters are compared.                                                                                                                      | If `Limit` is chosen carefully, this is safer than the two-argument version of `strcmp`. Not implemented in all versions of C++.                            | 

# The \<cctype\> Library

The following chart lists some useful functions in `cctype` library.

| Function            | Description                                                                                             |
| ------------------- | ------------------------------------------------------------------------------------------------------- |
| `toupper(Char_Exp)` | Convert `Char_Exp` to upper case and return it. (as a value of type `int`)                              |
| `tolower(Char_Exp)` | Convert `Char_Exp` to lower case and return it. (as a value of type `int`)                              |
| `isupper(Char_Exp)` | Returns `true` if `Char_Exp` is an uppercase letter.                                                    |
| `islower(Char_Exp)` | Returns `true` if `Char_Exp` is a lowercase letter.                                                     |
| `isalpha(Char_Exp)` | Returns `true` if `Char_Exp` is a letter of the alphabet.                                               |
| `isdigit(Char_Exp)` | Returns `true` if `Char_Exp` is a digit (`0` to `9`).                                                   |
| `isalnum(Char_Exp)` | Returns `true` if `Char_Exp` is either a number or a alphabet.                                          |
| `isspace(Char_Exp)` | Returns `true` if `Char_Exp` is a whitespace character, such as the blank or newline character.         |
| `ispunct(Char_Exp)` | Returns `true` provided `Char_Exp` is a printing character other than whitespace, a digit, or a letter. |
| `isprint(Char_Exp)` | Returns `true` if `Char_Exp` is a printable character.                                                  |
| `isgraph(Char_Exp)` | Returns `true` if `Char_Exp` is a printable character other than whitespace.                            |
| `isctrl(Char_Exp)`  | Returns `true` if `Char_Exp` is a control character.                                                    | 

---

參考資料:

Absolute C++, 6th edition

---

link:

[[Type]]