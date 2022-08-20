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

## Variables

You can declare global variable by using `var`:

```js
var myName = "Daniel";
```

Although the identifier `myName` has been assigned a type `string`, it can be changed:

```js
var myName = "Daniel";
myName = 8;
```

You can declare local variable by using `let`:

```js
let ourName = "NYCU";
```

To declare a constant variable, use `const`:

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

---

參考資料:

[javascript tutorial - youtube](https://youtu.be/PkZNo7MFNFg)

---

link:

