#include<stdio.h> // 표준 입출력 함수(printf 등)를 사용하기 위한 헤더

int add(int a, int b); // 두 정수를 더해 반환하는 함수의 프로토타입

int main(void){ // 프로그램의 시작점
    int first = 43, second = 72; // main 함수 내부에서만 유효한 지역 변수 두 개
    printf("%d + %d =%d", first, second, add(first,second)); // add 함수 호출 결과를 출력
    return 0; // 운영체제에 정상 종료를 알림
} 
    
int add(int a, int b){ // a, b는 add 함수 안에서만 유효한 매개변수(지역 변수)
    return a + b; // 두 값을 더해 호출한 곳으로 반환
}
    
    
    
    
