#include <iostream>
#include <omp.h>

void printHello(int id){
    printf("Hello thread %d \n", id);
}

int main()
{
    int i, thread_id;

    #pragma omp parallel
    {
        #pragma omp for
        for(i=0; i<100; i++){
            thread_id = omp_get_thread_num();
            printHello(thread_id);
        }
    }
    return 0;
}
