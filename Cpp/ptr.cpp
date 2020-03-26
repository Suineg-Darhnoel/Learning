#include <iostream>
using namespace std;

int man_func(int x){
    return x;
}

int man_func(int x, int y){
    return x & y;
}

int main()
{
    cout << man_func(2) << '\n';
    cout << man_func(2,5) << '\n';

    int array[5]{9, 7, 5, 3, 1};

    cout << "Element 0 has address: " << &array << '\n';
    cout << "The array decays to a pointer holding address: " << array << '\n';

    cout << *array << '\n';
    cout << "size of array: " << sizeof(array) << '\n';
    char name[]{"Jason"};
    cout << *name << '\n';

    // initializing a dynamically allocated vairable

    int *ptr1 = new int(5);
    int *ptr2 = new int {6};


    cout << *ptr1 + *ptr2 << endl;
    delete ptr1;
    delete ptr2;

    int *dptr = new int{2};
    int *otherDptr = dptr;
    cout << *otherDptr << endl;

    delete dptr;
    dptr = 0;

    cout << *otherDptr << endl;
    return 0;
}

