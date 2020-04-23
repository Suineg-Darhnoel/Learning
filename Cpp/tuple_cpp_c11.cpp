#include<iostream>
#include<tuple>

std::tuple<int, double> returnTuple() // return a tuple that contains an int and a double
{
    return { 5, 6.7 };
}

int main()
{
    std::tuple s { returnTuple() }; // get our tuple
    std::cout << std::get<0>(s) << ' ' << std::get<1>(s) << '\n'; // use std::get<n> to get the nth element of the tuple

    // use std::tie to unpack the tuple into predefined variables
    int a;
    double b;

    std::tie(a, b) = returnTuple(); // put elements of tuple in variables a and b
    std::cout << a << ' ' << b << '\n';

    // As of C++17, a structured binding delaration can be used to simplify
    // splitting multiple returned values into separate variables:
    
    
    auto [c, d] { returnTuple() };
    std::cout << c << ' ' << d << '\n';

    return 0;
}
