#include<iostream>

/* The void pointer, also known */
/* as the generic pointer, is a */
/* special type of pointer that */
/* can be pointed at objects of */
/* any data type! */

int nValue;
float fValue;

struct Something
{
    int n;
    float f;
};

Something sValue;

void *ptr;

/* The void pointer does not know */
/* what type of object it is pointing */
/* to, it cannot be dereferenced directly! */

int main()
{
    void *voidPtr{ &nValue }; // cannot dereference
    int *intPtr{ static_cast<int*>(voidPtr) };
    // if we case void pointer to an int pointer
    // then we can dereference
    std::cout << *intPtr << '\n';
    return 0;
}
