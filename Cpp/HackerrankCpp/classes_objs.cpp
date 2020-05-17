#include <iostream>
#include <vector>

class Student{
    private:
        int scores[5] {};
    public:
        void input(){
            for (int i = 0; i < 5; i++)
                std::cin >> scores[i];
        }
        int calculateTotalScore(){
            int sum {0};
            for (int i = 0; i < 5; i++)
                sum += scores[i];
            return sum;
        }
};

int main()
{
    Student a;
    std::cout << a.calculateTotalScore() << '\n';
    return 0;
}
