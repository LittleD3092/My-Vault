標籤: #cmake

---

[TOC]

---

# Tutorial

## Step 1: A Basic Start Point

The simplest cmake environment contains only a root file folder and a `CMakeLists.txt`. The directory are as follows:

```
project
|-- src
|   |-- CmakeLists.txt
|   |-- tutorial.cxx
```

Which the text file `CMakeLists.txt` has the following content:

```cmake
cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial)

# add the executable
add_executable(Tutorial tutorial.cxx)
```

The example above uses lower case commands in the file `CMakeLists.txt`, but upper, lower and mixed case commands are all supported.

`tutorial.cxx` is simply an example code. It may be replaced by any code you have. `Tutorial` is the command that you will use to run your code after building. See [[#Build and Run]].

### Build and Run

To build and run, you will have to create a build directory:

```bash
mkdir build
cd build
```

> Now the directory should look like this:
> ```
> project
> |-- src
> |   |-- CmakeLists.txt
> |   |-- tutorial.cxx
> |-- build
> ```

While you are now in the `build` directory, run `cmake` with the `src` directory specified to generate a native build system:

```bash
cmake ../src
```

Then you may call the build system to actually compile and link the project:

```bash
cmake --build
```

Finally, you may use the `Tutorial` command to run your code. Note that `Tutorial` command is specified in your `CmakeLists.txt`.

### Adding a Version Number and Configured Header File

We may provide version number in our source code, but using `CMakeLists.txt` provides more flexibility.

Modify the `CMakeLists.txt` like this to set version number and configure a header file to pass the version number:

```cmake
cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Tutorial VERSION 1.0)
# configure a header file to pass the version number to the source code
configure_file(TutorialConfig.h.in TutorialConfig.h)
# add directory to the list of paths
target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}")

# add the executable
add_executable(Tutorial tutorial.cxx)
```

Now that we need `TutorialConfig.h.in` to define the configured options and settings, we may create `TutorialConfig.h.in` with following contents in `src`:

```cpp
// the configured options and settings for Tutorial
#define Tutorial_VERSION_MAJOR @Tutorial_VERSION_MAJOR@
#define Tutorial_VERSION_MINOR @Tutorial_VERSION_MINOR@
```

Then add this line to `tutorial.cxx` to include the defined options and settings in `TutorialConfig.h.in` like this:

```cpp
#include "TutorialConfig.h"
```

Also, use the defined version number in `tutorial.cxx` to print out the executable name and version number:

```cpp
if(argc < 2) // report version
{
	cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
	     << Tutorial_VERSION_MINOR << endl;
	cout << "Usage: " << argv[0] << " number" << endl;
	return 1;
}
```

> Now the project directory looks like this:
> ```
> project
> |-- src
> |   |-- CmakeLists.txt
> |   |-- tutorial.cxx
> |   |-- TutorialConfig.h.in
> |-- build
> ```

### Specify the C++ Standard

The easiest way to enable supportfor a specific C++ standard in CMake is by using `CMAKE_CXX_STANDARD` variable. To use C++11, modify the `CMakeLists.txt` like this to specify the C++ standard:

```cmake
cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Tutorial VERSION 1.0)
# configure a header file to pass the version number to the source code
configure_file(TutorialConfig.h.in TutorialConfig.h)
# add directory to the list of paths
target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(Tutorial tutorial.cxx)
```

### Rebuild

Because we already setup the build directory and ran CMake in [[#Build and Run]] section, so we can simply use the build argument to rebuild:

```bash
cd Step1_build
cmake --build .
```

---

參考資料:

[cmake tutorial official](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

---

link:

[[Command-Line Arguments]]