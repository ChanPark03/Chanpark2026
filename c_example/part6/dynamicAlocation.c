#include <stdio.h>                // 표준 입출력 함수(printf 등)를 사용하기 위한 헤더
#include <stdlib.h>               // 동적 메모리 할당(malloc, free)과 종료(exit) 함수를 위한 헤더

int main(void)                     // 프로그램 시작점인 main 함수 정의, 반환형은 int
{                                  // main 함수의 시작 블록
    int *pInt;                     // int 타입 메모리를 가리킬 포인터 변수 선언(아직 유효한 주소 없음)
    double *pDouble;               // double 타입 메모리를 가리킬 포인터 변수 선언(아직 유효한 주소 없음)

    pInt = (int *)malloc(sizeof(int)); // int 1개 크기만큼 동적 메모리를 할당하고 그 시작 주소를 pInt에 저장
    if (pInt == NULL)              // malloc 실패 시 NULL을 반환하므로, 실패 여부를 확인
    {                              // if 블록 시작
        printf("메모리가 부족합니다.\n"); // 에러 메시지를 출력
        exit(1);                   // 비정상 종료 코드 1로 프로그램 종료
    }                              // if 블록 끝
    pDouble = (double *)malloc(sizeof(double)); // double 1개 크기만큼 동적 메모리를 할당하고 시작 주소를 pDouble에 저장

    *pInt = 10;                    // pInt가 가리키는 메모리(할당된 int 공간)에 10을 저장
    *pDouble = 3.4;                // pDouble이 가리키는 메모리(할당된 double 공간)에 3.4를 저장

    printf("정수형으로 사용: %d\n", *pInt); // pInt가 가리키는 값을 int 형식(%d)으로 출력
    printf("실수형으로 사용: %d\n", *pDouble); // pDouble 값은 double이므로 실제로는 %f가 맞지만, 여기서는 %d로 출력하고 있음

    free(pInt);                    // pInt가 가리키는 동적 메모리를 해제하여 메모리 누수를 방지
    free(pDouble);                 // pDouble이 가리키는 동적 메모리를 해제
    return 0;                      // 정상 종료를 운영체제에 알림
}                                  // main 함수의 끝
