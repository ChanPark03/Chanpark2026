#include "stack4.h"

void cleanupStack(Stack *ps)
{
    free(ps->pArr);
}

int size(Stack *ps)
{
    return ps->size;
}

void initStack(Stack *ps, int size, int eleSize)
{
    ps->pArr = malloc(eleSize * size);
    assert(ps->pArr);

    ps->eleSize = eleSize;
    ps->size = size;
    ps->tos = (unsigned char *)ps->pArr;
}

void push(Stack *ps, const void *pData)
{
    assert(ps->tos != (unsigned char *)ps->pArr + (ps->eleSize * ps->size));
    memcpy(ps->tos, pData, ps->eleSize);
    ps->tos += ps->eleSize;
}

void pop(Stack *ps, void *pData)
{
    assert(ps->tos != (unsigned char *)ps->pArr);
    ps->tos -= ps->eleSize;
    memcpy(pData, ps->tos, ps->eleSize);
}
