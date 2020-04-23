#include<iostream>
#include<vector>
#include<climits> // INT_MIN

int sumTo(const int input)
{
    int sum{0};
    for (int i {1}; i <= input; ++i)
        sum += i;
    return sum;
}

// Custom minmax
std::pair<int, int> minmax(const int x, const int y)
{
    int min{}, max{};
    if (x <= y){
        min = x;
        max = y;
    }
    else{
        min = y;
        max = x;
    }
    return {min, max};
}

std::vector<int>::iterator getIndexOfLargestValue(std::vector<int>& v)
{
    int max = *v.begin();
    std::vector<int>::iterator index_res;
    
    for (auto i = v.begin(); i != v.end(); i++)
    {
        if (max < *i){
            max = *i;
            index_res = i;
        }
    }
    return index_res;
}

int getIndexOfLargestValue2(std::vector<int>& v)
{
    int max = *v.begin();
    int max_index {0};

    for (size_t i{0}; i < v.size() ; i++){
        if (max < v.at(i)){
            max = v.at(i);
            max_index = i;
        }
    }
    return max_index;
}


int main()
{
    std::cout << sumTo(5) << '\n';

    std::pair result { minmax(20, 10) };
    std::cout << "min= " << result.first << ",max= " << result.second << '\n';

    result =  minmax(10, 20);
    std::cout << "min= " << result.first << ",max= " << result.second << '\n';
    
    std::vector<int> v {5, 3, 6, 8, 12, 32, 3};
    auto max_index { getIndexOfLargestValue(v) };
    std::cout << *max_index << '\n';

    int max_index2 { getIndexOfLargestValue2(v) };
    std::cout << v.at(static_cast<size_t>(max_index2)) << '\n';

    return 0;
}
