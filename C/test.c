#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c = 'l';
    char* ptrc = &c;
    char** ptr_ptrc = &ptrc;
    char*** ptr_ptr_ptrc = &ptr_ptrc;

    printf("%c\n", ptr_ptr_ptrc[0][0][0]);

    int* array = (int*) malloc(sizeof(int)*3);
    /* free(array); */

    return 0;
}
