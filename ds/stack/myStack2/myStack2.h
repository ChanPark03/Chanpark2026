/* 
 * myStack2.h - 스택 자료구조 헤더 파일
 * 스택(Stack)은 LIFO(Last In First Out) 원칙으로 동작하는 자료구조입니다.
 * 배열과 포인터를 사용하여 구현되었습니다.
 */

#pragma once  /* 헤더 파일 중복 포함을 방지하는 전처리기 지시어 */

#include <stdio.h>  /* 표준 입출력 함수 (printf 등)를 위한 헤더 */

#define STACKSIZE 100  /* 스택의 최대 크기를 100으로 정의. 매크로로 나중에 쉽게 변경 가능 */

typedef struct {
    int array[STACKSIZE];  /* 정수형 데이터를 저장하는 고정 크기 배열 (스택의 실제 데이터 저장소) */
    int *tos;              /* Top Of Stack 포인터. 현재 스택의 최상단 다음 위치를 가리킴.
                            * 초기에는 array 시작 위치를 가리키고, push 시 증가, pop 시 감소 */
} Stack;  /* Stack 타입 별칭 정의. 구조체 변수 선언 시 편리함 */

/* 
 * 스택 관련 함수 프로토타입 선언들 (구현은 .c 파일에)
 */

/* 스택을 초기화하는 함수. tos 포인터를 배열의 시작 위치로 설정 */
void initStack(Stack *ps);  /* ps: 초기화할 스택의 포인터 (포인터로 전달하여 원본 수정) */

/* 스택에 데이터를 추가(push)하는 함수. tos가 가리키는 위치에 데이터 저장 후 tos 증가 */
void push(Stack *ps, int data);  /* ps: 대상 스택 포인터, data: 추가할 정수 데이터 */

/* 스택에서 최상단 데이터를 꺼내는(pop) 함수. tos 감소 후 해당 위치 데이터 반환 */
int pop(Stack *ps);  /* ps: 대상 스택 포인터. 반환: 스택 최상단의 정수 데이터 */
