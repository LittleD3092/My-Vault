標籤: #cmake

---

[TOC]

---

# Quickstart

This is the simplest way of compile `helloSLAM.cpp` with library `libHelloSLAM.cpp` aka `hello_shared`.

```cmake
cmake_minimum_required(VERSION 2.8)
project(HelloSLAM)
set(CMAKE_BUILD_TYPE "Debug")

add_library(hello_shared SHARED libHelloSLAM.cpp)

add_executable(helloSLAM helloSLAM.cpp)
target_link_libraries(helloSLAM hello_shared)
```

---

```
📦ch2  
 ┣ 📜CMakeLists.txt  
 ┣ 📜helloSLAM.cpp  
 ┣ 📜libHelloSLAM.cpp  
 ┗ 📜libHelloSLAM.h
```

```cpp
// helloSLAM.cpp
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "libHelloSLAM.h"

int main()
{
    printHello();
    return 0;
}
```

```cpp
// libHelloSLAM.cpp
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void printHello()
{
    cout << "Hello SLAM" << endl;
}
```

```cpp
// libHelloSLAM.h
#ifndef LIBHELLOSLAM_H_
#define LIBHELLOSLAM_H_

void printHello();

#endif
```

# Tutorial

[[cmake Official Tutorial]]

---

參考資料:

[cmake tutorial official](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

---

link:

[[Command-Line Arguments]]
