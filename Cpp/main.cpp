#include <iostream>
#include <bitset>
#include <cstdint> // for std::int_fast64_t
#include <cmath> // std::abs
#include <algorithm> // std::max
#include "add.h"
#include "constants.h"

int intInput()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
    return x;
}

int two_power(int n)
{
    if (n == 0)
        return 1;
    else
        return (2 * two_power(n-1));
}

std::int_fast64_t powint(int base, int exp)
{
    std::int_fast64_t result{1};
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

bool approximatelyEqual(double a, double b, double epsilon)
{
    return (std::abs(a-b) <= (std::max(std::abs(a), std::abs(b)) * epsilon));
}

extern int g_x; // this extern is a foward declaration of a variable
// named g_x that is defined somewhere else
extern const int g_y; // this extern is a forward declaration of
// a const variable named g_y that is defined somewhere else

/* global variable */
int value {5};

void incrementAndPrint()
{
    static int s_value{1};
    ++s_value;
    std::cout << s_value << '\n';
}

//Define a new enumeration named color
enum Color
{
    COLOR_BLACK,
    COLOR_WHITE
};

const char* getName()
{
    return "Alex";
}

int main()
{
    // PEMDAS
    // mnemonic -> "Please Excuse My Dear Aunt Sally"
    // meaning -> Parenthesis
    //            Exponents
    //            Multiplication
    //            Division
    //            Addition
    //            Subtraction
    // int n{intInput()};
    // int result{n};
    // std::cout << "2^n= " << two_power(result) << '\n';
    std::cout << sizeof(std::size_t) << '\n';
    std::cout << 5.7f << '\n';
    
    double zero {0.0};
    double posinf {5.0 / zero};
    double nan {zero / zero};
    std::cout << posinf << std::endl;
    std::cout << -posinf << std::endl;
    std::cout << nan << std::endl;
    std::cout << (nan == nan) << std::endl;

    std::cout << true << std::endl;
    std::cout << false << std::endl;

    std::cout << std::boolalpha;

    std::cout << true << std::endl;
    std::cout << false << std::endl;

    char ch{98};
    std::cout << ch << std::endl;

    int8_t i(98); // int8_t is treated as a signed char in c++
    std::cout << static_cast<int>(i) << std::endl;
    std::cout << std::bitset<4>{ 0b1010 + 0b0011 } << '\n';
    // definining variable as shown below will cause a compile error
    // const double gravity;
    const double gravity {9.8}; /* the variable gravity must be initialized
                                   when used with const keyword */

    std::cout << gravity << std::endl;
    int radius{23};
    double circumference { 2*radius*constants::pi};
    std::cout << "The circumference is: " << circumference << '\n';

    std::cout << powint(7, 12) << std::endl;

    /* SIDEEFFECT
     C++ does not define the order in which function arguments
     are evaluated.
    */
    int x{1};
    int y{6};
    // int value = add(x, ++x);
    // std::cout << value << std::endl;

    // comma operator
    std::cout << (++x, ++y) << '\n';
    std::cout << x << '\n';

    std::cout << (true == 1) << '\n';
    std::cout << approximatelyEqual(1.003, 1.0029, 0.001) << '\n';

    /* local and global variable comparison */
    int value {7};
    std::cout << "local vairable value: " << value << '\n';
    std::cout << "global vairable value: " << ::value << '\n';

    std::cout << "g_x = " << g_x << std::endl;

    incrementAndPrint();
    incrementAndPrint();
    incrementAndPrint();

    typedef double distance_t1;
    using distance_t2 = double;
    distance_t1 d1{2.0};
    distance_t2 d2{3};

    std::cout << d1 << std::endl;
    std::cout << d2 << std::endl;

    // std::string
    std::string myName;
    myName = "Jonh";
    std::cout << myName << '\n';

    std::string a{"12"};
    std::string b{"13"};
    std::cout << a + b << '\n';
    a += " volts\n";
    std::cout << a;

    std::cout << "a's length is " << a.length() << '\n';

    if ( bool if_cond = true ){
        std::cout << if_cond << '\n';
    }

    const char *name1{ "Alex" };
    const char *name2{ "Alex" };

    printf("name1 = %s, name2 = %s\n", name1, name2);

    int val {5};
    int &rval { val }; // the ampesand does no mean "address of", it means "reference to"

    val = 6;
    rval = 7;

    std::cout << val << '\n';
    ++rval;
    std::cout << val << '\n';

    return 0;
}

