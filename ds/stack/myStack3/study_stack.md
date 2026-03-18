# 스택(Stack) 공부 가이드 (myStack3)

안녕하세요! 이 문서는 `myStack3` 예제를 통해 스택(Stack) 자료구조를 쉽게 이해할 수 있도록 돕기 위해 만들어졌습니다.

## 1. 스택(Stack)이란 무엇일까요?

스택은 "마지막에 들어온 것이 가장 먼저 나간다"는 뜻의 **LIFO(Last-In, First-Out)** 원칙으로 동작하는 자료구조입니다. 비유하자면, 프링글스 통에 과자를 넣고 빼는 것과 같습니다. 가장 마지막에 넣은 과자를 가장 먼저 꺼내 먹게 되죠.

주요 연산은 두 가지입니다.
*   **push**: 스택의 가장 위에 데이터를 쌓는(추가하는) 연산
*   **pop**: 스택의 가장 위에서 데이터를 꺼내는(제거하는) 연산

## 2. 프로젝트 파일 구조

이 프로젝트는 세 개의 파일로 구성되어 있습니다.

*   `stack3.h`: 스택의 구조(생김새)를 정의하는 **헤더 파일**
*   `stack3.c`: 스택의 실제 기능(함수)들을 구현하는 **소스 파일**
*   `main.c`: `stack3.h`와 `stack3.c`에 정의된 스택을 가져와 사용하는 **실행 파일**

각 파일의 역할을 자세히 살펴보겠습니다.

## 3. `stack3.h`: 스택 구조 정의하기

```c
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 스택의 구조를 정의합니다.
typedef struct {
    int *pArr;  // 데이터를 저장할 동적 배열을 가리키는 포인터
    int *tos;   // Top of Stack, 스택의 가장 위를 가리키는 포인터
    int size;   // 스택의 전체 크기
} Stack;

// 스택에서 사용할 함수들을 미리 선언합니다. (원래 파일에 빠져있어서 추가했습니다)
void initStack(Stack *ps, int size);
void cleanupStack(Stack *ps);
void push(Stack *ps, int data);
int pop(Stack *ps);
```

### 코드 설명

*   `#pragma once`: 이 헤더 파일이 컴파일 시 단 한 번만 포함되도록 하는 지시어입니다. 중복 포함을 방지합니다.
*   `typedef struct { ... } Stack;`: `Stack`이라는 이름의 새로운 자료형을 만듭니다. 이 구조체는 스택에 필요한 세 가지 정보를 담고 있습니다.
    *   `int *pArr`: `push`되는 정수(int)들을 저장할 배열의 시작 주소를 가리키는 포인터입니다. `malloc`을 통해 동적으로 메모리를 할당받아 사용합니다.
    *   `int *tos`: 'Top of Stack'의 약자로, 현재 스택에서 가장 마지막 데이터가 있는 위치 바로 다음을 가리킵니다. 다음에 `push`될 데이터가 저장될 위치입니다.
    *   `int size`: 스택이 최대로 저장할 수 있는 데이터의 개수입니다.

*   **함수 선언**: `stack3.c`에서 구현될 함수들을 다른 파일(`main.c`)에서 "이런 함수들이 있다"고 알려주는 역할을 합니다. 원본 `stack3.h` 파일에는 이 선언들이 빠져있어, `main.c`에서 경고가 발생할 수 있습니다.

## 4. `stack3.c`: 스택 기능 구현하기

```c
#include "stack3.h"

// 스택을 초기화하는 함수
void initStack(Stack *ps, int size)
{
    // size 만큼의 int 배열을 동적으로 할당하고 시작 주소를 pArr에 저장
    ps->pArr = malloc(sizeof(int) * size);
    // 스택의 최대 크기를 저장
    ps->size = size;
    // tos 포인터를 배열의 시작점(pArr)으로 설정. 아직 데이터가 없으므로.
    ps->tos = ps->pArr;
}

// 스택이 사용한 메모리를 해제하는 함수
void cleanupStack(Stack *ps)
{
    // initStack에서 할당한 메모리를 운영체제에 반납
    free(ps->pArr);
}

// 스택에 데이터를 추가하는 함수
void push(Stack *ps, int data)
{
    // assert는 프로그램의 특정 지점에서 반드시 만족해야 하는 조건을 검사하는 매크로입니다.
    // 만약 tos가 배열의 끝을 넘어섰다면 (스택이 꽉 찼다면) 프로그램을 중단시킵니다.
    assert(ps->tos != (ps->pArr + ps->size));

    // tos가 가리키는 위치에 데이터를 저장하고, tos를 한 칸 뒤로 이동시킵니다.
    *(ps->tos++) = data;
}

// 스택에서 데이터를 꺼내는 함수
int pop(Stack *ps)
{
    // assert를 이용해 스택이 비어있는지 확인합니다.
    // tos와 pArr이 같다면 데이터가 하나도 없는 상태입니다.
    assert(ps->tos != ps->pArr);

    // tos를 한 칸 앞으로 이동시킨 후, 그 위치의 데이터를 반환합니다.
    return *(--ps->tos);
}
```

