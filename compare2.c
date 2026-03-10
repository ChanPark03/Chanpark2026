#include <stdbool.h>
#include <string.h>

int main(void)
{
    int num;
    printf("숫자를 넣으세요 1~9 :");
    scanf("%d", &num); 

    printf("1 <= %d <= 9 : %s\n" , num, (1 <= num) && (num <= 9) ? "true" : "false"); // num이 1 이상이고 9 이하인지 여부를 판단하여 true 또는 false를 출력 // 삼항 연산자 사용 // (1 <= num) && (num <= 9) 조건이 참이면 "true"를, 그렇지 않으면 "false"를 출력

     if ((1 <= num) && (num <= 9)) // num이 1 이상이고 9 이하인 경우 실행 //&& 연산자는 논리 AND 연산자로, 두 조건이 모두 참일 때 전체 조건이 참이 됨
     {
         printf("숫자는 1 이상이고 9 이하입니다.\n"); // num이 1 이상이고 9 이하인 경우 출력
     }
     else // num이 1 미만이거나 9 초과인 경우 실행
     {
         printf("숫자는 1 미만이거나 9 초과입니다.\n"); // num이 1 미만이거나 9 초과인 경우 출력
     }
    return 0;
}