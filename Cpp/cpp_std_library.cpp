#include<iostream>
#include<array>
#include<algorithm>
#include<string_view>

bool containsNut(std::string_view str)
{
    return (str.find("nut") != std::u32string_view::npos);
}

int main()
{
    std::array arr{13, 90, 99, 5, 40, 80};
    std::cout << "Enter a value to search for and replace with: ";
    int search {};
    int replace {};

    std::cin >> search >> replace;

    auto found { std::find(arr.begin(), arr.end(), search) };

    if (found == arr.end())
        std::cout << "Could not find " << search << '\n';
    else
        *found = replace;

    for (int i : arr)
        std::cout << i << ' ';

    std::cout << '\n';


    // Use std::find_if to find an element that
    // matches some condition
    

    std::array<std::string_view, 4> arr2 { "apple", "banana", "walnut", "lemon" };
    auto found2{ std::find_if(arr2.begin(), arr2.end(), containsNut) };

    if (found2 == arr2.end())
        std::cout << "No nuts\n";
    else
        std::cout << "Found " << *found2 << '\n';

    /* if we were to write the above example by hand, */
    /* you'd need at least two loops (one too loop through */
    /* the array, and one to match the substring). */

    
    
    return 0;
}
