#include<iostream>

// Because allocating and deallocating two-dimensional
// arrays is complex and easy to mess up, it's often
// easier to "flatten" a two-dimensional array (of size x by y)
// into a one-dimensional array of size x*y
int getSingleIndex(int row, int col, int numberOfColumnsArray)
{
    return (row * numberOfColumnsArray) + col;
};

int main()
{
    int value = 5;
    int *ptr = &value;
    std::cout << *ptr << '\n';

    int **ptrptr = &ptr;
    std::cout << **ptrptr << '\n';

    /* we can not set a pointer to a pointer */
    /* directly to a value */
    // EXAMPLE: int **ptrptr = &&value;
    
    /* This is because the address of operator (operator&) */
    /* requires an lvalue, but &value is an rvalue */

    // int **array = new int [10][5]; // This example doesn't work
    // To fix it use
    int **array = new int*[10];
    for (int count=0; count < 10; ++count)
        array[count] = new int[count+1];

    /* Deallocating a dynamically allocated two-dimensional array */
    /* using this method requires loop as well */
    for (int count = 0; count < 10; ++count)
        delete[] array[count];
    delete[] array; // this needs to be done last

    /* Note that we delete the array in th opposite order */
    /* that we created it(element first, then the array itself). */
    /* If we delete array before the array elements, then we'd */
    /* have to access deallocated memory to delete the array elements. */
    /* And then would result in underfined behavior */
    

    return 0;
}

// If we want a function to be able to modify what a pointer
// argument points to, this is generally better done using
// a reference to a pointer instead.
