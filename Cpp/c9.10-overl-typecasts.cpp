#include <iostream>

class Cents
{
    private:
        int m_cents;
    public:
        Cents(int cents=0)
            : m_cents{ cents }
        {
        }
        // Overloaded int cast
        operator int() const { return m_cents; }

        int getCents() const { return m_cents; }
        void setCent(int cents) { m_cents = cents; }
};

void printInt(int value)
{
    std::cout << value << std::endl;
}

int main()
{
    Cents cents { 7 };
    printInt(cents.getCents());

    /* The compiler will first note that function printInt takes */
    /* and integer parameter. Then it will note that variable is not an int. */
    /* Finally, it will look to see if we've provided a way to convert */
    /* a Cents into an int. It will call our operator int() function, which */
    /* returns an int, and the returned int will be passed to printInt() */
    printInt(cents);

    return 0;
}
