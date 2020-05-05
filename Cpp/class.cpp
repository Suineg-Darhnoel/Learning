#include<iostream>
#include<vector>

class DateClass{
    public:
        int m_year;
        int m_month;
        int m_day;
        
        void print()
        {
            std::cout << m_year << "/" << m_month << "/" << m_day << '\n';
        }
};

// Using the "m_" prefix for member varibles helps
// distinguish member variables from function.
class Employee{
    public:
        std::string m_name;
        int m_id;
        double m_wage;

        // Print employee information to the screen
        void print()
        {
            std::cout   << "Name:" << m_name <<
                        " Id: " << m_id <<
                        " Wage: $" << m_wage << '\n';
        }
};

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

// Mixing access specifiers
class DateClass2{
    // members are private by default
    int m_month;
    int m_day;
    int m_year;

    public:
        void setDate(int month, int day, int year)
        {
            // setDate() can access members of the class
            // because it is a member of the class itself
            m_month = month;
            m_day = day;
            m_year = year;
        }

        void print()
        {
            std::cout << m_month << '/' << m_day << '/' << m_year << '\n';
        }
};

// One nuance of C++ that is often missed or misunderstood is
// that access control works on a per-class basis, not a per-object basis.
// This means that when a function has access to the private members
// of a class, it can access the private members of any object of that
// class type that it can see.
class DateClass3{
    // members are private by default
    int m_month;
    int m_day;
    int m_year;

    public:
        void setDate(int month, int day, int year)
        {
            // setDate() can access members of the class
            // because it is a member of the class itself
            m_month = month;
            m_day = day;
            m_year = year;
        }

        void print()
        {
            std::cout << m_month << '/' << m_day << '/' << m_year << '\n';
        }

        void copyFrom(const DateClass3 &d)
        {
            // Note that we can access the private members of d directly
            m_month = d.m_month;
            m_day = d.m_day;
            m_year = d.m_year;
        }
};


// main () function
int main()
{
    DateClass today { 2020, 10, 14 };
    today.m_day = 16; // use member selection operator to select a member variable of the class
    today.print(); // use member selection operator to call a member function of the class

    Employee alex {"Alex", 1, 25.00};
    Employee joe {"joe", 2, 22.25};

    // Print out the employee information
    alex.print();
    joe.print();

    Calculator cal{};
    std::cout << cal.add(3, 4) << '\n'; // 7
    std::cout << cal.add(99, 24) << '\n'; // 7

    for (Calculator::number_t result : cal.m_resultHistory)
        std::cout << result << '\n';
    
    DateClass2 date2;
    date2.setDate(10, 14, 2020); // okay because setDate() is public
    date2.print(); // okay, because print() is public

    DateClass3 date3;
    date3.setDate(12, 14, 2020);

    DateClass3 date3_copy;
    date3_copy.copyFrom(date3);
    date3_copy.print();

    return 0;
}
