#include <iostream>

class Simple
{
    private:
        int m_id;
    public:
        Simple(int id)
        {
            setID(id);
        }

        void setID(int id) { m_id = id; }
        int getID() { return m_id; }
};

// Explicitly referencing "this"
class Something
{
    private:
        int data;
    public:
        Something(int data)
        {
            this->data = data; // this -> data is the member, data is the local parameter
        }
};

// Chaining member functions
class Calc
{
    private:
        int m_value;
    public:
        Calc() { m_value = 0; }

        void add(int value) { m_value += value; }
        void sub(int value) { m_value -= value; }
        void mult(int value) { m_value *= value; }

        int getValue() { return m_value; }
};

// The new version of Calc with "chainable" functions
class Calc2
{
    private:
        int m_value;
    public:
        Calc2() { m_value = 0; }

        Calc2& add(int value) { m_value += value; return *this; }
        Calc2& sub(int value) { m_value -= value; return *this; }
        Calc2& mult(int value) { m_value *= value; return *this; }

        int getValue() { return m_value; }
};


int main()
{
    Simple simple(1);
    simple.setID(2);
    std::cout << simple.getID() << '\n';

    Simple A(1); // this = &A inside the Simple constructor
    Simple B(2); // this = &B inside the Simple constructor

    A.setID(3); // this = &A inside member function setID
    B.setID(4); // this = &B inside member function setID

    // We can effectively condense three lines into one expression
    Calc2 calc;
    std::cout << calc.getValue() << '\n';

    calc.add(5).sub(2).mult(4);
    std::cout << calc.getValue() << '\n';
    
    return 0;
}
