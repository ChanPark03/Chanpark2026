#include <stdio.h>

int main(void)
{
    int i = 100;
    double d = 3.14;

    void *p;  // void*는 "타입이 없는 포인터"라서 어떤 주소든 담을 수 있음

    // 1) int 변수의 주소 저장
    p = &i;                       // p는 int의 주소를 가리킴
    *(int *)p = 200;              // void*는 직접 역참조 불가 -> int*로 캐스팅 후 사용
    printf("i : %d, *p(int) : %d\n", i, *(int *)p);

    // 2) double 변수의 주소 저장
    p = &d;                       // 이번엔 double의 주소를 가리킴
    *(double *)p = 2.718;         // double*로 캐스팅 후 역참조
    printf("d : %.3f, *p(double) : %.3f\n", d, *(double *)p);

    // 주의사항
    // - void*는 타입 정보가 없어서 반드시 "원래 타입"으로 캐스팅해야 함
    // - 잘못된 타입으로 캐스팅하면 잘못된 값이나 프로그램 오류 발생

    return 0;
}
