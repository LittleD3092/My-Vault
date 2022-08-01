標籤: #cmake

---

[TOC]

---

# Tutorial

## Step 1: A Basic Start Point

The simplest cmake environment contains only a root file folder and a `CMakeLists.txt`. The directory are as follows:

```
project
|-- CMakeLists.txt
|-- tutorial.cxx
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
> |-- CmakeLists.txt
> |-- tutorial.cxx
> |-- build
> ```

While you are now in the `build` directory, run `cmake` with the `src` directory specified to generate a native build system:

```bash
cmake ..
```

Then you may call the build system to actually compile and link the project:

```bash
cmake --build .
```

Finally, you may use the `./Tutorial` command to run your code. Note that `./Tutorial` command is specified in your `CmakeLists.txt`.

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
> |-- CmakeLists.txt
> |-- tutorial.cxx
> |-- TutorialConfig.h.in
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
cd build
cmake --build .
```

## Step 2: Adding a Library

We will use a custom library which calculates square root numbers as an example. `MathFunctions` is a subdirectory which contains a header file `MathFunctions.h` and a source file `mysqrt.cxx`.

```
project
|-- MathFunctions
|   |-- MathFunctions.h
|   |-- mysqrt.cxx
|-- CMakeLists.txt
|-- tutorial.cxx
|-- TutorialConfig.h.in
|-- build
```

### Basics

To add a library, you will need to do the following 4 steps:

1. Create `CMakeLists.txt` for your library directory and append the following line that specify it is a library:

```
project
|-- MathFunctions
|   |-- CMakeLists.txt    # create this in the library folder!
|   |-- MathFunctions.h
|   |-- mysqrt.cxx
|-- CMakeLists.txt
|-- tutorial.cxx
|-- TutorialConfig.h.in
|-- build
```

```cmake
add_library(MathFunctions mysqrt.cxx)
```

2. Add the subdirectory to `CmakeLists.txt` in the root folder.
3. Link the libraries with main program
4. Include the directory

```cmake
# This is in project/CMakeLists.txt

# add the subdirectory
add_subdirectory(MathFunctions)

# link the library
target_link_libraries(Tutorial PUBLIC MathFunctions)

# include directory
target_include_directories(...
						   "${PROJECT_SOURCE_DIR}/MathFunctions"
						   )
```

Therefore the `CMakeLists.txt` under `project` directory should look like this:

```cmake
cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Tutorial VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(TutorialConfig.h.in TutorialConfig.h)

# add a library
add_subdirectory(MathFunctions)

# add the executable
add_executable(Tutorial tutorial.cxx)
target_link_libraries(Tutorial PUBLIC MathFunctions)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/MathFunctions"
                           )
```

### Options

For a massive project, we should use options to manage our project. In this case, we may want to implement an option that specifies whether to use our custom `MathFunctions` library or not.

#### In CMakeList.txt

To declare an option, use the following line:

```cmake
option(USE_MYMATH "Use tutorial provided math implementation" ON)
```

> `ON` value in the end is the default value we will give to `USE_MYMATH` if no other value is given elsewhere. See how to change the value in terminal in the section [[#Change Value in Options]].

We may implement the option in the `CMakeLists.txt` like this:

```cmake
if(USE_MYMATH)
	add_subdirectory(MathFunctions)
	list(APPEND EXTRA_LIBS MathFunctions)
	list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()

# add the executable
add_executable(Tutorial tutorial.cxx)
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${EXTRA_INCLUDES}"
                           )
```

> We use two lists `EXTRA_LIBS` and `EXTRA_INCLUDES` to store our library list and include list. It will be convenient to add new libraries afterwards if we use these lists.

#### In Program Code

To use the variable in our cpp code, we first need to append the config header file `TutorialConfig.h.in`. The following line imports `USE_MYMATH` variable as a defined [[Macro]] in C++.

```cpp
#cmakedefine USE_MYMATH
```

Then we may use `#ifdef` to determine whether `USE_MYMATH` is `ON` or `OFF`.

```cpp
#ifdef USE_MYMATH
	#include "MathFunctions.h"
#endif
```

```cpp
#ifdef USE_MYMATH
	const double outputValue = mysqrt(inputValue);
#else
	const double outputValue = sqrt(inputValue);
#endif
```

#### Change Value in Options

Of course, you may change the default value simply by modifying `CMakeLists.txt`, but you may also change the values by using terminal commands. The values changed in terminal store as a cache file and will not affect the default value, which is great.

Use the following command to configure the parameter:

```bash
cmake .. -D USE_MYMATH=OFF
```

---

參考資料:

[cmake tutorial official](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

---

link:

[[Command-Line Arguments]]
