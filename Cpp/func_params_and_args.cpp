#include<iostream>
#include<cmath> // for std::sin() and std::cos()

// A function parameter is sometimes called a formal parameter
// void foo (int x); x is a parameter
//
// An argument is sometimes called an actual parameter
// foo(6); 6 is the argument passed to parameter x
//
// When a function is called, all of the parameters of the
// function are created as variables, and the value of
// the arguments are copied into the parameters.
void foo1(int x, int y){
    std::cout << x << ' ' << y << '\n';
}
// foo(6, 7);

// pass by reference
// To pass a variable by reference, we simply declare the
// function parameters as references rather than as normal variables.
void addOne(int &ref)
{
    ref = ref + 1;
}

// Reference to pointers
// It's possible to pass a pointer by reference,
// and have the function change the address of the 
// pointer entirely

void foo(int *&ptr)
{
    ptr = nullptr;
}

void getSinCos(double degrees, double &sinOut, double &cosOut)
{
    static constexpr double pi { 3.141592653589793223846 };
    double radians = degrees * pi / 180.0;
    sinOut = std::sin(radians);
    cosOut = std::cos(radians);
}

int main()
{
    int value = 5;

    std::cout << "value = " << value << '\n';
    addOne(value);
    std::cout << "value = " << value << '\n';

    // Sometimes we need a function to return multiple values.
    // However, functions can only have one return value.
    // One way to return multiple values is using reference parameters.
    
    double sin(0.0);
    double cos(0.0);

    // getSinCos will return the sin and cos in variables sin and cos
    getSinCos(30.0, sin, cos);

    std::cout << "The sin is " << sin << '\n';
    std::cout << "The cos is " << cos << '\n';

    int x = 5;
    int *ptr = &x;

    std::cout << "ptr is: " << (ptr ? "non-null" : "null") << '\n'; // print non-null
    foo(ptr);
    std::cout << "ptr is: " << (ptr ? "non-null" : "null") << '\n'; // print non-null

    return 0;
}
