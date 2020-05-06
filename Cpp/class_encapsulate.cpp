#include<iostream>

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

class MyString
{
    private:
        char *m_string; // we'll dynamically allocate our string here
        int m_length; // we need to keep track of the string length
    public:
        int getLength() { return m_length; } // access function to get value of m_length
};

int main()
{
    Something something;
    something.setValue1(5);
    std::cout << something.getValue1() << '\n';
    return 0;
}
