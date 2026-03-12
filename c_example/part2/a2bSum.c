// a~b 까지의 합을 춢력 하세요. For 문을 사용

#include <stdio.h>

int main(void)

{
int a;
int b;

    printf("A의 값과 B값을 입력하시오 :\n");

    scanf("%d %d", &a, &b);
    int sum = 0;
        for (int i = a; i <= b; ++i)
        {
            sum  = sum + i ;
        }

printf("a부터 b까지의 합은 : %d\n", sum);
    
    return 0;
}