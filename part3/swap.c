#include<stdio.h>

int main(void){
    int a, b, tmp;
    
    a=100;
    b=200;

    printf("a: %d, b; %d", a, b);
    tmp = a;
    a = b;
    b = tmp;
    printf("a: %d, b; %d", a, b);
    
    

    return 0;
}