#include <stdio.h>

int main(void)
{
    int num;
    printf("숫자를 넣으세요: ");
    scanf("%d", &num);

    //if (num < 0) // 삼항연산자 대신 if문을 사용하여 num이 음수인지 확인합니다. 만약 num이 0보다 작으면, num은 음수입니다
   // {
   //     num = -num;  // num이 음수일 때, num의 부호를 바꿔 양수로 만듭니다. 예를 들어, num이 -5라면, -(-5) = 5가 됩니다. 이렇게 하면 num은 항상 양수가 됩니다.
   // }
   
   printf("절댓값: %d\n", num < 0 ? -num : num );  // ,num 은 printf 함수에서 %d 자리에 num의 값을 출력합니다. 예를 들어, num이 5라면 "절댓값: 5"가 출력됩니다.

    return 0;
}