標籤: #cpp 

---

# Using \#ifndef

A header file can accidently included twice or more times, and C++ does not allow this, even if the repeated definitions are identical. To avoid this problem, C++ provides a way of marking a section of code to say "if you have already included this stuff once before, do not include it again."

The following directive defines `DTIME_H`:

```cpp
#define DTIME_H
```

This put `DTIME_H` on a list to indicate that `DTIME_H` has been seen.

The following directive tests to see whether `DTIME_H` has been defined:

```cpp
#ifndef DTIME_H
```

`n` in `#ifndef` means not. Therefore `#ifndef` means "if not defined". Obviously there is a `#ifdef`, but we will have no occasion to use it. 

If `DTIME_H` has already been defined, then everything between this directive and the first occurrence of the following directive is skipped:

```cpp
#endif
```

Using all three directives `#ifndef`, `#endif`, and `#define`, we can have the following code:

```cpp
#ifndef DTIME_H
#define DTIME_H
// <a class definition>
#endif
```

This ensures that the class definition is only defined one time.

You may use some other identifier in place of `DTIME_H`, but the normal convention is to use the name of the file written in all uppercase letters with the underscore used in place of the period.

---

參考資料:

Absolute C++, 6th edition

---

link:

