// Constructor member initializer lists
#include <iostream>

/* Member initializer lists */
/* Prefer initializer list to assignments! */
class Something
{
    private:
        int m_value1;
        double m_value2;
        char m_value3;
    public:
        Something():
            m_value1 {1},
            m_value2 {2.2},
            m_value3 {'c'}
        {
            // No need for assignment here
        }
        void print()
        {
            std::cout << "Something(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ")\n";
        }

};

int main()
{
    // REVIEW POINT
    int value1 = 1; // copy intialization
    double value2(2.2); // direct initialization
    char value3 {'c'}; // uniform initialization

    Something sth{};
    sth.print();
    return 0;
}
