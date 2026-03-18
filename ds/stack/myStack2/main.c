#include "myStack2.h"
// test Driven Develop TDD 

 int main(void)
{
    Stack s1, s2;

    initStack(&s1);
    initStack(&s2);

    push(&s1, 100);
    push(&s1, 200);
    push(&s1, 300);

    printf("s1 첫 pop() 리턴 값 : %d\n", pop(&s1)); // 300
    printf("s1 두번째 pop() 리턴 값 : %d\n", pop(&s1)); // 200
    printf("s1 세번째 pop() 리턴 값 : %d\n", pop(&s1)); // 100

    push(&s2, 700);
    push(&s2, 800);
    push(&s2, 900);

    printf("s2 첫 pop() 리턴 값 : %d\n", pop(&s2)); // 900
    printf("s2 두번째 pop() 리턴 값 : %d\n", pop(&s2)); // 800
    printf("s2 세번째 pop() 리턴 값 : %d\n", pop(&s2)); // 700

    return 0;
}