### 코드 설명

*   `initStack`: `malloc`을 사용해 `size` 만큼의 정수를 저장할 공간을 메모리에서 빌려와 `pArr`에 연결합니다. `tos`는 아직 데이터가 없으므로 배열의 가장 앞을 가리키게 합니다.
*   `cleanupStack`: `initStack`에서 빌려온 메모리를 `free`를 통해 다시 시스템에 돌려줍니다. 메모리 누수(memory leak)를 방지하기 위해 꼭 필요합니다.
*   `push`: `assert`를 사용해 스택이 꽉 찼는지(`Stack Overflow`) 확인합니다. 꽉 차지 않았다면 `tos`가 가리키는 곳에 데이터를 넣고 `tos`를 다음 칸으로 이동시킵니다. `*(ps->tos++)`는 `*ps->tos = data; ps->tos++;` 와 동일한 동작을 합니다.
*   `pop`: `assert`를 사용해 스택이 비었는지(`Stack Underflow`) 확인합니다. 비어있지 않다면 `tos`를 이전 칸으로 먼저 이동시킨 후, 그 위치의 값을 반환합니다. `*(--ps->tos)`는 `ps->tos--; return *ps->tos;` 와 동일한 동작을 합니다.

## 5. `main.c`: 스택 사용해보기

```c
#include<stdio.h>
#include "stack3.h"

int main(void)
{
    Stack s1, s2;  

    // 스택을 사용하기 전에 반드시 초기화해야 합니다.
    // 10개의 int를 저장할 수 있는 크기로 s1을 초기화합니다.
    initStack(&s1, 10);
    initStack(&s2, 10);

    // s1에 데이터 push
    push(&s1, 100);
    push(&s1, 200);
    push(&s1, 300);

    // s1에서 데이터 pop (LIFO: 300, 200, 100 순서로 출력)
    printf("s1 첫 pop() 리턴 값 : %d
", pop(&s1));
    printf("s1 두번째 pop() 리턴 값 : %d
", pop(&s1));
    printf("s1 세번째 pop() 리턴 값 : %d
", pop(&s1));

    // s2에 데이터 push
    push(&s2, 700);
    push(&s2, 800);
    push(&s2, 900);

    // s2에서 데이터 pop (LIFO: 900, 800, 700 순서로 출력)
    printf("s2 첫 pop() 리턴 값 : %d
", pop(&s2));
    printf("s2 두번째 pop() 리턴 값 : %d
", pop(&s2));
    printf("s2 세번째 pop() 리턴 값 : %d
", pop(&s2));

    // 스택의 크기 출력 (원본 코드의 오류 수정)
    // printf("s1 스택 메모리 사이즈는 : %d, s1.size"); (X)
    printf("s1 스택의 최대 크기는 : %d
", s1.size); // (O)
    printf("s2 스택의 최대 크기는 : %d
", s2.size); // (O)

    // 사용이 끝난 스택은 메모리를 해제해줍니다.
    cleanupStack(&s1);
    cleanupStack(&s2);

    return 0;
}
```

### 원본 `main.c`의 문제점 및 수정

1.  `initStack(&s1);`: `initStack` 함수는 두 번째 인자로 스택의 크기를 받아야 하는데, 원본 코드에서는 이 부분이 누락되었습니다. `initStack(&s1, 10);` 처럼 크기를 명시해주어야 합니다.
2.  `printf("s1 스택 메모리 사이즈는 : %d, s1.size");`: `printf` 사용법이 잘못되었습니다. 변수 `s1.size`의 값을 출력하려면 포맷 지정자 `%d` 위치에 맞게 변수를 쉼표 뒤에 적어주어야 합니다. `printf("s1 스택의 최대 크기는 : %d
", s1.size);` 와 같이 수정했습니다.

## 6. 정리

`myStack3` 예제는 동적 메모리 할당과 포인터를 사용하여 스택을 구현하는 좋은 예시입니다.

*   **`stack3.h`**에서 스택의 **설계도**(`struct Stack`)를 그리고, 사용할 기능들(**함수 원형**)을 정의합니다.
*   **`stack3.c`**에서 `h`파일에 정의된 기능들을 실제로 **구현**합니다.
*   **`main.c`**에서는 잘 만들어진 스택을 가져와 **사용**합니다.

이 가이드를 통해 스택의 개념과 C언어에서의 구현 방법에 대해 더 깊이 이해하셨기를 바랍니다!
