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
>enum \<name\> { list };
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

...

bool can_read(flags flg)
{
    return flg & (rdonly | rdwr);
}
```
The size of enum is decided by the compiler based on the constant values. With gcc, it changes to fit the larger constants. However, cl does not go beyond 4. It is implementation defined though it is usually at least as big as `signed` or `unsigned` 32-bit integer depending on the values of the enumerated fields.

### Scoped enums
>enum class \<name\> \[: \<underlying-type\>\] { list}
- Bound to the enclosed namespace.
- Strictly typed - do not implicitly convert to integeral types though you are free to typecast explicitly.
- If used for flags, binary operators like `|`, `&', etc. must be overridden.

```C++
enum class flags {
        none   = 0x00000000,
        rdonly = 0x00000001,
        wronly = 0x00000002,
        rdwr   = 0x00000004
};

/*
 * Again two things to note:
 * - The same name can be used for enumerated list items.
 * - You can explicitly specify the underlying storage type avoiding any platform nuances.
 */
enum class flags_large : long long {
        none   = 0x7fffffff00000000L,
        rdonly = 0x7fffffff00000001L,
        wronly = 0x7fffffff00000002L,
        rdwr   = 0x7fffffff00000004L
};

...

flags f = flags::rdonly;              // Must specify the namespace
large_flags lf = large_flags::wronly; // Must specify the namespace

...

/*
 * The following does not compile.
 * gcc fails with:  error: no match for ‘operator|’ (operand types are ‘flags’ and ‘flags’)
 * Windows cl fails with: error C2676: binary '|': 'flags' does not define this operator or a conversion to a type acceptable to the predefined operator
 */
bool can_read(flags flg)
{
    return flg & (flags::rdonly | flags::rdwr);
}
```
There are various options to make can_read() work with scoped enums. One approach is listed below:
```C++
int operator| (const flags &f1, const flags &f2)
{
        return static_cast<int>(f1) | static_cast<int>(f2);
}

int operator| (const flags &f1, int f2)
{
        return static_cast<int>(f1) | f2;
}

int operator| (int f1, const flags &f2)
{
        return f1 | static_cast<int>(f2);
}

int operator& (const flags &f1, const flags &f2)
{
        return static_cast<int>(f1) & static_cast<int>(f2);
}

int operator& (const flags &f1, int f2)
{
        return static_cast<int>(f1) & f2;
}

int operator& (int f1, const flags &f2)
{
        return f1 & static_cast<int>(f2);
}
```
This works fine but can quickly get clumsy for flags. So personally I avoid using scoped macros for flags where I need binary operations. I prefer defining such enums in independent namespaces.
```C++
/*
 * Use unscoped enums but define the enum in an explicit namespace.
 * This gives me the scoping and binary operations.
 */
namespace fs {

enum flags {
        none   = 0x00000000,
        rdonly = 0x00000001,
        wronly = 0x00000002,
        rdwr   = 0x00000004
};

} // namespace fs
```
