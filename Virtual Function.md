標籤: #cpp 

---

A virtual function is indicated by including the modifier `virtual` in the member function declaration (which is given in the definition of the class).

If a function is virtual and a new definition of the function is given in a derived class, then for any object of the derived class, that object will always use the definition of the virtual function that was given in the derived class, even if the virtual function is used indirectly by being invoked in the definition of an inherited function. This method of deciding which definition of a virtual function to use is known as *late binding*.

# Example

Following example is a code about base class `Sale` and the derived class `DiscountSale`.

Interface for the base class `Sale`:

```cpp
// This is the header file sale.h
// This is the interface for the class Sale.
// Sale is a class for simple sales.

#ifndef SALE_H
#define SALE_H

namespace SavitchSale
{
	class Sale
	{
	public:
		Sale();
		double getPrice() const;
		void setPrice(double newPrice);
		virtual double bill() const;
		double savings(const Sale& other) const;
			// Returns the savings if you buy other instead
			// of the calling object.
		
	private:
		double price;
	};
	
	bool operator < (const Sale& first, const Sale& second);
		// Compares two sales to see which is larger.
}// SavitchSale

#endif // SALE_H
```

- The function `bill()` has a modifier `virtual`.

---

Implementation of the base class `Sale`:

```cpp
// This is the file sale.cpp.
// This is the implementation for the class Sale.
// The interface for the class Sale is in the file Sale.h.

#include <iostream>
#include "sale.h"
using std::cout;

namespace SavitchSale
{
	Sale::Sale() : price(0)
	{
		// Intentionally empty
	}
	
	Sale::Sale(double thePrice)
	{
		if(thePrice >= 0)
			price = thePrice;
		else
		{
			cout << "Error: Cannot have a negative price!\n";
			exit(1);
		}
	}
	
	double Sale::bill() const
	{
		return price;
	}
	
	double Sale::getPrice() const
	{
		return price;
	}
	
	void Sale::setPrice(double newPrice)
	{
		if(newPrice >= 0)
			price = newPrice;
		else
		{
			cout << "Error: Cannot have a negative price!\n";
			exit(1);
		}
	}
	
	double Sale::savings(const Sale& other) const
	{
		return (bill() - other.bill());
	}
	
	bool operator < (const Sale& first, const Sale& second)
	{
		return (first.bill() < second.bill());
	}
}// SavitchSale
```

- ==Virtual== function `bill()` is used in function `savings` and `operator <`. This means that `bill()` in base class can be changed to other implementation in other derived class, and the two functions `savings` and `operator <` will therefore use a different function `bill()` in derived class.

---

Interface for the derived class `DiscountSale`:

```cpp
// This is the file discountsale.h.
// This is the interface for the class DiscountSale.

#ifndef DISCOUNTSALE_H
#define DISCOUNTSALE_H
#include "sale.h"

namespace SavitchSale
{
	class DiscountSale : public Sale
	{
	public:
		DiscountSale();
		DiscountSale(double thePrice, double theDiscount);
		// Discount is expressed as a percentage of the price.
		// A negative discount is a price increase.
		double getDiscount() const;
		void setDiscount(double newDiscount);
		virtual double bill() const;
	private:
		double discount;
	};
} // SavitchSale

#endif // DISCOUNTSALE_H
```

- Since `bill` was declared virtual in the base class, it is automatically virtual in the derived class `DiscountSale`.
- You can add the modifier `virtual` to the declaration of `bill` or omit it; in either case `bill` is virtual in the class `DiscountSale`.

---

Implementation for the derived class `DiscountSale`:

```cpp
// This is the implementation for the class DiscountSale.
// This is the file discountsale.cpp.
// The interface for the class DiscountSale is in the header file discountsale.h.
#include "discountsale.h"

namespace SavitchSale
{
	DiscountSale::DiscountSale() : Sale(), discount(0)
	{
		// Intentionally empty
	}
	
	DiscountSale::DiscountSale(double thePrice, double theDiscount) : Sale(thePrice), discount(theDiscount)
	{
		// Intentionally empty
	}
	
	double DiscountSale::getDiscount() const
	{
		return discount;
	}
	
	void DiscountSale::setDiscount(double newDiscount)
	{
		discount = newDiscount;
	}
	
	double DiscountSale::bill() const
	{
		double fraction = discount / 100;
		return (1 - fractioin) * getPrice();
	}
} // SavitchSale
```

- You do not repeat the qualifier `virtual` in the function definition.

---

Use of a virtual function:

```cpp
// Demonstrates the performance of the virtual function bill.
#include <iostream>
#include "sale.h" // Not really needed, but safe due to ifndef.
#include "discountsale.h"
using std::cout;
using std::endl;
using std::ios;
using namespace SavitchSale;

int main()
{
	Sale simple(10.00); // One item at $10.00.
	DiscountSale discount(11.00, 10); // One item at $11.00 with a 10% discount
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	if(discount < simple)
	{
		cout << "Discounted item is cheaper.\n";
		cout << "Savings is $" << simple.savings(discount) << endl;
	}
	else
		cout << "Discounted item is not cheaper.\n";
	
	return 0;
}
```

Dialogue:

```
Discounted item is cheaper.
Savings is $0.10
```

# Overriding

When a virtual function definition is changed in a derived class, programmers often say the function definition is overridden.

## Provide Context with C++11's `override` Keyword

When we override a virtual function, sometimes it is not clear whether the programmer meant to override the function. Additionally, if we are only looking at the derived class, it may not be clear which functions are being overridden in the base class. 

These problems can be addressed in C++11 by using the new **override** keyword. For example, the virtual function `bill()` is overridden in the `DiscountSale()` class:

```cpp
class Sale
{
public:
	...
	virtual double bill() const;
	...
};
```

```cpp
class DiscountSale : public Sale
{
public:
	...
	double bill() const;
	...
};
```

If we are only looking at the `DiscountSale` class, it is not clear that `bill()` is overriding a function in the `Sale` class.

To make the relationship explicit, we can use the `override` keyword in the derived class to specify that this function is being overridde:

```cpp
class DiscountSale : public Sale
{
public:
	...
	double bill() const override;
	...
};
```

If we use the `override` keyword on a function that is not virtual, then there will be a compiler error.

## Preventing a Virtual Function from Being Overridden

C++11 also allows the programmer to specify whether or not a virtual function may be overriden. To do this, we simply add the keyword **final** to the end of the function definition. For example:

```cpp
class Sale
{
public:
	...
	virtual double bill() const final;
	...
};
```

---

參考資料:

Absolute C++, 6th edition

---

link:

[[Class]]