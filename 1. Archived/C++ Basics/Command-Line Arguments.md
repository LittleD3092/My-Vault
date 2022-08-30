標籤: #cpp 

---

To access the command-line arguments input to a C++ program, use the following header for `main`:

```cpp
int main(int argc, char* argv[])
```

- `argc`: an integer that specifies how mary arguments are given to the program.
- `argv`: an array of C-strings.

For example, if the program is named `getPalindromes` and is invoked from the command line as

```bash
getPalindromes string1 string2
```

Then inside main, `argc = 3`, `argv[0] = "getPalindromes"`, `argv[1] = "string1"`, `argv[2] = "string2"`.

---

參考資料:

Absolute C++, 6th edition

---

link:

