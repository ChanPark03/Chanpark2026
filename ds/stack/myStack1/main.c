#include"myStack1.h"

int main(void)
{
    push(100);
    push(200);
    push(300);
    
    printf("첫 pop() 리턴 값 : %d\n", pop()); // 300 
    printf("두번째 pop() 리턴 값 : %d\n", pop()); //200 
    printf("세번째 pop() 리턴 값 : %d\n", pop()); //100 
    
    return 0;
}