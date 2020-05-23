#include <iostream>
#include <map>

int main()
{
    std::map<std::string, int> my_map {{"abc", 0}, {"def", 1}};
    for (auto i : my_map){
        std::cout << i.pair::first << '\n';
        std::cout << i.pair::second << '\n';
    }
    return 0;
}
