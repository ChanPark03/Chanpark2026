#include <stdio.h>

int main(void)
{
    int num;
    printf("숫자를 넣으세요: ");
    scanf("%d", &num); // 사용자로부터 정수를 입력받아 num 변수에 저장

    int isOdd;
    isOdd = (num % 2 == 1); // num이 홀수인지 여부를 판단하여 isOdd 변수에 저장 // num을 2로 나눈 나머지가 1이면 홀수, 그렇지 않으면 짝수

    printf("숫자는: %d \t is isOdd: %d\n", num, isOdd); // 입력된 숫자와 isOdd 변수의 값을 출력 // isOdd는 1이면 홀수, 0이면 짝수 // %d는 정수를 출력하는 서식 지정자
   
    if (isOdd) // isOdd가 참(1)인 경우 실행
    {
        printf("홀수입니다.\n"); // num이 홀수인 경우 출력
    }
    else // isOdd가 거짓(0)인 경우 실행
    {
        printf("짝수입니다.\n"); // num이 짝수인 경우 출력
    }
   
    return 0; // 프로그램 종료

}