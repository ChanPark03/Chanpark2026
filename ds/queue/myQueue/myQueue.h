/* 
 * myQueue.h - 큐(Queue) 자료구조 헤더 파일
 * 큐는 FIFO(First In First Out) 원칙으로 동작하는 자료구조입니다. 
 * 원형 큐(Circular Queue) 구현: 배열 끝에서 처음으로 wrap-around 지원.
 * front(앞): 데이터 꺼낼 위치, rear(뒤): 데이터 추가할 위치.
 */

#pragma once  /* 헤더 중복 포함 방지 */

#include <stdio.h>   /* 입출력 함수 포함 */

#define ARRAYSIZE 100  /* 큐 배열 최대 크기 (매크로 정의로 변경 용이) */

typedef struct {
    int queue[ARRAYSIZE];  /* 정수 데이터 저장 배열 (큐의 메인 저장소) */
    int *front;            /* Front 포인터: 다음에 꺼낼(dequeue) 데이터 위치 가리킴 */
    int *rear;             /* Rear 포인터: 다음에 추가(enqueue)할 데이터 위치 가리킴.
                            * full: rear+1 == front (한 칸 남김), empty: front == rear */
} Qu;  /* Queue 타입 별칭 */

/* 큐 관련 함수 프로토타입 */

/* 큐 초기화: front와 rear를 배열 시작 위치로 설정 (빈 큐 상태) */
void initQueue(Qu *pQu);  /* pQu: 초기화할 큐 포인터 (&qu1 호출) */

/* 큐에 데이터 추가(enqueue/push): rear 위치에 저장 후 rear 증가, wrap-around 지원 */
void push(Qu *pQu, int data);  /* pQu: 대상 큐, data: 추가할 데이터 */

/* 큐에서 데이터 꺼내기(dequeue/pop): front 위치 데이터 반환 후 front 증가, wrap-around 지원 */
int pop(Qu *pQu);  /* pQu: 대상 큐. 반환: 큐 front의 데이터 (FIFO 순서) */
