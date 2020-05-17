#include <iostream>
#include <vector>
using namespace std;

int main()
{
    using intVector = std::vector <int>;

    intVector new_vector;
    new_vector.push_back(3);
    new_vector.push_back(5);


    intVector new_vector2;
    new_vector2.push_back(10);

    intVector v_arr[2];
    v_arr[0] = new_vector;
    v_arr[1] = new_vector2;

    for (int i{0}; i < 2; ++i){
        for (auto v: v_arr[i])
            cout << v << ' ';
        cout << '\n';
    }

    return 0;
}
