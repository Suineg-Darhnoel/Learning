#include <iostream>
#include <array>
#include <algorithm>
#include <string_view>
#include <functional>

int main()
{
    std::array months{
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    // Search for two consecutive months that start with the same letter.
    auto sameLetter {
        std::adjacent_find(
                months.begin(),
                months.end(),
                [](const auto& a, const auto& b){
                        return (a[0] == b[0]);
                    }
                )
    };

    // Make sure that two months were found.
    if (sameLetter != months.end())
    {
        // std::next returns the next iterator after sameletter
        std::cout << *sameLetter << " and " << *std::next(sameLetter)
                << " start with the same letter\n";
    }

    // Return  type deduction and trailing return types
    // 1. do explicit casts to make all the return types match, or
    // 2. explicitly specify a return type for the lambda, and 
    // let the comiler do implicit conversions.
    auto divide{
        [](int x, int y, bool bInteger) -> double {
            if (bInteger)
                return x / y; // will do implicit conversion to double
            else
                return static_cast<double>(x) / y;
        }
    };

    std::cout << divide(3, 2, true) << '\n';
    std::cout << divide(3, 2, false) << '\n';

    // standard library function objects
    // the objects are defined in <functional> header
    std::array arr{13,90,99,5,40,80};

    // Pass greater to std::sort
    std::sort(arr.begin(), arr.end(), std::greater{});
    for (int i : arr)
        std::cout << i << ' ';
    std::cout << '\n';
    return 0;
}
