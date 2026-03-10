
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int num;
    printf("sizeof(char) : %ld\n", sizeof(char)); // char 자료형의 크기를 바이트 단위로 출력 // sizeof 연산자는 데이터 타입이나 변수의 크기를 반환 // %ld는 long int를 출력하는 서식 지정자
    printf("sizeof(short) : %ld\n", sizeof(short)); // short 자료형의 크기를 바이트 단위로 출력
    printf("sizeof(int) : %ld\n", sizeof(int)); // int 자료형의 크기를 바이트 단위로 출력
    printf("sizeof(long) : %ld\n", sizeof(long)); // long 자료형의 크기를 바이트
    printf("sizeof(float) : %ld\n", sizeof(float)); // float 자료형의 크기를 바이트 단위로 출력 
    printf("sizeof(double) : %ld\n", sizeof(double)); // double 자료형의 크기를 바이트 단위로 출력  
    printf("sizeof(num) : %ld\n", sizeof(num)); // num 변수의 크기를 바이트 단위로 출력 // num은 int 자료형이므로 sizeof(num)은 sizeof(int)와 동일한 값을 반환
    printf("sizeof(3.141592) : %ld\n", sizeof(3.141592)); // 3.141592 상수의 크기를 바이트 단위로 출력 // 3.141592는 double 자료형으로 간주되므로 sizeof(3.141592)는 sizeof(double)과 동일한 값을 반환
    printf("sizeof(uint32_t) : %ld\n", sizeof(uint32_t)); // uint32_t 자료형의 크기를 바이트 단위로 출력 // uint32_t는 C99 표준에서 정의된 32비트 부호 없는 정수형 자료형 // sizeof(uint32_t)는 4를 반환할 것으로 예상됨 (32비트 = 4바이트
    return 0; // 프로그램 종료)
}

//sizeof 연산자는 데이터 타입이나 변수의 크기를 바이트 단위로 반환하는 연산자입니다. sizeof(char)은 char 자료형의 크기를, sizeof(short)은 short 자료형의 크기를, sizeof(int)은 int 자료형의 크기를, sizeof(long)은 long 자료형의 크기를, sizeof(float)은 float 자료형의 크기를, sizeof(double)은 double 자료형의 크기를 반환합니다. 또한 sizeof(num)은 num 변수의 크기를 반환하며, num이 int 자료형이므로 sizeof(num)은 sizeof(int)와 동일한 값을 반환합니다. 마지막으로 sizeof(3.141592)는 3.141592 상수의 크기를 반환하는데, 3.141592는 double 자료형으로 간주되므로 sizeof(3.141592)는 sizeof(double)과 동일한 값을 반환합니다. uint32_t는 C99 표준에서 정의된 32비트 부호 없는 정수형 자료형으로, sizeof(uint32_t)는 4를 반환할 것으로 예상됩니다 (32비트 = 4바이트).   