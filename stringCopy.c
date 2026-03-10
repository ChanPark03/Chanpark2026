#include <stdio.h>
#include <string.h> // 문자열 복사 함수 strcpy를 사용하기 위해 string.h 헤더 파일 포함 

int main()
{
    char fruit[] = "strawberry"; // 문자열 상수로 초기화
    printf("딸기 : %s\n", fruit); // 문자열 출력 // %s는 문자열을 출력하는 서식 지정자 // fruit은 문자열의 시작 주소를 가리킴 
    printf("딸기잼 : %s %s\n", fruit, "jam"); // 문자열 상수 "jam"을 출력 // 문자열 상수는 읽기 전용이므로 수정할 수 없음 // fruit[0] = 'b'; // 오류 발생
    strcpy(fruit, "banana"); // 문자열 복사 함수 strcpy(destination, source) // destination에 source 문자열을 복사 // fruit 배열에 "banana" 문자열을 복사 // fruit 배열의 크기는 충분히 커야 함 // fruit 배열의 크기는 20으로 선언되어 있으므로 "banana"를 안전하게 복사할 수 있음
    printf("바나나 : %s\n", fruit); // strcpy로 문자열을 복사한 후 출력

    // strcpy fruit ->apple

    fruit[0] = 'a'; // fruit 배열의 첫 번째 요소에 'a'를 할당
    fruit[1] = 'p'; // fruit 배열의 두 번째 요소에 'p'를 할당
    fruit[2] = 'p'; // fruit 배열의 세 번째 요소에 'p'를 할당
    fruit[3] = 'l'; // fruit 배열의 네 번째 요소에 'l'을 할당
    fruit[4] = 'e'; // fruit 배열의 다섯 번째 요소에 'e'를 할당
    fruit[5] = NULL;        // 문자열의 끝을 나타내는 NULL 문자로 종료 // 문자열은 NULL 문자로 끝나야 함 // fruit 배열의 크기는 20이므로 충분히 공간이 있음

    printf("사과 : %s\n", fruit); // fruit 배열에 "apple"을 수동으로 할당한 후 출력
    return 0; 

}