標籤: #cpp 

---

You should NOT use `throw` unless you have no other way. 

```cpp
try
{
	// Code_To_Try
	throw Some_Exception_Class;
	// More_Code
}
catch(NegativeNumber e)
{
	// Exception_Code
}
catch(DivideByZero)
{
	// Exception_Code
}
catch(...)
{
	// Unexplained_Exception
}
```

> The `...` in the last `catch` block do not stand for something omitted. You actually type in those three dots in your program.

- Each `catch` block can have at most one `catch`-block parameter. 
- A `try-throw-catch` setup is like an `if-else` statement *with the added ability to send a message to one of the branches*.

# Throw Statement

## Syntax

```cpp
throw Expression_for_Value_to_Be_Thrown;
```

When the throw Statement is executed, the execution of the enclosing `try` block is stopped. If the `try` block is followed by a suitable `catch` block, then flow of control is transferred to the `catch` block. A `throw` statement is almost always embedded in a branching statement, such as an `if` statement. The value thrown can be of any type.

## Example

```cpp
if (milk <= 0)
	throw donuts;
```

# Catch-Block Parameter

The `catch`-block parameter is an identifier in the heading of a `catch` block that serves as a placeholder for an exception (a value) that might be thrown. When a suitable value is thrown in the preceding `try` block, that value is plugged in for the `catch`-block parameter. You can use any legal identifier for a `catch`-block parameter.

## Example

```cpp
catch(int e)
{
	cout << e << " donuts, and No Milk!\n"
		 << "Go buy some milk.\n";
}
```

`e` is the `catch`-block parameter.

# Example

## Simple Division by Zero

First look at this example.

```cpp
cout << "Enter number of donuts:\n";
cin >> donuts;
cout << "Enter number of glasses of milk:\n";
cin >> milk;
dpg = donuts / static_cast<double>(milk);
cout << donuts << " donuts.\n"
	 << milk << " glasses of milk.\n"
	 << "You have " << dpg
	 << " donuts for each glass of milk.\n";
```

This example calculates how many donuts you can have for each glass of milk. It assumes that we do not run out of milk.

### Without Exception Handling

Of course, if we run out of milk, we will encounter a situation that the code include a division by zero. Therefore, we may consider this exception and handle this special case by using `if`.

```cpp
#include <iostream>
using std::cin;
using std::cout;

int main()
{
	int donuts, milk;
	double dpg;
	cout << "Enter number of donuts:\n";
	cin >> donuts;
	cout << "Enter number of glasses of milk:\n";
	cin >> milk;
	
	if(milk <= 0)
	{
		cout << donuts << " donuts, and No Milk!\n"
			 << "Go buy some milk.\n";
	}
	else
	{
		dpg = donuts / static_cast<double>(milk);
		cout << donuts << " donuts.\n"
			 << milk << "glasses of milk.\n"
			 << "You have " << dpg
			 << " donuts for each glass of milk.\n";
	}
	
	cout << "End of program.\n";
	return 0;
}
```

### Using Exception Handling

For this example, the `if` exception handling is good enough and it shouldn't be handled using `try`-`catch` exception handling. However, we can rewrite this example into a code that uses `try`-`catch` exception handling.

Keep in mind that for a simple example like this, you shouldn't use `try`-`catch` exception handling.

```cpp
#include <iostream>
using std::cin;
using std;;cout;

int main()
{
	int donuts, milk;
	double dpg;
	
	try
	{
		cout << "Enter number of donuts:\n";
		cin >> donuts;
		cout << "Enter number of glasses of milk:\n";
		cin >> milk;
		
		if(milk <= 0)
			throw donuts;
		
		dpg = donuts / static_cast<double>(milk);
		cout << donuts << " donuts.\n"
			 << milk << " glasses of milk.\n"
			 << "You have " << dpg
			 << " donuts for each glass of milk.\n";
	}
	catch(int e)
	{
		cout << e << " donuts, and No Milk!\n"
			 << "Go buy some milk.\n";
	}
	
	cout << "End of program.\n";
	return 0;
}
```

## Multiple Exceptions

We can catch multiple exceptions using classes. See example.

```cpp
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class NegativeNumber
{
public:
	NegativeNumber(){}
	NegativeNumber(string theMessage): message(theMessage){}
	string getMessage() const {return message;}
private:
	string message;
};

class DivideByZero
{};

int main()
{
	int pencils, erasers;
	double ppe; // pencils per eraser
	
	try
	{
		cout << "How many pencils do you have?\n";
		cin >> pencils;
		if(pencils < 0)
			throw NegativeNumber("pencils");
		cout << "How many erasers do you have?\n";
		cin >> erasers;
		if(erasers < 0)
			throw NegativeNumber("erasers");
		
		if(erasers != 0)
			ppe = pencils / static_cast<double>(erasers);
		else
			throw DivideByZero();
		cout << "Each eraser must last through "
			 << ppe << " pencils.\n";
	}
	catch(NegativeNumber e)
	{
		cout << "Cannot have a negative number of "
			 << e.getMessage() << endl;
	}
	catch(DivideByZero)
	{
		cout << "Do not make any mistakes.\n";
	}
	
	cout << "End of program.\n";
	return 0;
}
```

Note that there is no parameter in the `catch` block for `DivideByZero`. If you do not need a parameter, you can simply list the type with no parameter.

This example is an overqualified use of exception class and is only for illustration. You should use exception class on more complicated uses.

## Throw an Exception inside Function

Sometimes you may want to process the exception outside the function. 

For example, you have a divide program that throws `DivideByZero` exception when it encounters dividing by zero. But this function is tend to behave differently in different situation. Perhaps some programs that use the function should end immediately, and other programs that use the function should do something else.

To deal with this problem, we may throw an exception inside the function and process the exception outside it. See example.

```cpp
#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;

class DivideByZero
{};

double safeDivide(int top, int bottom) throw (DivideByZero);

int main()
{
	int numerator;
	int denominator;
	double quotient;
	cout << "Enter numerator:\n";
	cin >> numerator;
	cout << "Enter denominator:\n";
	cin >> denominator;
	
	try
	{
		quotient = safeDivide(numerator, denominator);
	}
	catch(DivideByZero)
	{
		cout << "Error: Division by zero!\n"
			 << "Program aborting.\n";
		exit(0);
	}
	
	cout << numerator << "/" << denominator
		 << " = " << quotient << endl;
	
	cout << "End of program.\n";
	return 0;
}

double safeDivide(int top, int bottom) throw (DivideByZero)
{
	if(bottom == 0)
		throw DivideByZero();
	
	return top / static_cast<double>(bottom);
}
```

If more than one possible exception can be thrown in the function definition, the exception types are listed separated by commas, as illustrated in what follows:

```cpp
void someFunction() throw (DivideByZero, SomeOtherException);
```

---

參考資料:

Absolute C++, 6th edition

---

link:

