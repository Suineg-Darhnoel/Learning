#include <iostream>
#include <cstdlib>
#include <array>

// If we want to terminate program immediately,
// the _exit_ function that lives in <cstdlib>
// can be used to return an error code to the
// operating system
int getArrayValue(const std::array<int, 10> &array, int index)
{
    // use if statement to detec violated assumption
    if (index < 0 || index >= static_cast<int>(array.size()))
        std::exit(2); // terminate program and return error number 2 to OS
    return array[index];
}

// _cerr_ is another mechanism that is meant specifically for printing
// error messages. _cerr_ is an output stream (just like cout) that is
// defined in <iostream>.

void printString(const char* cstring)
{
    // Only print if cstring is non-null
    if (cstring)
        std::cout << cstring;
    else
        std::cerr << "function printString() received a null pointer";
}

int main()
{
    printString("Hello World\n");
    printString(NULL);
    return 0;
}
