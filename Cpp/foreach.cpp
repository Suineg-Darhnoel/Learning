#include <iostream>

int main()
{
    constexpr int fibonacci []{
        0, 1, 1, 2, 3, 5, 8, 13, 21
    };

    for (int number : fibonacci)
        std::cout << number << ' ';
    std::cout << '\n';

    std::string array[]{
        "peter", "likes", "frozen", "yogurt"
    };

    for (auto element : array)
        std::cout << element << ' ';
    /* This means each array element
     * iterated over will be copied
     * into variable element.
     * Copying array elements can be
     * expensive, and most of the time
     * we really just want to refer
     * to the original element.
    */

    std::cout << '\n';

    // A good idea is to use reference variable
    for (auto &element: array)
        std::cout << element << ' ';
    std::cout << '\n';

    /* RULE
     * In for-each loops element declarations,
     * if your elements are non-fundamental
     * types, use references or const references
     * for performance reasons.
    */

    /* NOTE 
     * The array has to have size information.
     * An array that decayed to a pointer
     * cannot be used in for-each loop.
    */

    return 0;
}
