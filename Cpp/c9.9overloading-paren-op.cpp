#include <iostream>
#include <cassert>

class Matrix
{
    private:
        double data[4][4]{};
    public:
        double& operator()(int row, int col);
        const double& operator()(int row, int col) const; // for const objects
};

double& Matrix::operator()(int row, int col)
{
    assert(col >= 0 && col < 4);
    assert(row >= 0 && row < 4);

    return data[row][col];
}

const double& Matrix::operator()(int row, int col) const
{
    assert(col >= 0 && col < 4);
    assert(row >= 0 && row < 4);

    return data[row][col];
}

// Check Functors : classes that operate like functions
// The advantage of a functor over a normal function is that functors can store data in member variables (since they are classes)

class Accumulator // this is an example of functor
{
    private:
        int m_counter {0};
    public:
        Accumulator(){
        }
        int operator() (int i) { return (m_counter += i); }
};

int main()
{
    Matrix m;
    m(1, 2) = 4.5;
    std::cout << m(1, 2) << '\n';

    Accumulator acc;
    std::cout << acc(10) << '\n'; // prints 10
    std::cout << acc(20) << '\n'; // prints 30
    return 0;
}
