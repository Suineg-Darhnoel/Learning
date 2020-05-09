### Expression
An **Expression** is a combination of literals, variables,
operators, and explicit function calls (not shown above)
that produce a single output value.
[comment]: <> "type identifier { expression };"
---
    int x{2+3};
---

[comment]: <> "Author's note"
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

[comment]: <> "Best Practice 4.13"
- Any variable that should not be modifiable after initialization
and whose initializer is known at compile-time should be declared
as **constexpr**.
- Any variable that should not be modifiable after initialization
and whose initializer is __not__ known at compile-time should be
declared as **const**.

[comment]: <> "Global variables with internal linkage"
---
    static int g_x; // non-constant globals have external linkage
    // by default, but can be given internal linkage via the static keyword
    
    const int g_y {1}; // const globals have internal linkage by default
    constexpr int g_z {2}; // constexpr globals have internal linkage by default
---
Const and constexpr global variables have internal linkage by default
(and thus don't need the _static_ keyword -- if it used, it will be ignored)

[comment]: <> "External Linkage"
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

[comment]: <> "Global constants as external variables"
If __constants.h__ get included into 20 different code files, each of these
variables is duplicated 20 times. Header guards won't stop this from happening,
as they only prevent a header from being included more than once into a single
including file, not from being included one time into multiple different code files.

One way to avoid these problems is by turning these constants into __external__ variables.

[comment]: <> "Author's note"
Use __const__ instead of __constexpr__.

[comment]: <> "Global constants as inline variables"
C++17 introduced a new concept called __inline__ variables.
The compiler will consolidate all inline definitions into a single variable defintion.

[comment]: <> "Non-const global variables are evil"
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

[comment]: <> "20200325-Pointers and Array"

[comment]: <> "20200326-Pointers and const"
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


[comment]: <> "Not Formal Defintion but need to understand"
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

[comment]: <> "Chapter Summary"
Arrays allow us to store and access many variables of the
same type through a single identifier.

Arrays can be made multidimensional by using multiple indices.
std::string\_view and std::string instead

The new and delete operators can be used to dynamically allocate
memory for pointer variable or array.

Although it's likely to happen, operator _new_ can fail if the
operating system runs out of memory. If you're writing software
for a memory-limited system, make sure to check if _new_ was
successful.

Make sure to use the array _delete_ when deleting an array.
Pointers pointing to deallocated memory are called *dangling*
pointers. Using the wrong _delete_, or dereferencing a dangling
pointer causes undefined behavior.

Failing to delete dynamically allocated memory can result in
memory leaks when the last pointer to that memory goes out
of scope.

Normal variables are allocated from limited memory called
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

[comment]: <> "VIM's fix indentation"
Use "gg=G"

__Explanation__: *gg* goes to the top of the file, *=* is
a command to fix the indentation and *G* tells it to perform
the operation to the end of the file.

## 7.4a - Returning values by value, reference, and address

### RETURN by VALUE
When to use return by value:

- When returning values that were declared inside the function
- When returning function arguments that were passed by value

When not to use return by value:

- When returning a built-in array or pointer (use return by address)
- When returning a large struct or class (use return by reference)

### RETURN by ADDRESS
When to use return by values:

- When returning dynamically allocated memory and you can't
use a type that handles allocations for you
- When returning function arguments that were passed by address

When not to use return by address:

- When returning variables that were declared inside the function
or parameters that were passed by value (use return by value)
- When returning a large struct or class that was passed by
reference (use return by reference)

### RETURN by REFERENCE
When to use return by reference:

- When returning a reference parameter
- When returning an element from an array that was passed into the function
- When returning a large struct or class that will not be destroyed at
the end of the function (e.g. one that was passed in)

When not to use return by reference:

- When returning variables that were declared inside the function or
parameters that were passed by value (use return by value)
- When returning a built-in array or pointer value (use return by address)

### Lambdas (anonymous functions)
A _lambda expression_ (also called a _lambda_ or _closure_) allows us to define
an anonymous function inside another function.

Syntax for lambdas
~~~
    [ captureClause ] (parameters) -> returnType
    {
        statements;
    }
~~~

    In actuality, lambdas aren't functions (which is part of how they avoid
    the limitation of C++ not supporting nested functions).
    They're a special kind of object called a functor.
    Functors are objects that contain an overloaded _operator()_ that
    make them callable like a function.

