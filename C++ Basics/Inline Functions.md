標籤: #cpp 

---

Inline functions are called faster than ordinary functions, and should be used if the function we are writing is ==small== and ==frequently called==.

```cpp
inline return_type function_name (parameter list)
{
	// body of the function
}
```

Example:

```cpp
#include <iostream>
using namespace std;
inline int AREA(int l, int w)
{
	return l * w;
}
int main()
{
	cout << AREA(4+1. 3+1); // outputs 20
	return 0;
}
```

# Remarks

- Increase the speed of the program.
- Inserts multiple copies of a function's code into the program. Make the program larger.
- When handling inline functions, the compiler also performs all necessary data type conversions.

> Inline functions are [[Macro]]s with type checking and conversion.

# Inline Member Funciton

Inline functions can also used in class. The syntax is as follow:

```cpp
double getBalance() const { return (accountDollars +
								    accountCents * 0.01) }
```

Inline member functions are used for very short function definitions, as same as non-member inline functions.

## Example

Inline function definitions:

```cpp
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class BankAccount
{
public:
	BankAccount(double balance, double rate);
	BankAccount(int dollars, int cents, double rate);
	BankAccount(int dollars, double rate);
	BankAccount();
	void update();
	void input();
	void output() const;

	double getBalance() const { return (accountDollars + 
								accountCents *0.01); }
	
	int getDollars() const { return accountDollars; }

	int getCents() const { return accountCents; }

	double getRate() const { return rate; }

	void setBalance(double balance);
	void setBalance(int dollars, int cents);
	void setRate(double newRate);
private:
	int accountDollars; // of balance
	int accountCents; // of balance
	double rate; // as a percentage

	int dollarsPart(double amount) const 
	{ return static_cast<int>(amount); }

	int centsPart(double amount) const;

	int round(double number) const
	{ return static_cast<int>(floor(number + 0.5)); }

	double fraction(double percent) const 
	{ return (percent / 100.0); }
};
```

---

參考資料:

[C++ Function Enhancements - youtube](https://youtu.be/VQdfD5xma0k)
Absolute C++, 6th edition

---

link:

[[Macro]]
[[Function]]
[[Class]]