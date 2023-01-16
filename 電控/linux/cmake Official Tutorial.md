Tag: #cmake 
Previous: [[cmake]]
Link: 

---

[TOC]

---

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
# first variable ("Tutorial") specify the output executable name
# second variable ("tutorial.cxx") specify the source file
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

## Step 3: Adding Usage Requirements for a Library

> This step is the modern way to implement [[#Options]] in [[#Step 2 Adding a Library]]. Note that we use `EXTRA_INCLUDES` to keep track of the directories. We can do better when using the method in this section.

Usage requirements allow better control over a library. The primary commands that leverage usage requirements are:

- `target_compile_definitions()`
- `target_compile_options()`
- `target_include_directories()`
- `target_link_libraries()`

In the following steps, we will see the example of the use of `target_include_directories()`.

1. Add the following lines to the end of the `MathFunctions/CMakeLists.txt` (which is the `CMakeLists.txt` in the library folder).

```cmake
target_include_directories(MathFunctions
						   INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
						   )
```

The `INTERFACE` means things that consumers (the one who USES the library) require but the producer (the one who WRITES the library) doesn't. Therefore this line will execute only when the cosumer is using the library (in our case, in the `Tutorial`'s `CMakeLists.txt`)

2. Omit our uses of the `EXTRA_INCLUDES` in the root `CMakeLists.txt`.

Change the corresponding lines to this:

```cmake
if(USE_MATH)
	add_subdirectory(MathFunctions)
	list(APPEND EXTRA_LIBS MathFunctions)
endif()
```

And this:

```cmake
target_include_directories(Tutorial PUBLIC
						   "${PROJECT_BINARY_DIR}"
						   )
```

Once these two steps are done, there is no need to keep track of every library using `EXTRA_INCLUDES`. The `MathFunctions/CMakeLists.txt` automatically handles it.

## Step 4: Installing and Testing

### Install Rules

The install command of cmake will create another directory, building the whole package and include the dependencies in the specified folder. For example, our `Tutorial` package will be built into `bin` folder, and the `MathFunction` package will be built into `lib` folder. Also, the header file `MathFunctions.h` will be built to `include` folder.

For a install of dependencies, you need to append these lines to `MathFunctions/CMakeLists.txt`:

```cmake
install(TARGETS MathFunctions DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)
```

The syntax of these two lines are:

```cmake
install(TARGETS targets... DESTINATION <dir>)
install(FILES MathFunctions.h DESTINATION <dir>)
```

- We use the first line to specify where our library will be installed, which we specified `lib` folder.
- We use the second line to specify where our header file will be installed, which is the folder `include`.

And for a install of package, we append these lines to the end of the top-level `CMakeLists.txt`:

```cmake
install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
        DESTINATION include
        )
```

For the two lines that we just appended to top-level `CMakeLists.txt`:

- We use the first line to specify the `bin` folder for our main build binary folder.
- We use the second line to configure header files.

After we configure the install settings, we may now run the following lines and install our package:

```bash
# run the cmake executable
cmake .
# install
cmake --install .
```

You can configure the variable `CMAKE_INSTALL_PREFIX` to specify the root of where the files will be installed. You may also use the `--prefix` option while building. The `--prefix` option will override the variable `CMAKE_INSTALL_PREFIX`.

```bash
cmake --install . --prefix "/home/myuser/installdir"
```

### Testing Support

We can use the testing in cmake to test whether our package works.

```cmake
enable_testing()

# does the application run
add_test(NAME Runs COMMAND Tutorial 25)

# does the usage message work?
add_test(NAME Usage COMMAND Tutorial)
set_tests_properties(Usage
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
  )

# define a function to simplify adding tests
function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction()

# do a bunch of result based tests
do_test(Tutorial 4 "4 is 2")
do_test(Tutorial 9 "9 is 3")
do_test(Tutorial 5 "5 is 2.236")
do_test(Tutorial 7 "7 is 2.645")
do_test(Tutorial 25 "25 is 5")
do_test(Tutorial -25 "-25 is (-nan|nan|0)")
do_test(Tutorial 0.0001 "0.0001 is 0.01")
```

- The first test `add_test(NAME Runs COMMAND Tutorial 25)` simply verify that the application runs. The `NAME` field is the test name, and the `COMMAND` field is the command that need to run.
- The second test tests for the usage message. Note that the command is run without an argument, therefore the usage message will be printed.
- Lastly, we define a function `do_test` to verify that the output is correct for the given input. For every function call, a new test with a target, an argument, and a expected result is passed.

Use `ctest` to test the executable:

```bash
cd ./bin
# option -N list the tests that would be run, but not actually run them.
ctest -N
# option -VV show more output from tests.
ctest -VV
```

For multi-config generators, the configuraion type must be specified with the option `-C <mode>`. For example:

```bash
# use the debug mode
ctest -C Debug -VV
# use the release mode
ctest -C Release -VV
```

## Step 5: Adding System Introspection

Sometimes we would like to use a function, and we don't know whether the platform which our package will run on contains the essential functions that we need. In this case, we assume some platform may not have `std::log` and `std::exp`.

We first add the checking procedure in `CMakeLists.txt`. We add an example code and check whether it passes compilation. We store the result using constant `HAVE_LOG` and `HAVE_EXP`.

```cmake
target_include_directories(MathFunctions
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

# does this system provide the log and exp functions?
include(CheckCXXSourceCompiles)
check_cxx_source_compiles("
  #include <cmath>
  int main() {
    std::log(1.0);
    return 0;
  }
" HAVE_LOG)
check_cxx_source_compiles("
  #include <cmath>
  int main() {
    std::exp(1.0);
    return 0;
  }
" HAVE_EXP)
```

To pass the result to our C++ program, we use an if statement to define the keywords for C++. The if statement is also appended in `CMakeLists.txt`.

```cmake
if(HAVE_LOG AND HAVE_EXP)
  target_compile_definitions(MathFunctions
                             PRIVATE "HAVE_LOG" "HAVE_EXP")
endif()
```

In the C++ file, we use `#if` and `#else` to switch between using `std::exp, std::log` and not using them.

```cpp
#if defined(HAVE_LOG) && defined(HAVE_EXP)
  double result = std::exp(std::log(x) * 0.5);
  std::cout << "Computing sqrt of " << x << " to be " << result
            << " using log and exp" << std::endl;
#else
  double result = x;
```

## Step 6: Adding a Custom Command and Generated File

To add a custom file, in this case we want to add `Table.h`, we add the following lines to the subdirectory cmake file:

```cmake
# To add the executable for compilation:
add_executable(MakeTable MakeTable.cxx)
```

```cmake
# Convert the file to Table.h
add_custom_command(
	OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
	COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
	DEPENDS MakeTable
)
```

```cmake
# To include the generated Table.h
add_library(MathFunctions
	        mysqrt.cxx
	        ${CMAKE_CURRENT_BINARY_DIR}/Table.h
	        )
```

```cmake
# Include the build directory of Table.h, 
# so that cmake can find Table.h
target_include_directories(MathFunctions
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
	PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
	)
```

Now we can use `#include "Table.h"` anywhere.

## Step 7: Packaging an Installer

In the previous [[#Step 4 Installing and Testing]] section, we installed the binaries built from the source code.

But in some cases, open source sharing for instance, we want to provide both binary and source distribution. Also we want to provide the distribution that is compatible on a variety of platform, so the other people can use it.

In this section, we will use CPack to accomplish this.

At the bottom of the file `CMakeLists.txt`, append the following lines:

```cmake
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE 
    "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
set(CPACK_SOURCE_GENERATOR "TGZ")
include(CPack)
```

- `InstallRequiredSystemLibraries`: This is all the runtime libraries that are needed by the project for the current platform.
- `set(CPACK_PACKAGE_VERSION_MAJOR ...)` and `set(CPACK_PACKAGE_VERSION_MINOR ...)`: The two lines will set the major and minor versions for cpack. The variables `Tutorial_VERSION_MAJOR` and `Tutorial_VERSION_MINOR` are set in section [[#Adding a Version Number and Configured Header File]].
- `set(CPACKE_SOURCE_GENERATOR "TGZ")`: This line will select a file format. See the wiki for cmake for more options.
- `include(CPack)`: Include the cpack functionality.

After modifying the `CMakeLists.txt`, we will build our package.

To build binary distribution, from the binary directory run:

```bash
cpack
```

To specify generator, use `-G` option. For multi-config builds, use `-C` to specify the configuration.

```bash
cpack -G ZIP -C Debug
```

> `-G` option has a lot of generators available. The code block above shows how to create a `ZIP` package. 
> 
> To see all generators available, run `cpack --help`.

To create an archive of the full source tree:

```bash
cpack --config CPackSourceConfig.cmake
```

---

參考資料:

[cmake tutorial official](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.