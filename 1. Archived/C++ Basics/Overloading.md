標籤: #cpp 

---

[TOC]

---

The difference between overloading the `+` operator and defining an ordinary function involves only a slight change in syntax: you use the symbol `+` as the function name and precede the `+` with the keyword `operator`. The operator declaration for the plus sign is as follows:

```cpp
const Money operator +(const Money& amount1, const Money& amount2)
{
	...
	return ...;
}
```

Note that the overloaded operators `+` are not member operators of the class `Money` and therefore do not have access to the private members of `Money`.

The `const` will prevent modification of the object returned.

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
};
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

# Overloading as Friend Functions

## Advantage

Assume that you have a class named `Money`, and it has overloaded constructor that takes 0, 1 or 2 `int` numbers as parameters. Also the `+` operand is overloaded as member function of `Money`. The following works:

```cpp
Money baseAmount(100, 60), fullAmount;
fullAmount = baseAmount + 25;
fullAmount.output();
```

The integer `25` will be automatically converted to type `Money`, since class `Money` has a constructor for 1 `int`. This process is called "type convertion".

However, the code following will not work:

```cpp
Money baseAmount(100, 60), fullAmount;
fullAmount = 25 + baseAmount;
fullAmount.output();
```

Because there is no way for `baseAmount` to change to type `int`, the code above will not work.

But, if we overload the operator as stand-alone function, and declare it as a friend function of class `Money`, then not only the automatic type conversion works, but the operator function has access to all private members.

> - One of the disadvantage of overloading stand-alone function is that it doesn't have access to private members.
> - One of the disadvantage of overloading as member function is that the first operand does not apply auto conversion.
> - We can use friend function and stand-alone function to avoid two disadvantage above.

## Implementation

```cpp
class Money
{
public:
	...
	friend const Money operator +(const Money& amount1,
								  const Money& amount2);
	friend const Money operator -(const Money& amount1,
								  const Money& amount2);
	friend bool operator ==(const Money& amount1,
						    const Money& amount2);
	friend const Money operator -(const Money& amount);
	...
};
...
const Money operator +(const Money& amount1, 
					   const Money& amount2)
{
	...
	return ...;
}
const Money operator -(const Money& amount1, 
					   const Money& amount2)
{
	...
	return ...;
}
bool operator ==(const Money& amount1, 
			     const Money& amount2)
{
	...
	return ...;
}
const Money operator -(const Money& amount1)
{
	...
	return ...;
}
...

```

A friend function is not a member function. A friend function is defined and called the same way as an ordinary function. You do not use the dot operator in a call to a friend function, and you do not use a type qualifier in the definition of a friend function.

# Rules on Overloading Operators

- When overloading an operator, at least one parameter (one operand) of the resulting overloaded operator must be of a class type.
- Most operators can be overloaded as a member of the class, a friend of the class, or a nonmember, nonfriend.
- The following operators can only be overloaded as (nonstatic) members of the class: `=`, `[]`, `->`, and `()`
- You cannot create a new operator. All you can do is overload existing operators such as `+`, `-`, `*`, `/`, `%`, and so forth.
- You cannot change the number of arguments that an operator takes. For example, you cannot change `%` from a binary to a unary operator when you overload `%`; you cannot change `++` from a unary to a binary operator when you overload it.
- You cannot change the precedence of an operator. An overloaded operator has the same precedence as the ordinary version of the operator. For example, `x*y + z` always means `(x*y) + z`.
- The following operators cannot be overloaded: the dot operator `.`, the scope resolution operator `::`, `sizeof`, `?:`, and the operator `.*`.
- An overloaded operator cannot have default arguments.

# More Operators

## >> and <<

```cpp
class Money
{
public:
	...
	friend ostream& operator <<(ostream& outs, 
								const Money& amount);
};
...
ostream& operator <<(ostream& outs, const Money& amount)
{
	// outs << amount.element;
	return outs;
}
```

For extraction operator:

```cpp
istream& operator >>(istream& ins, Money& amount)
{
	// ins >> amount.element;
	return ins;
}
```

## ++ and --

- Postfix increment looks like this: `x++`
- While prefix increment looks like this: `++x`

A postfix increment operator returns the state "before" increase, and a prefix increment returns the state "after" increase.

```cpp
class IntPair
{
public:
	IntPair operator++();		//Prefix version
	IntPair operator++(int); 	//Postfix version
	...
private:
	int first;
	int second;
};
...
IntPair IntPair::operator++(int ignoreMe)	//Postfix version
{
	int temp1 = first;
	int temp2 = second;
	first++;
	second++;
	return IntPair(temp1, temp2);
}
IntPair IntPair::operator++()	//Prefix version
{
	first++;
	second++;
	return IntPair(first, second);
}
...
```

## []

- When overloading `[]`, the operator `[]` must be a member function.
- The indexing operator `[]` should return a reference.

```cpp
class CharPair
{
public:
	...
	char& operator[](int index);
	...
private:
	char first;
	char second;
};
...
char& CharPair::operator[](int index)
{
	if(index == 1)
		return first;
	else if(index == 2)
		return second;
	else
	{
		cout << "Illegal index value.\n";
		exit(1);
	}
}
```

## =

The assignment operator `=` must be overloaded as member operator. If we overload `=` using friend function, there will be two overloaded operator `=`, which is ambiguous.

We often use default assignment operator without overloading `=`, but with classes with pointers, we must write and overload our own operator `=`. For example, we have a dynamic memory allocating class `PFArrayD`. In this scenario, we must overload `=`:

```cpp
class PFArrayD
{
public:
	...
	PFArrayD& operator =(const PFArrayD& rightSide);
protected:
	double *a;
	int capacity;
	int used;
};
```

```cpp
PFArrayD& PFArrayD::operator =(const PFArrayD& rightSide)
{
	if (capacity != rightSide.capacity)
	{
		delete [] a;
		a = new double[rightSide.capacity];
	}
	
	capacity = rightSide.capacity;
	used = rightSide.used;
	for (int i = 0; i < used; i++)
		a[i] = rightSide.a[i];
	return *this;
}
```

Note that we return reference from assignment. It's because returning reference allows chaining.

```cpp
a = b = c; // shorter than the equivalent "b = c; a = b;"
```

---

參考資料:

Absolute C++, 6th edition

---

link:

