#include <stdio.h>                 // 표준 입출력 함수(printf, scanf 등)를 사용하기 위한 헤더
#include <stdlib.h>                // 동적 메모리 함수(malloc, free)와 종료(exit) 함수를 위한 헤더
#include <string.h>                // 문자열 복사(strcpy) 함수 선언을 위한 헤더
#include <time.h>                  // 시간 관련 함수(time) 선언을 위한 헤더


typedef struct {                   // Book 구조체 정의 시작
    int bookid;                    // 책 ID를 저장하는 정수 필드
    char bookname[40];             // 책 제목을 저장하는 문자 배열(문자열)
    char publisher[40];            // 출판사를 저장하는 문자 배열(문자열)
    int price;                     // 가격을 저장하는 정수 필드
} Book;                            // Book 구조체 타입 이름

int main(void)                     // 프로그램 시작점인 main 함수 정의
{                                  // main 함수 시작
    Book *pBook;                   // Book 구조체 배열의 시작 주소를 저장할 포인터
    int size;                      // 입력받을 데이터 개수(구조체 배열 크기) 저장 변수
    printf("넣을 데이터의 크기를 알려주세요 : "); // 사용자에게 배열 크기를 입력받도록 안내
    scanf("%d", &size);           // 입력된 값을 size에 저장
    pBook = (Book *)malloc(sizeof(Book) * size); // Book 구조체 size개를 담을 힙 메모리 할당
    if (pBook == NULL)             // malloc 실패 시 NULL을 반환하므로, 실패 여부를 확인
    {                              // if 블록 시작
        printf("메모리 할당에 실패 했습니다 .\n"); // 에러 메시지 출력
        exit(-1);                  // 비정상 종료 코드로 프로그램 종료
    }                              // if 블록 끝

    srand(time(NULL));             // 난수 생성기의 시드를 현재 시간으로 설정
    for (int i = 0; i < size; ++i) // 0부터 size-1까지 반복하며 각 구조체 필드 채우기
    {                              // for 블록 시작
        (pBook + i)->bookid = rand() & 1001; // 난수 값을 bookid에 저장(비트 AND 연산 사용)
        strcpy((pBook + i)->bookname, "책이름"); // bookname에 문자열을 복사
        strcpy((pBook + i)->publisher, "출판사"); // publisher에 문자열을 복사
        (pBook + i)->price = rand() % 1001 + 10000; // 10000~11000 범위의 가격을 생성해 저장
    }                              // for 블록 끝
    for (int i = 0; i < size; ++i) // 채워진 구조체 데이터를 출력
    {                              // for 블록 시작
        printf("%d %s %s %d\n",
               (pBook + i)->bookid, (pBook + i)->bookname,
               (pBook + i)->publisher, (pBook + i)->price); // 한 줄에 1개 구조체 정보 출력
    }                              // for 블록 끝
    free(pBook);                   // 동적으로 할당한 메모리를 해제
    return 0;                      // 정상 종료를 운영체제에 알림

}                                  // main 함수 끝
