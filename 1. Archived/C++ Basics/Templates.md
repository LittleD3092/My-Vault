標籤: #cpp 

---

Templates allow you to declare a function with undetermined parameter types. 

For example, you might want to write a function `swap()` for `char`, `int`, and `double`. You may overload three kinds of functions, but the easier way is to use templates.

```cpp
#include <iostream>
using std::cout;
using std::endl;

// Interchanges the values of variable1 and variable2.
// The assignment operator must work for the type T.
template<class T>
void swapValues(T& variable1, T& variable2)
{
	T temp;
	
	temp = variable1;
	variable1 = variable2;
	variable2 = temp;
}

int main()
{
	int integer1 = 1, integer2 = 2;
	cout << "Original integer values are "
		 << integer1 << " " << integer2 << endl;
	swapValues(integer1, integer2);
	cout << "Swapped integer values are "
		 << integer1 << " " << integer2 << endl;
	
	char symbol1 = 'A', symbol2 = 'B';
	cout << "Original character values are: "
		 << symbol1 << " " << symbol2 << endl;
	swapValues(symbol1, symbol2);
	cout << "Swapped character values are: "
		 << symbol1 << " " << symbol2 << endl;
	
	return 0;
}
```

- We use `T` as the parameter for the type, but this can be other names.
- It is possible to have more than one type parameter.

```cpp
template<class T1, class T2>
```

# Class Templates

## Syntax

The syntax for class templates are basically the same as those for function templates.

```cpp
// Class for a pair of values of type T:
template<class T>
class Pair
{
public:
	Pair();
	Pair(T firstValue, T secondValue);
	void setFirst(T newValue);
	void setSecond(T newValue);
	T getFirst() const;
	T getSecond() const;
private:
	T first;
	T second;
};

template<class T>
Pair<T>::Pair(T firstValue, T secondValue)
{
	first = firstValue;
	second = secondValue;
}

template<class T>
void Pair<T>::setFirst(T newValue)
{
	first = newValue;
}

template<class T>
T Pair<T>::getFirst() const
{
	return first;
}
```

- Not all the member functions are shown here.

Once the class template is defined, you can declare objects of this class.

```cpp
Pair<int> score;
Pair<char> seats;
```

The objects are then used just like other objects.

```cpp
score.setFirst(3);
score.setSecond(0);
```

## Type Definitions

You can define a new class type name that has the same meaning as a specialized class template name, such as `Pair<int>`. The syntax for such a defined class type name is as follows:

```cpp
typedef Class_Name<Type_Argument> New_Type_Name;
```

For example:

```cpp
typedef Pair<int> PairOfInt;
```

The type name `PairOfInt` can then be used to declare objects of type `Pair<int>`, as in the following example:

```cpp
PairOfInt pair1, pair2;
```

---

參考資料:

Absolute C++, 6th edition

---

link:

[[Overloading]]
[[Class]]