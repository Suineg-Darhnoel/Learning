#include <iostream>

// In this way the code duplication is kept to a minimum
class Foo
{
    private:
        int value {};
        void DoA()
        {
            // code to do A
        }
    public:
        Foo()
        {
            DoA();
        }

        Foo(int nValue): value {nValue}
        {
            DoA();
            // code to do B
        }
};

// Use delegating constructor
class Employee
{
    private:
        int m_d;
        std::string m_name;
    public:
        Employee(int id=0, const std::string& name=""):
            m_d(id), m_name(name)
        {
            std::cout << "Employee " << m_name << " created.\n";
        }

        // Use a delegating constructor to minimize redundant code
        Employee(const std::string& name): Employee(0, name) {}
};


int main()
{

    return 0;
}
