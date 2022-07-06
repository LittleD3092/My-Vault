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

---

參考資料:

Absolute C++, 6th edition

---

link:

