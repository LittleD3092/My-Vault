標籤: #cpp 

---

Inline functions are called faster than ordinary functions, and should be used if the function we are writing is ==small== and ==frequently called==.

```cpp
inline return_type function_name (parameter list)
{
	// body of the function
}
```

Example:

```cpp
#include <iostream>
using namespace std;
inline int AREA(int l, int w)
{
	return l * w;
}
int main()
{
	cout << AREA(4+1. 3+1); // outputs 20
	return 0;
}
```

# Remarks

- Increase the speed of the program.
- Inserts multiple copies of a function's code into the program. Make the program larger.
- When handling inline functions, the compiler also performs all necessary data type conversions.

> Inline functions are [[Macro]]s with type checking and conversion.

---

參考資料:

[C++ Function Enhancements - youtube](https://youtu.be/VQdfD5xma0k)

---

link:

[[Macro]]
[[Function]]