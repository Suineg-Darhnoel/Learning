#include "c8.9Date.h"

// Date constructor
Date::Date(): m_year {2020}, m_month {5}, m_day {10} {}
Date::Date(int year, int month, int day)
{
    setDate(year, month, day);
}

/* Date member function */
void Date::setDate(int year, int month, int day)
{
    m_month = month;
    m_day = day;
    m_year = year;
}

// Now any other header or code file that wants 
// to use the Date class can simply #include "Date.h".
// Note that Date.cpp also needs to be compiled into any
// project that uses Date.h so the linker knows how
// Date is implemented.
