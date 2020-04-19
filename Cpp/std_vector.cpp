#include<iostream>
#include<vector>

/* std::vector provides dynamic array functionality that */
/* handles its own memory management. */
/* This means you can create arrays that haev their */
/* length set at run-time, without having to explicitly */
/* allocate and deallocate memory using new and delete. */

/* std::vector lives in the <vector> header */

int main()
{
    // no need to specify length at initialization
    std::vector<int> array;

    // use initializer list to initilialize array
    std::vector<int> array2 = {9,7,5,3,1};

    // use uniform initialization to initialize array
    std::vector<int> array3 {9,7,5,3,1};

    /* note that in both the uninitialized and initialized case, */
    /* you do not need to include the array length at compile time. */

    // assign values to a std::vector using an initializer-list
    array = {0,1,2,3,4};
    array = {9, 8, 7};

    // When a vector variable goes out of scope, it automatically
    // deallocates the memory it controls (if neccessary).

    /// If array is an std::vector, memory will be deallocated as soon as
    // array goes out of scope (regardless of whether the function
    // exits early or not). This is safer than doing our own memory allocation
    

    // vectors remember their length
    array = {0,1,2,3,4};
    std::cout << array.size() << '\n';

    array = {9, 8, 7};
    std::cout << array.size() << '\n';

    // Resizing a vector
    array.resize(5); // set size to 5
    std::cout << "The length is: " << array.size() << '\n';
    
    // Resizing a vector is computationally expensive
    
    // using direct initialization, we can create a vector with 10 elements
    std::vector<int> array4(10);

    std::cout << "The length is: " << array4.size() << '\n';

    for (int i : array4)
        std::cout << i << ' ';
    std::cout << '\n';

    return 0;
}
