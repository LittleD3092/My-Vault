標籤: #cpp #computer-organization 

---

[TOC]

---

# C++

## Overload

C++ allows you to give two or more different definitions to the same function name, which means you can reuse names that have strong intuitive appeal across a variety of situations.

For example, you might need a function that calculates average of both two and three arguments:

```cpp
// Illustrates overloading the function name `ave`
#include <iostream>
using namespace std;

double ave(double n1, double n2);
// Returns the average of the two numbers n1 and n2

double ave(double n1, double n2, double n3);
// Returns the average of the three numbers n1, n2, and n3

int main()
{
	cout << "The average of 2.0, 2.5, and 3.0 is "
		 << ave(2.0, 2.5, 3.0) << endl;
	cout << "The average of 4.5 and 5.5 is "
		 << ave(4.5, 5.5) << endl;
	return 0;
}

double ave(double n1, double n2)
{
	return ((n1 + n2) / 2.0);
}

double ave(double n1, double n2, double n3)
{
	return ((n1 + n2 + n3) / 3.0);
}
```

If you have two or more function definitions for the same function name, that is called overloading. When you overload a function name, the function definitions must have different numbers of formal parameters or some formal parameters of differnet types. When there is a function call, the compiler uses the function definition whose number of formal parameters and types of formal parameters match the arguments in the function call.

### Rules for Resolving Overloading

The rules that the compiler uses for resolving which of multiple overloaded definitions of a function name to apply to a given function call are as follows:

1. Exact match: If the number and types of arguments exactly match a definition without any automatic type conversion, then that is the definition used.
2. Match using automatic type conversion: If there is no exact match but there is a match using automatic type conversion, then that match is used.

The previous two rules will work in almost all situations. In fact, if you need more precise rules, you should rewrite your code to be more straightforward.

However, the exact rules are more complicated (for reference):

1. Exact match as described earlier.
2. Matches using promotion within integer types or within floating-point types, such as `short` to `int` or `float` to `double`. (Note that `bool`-to-`int` and `char`-to-`int` conversions are considered promotions within integer types.)
3. Matches using other conversions of predefined types, such as `int` to `double`.
4. Matches using conversions of user-defined types.
5. Matches using ellipses ...

## Default Arguments

You can specify a default argument for one or more call-by-value parameters in a function. If the corresponding argument is omitted, then it is replaced by the default argument.

```cpp
#include <iostream>
using namespace std;

void shorVolume(int length, int width = 1, int height = 1);
// Returns the volume of a box.
// If no height is given, the height is assumed to be 1.
// If neither height nor width is given, both are assumed to be 1.

int main()
{
	showVolume(4, 6, 2);
	showVolume(4, 6);
	showVolume(4);
	
	return 0;
}

void showVolume(int length, int width, int height)
{
	cout << "Volume of a box with\n"
		 << "Length = " << length << ", Width = " << width << endl
		 << "and Height = " << height
		 << " is " << length * width * height << endl;
}
```

Note that a default argument should not be given a second time.

# MIPS Assembly

Calling functions in MIPS assembly is achieved using `jal`, and function returning is achieved using `jr`.

Also, for nested function calling, we use `$sp` to save parameters and return address `$ra`.

| Name          | Assembly               | Comments                                                                                                             |
| ------------- | ---------------------- | -------------------------------------------------------------------------------------------------------------------- |
| Jump and link | `jal ProcedureAddress` | Jump to an address and save the following instruction address to a register `$ra` for link. Used to call a function. |
| Jump register | `jr $ra`               | Unconditinally jump to an instruction saved in a register. Used to return.                                           | 

## Normal Procedure

For a C procedure like this, note that it does not call another procedure:

```c
int leaf_example(int g, int h, int i, int j)
{
    int f;
    f = (g + h) - (i + j);
    return f;
}
```

> Note that for a procedure, the parameters are stored in `$a0`, `$a1`, `$a2`, `$a3`..., and the return value is stored in `$v0`.

The compiled MIPS assembly code is:

```s
leaf_example: addi $sp, $sp, -12   # adjust stack to 
                                   # store 3 items
              sw   $t1, 8($sp)
              sw   $t0, 4($sp)
              sw   $s0, 0($sp)     # save the register values,
                                   # because we are going to
                                   # use these registers.
              add  $t0, $a0, $a1   # $t0 = g + h
              add  $t1, $a2, $a3   # $t1 = i + j
              sub  $s0, $t0, $t1   # $s0 = (g+h) - (i+j)
              add  $v0, $s0, $zero # $v0 = (g+h)-(i+j)
              lw   $s0, 0($sp)
              lw   $t0, 4($sp)
              lw   $t1, 8($sp)     # restore $s0, $t0, $t1
                                   # from stack
              addi $sp, $sp, 12    # pop 3 items
              jr $ra               # return

```

## Nested Procedure

For a recursive procedure in C:

```c
int fact (int n)
{
    if(n < 1)    return (1);
    else         return (n * fact(n - 1));
}
```

The MIPS assembly is:

```s
fact: addi $sp, $sp, -8   # adjust stack to store 2 items
      sw   $ra, 4($sp)  
      sw   $a0, 0($sp)    # because it is recursive,
                          # we need to save return address
                          # and parameter.
      slti $t0, $a0, 1    # $t0 = n < 1 ? 1 : 0
      beq  $t0, $zero, L1 # goto L1 if n < 1 == false
      addi $v0, $zero, 1  # $v0 = 1
      addi $sp, $sp, 8    # pop 2 items from stack
      jr   $ra            # return $v0 = 1
L1:   addi $a0, $a0, -1   # if(n >= 1) $a0 = n - 1
      jal  fact           # $v0 = fact(n - 1)
      lw   $a0, 0($sp)
      lw   $ra, 4($sp)
      addi $sp, 8         # restore 2 items on stack
                          # and pop 2 items
      mul  $v0, $a0, $v0  # $v0 = n * fact(n - 1)
      jr   $ra            # return $v0
```

---

參考資料:

Absolute C++, 6th edition
Computer Organization and Design, 5th edition

---

link:

[[Overloading]]