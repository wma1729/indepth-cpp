# Constants

## Avoid #define'd macros for constants
Avoid the urge to use #define'd macros for constant literals, especially in new code, because macros are:
- not typed.
- not scoped.
- difficult to debug (compiler just get to see the constant literal and not the symbol).
```C++
File: myconst.h

#if !defined(_MYCONST_H_)
#define _MYCONST_H

#include <string>

/*
 * Preferred way to define constants.
 * The file, myconst.h, can be safely included in multiple C++ implementation files.
 * You are guaranteed to get only 1 read-only copy of Century, Pi, CStyledConst, and
 * CppStyledConst
 */
const int Century = 100;
const double Pi = 3.14;
const char * const CStyledConst = "a C styled constant string";
const std::string CppStyledConst("a C++ styled constant string";

#endif // _MTCONST_H_
```

## Prefer enums
Prefer enums over related #define'd macros. Prefer `scoped enums` over `unscoped enums`.

### Unscoped enums
>enum <name> { list }
- Not bound to any namespace.
- Though typed but not strictly typed. Enumerated values implicitly converts to integral types.
- Because of implicit conversion to integral types, binary operations like `|`, `&', etc. works fine.

```C++
/*
 * Example of unscoped enum.
 */
 
/*
 * Size of flags is 4 on both linux and windows.
 */
enum flags {
        none   = 0x00000000,
        rdonly = 0x00000001,
        wronly = 0x00000002,
        rdwr   = 0x00000004
};

/*
 * Two things to note here:
 * - Cannot use same names: none, rdonly, wronly, rdwr.
 * - Size of flags_large is 8 on linux and 4 on Windows. In fact,
 *   compilation fails on Windows with /W2 /WX flag.
 */
enum flags_large {
        l_none   = 0x7fffffff00000000,
        l_rdonly = 0x7fffffff00000001,
        l_wronly = 0x7fffffff00000002,
        l_rdwr   = 0x7fffffff00000004
};
```
The size of enum is decided by the compiler based on the constant values. With gcc, it changes to fit the larger constants. However, cl does not go beyond 4. It is implementation defined though it is usually at least as big as `signed` or `unsigned` 32-bit integer depending on the values of the enumerated fields.
