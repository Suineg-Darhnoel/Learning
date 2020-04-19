#include<iostream>
#include<iterator> // std::begin and std::end
#include<array>

int main()
{
    std::array data {0,1,2,3,4,5,6};

    // many different ways to loop

    std::size_t length{ std::size(data) };
    for (auto ptr{ &data[0] }; ptr != (&data[0] + length); ++ptr)
        std::cout << *ptr << ' ';
    std::cout << '\n';

    // An iterator is an object designed to traverse through
    // a container (e.g the values in an array, or the characters
    // in a string), providing access to each element along the way


    /* pointers as an iterator */
    auto begin { &data[0] };
    auto end { begin + std::size(data) };

    for (auto ptr{ begin }; ptr != end; ++ptr)
        std::cout << *ptr << ' ';
    std::cout << '\n';


    /* Use iterator library */
    std::array array_l{1, 2, 3};
    auto begin_l { std::begin(array_l) };
    auto end_l { std::end(array_l) };

    for (auto p { begin_l }; p != end_l; ++p)
        std::cout << *p << ' ';// deference to get value of current element
    std::cout << '\n';

    // Remind range-based for-loops
    for (int i : array_l )
        std::cout << i << ' ';
    std::cout << '\n';

    return 0;
}
