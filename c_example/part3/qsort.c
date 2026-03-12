#include<stdlib.h>
#include<stdio.h>

int compare(const void *a, const void *b);
  
int main(void)
{

    int nums[10] = {21, 43, 51, 43, 53, 23, 64, 25, 26, 90};
    int indexN = sizeof(nums) / sizeof(int);

    qsort(nums, indexN, sizeof(int), compare);

    for (int i = 0; i < indexN; ++i)
    {
        printf("%d, ", nums[i]);
    }
     printf("\n");
    return 0;
}
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b); // a는 주소 void *(int*) 은 int 주소로 바꾸는것 - 산술 연산자를 쓰기위해서 사용 void * itself 는 산술연산자 사용 불가능 
                                    // 주소가 가르키는 값을 의미함 
}

