#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector <int> parseInt(string str){
    // Complete this function
    istringstream ss {str};

    vector <int> num_arr;
    string token;

    while (getline(ss, token, ',')){
        num_arr.push_back(stoi(token));
    }
    return num_arr;
}

int main()
{
    string str;
    cin >> str;
    vector<int> integers = parseInt(str);
    for(int i = 0; i < int(integers.size()); i++){
        cout << integers[i] << '\n';
    }
    return 0;
}
