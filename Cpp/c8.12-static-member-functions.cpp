#include <iostream>
class Something
{
    private:
        static int s_value;
    public:
        static int getValue() { return s_value; } // static member function
};

class IDGenerator
{
    private:
        static int s_nextID;
    public:
        static int getNextID(); // Here's the declaration for a static function
};

// Definition of the static member outside the class.
// Note we don't use the static keyword here
int IDGenerator::s_nextID { 1 };

// Defintion of the static function outside of the class.
// Note we don't use the static keyword here
int IDGenerator::getNextID() { return s_nextID++; }
/* Initializer, this is okay even though s_value is 
 * private since it's a definition */
int Something::s_value{ 1 };

int main()
{
    std::cout << Something::getValue() << '\n';
    for (int count {0}; count < 5; ++count)
        std::cout << "The next ID is: " << IDGenerator::getNextID() << '\n';
    return 0;
}
