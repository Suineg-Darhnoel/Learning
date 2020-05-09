#include <iostream>

class Date
{
    private:
        int m_year;
        int m_month;
        int m_day;
    public:
        Date(int year, int month, int day);

        void setDate(int year, int month, int day);

        int getYear() { return m_year; }
        int getMonth() { return m_month; }
        int getDay() { return m_day; }
};

// Date constructor
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

/* Another example */
class Calc
{
    private:
        int m_value = 0;
    public:
        Calc(int value=0);
        Calc& add(int value);
        Calc& sub(int value);
        Calc& mult(int value);

        int getValue() { return m_value; }
};

Calc::Calc(int value): m_value(value)
{
}

Calc& Calc::add(int value)
{
    m_value += value;
    return *this;
}

Calc& Calc::sub(int value)
{
    m_value -= value;
    return *this;
}

Calc& Calc::mult(int value)
{
    m_value *= value;
    return *this;
}

int main()
{
    Date date {2020, 5, 9};
    std::cout << date.getDay() << '\n';

    date.setDate(2020, 5, 10);
    std::cout << date.getDay() << '\n';

    return 0;
}
