標籤: #cpp

---

[TOC]

An enumeration type is very much like a list of declared constants. Enumeration types can be handy for defining a list of identifiers to use as the `case` labels in a `switch` statement.

For example:

```cpp
enum MonthLength { JAN_LENGTH = 31, 
				   FEB_LENGTH = 28,
				   MAR_LENGTH = 31,
				   APR_LENGTH = 30,
				   MAY_LENGTH = 31,
				   JUN_LENGTH = 30,
				   JUL_LENGTH = 31,
				   AUG_LENGTH = 31,
				   SEP_LENGTH = 30,
				   OCT_LENGTH = 31,
				   NOV_LENGTH = 30,
				   DEC_LENGTH = 31 };
```

If you do not specify any numeric values, the identifiers in an enumeration type definition are assigned consecutive values beginning with 0.

For example:

```cpp
enum Direction { NORTH = 0,
				 SOUTH = 1,
			     EAST  = 2,
			     WEST  = 3}
```

is equivalent to:

```cpp
enum Direction { NORTH, SOUTH, EAST, WEST }
```

To use enum in switch-case, you may treat it like normal int:

```cpp
private int direction;
public enum eDirection
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
}
public void move()
{
    switch (direction)
    {
        case eDirection.UP:
            y++;
            break;
        case eDirection.DOWN:
            y--;
            break;
        case eDirection.LEFT:
            x++;
            break;
        case eDirection.RIGHT:
            x--;
            break;
    }
}
```

# Enum Classes

Also called "Strong Enums". C++11 introduced a new version of enumerations "enum classes" to avoid some of the problems with conventional enums.

Problems with conventional enums that is avoided in enum classes:

1. You may not want an enum to act as an integer.
2. Enums are global in scope.

To define and use a enum class:

```cpp
enum class Days { Sun, Mon, Tue, Wed, Thu, Fri, Sat };
enum class Weather { Rain, Sun };
Days d = Days::Tue;
Weather w = Weather::Sun;
```

---

參考資料:

Absolute C++, 6th edition
[enum - ithome](https://ithelp.ithome.com.tw/articles/10184794)

---

link:

[[Type]]