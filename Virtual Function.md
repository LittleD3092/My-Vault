標籤: #cpp 

---

A virtual function is indicated by including the modifier `virtual` in the member function declaration (which is given in the definition of the class).

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

參考資料:

Absolute C++, 6th edition

---

link:

[[Class]]