### Expression
An **Expression** is a combination of literals, variables,
operators, and explicit function calls (not shown above)
that produce a single output value.
[comment]: <> (type indentifier { expression };)
---
    int x{2+3};
---

[comment]: <> (Author's note)
"C++ has so many rules and concepts. How do I remember
all of this stuff?"
__Short Answer__: You don't. C++ is one part using
what you know, and two parts looking up how to do the rest.

__size_of__

if *size_t* is 4 bytes, the largest object creatable
    on your system can't be larger than the largest
    number respresentable by a 4-byte unsigned iteger
    (per the table above, 4,294,967,295 bytes)

__"Depricated"__
means still supported, but no longer recommended for use,
because it has been replaced by something better or is no
longer considered safe.

[comment]: <> (Best Practice 4.13)
- Any variable that should not be modifiable after initialization
and whose initializer is known at compile-time should be declared
as **constexpr**.
- Any vairable that should not be modifiable after initialization
and whose initializer is __not__ known at compile-time should be
declared as **const**.

[comment]: <> (Global variables with internal linkage)
---
    static int g_x; // non-constant globals have external linkage
    // by default, but can be given internal linkage via the static keyword
    
    const int g_y {1}; // const globals have internal linkage by default
    constexpr int g_z {2}; // constexpr globals have internal linkage by default
---
Const and constexpr global variables have internal linkage by default
(and thus don't need the _static_ keyword -- if it used, it will be ignored)

[comment]: <> (External Linkage)
The **extern** keyword has different meanings in different contexts.
In some contexts, **extern** means "give this variable external linkage".
In other contexts, **extern** means "this is a forward declaration for an
external vairable that is defined somewhere else".

Function forward declarations don't need the **extern** keyword --
the compiler is able to tell whether you're defining a new function
or making a forward declaration based on whether you supply a function
body or not.
Variables forward declarations do need the **extern** keyword to help
differentiate vairables definitions from variable forward declarations.

[comment]: <> (Global constants as external variables)
If __constants.h__ get included into 20 different code files, each of these
variables is duplicated 20 times. Header guards won't stop this from happening,
as they only prevent a header from being included more than once into a single
including file, not from being included one time into multiple different code files.

One way to avoid these problems is by turning these constants into __external__ variables.

[comment]: <> (Author's note)
Use __const__ instead of __constexpr__.

[comment]: <> (Global constants as inline variables)
C++17 introduced a new concept called __inline__ variables.
The compiler will consolidate all inline definitions into a single variable defintion.

[comment]: <> (Non-const global variables are evil)
__Non-const__ global variables are dangerous is because their values can be changed
by any function that is called, and there is no easy way for the programmer to know
that this will happen.

The global variables make the program's state unpredictable.
Rule of thumb for the use of a global variable:
- There should only ever be one of the thing the variable represents in your program
- Its use should be ubiquitous throughout your program

When the extraction operator is used, the following procedure happens:
- If there is data already in the input buffer, that data is used for extraction
- If the input buffer contains no data, the user is asked to input data for extraction
(this is the case mot of the time). When the user hits enter, a '\n' character will be
placed in the input buffer.
- Operator __>>__ extracts as much data from the input buffer as it can into the
variable (ignoring any leading whitespace character, such as spaces, tabs or '\n').
- Any data that can not be extracted is left in the input buffer for the next
extraction.

[comment]: <> (20200325-Pointers and Array)

[comment]: <> (20200326-Pointers and const)
A __pointer to a const value__ is a (non-const) pointer that points to a constant value.
A pointer to a constant vairable can point to a non-constant variable.
How to think: A pointer to a constant variable treats the variable as constant
when it is accessed through the pointer, regardless of whether the variable was
initially defined as const or not.

This code is okay
---
    int value = 5;
    const int *ptr = &value;
    value = 6;
---
This code is not 
---
    int value = 5;
    const int *ptr = &value;
    *ptr = 6;
---

We can also make a pointer itself constant.
A __const pointer__ is a pointer whose value can not be changed after initialization.

__Const pointer to a const value__
It is possible to declare a const pointer to a const value by using the _const_
keyword both before the type and before the variable name.

---
    int value = 5;
    const int *const ptr = &value;
---

A const pointer to a const value can not be set to point to another address, nor
can the value it is pointing to be changed through the pointer.

__Reference variable__
Best Practice:
Pass arguments by non-const reference when the argument needs to be modified by the function.


[comment]: <> (Not Formal Defintion but need to understand)
**Lvalue** is something that points to a specific memory location.
**Rvalue** is something that doesn't point anywhere.
In general rvalues are temporary and short lived, while lvalues
live a longer life since they exists as variables.

Think of lvalues as *containers* and rvalues as *things*

Example:
```
    int x = 3;
```

Here 3 is an rvalue.
The variable x has a specific memory location, so it's an lvalue.

[comment]: <> (Chapter Summary)
Arrays allow us to store and access many variables of the
same type through a single identifier.

Arrays can be made multidimensional by using multiple idices.
std::string\_view and std::string instead

The new and delete operators can be used to dynamically allocate
memory for pointer variable or array.

Although it's likely to happen, operator _new_ can fail if the
operating system runs out of memory. If you're writing software
for a memory-limited system, make sure to check if _new_ was
successful.

Make sure to use the array _delete_ when deleting an array.
Pointers pointing to deallocated memory are called *dangling*
pointers. Using the wrong _delete_, or deferencing a dangling
pointer causes undefined behavior.

Failing to delete dynamically allocated memory can result in
memory leaks when the last pointer to that memory goes out
of scope.

Normal variables are allocated from limited memery called
stack. Dynamically allocated variables are allocated from
a general pool of memory called the heap.

A pointer to a const value treats the value it is pointing
to as const.

A reference is an alias to another variable. References are
declared using an ampersand (&), but this does not mean
address-of in this context.

References are implicitly const -- they must be initialized
with a value, and a new value can not be assigned to them.
References can be used to prevent copies from being made
when passing data to or from a function.

[comment]: <> (VIM's fix indentation)
Use "gg=G"

__Explanation__: *gg* goes to the top of the file, *=* is
a command to fix the indentation and *G* tells it to perform
the operation to the end of the file.
