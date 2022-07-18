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

Constructors may be used to initialize `Rectangle` objects as follows:

```cpp
Rectangle r(1, 3, 6, 6);
Rectangle *s = new Rectangle(0, 0, 3, 4);
```

## Constructor with No Argumanets

To declare an object and pass two arguments to the constructor, you might do the following:

```cpp
DayOfYear date1(12, 31);
```

However, if you want the constructor with zero arguments to be used, you declare the object as follows:

```cpp
DayOfYear date2;
```

You DO NOT declare the object as follows, since this syntax declares a function:

```cpp
DayOfYear date2(); // PROBLEM!
```

You do, however, include the parentheses when you explicitly invoke a constructor with no arguments:

```cpp
date1 = DayOfYear();
```

## Constructor delegation

This allows one constructor to call another constructor.

For example, the definition of class:

```cpp
class Coordinate
{
public:
	Coordinate();
	Coordinate(int x);
	Coordinate(int x, int y);
	int getX();
	int getY();
private:
	int x = 1;
	int y = 2;
};

Coordinate::Coordinate()
{}

Coordinate::Coordinate(int xval) : x(xval)
{}

Coordinate::Coordinate(int xval, int yval) : x(xval), y(yval)
{}

int Coordinate::getX()
{
	return x;
}

int Coordinate::getY()
{
	return y;
}
```

We could modify the implementation of the default constructor so that it invokes the constructor with two parameters:

```cpp
Coordinate::Coordinate() : Coordinate(99, 99)
{}
```

# Destructor

Destructor is a function that will be called when the object is out of scope or when the object is deleted. Its name must be identical to the name of its class prefixed with a tilde, `~`.

```cpp
class Rectangle
{
public:
	...
	~Rectangle();
	...
}
```

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

# Const

If you have a member function that should not change the value of a calling object, you can mark the function with the `const` modifier. The computer will then issue an error message if your function code inadvertently changes the value of the calling object.

```cpp
class BankAccount
{
public:
	...
	void output() const;
	...
```

```cpp
void BankAccount::output() const
{
	...
```

# Static

Sometimes you want to have one variable that is shared by all the objects of a class. Such variables are called static variables.

If a function does not access the data of any object and yet you want the function to be a member of the class, you can make it a static function.

Because a static function does not need a calling object, the definition of a static function cannot use anything that depends on a calling object.

Example:

```cpp
#include <iostream>
using namespace std;

class Server
{
public:
	Server(char letterName);
	static int getTurn();
	void serveOne();
	static bool stillOpen();
private:
	static int turn;
	static int lastServed;
	static bool nowOpen;
	char name;
};

// note that static variables are initialized outside the class definition
int Server::turn = 0;
int Server::lastServed = 0;
bool Server::nowOpen = true;

int main()
{
	Server s1('A'), s2('B');
	int number, count;
	do
	{
		cout << "How many in your group? ";
		cin >> number;
		cout << "Your turns are: ";
		for (count = 0; count < number; count++)
			cout << Server::getTurn() << ' ';
		cout << endl;
		s1.serveOne();
		s2.serveOne();
	} while(Server::stillOpen());
	
	cout << "Now closing service.\n";
	
	return 0;
}

Server::Server(char letterName) : name(letterName)
{/*Intentionally empty*/}

int Server::getTurn()
{
	turn++;
	return turn;
}

bool Server::stillOpen()
{
	return nowOpen;
}

void Server::serveOne()
{
	if (nowOpen && lastServed < turn)
	{
		lastServed++;
		cout << "Server " << name
			 << " now serving " << lastServed << endl;
	}
	
	if(lastServed >= turn) // Everyone served
		nowOpen = false;
}
```

---

參考資料:

Fundamentals of Data Structures in C++, 2nd edition

---

link:

[[Function]]
[[Overloading]]
[[Type]]
[[Seperate Compilation]]
[[Pointers]]