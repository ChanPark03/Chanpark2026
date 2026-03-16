#include <stdio.h>

enum season // 열거형 타입 정의 // 열거형은 정수형 상수들의 집합을 정의하는데 사용됨 
{
    SPRING, // 0  
    SUMMER, // 1
    FALL, // 2
    WINTER // 3 
};

int main (void)
{
    enum season ss; // 열거형 변수 선언
    char *pString = NULL;
    
    ss = SPRING;
    switch(ss) // 열거형 변수 ss의 값에 따라 분기
    {
        case SPRING: 
        pString = "inline";
        break;
    case SUMMER:
        pString = "swimming";
        break;
    case FALL:
        pString = "trip";
        break;
    case WINTER: 
        pString = "skiing";
        break;
    }

    printf("나의 레저 활동 => %s\n", pString);
    return 0; 
}