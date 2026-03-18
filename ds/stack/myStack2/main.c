/* 
 * main.c - 스택 구현 테스트 프로그램 (Test Driven Development: TDD)
 * myStack2.h/c 의 스택 기능을 테스트합니다.
 * 두 개의 스택(s1, s2)을 생성하고 push/pop 연산을 수행하여 LIFO 동작 확인.
 * 컴파일: cd ds/stack/myStack2 && cmake . && make
 * 실행: ./main
 * 예상 출력:
 * s1 첫 pop() 리턴 값 : 300
 * s1 두번째 pop() 리턴 값 : 200
 * s1 세번째 pop() 리턴 값 : 100
 * s2 첫 pop() 리턴 값 : 900
 * s2 두번째 pop() 리턴 값 : 800
 * s2 세번째 pop() 리턴 값 : 700
 */

#include "myStack2.h"  /* 스택 구조체와 함수들 포함 */

/*
 * main 함수: 프로그램 진입점
 * 스택 TDD 테스트 수행
 */
int main(void)  /* void: 매개변수 없음 */
{
    Stack s1, s2;  /* 두 개의 Stack 구조체 변수 선언 (자동으로 array 초기화됨) */

    /* 스택 초기화: tos를 array 시작 위치로 설정 */
    initStack(&s1);  /* &s1: s1의 주소 전달 (포인터로 원본 수정) */
    initStack(&s2);

    /* s1에 데이터 push: 100 -> 200 -> 300 (최상단: 300) */
    push(&s1, 100);  /* 스택: [100] */
    push(&s1, 200);  /* 스택: [100, 200] */
    push(&s1, 300);  /* 스택: [100, 200, 300] <- tos */

    /* s1에서 pop 테스트: LIFO로 300, 200, 100 순서로 출력 */
    printf("s1 첫 pop() 리턴 값 : %d\n", pop(&s1));  /* 300 출력, tos 감소 */
    printf("s1 두번째 pop() 리턴 값 : %d\n", pop(&s1)); /* 200 출력 */
    printf("s1 세번째 pop() 리턴 값 : %d\n", pop(&s1)); /* 100 출력, 스택 비움 */

    /* s2에 데이터 push: 700 -> 800 -> 900 (최상단: 900) */
    push(&s2, 700);
    push(&s2, 800);
    push(&s2, 900);

    /* s2에서 pop 테스트: 900, 800, 700 순서 */
    printf("s2 첫 pop() 리턴 값 : %d\n", pop(&s2));   /* 900 */
    printf("s2 두번째 pop() 리턴 값 : %d\n", pop(&s2)); /* 800 */
    printf("s2 세번째 pop() 리턴 값 : %d\n", pop(&s2)); /* 700 */

    return 0;  /* 프로그램 정상 종료 */
}
