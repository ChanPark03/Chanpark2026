#include <stdio.h>                 // 표준 입출력 함수(printf, scanf 등)를 사용하기 위한 헤더
#include <stdlib.h>                // 동적 메모리 함수(malloc, free)와 난수 함수 시드 관련을 위한 헤더
#include <string.h>                // 문자열 처리 함수(여기서는 포함만 되어 있고 미사용)
#include <time.h>                  // 시간 관련 함수(time) 선언을 위한 헤더

typedef struct {                   // Book 구조체 정의 시작
    int bookid;                    // 책 ID를 저장하는 정수 필드
    char bookname[40];             // 책 제목을 저장하는 문자 배열(문자열)
    char publisher[40];            // 출판사를 저장하는 문자 배열(문자열)
    int price;                     // 가격을 저장하는 정수 필드
} Book;                            // Book 구조체 타입 이름

int main(void)                     // 프로그램 시작점인 main 함수 정의
{                                  // main 함수 시작
    int size;                      // 입력받을 데이터 개수(배열 크기)를 저장할 변수
    printf("넣을 데이터의 크기를 알려주세요 :"); // 사용자에게 배열 크기를 입력받도록 안내
    scanf("%d", &size);           // 입력된 값을 size에 저장
    int *pArr;                     // 동적으로 할당한 int 배열의 시작 주소를 저장할 포인터
    pArr = (int *)malloc(sizeof(int) * size); // size개 int를 저장할 힙 메모리 할당

    srand(time(NULL));             // 난수 생성기의 시드를 현재 시간으로 설정
    for (int i = 0; i < size; ++i) // 0부터 size-1까지 반복하며 값 채우기
    {                              // for 블록 시작
        *(pArr + i) = rand() % 101; // 0~100 범위의 난수를 생성해 배열 i번째에 저장
    }                              // for 블록 끝
    for (int i = 0; i < size; ++i) // 저장된 값과 주소를 출력하는 반복문
    {                              // for 블록 시작
        printf("%d, %p, ", *(pArr + i), (void *)(pArr + i)); // 값과 해당 요소의 주소를 출력
    }                              // for 블록 끝
    free(pArr);                    // 동적으로 할당한 메모리를 해제하여 누수를 방지
    return 0;                      // 정상 종료를 운영체제에 알림
}                                  // main 함수 끝
