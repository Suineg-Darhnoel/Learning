#include <iostream>

int main()
{
    int *intptr1 = new int(50);
    int *intptr2 = new int(30);

    // Deep copy (safe!)
    *intptr1 = *intptr2;
    std::cout << *intptr1 << " " << *intptr2 << '\n';

    delete intptr1;
    delete intptr2;
    return 0;
}
