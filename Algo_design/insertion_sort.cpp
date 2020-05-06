#include<iostream>

void swap(char &a, char &b)
{
    char tmp{a};
    a = b;
    b = tmp;
}

void insertion_sort(char s[], int n)
{
    for (int i=0; i < n; i++){
        int j{i};
        while ((j>0) && s[j] < s[j-1]){
            swap(s[j], s[j-1]);
            std::cout << "swap " << s[j] << " with " << s[i] << '\n';
            j = j-1;
        }
    }
}

int main()
{
    char a[] = {"INSERTIONSORT"};
    std::cout << a << std::endl;
    insertion_sort(a, 13);
    std::cout << a << std::endl;
    return 0;
}
