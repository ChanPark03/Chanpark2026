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
 