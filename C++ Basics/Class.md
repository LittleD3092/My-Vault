標籤: #cpp 

---

# Constructor

Let's look at a class named `Rectangle`:

```cpp
#ifndef RECTANGLE_H
#define RECTANGLE_H
// In the header file Rectangle.h
class Rectangle
{
public:		// the following members are public
	// the next four members are member functions
	Rectangle();		// constructor
	~Rectangle();		// deconstructor
	int GetHeight();	// returns the height of the rectangle
	int GetWidth();		// returns the width of the rectangle
private:	// the following members are private
	// the following members are data members
	int xLow, yLow, height, width;
	// (xLow, yLow) are the coordinates of the bottom left corner of the rectangle
};
#endif
```

Constructor can be defined in two ways, the first one using funciton:

```cpp
Rectangle::Rectangle(int x, int y, int h, int w)
{
	xLow = x;
	yLow = y;
	height = h;
	width = w;
}
```

The second way is to use initialization list:

```cpp
Rectangle::Rectangle(int x, int y, int h, int w)
:xLow(x), yLow(y), height(h), width(w)
{}
```

In the first way, the constructor first initializes the data members and then assigns arguments to them in two seperate steps, while in the second way, it directly initializes the data members to the corresponding arguments in a single step. Thus, the latter approach results in a more efficient constructor.

# Destructor

If a destructor is not defined, the deletion of an object results in the freeing of memory associated with data members of the class. If a data member is a pointer to some other object, the space allocated to the pointer is returned, but the object that it was pointing to is not deleted. If we also wish to delete this object, we must define a destructor that explicitly does so.

# Operator Overloading

If we try to use operator `==` to check for equality between two objects, the compiler would complain that operator `==` is not defined for the objects.

Fortunately, C++ allows the programmer to overload operators for user-defined data types.

```cpp
bool Rectangle::operator==(const Rectangle& s)
{
	if(this == &s)
		return true;
	if((xLow == s.xLow) && (yLow == s.yLow) &&
	   (height == s.height) && (width == s.width))
		return true;
	else
		return false;
}
```

The program used `this`, which is a pointer that points to itself. The first `if` determines whether two rectangles are identical. If the objects are the same object, there is no need to compare the individual data members, therefore saves time.

The following program is another example that overloads operator `<<` so that `Rectangle` objects can be output by using `cout`.

```cpp
ostream& operator<<(ostream& os, Rectangle& r)
{
	os << "Position is: " << r.xLow << " ";
	os << r.yLow << endl;
	os << "Height is: " << r.height << endl;
	os << "Width is: " << r.width << endl;
	return os;
}
```

---

參考資料:

Fundamentals of Data Structures in C++, 2nd edition

---

link:

[[Function]]