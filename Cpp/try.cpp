#include <iostream>
#include <bits/stdc++.h>

int main()
{
    std::vector<int> g1;
    for (int i = 1; i <= 10; i++)
        g1.push_back(i*10);

    std::cout << g1.at(4) << '\n';
    std::cout << g1.front() << '\n';
    std::cout << g1.back() << '\n';

    int *pos = &g1.back();
    std::cout << *pos << '\n';
    return 0;
}
