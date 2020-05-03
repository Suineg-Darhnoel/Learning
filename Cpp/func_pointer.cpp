#include<iostream>
#include<vector>

void HelloWorld()
{
    std::cout << "Hello World!" << std::endl;
}

void func_with_arg(int a)
{
    std::cout << "a = " << a << std::endl;
}

void PrintValue(int value)
{
    std::cout << "Value: " << value << std::endl;
}

void for_each(const std::vector<int>& values, void(*func)(int))
{
    for (int value : values)
        func(value);
}

int main()
{
    auto func = HelloWorld;
    func();

    void (*func2)();
    func2 = HelloWorld;

    func2();

    typedef void(*func3)();
    func3 myfunc = HelloWorld;

    myfunc();

    typedef void(*func4)(int);
    func4 myfunc2 = func_with_arg;

    myfunc2(3);
    myfunc2(10);

    std::vector<int> values = {1, 4, 5, 2, 3};
    for_each(values, PrintValue);
    return 0;
}
