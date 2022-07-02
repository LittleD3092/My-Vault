標籤: #cpp 

---

The difference between overloading the `+` operator and defining an ordinary function involves only a slight change in syntax: you use the symbol `+` as the function name and precede the `+` with the keyword `operator`. The operator declaration for the plus sign is as follows:

```cpp
const Money operator +(const Money& amount1, const Money& amount2)
{
	...
	return ...;
}
```

Note that the overloaded operators `+` are not member operators of the class `Money` and therefore do not hvae access to the private members of `Money`.

---

參考資料:

Absolute C++, 6th edition

---

link:

