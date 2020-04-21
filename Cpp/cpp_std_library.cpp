#include<iostream>
#include<array>
#include<algorithm>
#include<string_view>

bool containsNut(std::string_view str)
{
    // std::string_view::find returns std::string_view::npos
    // if it doesn't find the substring
    // Otherwise it returns the index where the substring
    // occurs in str.
    return (str.find("nut") != std::u32string_view::npos);
}

void doubleNumber(int &i)
{
    i *= -2;
}

int main()
{
    /* std::array arr{13, 90, 99, 5, 40, 80}; */
    /* std::cout << "Enter a value to search for and replace with: "; */
    /* int search {}; */
    /* int replace {}; */

    /* std::cin >> search >> replace; */

    /* auto found { std::find(arr.begin(), arr.end(), search) }; */
    /* // std::find returns an iterator pointing to the found element */

    /* if (found == arr.end()) */
    /*     std::cout << "Could not find " << search << '\n'; */
    /* else */
    /*     *found = replace; */

    /* for (int i : arr) */
    /*     std::cout << i << ' '; */

    /* std::cout << '\n'; */


    // Use std::find_if to find an element that
    // matches some condition
    

    std::array<std::string_view, 4> arr2 { "apple", "banana", "lemon", "walnut"};
    // std::string_view, is a non-owning range of const chars, implementable as
    // either a pair of pointers or a pointer and a length.
    
    auto found2{ std::find_if(arr2.begin(), arr2.end(), containsNut) };

    if (found2 == arr2.end())
        std::cout << "No nuts\n";
    else
        std::cout << "Found " << *found2 << '\n';

    /* if we were to write the above example by hand, */
    /* you'd need at least two loops (one too loop through */
    /* the array, and one to match the substring). */

    std::array arr3{ 13, 90, 99, 5, 40, 80 };

    // pass greater to std::sort
    std::sort(arr3.begin(), arr3.end(), std::greater{});

    for (int i : arr3)
        std::cout << i << ' ';
    std::cout << '\n';

    std::for_each(arr3.begin(), arr3.end(), doubleNumber);

    for (int i : arr3)
        std::cout << i << ' ';
    std::cout << '\n';

    // Favor using functions from the algorithm library over writing
    // your own functionality to do the same thing.

    return 0;
}
