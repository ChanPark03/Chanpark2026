#include <stdbool.h>
#include <string.h>

int main(void)
{
    int a, b;
    bool greater = false;
    printf("두 숫자를 입력하세요: ");
    scanf("%d %d", &a, &b); // 사용자로부터 두 정수를 입력받아 a와 b 변수에 저장

    greater = (a > b); // a가 b보다 큰지 여부를 판단하여 greater 변수에 저장 // a가 b보다 크면 greater는 1(true), 그렇지 않으면 0(false)
    printf("greater 의 값은 %d 이다.", greater); // greater 변수의 값을 출력 // %d는 정수를 출력하는 서식 지정자
    if (greater == true) // greater가 참(1)인 경우 실행
    {
        printf("a는 b보다 크다.\n"); // a가 b보다 큰 경우 출력
    }
    else // greater가 거짓(0)인 경우 실행
    {
        printf("a는 b보다 크지 않다.\n"); // a가 b보다 크지 않은 경우 출력
    }
    return 0;
}
