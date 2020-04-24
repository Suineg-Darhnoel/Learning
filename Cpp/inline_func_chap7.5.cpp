#include<iostream>

// Terminology
// 1. Overhead Penalty

// Inlining a function is best suited to short functions
// (no more than a few lines)

inline int min(int x, int y)
{
    return x > y ? y : x;
}

int main()
{
    std::cout << min(5, 6) << '\n';
    std::cout << min(3, 2) << '\n';
    // the above code is equivalent to
    // std::cout < (5 > 6 ? 6 : 5 ) << '\n';
    // std::cout < (3 > 2 ? 2 : 3 ) << '\n';

    // Modern compilers are now very good at inlining functions automatically
    // Even if you don't mark a function as inline
    return 0;
}
