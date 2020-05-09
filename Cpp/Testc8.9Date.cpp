#include <iostream>
#include "c8.9Date.h"

int main()
{
    Date d { 2020, 04, 12 };
    std::cout << d.getDay() << std::endl;
    return 0;
}
