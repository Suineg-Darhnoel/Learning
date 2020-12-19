#include "variables.h"
#include "functions.h"
#include <stdio.h>
int var1;
int var2;
/* here the variables var1 and var2 are defined */

int add(int a, int b) {
    return a + b;
}
int sub(int a, int b){
    return a - b;
}
void show_var1(){
    var1 = 1;
    printf("%d", var1);
}

void show_var2(){
    var2 = 2;
    printf("%d", var2);
}
