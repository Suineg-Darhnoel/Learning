#include<iostream>

class Rectangle
{
    private:
        double m_length {1.0}; // m_length has a default value of 1.0
        double m_width {1.0}; // m_width has a default value of 1.0
    public:
        void print()
        {
            std::cout << "length: " << m_length <<  ", width: " << m_width << '\n';
        }
};

class Rectangle2
{
    private:
        double m_length {1.0}; // m_length has a default value of 1.0
        double m_width {1.0}; // m_width has a default value of 1.0
    public:
        Rectangle2(double len, double width)
            : m_length { len },
            m_width { width }
        {
            // m_length and m_width are initialized by the constructor
            // (the default values aren't used)
        }
        void print()
        {
            std::cout << "length: " << m_length <<  ", width: " << m_width << '\n';
        }
};



int main()
{
    Rectangle x{}; // x.m_length = 1.0, x.m_width = 1.0
    x.print();

    /* Rectangle2 y{}; */ // will not compile, no default constructor exists, even though members have default initialization values
    /* y.print(); */
    /* RULE */
    /* Favor use of non-static member initialization to give default values for your member variables. */

    return 0;
}
