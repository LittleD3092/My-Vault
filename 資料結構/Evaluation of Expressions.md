標籤: #DataStructure 

---

[TOC]

---

An assignment statement such as

```cpp
X = A / B - C + D * E - A * C
```

is an arithmetic expression. It is hard for programmers to generate correct machine-language instructions to evaluate an arithmetic expression like this.

# Postfix Notation

A compiler can accept an expression and produce correct code by reworking the expression into a form we call "postfix notation".

Assume we have an expression `e`, it is called `infix` because the operators come in-between the operands. The "postfix" form of an expression calls for each operator to appear after its operands. For example:

$$
\text{ infix }
A \times B / C
\text{ has postfix }
AB\times C/
$$

Now let us look at the previous example.

> Previous example (infix):
> $$A / B - C + D \times E - A \times C$$

We may convert it to postfix:

$$AB/C-DE*-AC*-$$

The advantage of postfix notation is that the expression may be evaluated by making a left to right scan and stacking both operands and operators. For example, the example 

$$A / B - C + D \times E - A \times C$$

may now be evaluated like this:

| Operation           | Postfix             |
| ------------------- | ------------------- |
| $$T_1 = A / B$$     | $$T_1C - DE*+AC*-$$ |
| $$T_2 = T_1 - C$$   | $$T_2DE*+AC*-$$     |
| $$T_3 = D*E$$       | $$T_2T_3+AC*-$$     |
| $$T_4 = T_2+T_3$$   | $$T_4AC*-$$         |
| $$T_5 = A*C$$       | $$T_4T_5-$$         |
| $$T_6 = T_4 - T_5$$ | $$T_6$$             | 

## Algorithm

```cpp
void Eval(Expression e)
// Evaluate the postfix expression e.
// It is assumed that the last token
// (a token is either an operator, operand, or '#')
// in e is '#'.
// A function NextToken is used to get the next token from e.
// The function uses stack.
{
	Stack<Token> stack; // initialize stack
	for(Token x = NextToken(e); x != '#'; x = NextToken(e))
		if(x is an operand)
			stack.Push(x) // add to stack
		else
		// x is an operator
		{
			remove the correct number of operands 
			for operator x from stack;
			perform the operation x 
			and store the result (if any)
			onto the stack;
		}
}
```

# Infix to Postfix

From [[#Postfix Notation]], we found out that [[#Postfix Notation]] is useful and we learnt how to evaluate [[#Postfix Notation]]. But how to convert infix notation to [[#Postfix Notation]]?

The steps are as follows:

1. Fully parenthesize the expression.
2. Move all operators so that they replace their corresponding right parentheses.
3. Delete all parentheses.

---

參考資料:

Fundamentals of Data Structures in C++, 2nd edition

---

link:

