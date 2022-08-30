標籤: #cpp 

---

You place a name definition in a namespace by placing it in a namespace grouping, which has the following syntax:

```cpp
namespace Namespace_Name
{
	Definition_1
	Definition_2
	...
	Definition_Last
}
```

You can have multiple namespace groupings (even in multiple files), and all the definitions in all the groupings will be in the same namespace.

# Unnamed Namespace

You can use the unnamed namespace to make a definition local to a compilation unit. Each compilation unit has one unnamed namespace.

```cpp
namespace
{
	Definition_1
	Definition_2
	...
	Definition_Last
}
```

You can use any name in the unnamed namespace without qualifiers anyplace in the compilation unit.

---

參考資料:

Absolute C++, 6th edition

---

link:

