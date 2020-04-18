#include<iostream>
#include<array>
#include<algorithm>

// C++ standard library includes
// functionality that makes array
// management easier,
// std::array and std::vector.
void printLength(const std::array<float, 5> &myArray)
{
    std::cout << "length: " << myArray.size() << '\n';
}

int main()
{
    std::array<int, 3> myArray1; // declare an integer array with length 3

    std::array<int, 5> myArray2 = {9,7,5,3,1};
    // initializer list
    
    /* std::array<int> myArray {9,7,5,3,1}; */
    // illegal, array length must be provide
    
    // we can assign values to the array using
    // an initializer list
    
    myArray1 = {0, 1, 2};
    myArray2 = {9, 8, 7}; // this is okay, elements 3 and 4 are est to zero!

    myArray2 = {0, 1, 2, 3, 4};
    /* myArray2 = {0, 1, 2, 3, 4, 5}; // not allowed, to many elements in initializer list! */

    // Accessing std::array values using the subscript operator works
    // just like we would expect
    
    std::cout << myArray1[1] << '\n';
    myArray2[2] = 5;

    /* std::array supports a second form of array element */
    /* access (the at() function) that does bounds checking: */
    myArray1.at(1) = 6;
    std::cout << myArray1[1] << '\n'; // assure the method works

    /* The size() function can be used to retrieve the length */
    /* of the std::array: */

    std::array<float, 5> myArray {9.0, 7.2, 5.4, 3.6, 1.8};
    std::cout << "length: " << myArray.size() << '\n';


    // Because std::array doesn't decay to a pointer when
    // passed to a function, the size() function will work
    // even if you call it from within a function:
    
    printLength(myArray);

    // RULE: Always pass std::array by reference or const reference
    // This is to prevent the compiler from making a copy of the
    // std::array when the std::array was passed to the function
    // (for performance reasons)

    // we can sort array using std::sort
    myArray = {7,3,1,9,5};
    std::sort(myArray.begin(), myArray.end());

    for (int element: myArray)
        std::cout << element << ' ';

    std::cout << '\n';
    
    // Manually indexing std::array via size_type
    /* for (int i{0}; i < myArray.size(); ++i) */
    /*     std::cout << myArray[i] << ' '; */
    /* std::cout << '\n'; */

    // The above example doesn't work because
    // the counter i is a signed int while
    // myArray.size()'s type is size_type in C++
    
    // Therefore the correct way is:
    for (std::array<int, 5>::size_type i{0}; i < myArray.size(); ++i)
        std::cout << myArray[i] << ' ';
    std::cout << '\n';

    // use type alias
    using index_t = std::array<int, 5>::size_type;
    for (index_t i{0}; i < myArray.size(); ++i)
        std::cout << myArray[i] << ' ';
    std::cout << '\n';

    // Or just std::size_t
    for (std::size_t i{0}; i < myArray.size(); ++i)
        std::cout << myArray[i] << ' ';
    std::cout << '\n';

    // Print array in the reverse order
    for (auto i{ myArray.size() }; i-- > 0; )
        std::cout << myArray[i] << ' ';
    std::cout << '\n';

    return 0;
}
