#include <iostream>
#include <cassert> // assert

// Constructors have specific rules for how they must be named
// 1. Constructors must have the same name as the class (with the same capitalization)
// 2. Constructors have no return type (not even void)
class Fraction
{
    private:
        int m_numerator;
        int m_denominator;
    public:
        Fraction() // defualt constructor
        {
            m_numerator = 0;
            m_denominator = 1;
        }

        int getNumerator() { return m_numerator; }
        int getDenominator() { return m_denominator; }
        double getValue() 
        { 
            return static_cast<double>(m_numerator) / m_denominator;
        }

};

// Constructors can also be declared with parameters.
class Fraction2
{
private:
    int m_numerator;
    int m_denominator;
public:
    Fraction2() // default constructor
    {
        m_numerator = 0;
        m_denominator = 1;
    }

    // Constructor with two parameters, one parameter having a default value
    Fraction2(int numerator, int denominator=1)
    {
        assert(denominator != 0);
        m_numerator = numerator;
        m_denominator = denominator;
    }

    int getNumerator() { return m_numerator; }
    int getDenominator() { return m_denominator; }
    double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
};

// Reducing constructors
class Fraction3
{
private:
    int m_numerator;
    int m_denominator;
public:
    // Default constructor
    Fraction3(int numerator=0, int denominator=1)
    {
        assert(denominator != 0);
        m_numerator = numerator;
        m_denominator = denominator;
    }

    int getNumerator() { return m_numerator; }
    int getDenominator() { return m_denominator; }
    double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
};
// If our class has any other constructors, the implicitly generated
// constructor will not be provided.
class Date
{
    private:
        int m_year { 1900 };
        int m_month { 1 };
        int m_day { 1 };
    public:
        Date(int year, int month, int day)
        {
            m_year = year;
            m_month = month;
            m_day = day;
        }

        // No implicit constructor provided because we already defined our own constructor
};

// To allow construction of a Date without arguments,
// either add default arguments to the constructor,
// add an empty default constructor,
// or explicitly add a default constructor
class Date2
{
    private:
        int m_year { 1900 };
        int m_month { 1 };
        int m_day { 1 };
    public:
        // Tell the compiler to create a default constructor, even if
        // there are other user-provided constructors
        Date2() = default;
        Date2(int year, int month, int day) // normal non-default constructor
        {
            m_year = year;
            m_month = month;
            m_day = day;
        }
};

// RULE: If you have constructors in your class and need a default constructor that does nothing, use = default.

// Classes containing classes
class A
{
    public:
        A() { std::cout << "A\n"; }
};
class B
{
    private:
        A m_a; // B contains A as a member variable
    public:
        B() { std::cout << "B\n"; }
};

int main()
{
    Fraction frac; // Since no arguments, calls Fraction() default constructor
    std::cout << frac.getNumerator() << '/' << frac.getDenominator() << '\n';

    // Use brace or direct initilization
    Fraction2 five_thirds {5, 3}; // Brace initialization, calls Fraction2(int, int)
    Fraction2 three_quarters (3, 4); // Direct initialization, also calls Fraction2(int, int)
    Fraction2 six {6}; // calls Fraction2(int, int) constructor, second parameter uses default value

    std::cout << five_thirds.getNumerator() << '/' << five_thirds.getDenominator() << '\n';
    std::cout << three_quarters.getNumerator() << '/' << three_quarters.getDenominator() << '\n';
    std::cout << six.getNumerator() << '/' << six.getDenominator() << '\n';

    Fraction3 zero; // will call Fraction3(0, 1)
    Fraction3 zero2{}; // will call Fraction3(0, 1)
    Fraction3 seven{ 7 }; // will call Fraction3(6, 1)
    Fraction3 fiveThirds{ 5, 3 }; // will call Fraction3(5, 3)

    B b;

    return 0;
}
