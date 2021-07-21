#include <iostream>
#include <boost/thread.hpp>

/* function to print even numbers */
void even_func(int n){
    for(int i=0; i<n; i++){
        printf("even_func %d\n", 2*i);
    }
}

/* function to print odd functions */
void odd_func(int n){
    for(int i=0; i<n; i++){
        printf("odd_func %d\n", 2*i);
    }
}

int main()
{
    boost::thread even_thread(even_func, 1000);
    boost::thread odd_thread(odd_func, 1000);

    even_thread.join();
    odd_thread.join();
    return 0;
}
