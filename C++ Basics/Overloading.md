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

# Overloading Unary Operators

C++ has unary operators too, for example, `-` when it is used to mean negation:

```cpp
const Money operator -(const Money& amount)
{
	...
	return ...;
}
```

# Overloading as Member Functions

Not only can we overload operators as stand-alone functions like above, we can also overload an operator as a member operator (member function).

For example:

```cpp
...
	
class Money
{
public:
	...
	const Money operator +(const Money& amount2) const;
	const Money operator -(const Money& amount2) const;
	bool operator ==(const Money& amount2) const;
	const Money operator -() const;
	...
}
...
const Money Money::operator +(const Money& secondOperand) const
{
	int allCents1 = cents + dollars * 100;
	int allCents2 = secondOperand.cents + secondOperand.dollars * 100;
	...
	return ...;
}
```

Note that:
1. The first operand is "self" object, and the second operand is a parameter of the function.
2. The function has direct access to private members of `secondOperand`, such as `secondOperand.cents` and `secondOperand.dollars`.

---

參考資料:

Absolute C++, 6th edition

---

link:

