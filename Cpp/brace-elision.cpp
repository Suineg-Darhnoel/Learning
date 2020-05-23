#include <iostream>
struct Foo{
    int i;
    int j;
};

struct Bar{
    Foo f;
    int k;
};

int main()
{
    Bar b = {{1, 2};
    std::cout << b.k;
    return 0;
}
