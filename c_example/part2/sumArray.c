// random 으로 int 10개 짜리 배열을 만들어서 값을 넣고 총합을 계산하는 프로그램을 만드세요.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void){
    int num[10];
    srand(time(NULL));
    
    for int( i = 0; i<10 ++i ){

        num[i]= rand() % 6 + 1;
        printf("%d ", num[i]);
    }
    for (int i =0; i < 10; ++i)
    {
        sum += nums[i];
    }
    printf("\n 배열의 총합은 %d 이다.", sum);
    return 0;
}