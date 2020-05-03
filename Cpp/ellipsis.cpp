#include <iostream>
#include <cstdarg>

// Ellipsis "..."
// The ellipsis must be the last parameter
// count is how many additional arguments we're passsing
double findAverage(int count, ...)
{
    double sum{0};

    // We access the ellipsis through a va_list, so
    // lets declare one
    va_list list;

    // We initialize the va_list using va_start.
    // The first parameter is the list to initialize.
    // The second parameter is the last non-ellipsis parameter
    va_start(list, count);

    // Loop through all the ellipsis arguments
    for (int arg=0; arg < count; ++arg)
        // We use va_arg to get parameters out of our ellipsis
        // The first parameter is the va_list we're using
        // The second parameter is the type of the parameter
        sum += va_arg(list, int);
    // Clean up the va_list when we're done.
    va_end(list);

    return sum / count;
}

int main()
{
    std::cout << findAverage(10, 1,2,3,4,5,6,7,8,9,10) << std::endl; 
    return 0;
}
