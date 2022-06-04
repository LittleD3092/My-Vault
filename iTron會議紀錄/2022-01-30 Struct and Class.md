# Struct and Class

---

# Struct 

---

## 用途

將多個變數包裝在一起，方便管理

---

## 宣告

- 結構可以同時存放不同型態的資料於同一個結構體

---

## 宣告

```cpp
struct 結構名稱
{
	資料型態 欄位名稱1;
	資料型態 欄位名稱2;
	
	// ...

	資料型態 欄位名稱n;	
};
```

---

## 例子

```cpp
struct Account
{
	String id;
	String name;
	double balance;
};
```

---

## 取值

- 結構內的成員可以利用小數點存取

---

## 例子

```cpp
struct Account
{
	String id;
	String name;
	double balance;
};

int main()
{
	Account acct;
	acct.id = "123-456-789";
	acct.name = "Justin Lin";
	acct.balance = 1000;

	return 0;
}
```

---

# Class

---

## 用途

相較於 struct 多了 function 可以定義在內，並多了繼承、多形等不同的功能

---

## 宣告

類別 (class) 用來設計自己需要的物件 (object)

```cpp
class Demo
{
	int a;
	int b;
	int DoSomething();
};
```

---

## 宣告

```cpp
class Demo
{
	int a;
	int b;
	int DoSomething();
};

int Demo::DoSomething()
{
	return a + b;
}
```

---

## 宣告

```cpp
#include <iostream>
using namespace std;

class Demo
{
	int a;
	int b;
	int DoSomething();
};

int Demo::DoSomething()
{
	return a + b;
}

int main()
{
	Demo t;
	t.a = 11;
	t.b = 22;

	cout << t.DoSomething() << endl;

	return 0;
}
```

---

## 權限

- public: 所有人皆可以存取
- private: 只有 class 內成員可以存取

---

## 權限

顯示錯誤!

```cpp
#include <iostream>
using namespace std;

class Account 
{
private:
	string id;
	string name;
	double balance;

public:
	void set_id(string);
	string get_id();
};

void Account::set_id(string input_id)
{
	id = input_id;
}

void Account::get_id()
{
	return id;
}

int main()
{
	Account me;
	me.id = "123";
}
```

---

## 權限

應使用以下方式

```cpp
#include <iostream>
using namespace std;

class Account 
{
private:
	string id;
	string name;
	double balance;

public:
	void set_id(string);
	string get_id();
};

void Account::set_id(string input_id)
{
	id = input_id;
}

void Account::get_id()
{
	return id;
}

int main()
{
	Account me;
	me.set_id("123");
	cout << me.get_id();

	return 0;
}
```

---

## constructor

宣告時自動執行的 function ，用於賦值

```cpp
#include <iostream>
using namespace std;

class Account 
{
private:
	string id;
	string name;
	double balance;

public:
	Account();
	void set_id(string);
	string get_id();
};

Account::Account()
{
	id = "555";
	name = "Daniel";
}

void Account::set_id(string input_id)
{
	id = input_id;
}

void Account::get_id()
{
	return id;
}

int main()
{
	Account me;
	cout << me.get_id();

	return 0;
}
```

---

## Header File

### my_class.h

```cpp
class my_class
{
public:
	void do_something();
};
```

---

## Header File

### my_class.cpp

```cpp
#include "my_class.h"
void my_class::do_something()
{
	cout << 123;
}
```