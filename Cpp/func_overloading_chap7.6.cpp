#include<iostream>

// Function overloading is a feature of C++
// that allows us to create multiple functions
// with the same name, so long as they have
// different parameters.

int add(int x, int y){
    return x + y;
}

double add(double x, double y){
    return x + y;
}

// We can define as many overloaded add()
// functions as we want, so long as each add()
// function has unique parameters.

void print(char *value)
{
    std::cout << *value << '\n';
}

void print(int value)
{
    std::cout << value << '\n';
}

int main()
{
    std::cout << add(2, 3) << '\n';
    std::cout << add(2.0, 3.5) << '\n';

    print('a');
    // In this case, because there is no print(char), the char 'a'
    // is promoted to an integer, which then matches print(int).
    //
    // ANd if no promotion is possible, C++ tries to find a match
    // through standard conversion.
    return 0;
}
