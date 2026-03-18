/* 
 * myQueue.c - 큐 자료구조 구현 파일
 * myQueue.h 선언 함수 구현. 원형 큐: 배열 끝에서 처음으로 순환.
 * full 체크 (rear+1 == front), empty 체크 (front == rear).
 * 에러 시 stderr 출력 후 exit(1).
 */

#include "myQueue.h"  /* 큐 구조체와 프로토타입 포함 */
#include <stdlib.h>   /* exit 함수 위해 추가 */

/* 
 * 큐 초기화 함수
 * front와 rear를 queue 배열 시작으로 설정 (빈 상태).
 */
void initQueue(Qu *pQu)
{
    pQu->front = pQu->queue;  /* front를 첫 위치로 */
    pQu->rear = pQu->queue;   /* rear도 첫 위치로 (empty) */
}

/* 
 * 큐에 데이터 push(enqueue)
 * 1. wrap-around: rear가 끝나면 처음으로 리셋.
 * 2. full 체크: rear+1 == front 이면 full (슬롯 하나 남김으로 구분).
 * 3. 데이터 저장 후 rear 증가.
 */
void push(Qu *pQu, int data)
{
    if(pQu->rear == pQu-> queue + ARRAYSIZE){  /* wrap-around: 끝나면 처음으로 */
        pQu->rear = pQu->queue;
    }
    if(pQu->rear + 1 == pQu->front){  /* full 조건: 다음 rear가 front와 같음 */
        fprintf(stderr, "stack is full\n");  /* 에러 출력 (원본 오타 유지, queue로 수정 제안 가능) */
        exit(1);  /* 프로그램 비정상 종료 */
    }
    *(pQu->rear++) = data;  /* *rear에 data 저장 후 rear 증가 (post-increment) */
}

/* 
 * 큐에서 데이터 pop(dequeue)
 * 1. wrap-around: front 끝나면 처음으로.
 * 2. empty 체크: front == rear 이면 empty.
 * 3. front 데이터 반환 후 front 증가.
 */
int pop(Qu *pQu)
{
    if(pQu->front == pQu-> queue + ARRAYSIZE){  /* wrap-around */
        pQu->front = pQu->queue;
    }
    if(pQu->front == pQu->rear){  /* empty 조건 */
        fprintf(stderr, "there is no data\n");  /* 에러 메시지 */
        exit(1);
    }
    return *(pQu->front++);  /* *front 반환 후 front 증가 (post-increment, FIFO) */
}
