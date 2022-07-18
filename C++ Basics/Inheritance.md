標籤: #cpp 

---

Inheritance is a process by which a new class (derived class) is created from another class (base class).

For example, a base class `Employee` looks like this:

```cpp
// This is the header file employee.h
// This is the interface for the class Employee.
// This is primarily intended to be used as a base class
// to derive classes for different kinds of employees.
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using std::string;

namespace SavitchEmployees
{
	class Employee
	{
	public:
		Employee();
		Employee(const string& theName, const string& theSsn);
		string getName() const;
		double getNetPay() const;
		void setName(const string& newName);
		void setSsn(const string& newSsn);
		void setNetPay(double newNetPay);
		void printCheck() const;
	private:
		string name;
		string ssn;
		double netPay;
	};
} // SavitchEmployees

#endif // EMPLOYEE_H
```

```cpp
// This is the file employee.cpp.
// This is the implementation for the class Employee.
// The interface for the class Employee is in the header file employee.h.
#include <string>
#include <cstdlib>
#include <iostream>
#include "employee.h"
using std::string;
using std::cout;

namespace SavitchEmployees
{
	Employee::Employee() : name("No name yet"),
						   ssn("No number yet"),
						   netPay(0)
	{
		// deliberately empty
	}
	
	string Employee::getName() const
	{
		return name;
	}
	
	string Employee::getSsn() const
	{
		return ssn;
	}
	
	double Employee::getNetPay() const
	{
		return netPay;
	}
	
	void Employee::setName(const string& newName)
	{
		name = newName;
	}
	
	void Employee::setSsn(const string& newSsn)
	{
		ssn = newSsn;
	}
	
	void Employee::setNetPay(double newNetPay)
	{
		netPay = newNetPay;
	}
	
	void Employee::printCheck() const
	{
		cout << "\nERROR: printCheck FUNCTION CALLED FOR AN \n"
			 << "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n"
			 << "Check with the author of the program about this bug.\n";
		exit(1);
	}
}
```

You may create derived class `HourlyEmployee` and class `SalariedEmployee` like this:

```cpp
// This is the header file hourlyemployee.h.
// This is the interface for the class HourlyEmployee.
#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include <string>
#include "employee.h"

using std::string;

namespace SavitchEmployees
{
	class HourlyEmployee : public Employee
	{
	public:
		HourlyEmployee();
		HourlyEmployee(const string& theName,
					   const string& theSsn,
					   double theWageRate,
					   double theHours);
		void setRate(double nerWageRate);
		double getRate() const;
		void setHours(double hoursWorked);
		double getHours() const;
		void printCheck();
	private:
		double wageRate;
		double hours;
	};
}// SavitchEmployees

#endif //HOURLYEMPLOYEE_H
```

```cpp
// This is the header file salariedemployee.h.
// This is the interface for the class SalariedEmployee.
#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <string>
#include "employee.h"

using std::string;

namespace SavitchEmployees
{
	class SalariedEmployee : public Employee
	{
	public:
		SalariedEmployee();
		SalariedEmployee(const string& thename, 
						 const string& theSsn,
						 double theWeeklySalary);
		double getSalary() const;
		void setSalary(double newSalary);
		void printCheck();
	private:
		double salary; // weekly
	};
}// SavitchEmployees

#endif // SALARIEDEMPLOYEE_H
```

Note that the definition of a derived class begins like any other class definition but adds a colon, the reserved word `public`, and the name of the base class.

```cpp
class HourlyEmployee : public Employee
{
```

The derived class automatically receives all the member variables and member functions of the base class (such as `Employee`) and can add additional member variables and member functions.

The member function `printCheck()` is redefined and will behave differently compared to the base class.

# Constructors

The constructor in a base class is not inherited in the derived class, but you can invoke a constructor of the base class within the definition of a derived class within the definition of a derived class constructor.

For example, you can use constructor `Employee::Employee` in the new constructor `HourlyEmployee::HourlyEmployee`:

```cpp
HourlyEmployee::HourlyEmployee(const string& theName,
							   const string& theNumber,
							   double theWageRate,
							   double theHours)
							 : Employee(theName, theNumber),
							   wageRate(theWageRate), 
							   hours(theHours)
{
	// deliberately empty
}
```

If you do not include a call to a constructor of the base class, then the default (zero-argument) constructor of the base class will automatically be called when the derived class constructor is called. We tend to always include a call to the constructor of the base class.

# Access Private Member from Base Class

A member variable (or member function) that is private in a base class is not accessible by name in the definition of a member function for any other class, not even in a member function definition of a derived class.

Therefore, you should avoid accessing private member from base class and use public function to do so instead.

# Protected

`protected` is a qualifier as `private` and `public` is. If you use `protected` as a qualifier, the member variable or function acts like it is private, except that it can be accessed by derived class (recall that `private` members are not accessable by derived class).

Many, but not all, programming authorities say it is bad style to use protected member variables because doing so compromises the principle of hiding the class implementation. Therefore you should think twice before using it.

# Access to a Redefined Base Function

Consider the base class `Employee` and the derived class `HourlyEmployee`. The function `printCheck()` is defined in both classes. Suppose you have an object:

```cpp
HourlyEmployee SallyH;
```

And you use `printCheck()`:

```cpp
SallyH.printCheck();
```

You will call a function in class `HourlyEmployee`, which is `HourlyEmployee::printCheck()`.

Now, what if you don't want to call `HourlyEmployee::printCheck()`, but the function defined in base class `Employee::printCheck()`? You may use the following:

```cpp
SallyH.Employee::printCheck();
```

---

參考資料:

Absolute C++, 6th edition

---

link:

