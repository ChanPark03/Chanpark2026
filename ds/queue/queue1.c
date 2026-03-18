#include <stdio.h>

int queue[100];
int front = 0;
int rear = 0;

void push(int data);
int pop(void);



int main(void)
{
    push(100);
    push(200);
    printf("첫번째 pop() : %d\n", pop());
    push(300);
    printf("두번째 pop() : %d\n", pop());
    printf("세번째 pop() : %d\n", pop());

    return 0;
}

void push (int data)
{
    queue[rear++] = data;
}

int pop(void)
{
    return queue[front++];
}

