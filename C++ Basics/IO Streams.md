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

Like we can format the output of `cout`,

```cpp
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);
```

we can format the output of any stream object:

```cpp
outStream.setf(ios::fixed);
outStream.setf(ios::showpoint);
outStream.precision(2);
```

Beside `setf`, there is `unsetf`, which unset the formatting flag:

```cpp
cout.unsetf(ios::showpos);
```

---

參考資料:

Absolute C++, 6th edition

---

link:

