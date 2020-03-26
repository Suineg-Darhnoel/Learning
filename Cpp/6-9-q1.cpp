#include <algorithm> // for std::sort
#include <iostream>
#include <string>

int main()
{
    int num;
    std::cout << "How many names would you like to enter? ";
    std::cin >> num;

    std::string* array { new std::string [num]{} };

    for (int i = 0; i < num; ++i)
    {
        std::cout << "Enter name #1: ";
        std::cin >> array[i];
    }

    std::sort(array, array+num);
    for (int i = 0; i < num; ++i)
    {
        std::cout << "Name #" << i+1 << " " << array[i] << '\n';
    }

    delete[] array;

    return 0;
}
