#include <stdio.h>                 // 표준 입출력 함수(printf, scanf 등)를 사용하기 위한 헤더
#include <stdlib.h>                // 동적 메모리 함수(calloc, realloc, free) 선언을 위한 헤더

int main(void)                     // 프로그램 시작점인 main 함수 정의
{                                  // main 함수 시작
    int *pInt;                     // 동적으로 할당한 int 배열의 시작 주소를 저장할 포인터
    int size = 5;                  // 현재 배열 크기(처음에는 5칸)
    int count = 0;                 // 실제로 입력된 값의 개수
    int num;                       // 사용자 입력을 임시로 저장할 변수
    int i;                         // 반복문 인덱스 변수

    pInt = (int *)calloc(size, sizeof(int)); // size개 int를 0으로 초기화하며 힙 메모리 할당
    while (1)                      // 종료 조건을 만날 때까지 반복
    {                              // while 블록 시작
        printf("양수만 입력하세요 끝내려면 음수나 0을 입력 =>"); // 입력 안내
        scanf("%d", &num);        // 사용자 입력을 num에 저장
        if (num <= 0)              // 0 이하 입력 시 종료 조건
            break;                 // 반복문 탈출
        if (count == size)         // 배열이 꽉 찼으면
        {                          // if 블록 시작
            size += 5;             // 배열 크기를 5칸 늘림
            pInt = (int *)realloc(pInt, size * sizeof(int)); // 더 큰 크기로 재할당
        }                          // if 블록 끝
        pInt[count++] = num;       // 현재 값 저장 후 count를 1 증가
    }                              // while 블록 끝
    for (i = 0; i < count; ++i)    // 입력된 값들만 출력
    {                              // for 블록 시작
        printf("%5d\n", pInt[i]); // 각 값을 5칸 너비로 출력
    }                              // for 블록 끝
    free(pInt);                    // 동적으로 할당한 메모리를 해제
    return 0;                      // 정상 종료를 운영체제에 알림
}                                  // main 함수 끝
