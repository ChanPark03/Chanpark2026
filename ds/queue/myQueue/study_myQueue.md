# 큐(Queue) 공부 가이드 - myQueue 분석

## 누구나 쉽게 이해할 수 있도록 설명! 초보자도 OK! 🎉

### 1. 큐(Queue)란? 🤔
```
**줄 서기!** FIFO(First In First In Out) 원칙.
맨 앞에서 꺼내고, 맨 뒤에 추가.

**비유**: 은행 줄 🚶‍♂️
1. 맨 뒤에 서기 (push/enqueue)
2. 맨 앞 사람 나감 (pop/dequeue)
```

**원형 큐(Circular Queue)**: 배열 끝나면 처음으로 돌아감! 🔄 효율적!

```
빈 상태: front=rear (같은 위치)
꽉 찬 상태: rear+1 == front (한 칸 여유 둠)
```

### 2. myQueue 코드 구조 이해하기 📝

#### 📌 Qu 구조체 (큐 상자)
```c
typedef struct {
    int queue[ARRAYSIZE];  // 100개 크기 배열 (데이터 저장소)
    int *front;            // 앞(꺼낼 위치) 화살표
    int *rear;             // 뒤(추가할 위치) 화살표
} Qu;
```
- `ARRAYSIZE 100`: 최대 99개 저장 (full 체크용 1칸 여유)

#### 📌 main()에서 큐 사용법
```c
Qu qu1, qu2;           // 두 개 큐 생성
initQueue(&qu1);       // 초기화 (front=rear=queue[0])

push(&qu1, 100);       // qu1 뒤에 100 추가
push(&qu1, 200);       // 뒤에 200 추가 → [100, 200]
printf("%d\n", pop(&qu1));  // 앞 100 꺼냄 → [200]
```
**테스트**: 정상 동작 확인 + 99개 꽉 채우기 + 101개 pop 테스트 (empty 에러)

#### 📌 initQueue - 큐 초기화 🆕
```c
void initQueue(Qu *pQu)
{
    pQu->front = pQu->queue;  // front를 처음으로
    pQu->rear = pQu->queue;   // rear도 처음으로 (빈 상태)
}
```

#### 📌 push(data) - 큐 뒤에 추가 ➕
```c
void push(Qu *pQu, int data)
{
    if(pQu->rear == pQu->queue + ARRAYSIZE)  // 끝났으면 처음으로 🔄
        pQu->rear = pQu->queue;
    
    if(pQu->rear + 1 == pQu->front) {        // 꽉 찼나? ❌
        fprintf(stderr, "stack is full\n");  // 오타! queue 맞음
        exit(1);
    }
    
    *(pQu->rear++) = data;  // rear에 저장 + rear 앞으로!
}
```

#### 📌 pop() - 큐 앞에서 꺼내기 ➖
```c
int pop(Qu *pQu)
{
    if(pQu->front == pQu->queue + ARRAYSIZE)  // 끝났으면 처음으로 🔄
        pQu->front = pQu->queue;
    
    if(pQu->front == pQu->rear) {             // 비었나? ❌
        fprintf(stderr, "there is no data\n");
        exit(1);
    }
    
    return *(pQu->front++);  // front 데이터 반환 + front 앞으로!
}
```

### 3. 동작 과정 그림으로 이해! 🖼️

#### 초기화 후:
```
front → [ | | | ... ]
rear  → [ | | | ... ]  같은 위치 (empty)
```

#### push(100), push(200):
```
front → [100|200| | ... ]
        ↑
rear      ↑  (rear+1 위치)
```

#### pop() → 100 반환:
```
front → [ |200| | ... ]  front 앞으로!
rear      ↑
```

#### 꽉 찼을 때 (99개):
```
front → [ |99| |1| ... ]
rear   → [ | | |1| ... ]  rear+1 == front (full!)
```

### 4. 핵심 개념 정리 💡

| 개념 | 설명 | 코드 |
|------|------|------|
| **FIFO** | 먼저 들어온 게 먼저 나감 | push 뒤, pop 앞 |
| **원형** | 끝 → 처음 | `rear = queue` |
| **Full** | `rear+1 == front` | 1칸 여유 (empty와 구분) |
| **Empty** | `front == rear` | 포인터 같음 |
| **포인터 증가** | `*(rear++) = data` | 저장 후 앞으로! |

### 5. 주의점 & 개선점 ⚠️
- **오타**: "stack is full" → "queue is full"
- **에러 처리**: exit(1) 강제 종료 → graceful handling 추천
- **컴파일**: `cd ds/queue/myQueue && cmake . && make`
- **테스트**: main.c의 99 push + 101 pop → full/empty 에러 확인

### 🎯 연습 문제
1. 큐에 문자열 넣기?
2. peek() 함수 추가 (앞 데이터 확인만)?
3. 두 큐 합치기?

**이 가이드로 원형 큐 완전 마스터!** 🚀

