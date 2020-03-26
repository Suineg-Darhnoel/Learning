#include <iostream>
void changeN(int &ref)
{
    ref = 6;
}

void swap(int &a, int &b)
{
    int tmp {a};
    a = b;
    b = tmp;
}

int main()
{
    /* References work similarly in this regard.
     * Because the reference parameter acts as an
     * alias for the argument, a function that uses
     * a reference parameter is able to modify the 
     * argument passed in
    */
    int n{ 5 };
    std::cout << n << '\n';

    changeN(n);

    std::cout << n << '\n';

    int a{2}, b{3};
    std::cout << "a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;

    /* References as shortcuts */
    struct Something
    {
        int value1;
        float value2;
    };

    struct Other
    {
        Something something;
        int otherValue;
    };

    Other other;

    int &ref{ other.something.value1 };
    other.something.value1 = 5;

    ref = 5;

    /* Because references must be initialized to valid objects (cannot be null)
     * and cannot be changed once set, references are generally much safer
     * to use than pointers.
     *
     * If a given task can be solved with either a reference or a pointer,
     * the reference should generally be preferred.
     * Pointers should only be used in situations where references are
     * not sufficient (such as dynamically allocating memory).
    */

    return 0;
}
