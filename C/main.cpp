#include <iostream>

class Myclass{
    private:
        int x;
        int y;
    public:
        void what(){
            printf("Hello\n");
        }
};

int main()
{
    printf("%zu\n", sizeof(Myclass));
    return 0;
}
