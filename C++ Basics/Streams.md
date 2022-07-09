標籤: #cpp 

---

To send output to a file, you must first connect the file to a (stream) object of the class `ifstream`. The classes `ifstream` and `ofstream` are defined in the `<fstream>` library:

```cpp
#include <fstream>
using std::ifstream;
using std::ofstream;
```

A stream is declared just like any other class variable:

```cpp
ifstream inStream;
ofstream outStream;
```

Then you may open the file and connect it to the stream like this:

```cpp
inStream.open("infile.txt");
outStream.open("outfile.txt");
```

After that, you may use the object just like `cin` and `cout`.

Every file should be closed when your program is finished getting input from the file. It can be done using the function close:

```cpp
inStream.close();
outStream.close();
```

# Appending to a File

If you want to append data to a file so that it goes after any existing contents of the file, open the file as follows.

## Syntax

```cpp
Output_Stream.open(File_Name, ios::app);
```

## Example

```cpp
ofstream outStream;
outStream.open("important.txt", ios::app);
```

# Fail Function

You can use function `fail` to check whether the open process is successful.

```cpp
inStream.fail()
outStream.fail()
```

The `fail` function returns a `bool` value. If the open process failed, it returns `true`.

# End of File

There is a function called `eof` that checks whether the input reached end of file.

```cpp
inStream.eof()
outStream.eof()
```

Notice that `eof` does not become `true` until the program attempts to read one character and read the "end of file marker". You should avoid outputting the end of file marker.

# Formatting Output

There are two ways to format your output.

1. You may use stream functions to format the output:

```cpp
outStream.setf(ios::fixed);
outStream.setf(ios::showpoint);
outStream.precision(2);
```

Beside `setf`, there is `unsetf`, which unset the formatting flag:

```cpp
cout.unsetf(ios::showpos);
```

2. You may use manipulators to format the output. A manipulator is a function that is called in a nontraditional way. They are placed after the insertion operator.

```cpp
cout << "Start" << setw(4) << 10
	 << setw(4) << 20 << setw(6) << 30;
```

Following chart is a list of formatting tools (functions), its meaning and the corresponding manipulator:

| Function                   | Description                                                                                                 | Corresponding Manipulator |
| -------------------------- | ----------------------------------------------------------------------------------------------------------- | ------------------------- |
| `setf(ios_Flag)`           | Sets flags. See [[#Flags]] for a number of flags that can be set.                                           | `setiosflags(ios_Flag)`   |
| `unsetf(ios_Flag)`         | Unsets floag                                                                                                | `resetiosflags(ios_Flag)` |
| `setf(0, ios::floatfield)` | Restores default flag settings.                                                                             | None                      |
| `precision(int)`           | Sets precision for floating-point number output.                                                            | `setprecision(int)`       |
| `precision()`              | Returns the current precision setting.                                                                      | None                      |
| `width(int)`               | Sets the output field width; applies only to the next item output.                                          | `setw(int)`               |
| `fill(char)`               | Specifies the fill character when the output field is larger than the value output; the default is a blank. | `setfill(char)`           | 

## Flags

Notice that there is a `setf` function in outStream:

```cpp
outStream.setf(ios::fixed);
```

`setf` means set "flags", there are some flags for `setf`:

| Flag              | Meaning of Setting the Flag                                                                                               | Default |
| ----------------- | ------------------------------------------------------------------------------------------------------------------------- | ------- |
| `ios::fixed`      | Floading-point numbers are not written in e-notation. (Setting this flag automatically unsets the flag `ios::scientific`) | Not Set |
| `ios::scientific` | Floating-point numbers are written in e-notation. (Setting this flag automatically unsets the flag `ios::fixed`)          | Not Set |
| `ios::showpoint`  | A decimal point and trailing zeros are always shown for floating-point numbers.                                           | Not Set |
| `ios::showpos`    | A plus sign is output before positive integer values.                                                                     | Not Set | 
| `ios::right`      | If this flag and the field-width value is set, the output will be at the right end of the space specified by `width`.     | Set     |
| `ios::left`       | Opposite to `ios::right`.                                                                                                 | Not Set |
| `ios::dec`        | Integers are output in decimal notation.                                                                                  | Set     |
| `ios::oct`        | Integers are output in octal notation.                                                                                    | Not Set |
| `ios::hex`        | Integers are output in haxadecimal notation.                                                                              | Not Set |
| `ios::uppercase`  | Uppercase `E` is used to output scientific value. Also, hexadecimal numbers are output using uppercase letters.           | Not Set |
| `ios::showbase`   | Show the base of output number, such as `0x`.                                                                             | Not Set |

# stringstream

`stringstream` class is a class derived from the `istream` class. It allows users to manipulate a string using the `>>` operator that is inherited from `istream`.

To include it:

```cpp
#include <sstream>
using std::stringstream;
```

Next create an object of class `stringstream`:

```cpp
stringstream ss;
```

If you want to clear and initialize the `stringstream` to an empty string:

```cpp
ss.clear();
ss.str("");
```

The `str` function is used to set `ss` to an initial string. You may put any string as a parameter instead of empty string.

We can also use the `str()` method to return the value of the `stringstream` as a string:

```cpp
string s;
s = ss.str();
```

Most importantly, `stringstream` allows user to insert and extract like ordinary `istream`:

```cpp
stringstream ss;
ss.clear();
ss.str("");

// insert scores into ss
string scores = "Luigi 70 100 90";
ss << scores

// extract the name and scores
int score[3];
string name;
ss >> name >> score[0] >> score[1] >> score[2];
```

---

參考資料:

Absolute C++, 6th edition

---

link:

