標籤: #cpp 

---

The `exit` function is a predefined void function that takes one argument of type `int`. 

```cpp
exit(Integer_Value);
```

When the `exit` function is invoked, the program ends immediately. Any `Integer_Value` may be used, but by convention, `1` is used for a call to `exit` that is caused by an error, and `0` is used in other cases.

The `exit` function definition is in the library `cstdlib`, and it places the `exit` function in the `std` namespace. Therefore, any program that uses the `exit` function must contain the following two directives:

```cpp
#include <cstdlib>
using namespace std;
```

---

參考資料:

Absolute C++, 6th edition

---

link:

[[Function]]