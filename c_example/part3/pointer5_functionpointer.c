#include<stdio.h> // 표준 입출력 함수(printf)를 사용하기 위한 헤더

int add(int a, int b); // 두 정수를 더하는 함수의 선언
int substract(int a, int b); // 두 정수를 빼는 함수의 선언

int main(void)
{
    // 함수 포인터: "함수의 주소"를 저장하는 포인터
    // 여기서 fp는 "int를 반환하고 int 두 개를 받는 함수"를 가리킨다
    int (*fp)(int, int);

    // add의 주소를 fp에 저장 (함수 이름은 곧 함수의 시작 주소)
    fp = add;

    // 포인터로 함수 호출 (역참조 호출)
    int re = (*fp)(4, 3);

    // 포인터 이름만으로도 호출 가능 (C에서 동일하게 동작)
    re = fp(4, 3);
    printf("결과 : %d\n", re);

    // 다른 함수의 주소로 교체하여 같은 포인터로 다른 동작 수행
    fp = &substract; // &를 붙여도 동일한 함수 주소
    re = (*fp)(4, 3);
    printf("re : %d\n", re);

    return 0; // 정상 종료
}
int add(int a, int b)
{
    return a + b; // 두 값을 더해 반환
}

int substract(int a, int b)
{
    return a - b; // 두 값을 빼서 반환
}
