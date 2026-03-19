# 🎓 myStack4 스택 - 완벽 가이드 (초보자 OK!)

## 📚 기본 개념 사전
- **스택**: 접시 (LIFO: 마지막 넣은 먼저 꺼냄)
- **포인터 (`*`)**: 주소 (집 주소처럼 데이터 위치)
- **`*var`**: var가 가리키는 **내용** (집 안 물건)
- **`->`**: 구조체 멤버 접근 (ps->tos = ps 안 tos)
- **`&var`**: var의 주소
- **`malloc(size)`**: size 바이트 메모리 빌려 주소 반환
- **`memcpy(to, from, n)`**: from의 n바이트를 to로 복사
- **`void*`**: 만능 타입 포인터
- **`assert(cond)`**: cond 거짓 → 에러 정지
- **`(char*)ptr`**: ptr을 바이트 단위 포인터로 변환 (+1바이트 이동)

## 1. stack4.h 원본 + 상세 설명
```c
#pragma once  // 한 번만 포함
#include <stdio.h>  // printf
#include <stdlib.h> // malloc/free
#include <assert.h> // assert
#include <string.h> // memcpy

typedef struct {  // Stack 구조체 정의
    void *pArr;   // 배열 시작 주소 (*pArr = 첫 데이터 내용)
    int eleSize;  // 한 요소 바이트 (sizeof(int))
    void *tos;    // TOS 포인터 (*tos = tos 위치 데이터)
    int size;     // 최대 요소 수
} Stack;

void initStack(Stack *ps, int size, int eleSize);  // ps: 스택 주소
void cleanupStack(Stack *ps);
void push(Stack *ps, const void *pData);           // pData: 넣을 데이터 주소
void pop(Stack *ps, void *pData);                  // pData: 꺼낼 데이터 주소
int size(Stack *ps);
```

## 2. stack4.c 각 함수 원본 + 줄별 설명
### initStack
**함수 역할:** 메모리 할당해 스택 초기화 (빈 상태)
```c
void initStack(Stack *ps, int size, int eleSize)
{
    ps->pArr = malloc(eleSize * size);  // 총 바이트만큼 메모리 → pArr 주소 저장
    assert(ps->pArr);                   // pArr==NULL이면 정지 (실패 체크)
    ps->eleSize = eleSize;              // 요소 크기 저장
    ps->size = size;                    // 최대 크기 저장
    ps->tos = ps->pArr;                 // tos = 배열 시작 (빈 스택)
}
```

### push
**함수 역할:** 데이터 끝에 추가 (오버플로우 체크)
```c
void push(Stack *ps, const void *pData)
{
    assert(ps->tos != (ps->pArr + ps->size));  // tos == 끝이면 꽉 참 (ps->pArr + size = 끝주소)
    memcpy((unsigned char *)ps->tos, pData, ps->eleSize);  // tos 위치에 pData 내용 복사
    ps->tos = (unsigned char *)ps->tos + ps->eleSize;      // tos를 다음 위치로 (바이트만큼 이동)
}
```

### pop
**함수 역할:** 끝 데이터 꺼냄 (언더플로우 체크)
```c
void pop(Stack *ps, void *pData)
{
    assert(ps->tos != ps->pArr);         // tos == 시작이면 빈
    ps->tos = (unsigned char *)ps->tos - ps->eleSize;  // tos 이전 위치로
    memcpy(pData, (unsigned char *)ps->tos, ps->eleSize);  // tos 내용 → pData 복사
}
```

### cleanupStack & size
```c
void cleanupStack(Stack *ps) { free(ps->pArr); }  // 메모리 반납
int size(Stack *ps) { return ps->size; }         // 최대 크기 반환
```

## 3. main.c 테스트 원본 + 설명
**역할:** int/double 스택 생성 → push/pop → LIFO 확인
```c
#include "stack4.h"

int main(void)
{
    Stack s1, s2;  // Stack 변수 2개

    initStack(&s1, 10, sizeof(int));     // &s1 주소 전달
    int i = 100; push(&s1, &i); i=200; push(&s1, &i); i=300; push(&s1, &i);  // 주소로 push

    int re; pop(&s1, &re); printf("s1 pop: %d\n", re);  // 300,200,100

    initStack(&s2, 100, sizeof(double));
    double d = 1.1; push(&s2, &d); /* ... */
    double re2; pop(&s2, &re2); printf("%.1lf\n", re2); // 3.3..

    printf("s1 size: %d\n", s1.size);    // 10 (ps->size 직접 접근)

    cleanupStack(&s1); cleanupStack(&s2); // 필수!
    return 0;
}
```

## 🏗️ 빌드
```
cd ds/stack/myStack4
cmake . && make
./stack4
```

완벽! 📘
