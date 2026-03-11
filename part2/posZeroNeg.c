#include <stdio.h>

int main(void) 
{
    int num;
    printf("숫자를 넣으세요 : \n");
    scanf("%d", &num);

    if(num>0)
    {
        printf("%d는 양수 입니다.\n", num);

    }
    else if (num==0)
    {
        printf("%d는 0입니다.\n", num); // == 연산자는 두 값이 같은지를 비교하는 연산자입니다. 예를 들어, num이 0인 경우, num == 0은 참이 되어 if 문이 실행됩니다. 만약 num이 5인 경우, num == 0은 거짓이 되어 else if 문이 실행되지 않고 else 문으로 넘어갑니다.
    }else
    {
        printf("%d는 음수입니다.\n", num);  
    }

    return 0;
}