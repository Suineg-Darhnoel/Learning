#include<iostream>
#include<vector>

void printStack(const std::vector<int> &stack)
{
    for (auto elem : stack)
        std::cout << elem << ' ';
    std::cout << "(cap " << stack.capacity() << " length " << stack.size() << ")\n";
}

int main()
{
    // stack behavior with std::vector
    std::vector<int> stack;
    printStack(stack);

    stack.push_back(1);
    printStack(stack);

    stack.push_back(5);
    printStack(stack);

    stack.push_back(3);
    printStack(stack);

    // back() returns the last elements
    std::cout << "top: " << stack.back() << '\n';

    // pop_back() back pops an element off the stack
    stack.pop_back();
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    std::vector<int> v = {0,1,2,3,4};
    std::cout << "size: " << v.size() << " cap: " << v.capacity() << '\n';
    
    v.push_back(5); // add another element
    // when a vector is resized, the vector may allocate more capacity than
    // is needed. This is done to provide some "breathing room" for additional
    // elements, to minimize the number of resize operations needed.
    std::cout << "size: " << v.size() << " cap: " << v.capacity() << '\n';

    return 0;
}
