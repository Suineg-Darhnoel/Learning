#include <iostream>
#include <cassert>
#include <cstddef>

class IntArray
{
    private:
        int *m_array;
        int m_length;
    public:
        IntArray(int length)// constructor
        {
            assert(length > 0);
            m_array = new int[static_cast<std::size_t>(length)];
            m_length = length;
        }
        ~IntArray() // destructor
        {
            // Dynamically delete the array we allocated earlier
            delete[] m_array;
        }

        void setValue(int index, int value)
        {
            m_array[index] = value;
        }

        int getValue(int index)
        {
            return m_array[index];
        }
        
        int getLength()
        {
            return m_length;
        }
};

class Simple
{
    private:
        int m_nID;
    public:
        Simple(int nID)
            : m_nID { nID }
        {
            std::cout << "Constructing Simple " << nID << '\n';
        }

        ~Simple()
        {
            std::cout << "Destructing Simple" << m_nID << '\n';
        }

        int getID() { return m_nID; }
};


int main()
{
    IntArray arr(10); // allocate 10 integers
    for (int count { 0 }; count < arr.getLength(); ++count)
        arr.setValue(count, count+1);

    std::cout << "The value of element 5 is: " << arr.getValue(5) << '\n';

    // Allocate a Simple on the stack
    Simple simple { 1 };
    std::cout << simple.getID() << '\n';

    /* Allocate a Simple dynamically */
    Simple *pSimple { new Simple { 2 } };
    std::cout << pSimple->getID() << '\n';

    /* We allocated pSimple dynamically, so we have to delete it */
    delete pSimple;
    return 0;
}
// arr is destroyed here, so the ~IntArray() destructor function is called here
