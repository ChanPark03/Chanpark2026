#include <stdio.h> // 표준 입출력 라이브러리 포함

int main() // main 함수의 시작
{
    char ch1 = 'A'; // 선언과 동시에 대입
    char ch2 = 64; // 선언과 동시에 대입, 64는 ASCII 코드에서 '@'에 해당
    char ch3; // 선언만
    printf("ch1: %c Number: %d\n", ch1, ch1); // 문자와 숫자 모두 출력
    printf("ch2: %c Number: %d\n", ch2, ch2); // 문자와 숫자 모두 출력
    scanf("%c", &ch3); // 사용자로부터 문자 입력 받기 // &ch3는 ch3 변수의 주소를 의미
    printf("ch3: %c Number: %d\n", ch3, ch3); // 초기화되지 않은 변수는 쓰레기값이 출력될 수 있음 // 입력받은 문자와 그에 해당하는 숫자 출력 // %c는 문자 형식 지정자, %d는 정수 형식 지정자
    return 0; // 프로그램 종료

}