**Rule**
Use _auto_ when initializing variables with lambdas, and _std::function_ if
you can't initialize the variable with the lambda.

    When used in the context of a lambda, _auto_ is just a shorthand for a template parameter.

## Object Oriented Programming with C++
### Classes and class members

With normal non-member functions, a function can't call
a function that's defined "below" it (without a forward declaration)

~~~c++
    void x()
    {
        // You can't call y() from here unless the compiler
        // has already seen a forward declaration for y()
    }
    void y()
    {
    }
~~~

With member functions, this limitation doesn't apply
~~~c++
    class foo
    {
        plublic:
            void x() { y(); }; // okay to call y() here, even though y() isn't deined until later in this class
            void y() {};
    }
~~~

In addition to member variables and member functios, _classes_ can have **member types** or **nested types** (including type aliases).
~~~c++
    // Member types
    class Calculator
    {
        public:
            using number_t = int; // this is a nested type alias

            std::vector<number_t> m_resultHistory{};
            number_t add(number_t a, number_t b)
            {
                auto result{ a+b };
                m_resultHistory.push_back(result);
                return result;
            }
    };
~~~

Type alias members make code easier to maintain and can reduce typing.
Template classes often make use of type alias members.
Nested types cannot be forward declared.

~~~
    Use the struct keyword for data-only structures.
    Use the class keyword for objects that have both data and functions.
~~~

### Access functions and encapsulation
- Benefit: encapsulated classes are easier to change

Encapsulation gives us the ability to change how classes are implemented without breaking all of the programs that use them.

~~~c++
    class Something
    {
        private:
            int m_value1;
            int m_value2;
            int m_value3;
        public:
            void setValue1(int value){ m_value1 = value; }
            int getValue1() { return m_value1; }
    };
~~~
- Benefit: encapsulated classes are easier to debug
If everybody has to call the same public function to modify a value, then you can simply breakpoint that function and watch as each caller changes the value until you see where it goes wrong.

An *access function* is a short public function whose job is to retrieve or change the value of a private member variable.
~~~c++
    class MyString
    {
        private:
            char *m_string; // we'll dynamically allocate our string here
            int m_length; // we need to keep track of the string length
        public:
            int getLength() { return m_length; } // access function to get value of m_length
    };
~~~

- Access functions typically come in two flavors: getters and setters.
- _Getters_ (_accessors_) are functions that return the value of a private member variable.
_- Setters_ (_mutators_) are functions that set the value of a private member variable

Access functions concerns
A pragmatic approach. As you create your classes, consider the following:
- If nobody outside your class needs to access a member, don't provide access functions for that member
- If someone outside your class needs to access a member, think about whether you can expose a behavior or action instead.
- If you can't, consider whether you can provide only a getter.

## 8.5 Constructors
A *constructor* is a special kind of class member function that is automatically called when an object is instantiated.

- Constructors have specific rules for how they must be named
1. Constructors must have the same name as the class (with the same capitalization)
2. Constructors have no return type (not even void)

## 8.5a Constructor member initializer lists
The member initializer list is inserted after the contructor parameters.
It begins with a colon (:), and then lists each variable to initialize
along with the value for that variable separated by a comma.

*Initializer list order*
For best results, the following recommendations should be observed:
1. Don't initialize member variables in such a way that they are dependent upon other member variables being initialized first.
2. Initialize variables in the initialzer list in the same order in which  they are declared in your class.
This isn't strictly required so long as the prior recommendation has been followed, but your compiler may give you a warning if you don't do so and you have all warnings turned on.

