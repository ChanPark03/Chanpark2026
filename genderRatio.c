#include <stdio.h>

int main(void)

{
    int man, woman;
    double sum, manRate, womanRate; // 전체 인구 수, 남자의 비율, 여자의 비율을 저장할 변수 선언 // double 자료형을 사용하여 소수점 이하의 값을 저장할 수 있도록 함

    printf("남자의 수는 :");
    scanf("%d", &man); // 사용자로부터 남자의 수를 입력받아 man  변수에 저장 //%d는 정수를 입력받는 서식 지정자 // &는 주소 연산자로, 변수의 주소를 scanf 함수에 전달하여 입력된 값을 해당 변수에 저장
    printf("여자의 수는 :");
    scanf("%d", &woman); // 사용자로부터 여자의 수를 입력받아 woman 변수에 저장 // &는 주소 연산자로, 변수의 주소를 scanf 함수에 전달하여 입력된 값을 해당 변수에 저장

    sum = man + woman; // 남자의 수와 여자의 수를 더하여 전체 인구 수를 계산하여 sum 변수에 저장    
    womanRate = woman / sum * 100; // 여자의 수를 전체 인구 수로 나눈 후 100을 곱하여 여자의 비율을 계산하여 womanRate 변수
    manRate = man / sum * 100; // 남자의 수를 전체 인구 수로 나눈 후 100을 곱하여 남자의 비율을 계산하여 manRate 변수에 저장

    printf("남자의 수는 %d명이고 여자의 수는 %d명이다.\n", man, woman);   
    printf("총 수는 %.f명\n남자의 비율은 %.2f\n여자의 비율은 %.2f\n", sum, manRate, womanRate); 
    
    return 0; // 프로그램 종료

}