標籤: #DataStructure 

---

哪個要先算

# Precedence of Operators

The following chart is the precedence of operators. The top of the chart is the highest precedence (done first), and the bottom of the chart is the lowest precedence (done last).

| Operator                                                                                                                       | Meaning                                                                                                                                                                                                                                                                                                                |
| ------------------------------------------------------------------------------------------------------------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `::`                                                                                                                           | Scope resolution operator                                                                                                                                                                                                                                                                                              |
| `.` <br> `->` <br> `[]` <br> `()` <br> `++` <br> `--`                                                                          | Dot operator <br> Member selection <br> Array indexing <br> Function call <br> Postfix increment operator (placed before the variable) <br> Postfix decrement operator (placed before the variable)                                                                                                                    |
| `++` <br> `--` <br> `!` <br> `--` <br> `+` <br> `*` <br> `&` <br> `new` <br> `delete` <br> `delete []` <br> `sizeof` <br> `()` | Prefix increment operator (placed after the variable) <br> Prefix decrement operator (placed after the variable) <br> Not <br> Unary minus <br> Unary plus <br> Dereference <br> Address of <br> Create (allocate memory) <br> Destroy (deallocate) <br> Destroy array (deallocate) <br> Size of object <br> Type cast |
| `*` <br> `/` <br> `%`                                                                                                          | Multiply <br> Divide <br> Remainder (modulo)                                                                                                                                                                                                                                                                           |
| `+` <br> `-`                                                                                                                   | Addition <br> Subtraction                                                                                                                                                                                                                                                                                              |
| `<<` <br> `>>`                                                                                                                 | Insertion operator (console output) <br> Extraction operator (console input)                                                                                                                                                                                                                                           |
| `<` <br> `>` <br> `<=` <br> `>=`                                                                                               | Less than <br> Greater than <br> Less than or equal to <br> Greater than or equal to                                                                                                                                                                                                                                   |
| `==` <br> `!=`                                                                                                                 | Equal <br> Not equal                                                                                                                                                                                                                                                                                                   |
| `&&`                                                                                                                           | And                                                                                                                                                                                                                                                                                                                    |
| `||`                                                                                                                           | Or                                                                                                                                                                                                                                                                                                                     |
| `=` <br> `+=` <br> `-=` <br> `*=` <br> `/=` <br> `%=`                                                                          | Assignment <br> Add and assign <br> Subtract and assign <br> Multiply and assign <br> Divide and assign <br> Modulo and assign                                                                                                                                                                                         |
| `? :`                                                                                                                          | Conditional operator                                                                                                                                                                                                                                                                                                   |
| `throw`                                                                                                                        | Throw an exception                                                                                                                                                                                                                                                                                                     |
| `,`                                                                                                                            | Comma operator                                                                                                                                                                                                                                                                                                         | 

---

參考資料:

Absolute C++, 6th edition

---

link:

