#include<iostream>
#include<algorithm>
#include<array>

// Note that most of the algorithms in the algorithms
// library do not guarantee a particular order of execution.
// For such algorithms, take care to ensure any functions
// you pass in do not assume a particular ordering, as the
// order of invocation may not be the same on every compiler.

// Algorithms do guarantee sequential execution:
// std::for_each
// std::copy
// std::copy_backward
// std::move
// std::move_backward

void doubleNumber(int &i)
{
    i *= 2;
}

int main()
{
    std::array arr{1,2,3,4};
    std::for_each(arr.begin(), arr.end(), doubleNumber);

    for (int i : arr)
        std::cout << i << ' ';

    std::cout << '\n';
    return 0;
}