## 8.6 Overlapping and delegating constructor

**Using a separate function**
Constructors are allowed to call non-constructor function in the class.
The best solution to this issue is to create a non-constructor function that does the common initialization, and have both constructors call that function.

~~~c++
    class Foo
    {
        private:
            int value {};
            void DoA()
            {
                // code to do A
            }
        public:
            Foo()
            {
                DoA();
            }

            Foo(int nValue): value {nValue}
            {
                DoA();
                // code to do B
            }
    };
~~~

## 8.7 Destructors
A *destructor* is another special kind of class member function that is executed when an object of that class is destroyed.

If our class object is holding any resources (e.g. dynamic memory, or a file, or database handle), or if we need to do any kind of maintenance before the object is destroyed, the destructor is the perfect place to do so, as it is typically the last thing to happen before the object is destroyed.

### Destructor naming

Destructors have specific naming rules:
1. The destructor must have the same name as the class, preceded by a tilde (~).
2. The destructor can not take arguments.
3. The destructor has no return type.

*Warning*
Note that if we use the exit() function, our program will terminate and no destructors will be called.

## 8.8 `This` Pointer

The *this* pointer is a hidden const pointer that holds the address of the object the member function was called on.

**Summary**
- The "this" pointer is a hidden parameter implicitly added to any non-static member function. Most of the time, you will not need to access it directly, but you can if needed.
- It's worth noting that "this" is a const pointer -- you can change the value of the underlying object it points to, but you cannot make it point to something else!

- By having functions that would otherwise return void return \*this instead, you
can make those functions chainable.
~~~c++
    void setID(int id) { m_id = id; }
~~~
is converted by the compiler into:
~~~c++
    void setID(Simple* const this, int id) 
    {
         this -> m_id = id;
    }
~~~

"*this*" always points to the object being operated on

## 8.9 Class code and header files
### Defining member functions outside the class defintion

As classes get longer and more complicated, having all the member function definitions inside the class can make the class harder to manage and work with.

C++ provides a way to seperate the "declaration" portion of the class from the "implementation" portion. This is done by defining the class member functions outside of the class definition.

To do so, simply define the member functions of the class as if they were normal functions, but prefix the class name to the function using the *scope resolution* (::) (same as for a namespace).

**Recommendation**
- For classes used in only one file that aren't generally resusable, define them directly in the single .cpp file they're used in.
- For classes used in multiple files, or intended for general reuse, define them in a .h file that has the same name as the class.
- Trivial member functions (trivial constructors or destructors, access functions, etc...) can be defined inside the class.
- Non-trivial member functions should be defined in a .cpp file that has the same name as the class.

**Library**
Throughout your programs, you've #included headers that belong to the standard library, such as iostream, string, vector, array, and other.
Notice that we haven't needed to add iostream.cpp, string.cpp, vector.cpp, or array.cpp into our projects.
Our program needs the declarations from the header files in order for the compiler to contained in a precompiled file that is linked in at the link stage.

Most 3rd party libraries provide only header files, along with a precompiled library file.

*Reasons*:
1. It's faster to link a precompiled library than to recompile it every time we need it.
2. A single copy of a precompiled library can be shared by many applications, whereas compiled code gets compiled into every executable that uses it
3. Intellectual property reasons (when we don't want people to steal our code)

## 8.10 Const class objects and member functions
*Rule*: Make any member function that does not modify the state of the class object const, so that it can be called by const objects.

### Overloading const and non-const function
~~~c++
class Something
{
    private:
        std::string m_value;
    public:
        Something(const std::string &value="") { m_value = value; }
        const std::string& getValue() const { return m_value; } // getValue() for const objects
        std::string& getValue() { return m_value; } // getValue() for non-const objects
};
~~~

**Summary**
Because passing objects by const reference is common, our classes should be const-friendly. That means making any member function that does not modify the state of the class object const!
