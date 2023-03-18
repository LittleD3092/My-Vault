標籤: #javascript

---

[TOC]

---

# Run

Every web browser can run javascript. You may write the following block in your html to add javascript:

```html
<script>
	// your program
</script>
```

In google chrome, you can open console by pressing `ctrl + shift + J`

Or, you can use terminal:

```bash
node file.js
```

# Comments

The comments of javascript is similar to C++, you use `//` and `/**/` to write single line comment and multiline comments.

```js
// comment

/* comment1
comment2*/
```

# Data Types and Variable

## Data Types

In javascript, there are several types of variable:

- `undefined`: the variable has no type
- `null`
- `boolean`
- `string`
- `symbol`
- `number`
- `object`

### Object

The declaration of object and its usage is like the `dictionary` in python. We declare object like this:

```js
var ourDog = 
{
	"name" : "Camper",
	"legs" : 4,
	"tails" : 1,
	"friends" : ["everything"]
};
```

And we may access the elements using two ways:

```js
ourDog.name; // this works!
outDog["name"]; // this works too!
```

#### Spaces in Element Names

Note that we may use `""` when implementing the object's elements. The object's element name can have spaces!

```js
var testObj = 
{
	"an entree" : "hamburger",
	"my side" : "veggies",
	"the drink" : "water"
};
```

But we cannot use `.` to access our elements if the element's name contains space, we can only use `[]`:

```js
var entreeValue = testObj["an entree"];
```

#### Append an Element

If you are assigning an element that is not in the object, the object will add it.

```js
var ourDog = 
{
	"name" : "Camper",
	"legs" : 4,
	"tails" : 1,
	"friends" : ["everything!"]
};

ourDog.bark = "woof";
```

#### Delete an Element

You can delete an element using keyword `delete`:

```js
var ourDog = 
{
	"name" : "Camper",
	"legs" : 4,
	"tails" : 1,
	"friends" : ["everything!"]
};

ourDog.bark = "woof";
delete ourDog.bark;
```

#### Testing whether Object has Element

Sometimes it is useful to test whether the object has a specific element. We can use a element function `hasOwnProperty()`:

```js
var myObj = 
{
	gift : "pony",
	pet : "kitten",
	bed : "sleigh"
};

myObj.hasOwnProperty("gift"); // this will be true
```

## Variables

### var

You can declare function scope variable by using `var`:

```js
var myName = "Daniel";
```

Although the identifier `myName` has been assigned a type `string`, it can be changed:

```js
var myName = "Daniel";
myName = 8;
```

### let

You can declare block scope variable by using `let`:

```js
let ourName = "NYCU";
```

> Apart from scope, another difference between `let` and `var` is that `let` does not allow duplicate declaration. `var` does.

### const

To declare a constant variable (it is block scope), use `const`:

```js
const PI = 3.14;
```

## Typeof

To get a type of a variable, we use keyword `typeof`:

```js
typeof myVariable == "string"
```

# Output

To output a variable to the console, we use `console.log`:

```js
var a = 7;
console.log(a);
```

You can add comma in the middle of two variable like `console.log(a, b)`, this will output both variable, with a space in the middle.

```js
let myName = "Daniel";
console.log("Hello,", myName, "!");
```

The code block above will output:

```
Hello, Daniel !
```

# Operators

We have the following operators, just like C++:

- `+`
- `-`
- `*`
- `/`
- `++`
- `--`
- `%`
- `+=`
- `-=`
- `*=`
- `/=`

# String

The length of a string can be accessed by using `str.length`:

```js
let sl = str.length;
```

A single character of a string can be accessed by using `[]`:

```js
let c = str[0];
```

Note that `string` is a type that is imutable, meaning that we can't change single letter of it. However, we can change the whole string.

```js
let str = "ping";
str[0] = "w"; // This will have an error.

str = "wing"; // This is OK.
```

## Escape Character

Like C++, javascript use escape characters to represent special characters:

| Escape Character | Meaning                             |
| ---------------- | ----------------------------------- |
| `\'`             | The character `'`                   |
| `\"`             | The character `"`                   |
| `\\`             | The character `\`                   |
| `\n`             | End line                            |
| `\r`             | Keyboard enter                      |
| `\t`             | Tab                                 |
| `\b`             | Backspace                           |
| `\f`             | Form feed (change page for printer) | 

## Convert to Int

We may have a number represented in string type, like `"56"`. There is a convenient function `parseInt()` that can convert this type of string to an integer type. Below is an example.

```js
result = parseInt("56");
```

`parseInt()` can also convert a string in binary representation to an integer. You only need to pass a parameter `2` at the second position. This parameter specifies that the string is written in binary representation.

```js
result = parseInt("10011", 2);
```

# Array

The array of javascript has more freedom than the array of C++. The array of javascipt allow storing of different type of data. The assigning is more like python.

```js
var arr = ["John", 23];
arr[0] = 1; // [1,23]

// use push to append an element at the end
arr.push(2); // [1,23,2]

// use pop to delete one element at the end
removed = arr.pop(); // [1,23]

// use shift to delete one element at the front
removed = arr.shift(); // [23]

// use unshift to append one element at the front
arr.unshift("Add"); // ["Add", 23]
```

# Function

A function declaration is as follows:

```js
function f(param)
{
	return param + 1;
}
```

- If the function does not have a return value, a parameter with type `undefined` is returned.

# Equality

We have normal equality:

```js
3 == 3
3 == '3'
```

Both these statements is true.

But javascript has another equality `===`, called "strictly equal":

```js
3 === 3
3 === '3'
```

The second statement doesn't evaluate to true. This is because normal equality has automatic type conversion, and strictly equal doesn't.

# Conditions

## And

We use `&&` just like C++.

## Or

We use `||` just like C++.

# If-Else

We use if-else like C++.

```js
if()
{

}
else if()
{

}
else
{

}
```

# Switch

We use switch like C++.

```js
switch(val)
{
case 1:
	...
	break;
	
case 2:
	...
	break;

case 3:
	...
	break;

default:
	...
	break;
}
```

# While Loop

We have `while` and `do-while` loop like C++.

```js
var myArray = [];
var i = 0;
while(i < 5)
{
    myArray.push(i);
    i++;
}
```

```js
var myArray = [];
var i = 0;
do
{
    myArray.push(i);
    i++;
}while(i < 5)
```

# For Loop

The for loop is similar to the one in C++.

```js
var ourArray = [];
for(var i = 0; i < 5; i++)
{
    ourArray.push(i);
}
```



---

參考資料:

[javascript tutorial - youtube](https://youtu.be/PkZNo7MFNFg)

---

link:

[[Random]]