#include <iostream>
#include <array>
#include <algorithm>
#include <string>

struct Student{
    std::string name;
    int points;
};

int main()
{
    std::array<Student, 8> arr{
        {
            {"Albert", 3},
            {"Ben", 5},
            {"Christine", 2},
            {"Dan", 8}, // Dan has the most points (8)
            {"Enchilada", 4},
            {"Francis", 1},
            {"Greg", 3},
            {"Hagrid", 5}
        }
    };

    auto best{
        std::max_element(
                arr.begin(),
                arr.end(),
                [](const auto& s1, const auto& s2){
                    return (s1.points < s2.points);
                })
    };

    std::cout << best->name << " is the best student\n";
    return 0;
}
