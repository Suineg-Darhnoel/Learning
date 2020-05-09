#include<iostream>
#include "c8.9Date.h"

/* Reminder */

/* Fundamental data types (int, double, char, etc..) */
/* can be made const via the const keyword, and that */
/* all const variables must be initialized at time of creation */

const int value1 = 5; // copy initialization
const int value2(7); // direct initialization
const int value3 { 9 }; // uniform intialization

/* Overloading const and non-const function */
class Something
{
    private:
        std::string m_value;
    public:
        Something(const std::string &value="") { m_value = value; }
        const std::string& getValue() const { return m_value; } // getValue() for const objects
        std::string& getValue() { return m_value; } // getValue() for non-const objects
};

int main()
{
    const Date date1; // initialize using default constructor;
    const Date date2(2020, 10, 16); // initialize using parameterized constructor
    const Date date3 { 2020, 10, 16}; // initialzie using parameterized constructor (c++11)

    /* Once a const class object has been initialized via constructor, any attempt to modify the member variables of the object is disallowed, as it would violate the const-ness of the object */

    return 0;
}
