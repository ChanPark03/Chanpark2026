#include"myStack1.h"

int stack[50];
int tos = 0; //top of stack


void push (int data)
{ 
    stack[tos] = data;
    tos++;
    // tos= tos + 1 이렇게 적어도 된다
}

int pop (void)
{
    tos--;
    return stack[tos];
}


