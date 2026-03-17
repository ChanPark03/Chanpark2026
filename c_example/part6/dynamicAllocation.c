#include <stdio.h>                 // 표준 입출력 함수(printf 등)를 사용하기 위한 헤더
#include <stdlib.h>                // 동적 메모리 할당(malloc/free)과 종료(exit) 함수를 위한 헤더

int main(void)                      // 프로그램 시작점인 main 함수 정의, 반환형은 int
{                                   // main 함수의 시작 블록
    char *pLiteral = "리터럴 상수이다."; // 문자열 리터럴을 가리키는 포인터(읽기 전용 영역에 저장됨)
    int *pInt;                      // int 타입 메모리를 가리킬 포인터 변수 선언(아직 유효한 주소 없음)
    double *pDouble;                // double 타입 메모리를 가리킬 포인터 변수 선언(아직 유효한 주소 없음)
    char localVariable = 'c';       // 스택에 생성되는 지역 변수(문자 하나 저장)
    char pArray[30] = "지역변수 ( 배열)"; // 스택에 생성되는 문자 배열(문자열을 담는 공간)

    pInt = (int *)malloc(sizeof(int));  // int 1개 크기만큼 힙 메모리를 할당하고 시작 주소를 pInt에 저장
    if (pInt == NULL)               // malloc 실패 시 NULL을 반환하므로, 실패 여부를 확인
    {                               // if 블록 시작
        printf("메모리가 부족합니다.\n"); // 에러 메시지를 출력
        exit(1);                    // 비정상 종료 코드 1로 프로그램 종료
    }                               // if 블록 끝
    pDouble = (double *)malloc(sizeof(double)); // double 1개 크기만큼 힙 메모리를 할당하고 시작 주소를 pDouble에 저장

    *pInt = 10;                     // pInt가 가리키는 메모리(할당된 int 공간)에 10을 저장
    *pDouble = 3.4;                 // pDouble이 가리키는 메모리(할당된 double 공간)에 3.4를 저장

    printf("정수형으로 사용: %d\n", *pInt);   // pInt가 가리키는 값을 int 형식(%d)으로 출력
    printf("실수형으로 사용: %lf\n", *pDouble); // pDouble 값을 double 형식(%lf)으로 출력
    printf("%s : 0x%p\n", pLiteral, (void *)pLiteral); // 문자열 리터럴 내용과 그 주소를 출력
    printf("%d 힙메모리 : 0x%p\n", *pInt, (void *)pInt); // 힙에 할당된 int 값과 그 주소를 출력
    printf("%c 지역변수 : 0x%p\n", localVariable, (void *)&localVariable); // 지역 변수 값과 그 주소를 출력
    printf("%s : 0x%p\n", pArray, (void *)pArray); // 지역 배열 내용과 그 시작 주소를 출력

    free(pInt);                     // pInt가 가리키는 힙 메모리를 해제하여 메모리 누수를 방지
    free(pDouble);                  // pDouble이 가리키는 힙 메모리를 해제
    return 0;                       // 정상 종료를 운영체제에 알림
}                                   // main 함수의 끝
