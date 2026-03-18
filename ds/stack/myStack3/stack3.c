#include "stack3.h"

void initStack(Stack *ps, int size)
{
    ps->pArr = malloc(sizeof(int) * size);
    ps->size = size;
    ps->tos = ps->pArr;
}

void cleanupStack(Stack *ps)
{
    free(ps->pArr);
}

int size(Stack *ps)
{
    return ps->size;
}

void push(Stack *ps, int data)
{
    assert(ps->tos != (ps->pArr + ps ->size));
    *(ps->tos++) = data;
}

int pop(Stack *ps)
{
    assert(ps->tos != ps->pArr);
    return *(--ps->tos);
}
