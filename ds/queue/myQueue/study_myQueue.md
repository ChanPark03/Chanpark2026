# ue드 - myQueue 분석

## 누구나 쉽게해할 할 수록있도록 🎉!초보자도 OK! 🎉

### 1. 큐(ue)란?)란?🤔
```
* 줄앞서기!*In .
맨앞에서꺼내고, 맨 뒤에 추가

**비유**:은행 줄 🚶‍♂️
1.*맨비뒤에 서기 (push/enqueue)
2. 맨 앞 사람 나감 (pop/dequeue)
```

**유**: 은행 줄 🚶‍♂️**나면돌아감!🔄 효율적!

```
빈1상태: 맨 뒤에 =) 같은)
꽉2찬 상태: er+1== frt(한칸여유둠)
```**원형 큐(Circular Queue)**: 배열 끝나면 처음으로 돌아감! 🔄 효율적!

##2myQueue코드구조이해하기📝
```
빈###r📌(Qu위구조체치(상자
```c꽉 찬 상태: rear+1 == front (한 칸 여유 둠)
```
/100개크기데이터
### 2. myQueue 코드 구조 이해하기 📝/앞()화살표
/뒤()화살표
}#Qu;
```
-#`ARRAYSIZE#100`:#최대 99개저장📌(full 체크용Q1칸u여유)

#### 📌구main()에서조큐체사용법
```c
Qu qu1,(qu2;큐 상자)//두개큐 생성
initQuue(&qu);// 초기화 (=queue[0])

pcsh(&qu1, 100)     /q1 뒤에 100 추가
push(&q1, 200);    / 뒤에 200 추가 → [100, 200]typedef struct {
printf("%d\n", pop(&qu1));  /  앞i100 꺼냄e→R[200]SIZE];  // 100개 크기 배열 (데이터 저장소)
```    int *front;            // 앞(꺼낼 위치) 화살표
**테스트* : 정상 동작 확인 + 99개 꽉i채우t + 101개rprp 테스트 ( mpty 에러)

####/📌추initQueue -) 화초기화🆕
```c
} Qu;
{
 ->front=pQu->uee;/ front를 처음으로```
 `RIpQu->r1ar = pQu->0`: 최;   /대장 (fu도크처음으로1(빈 상태)
}
```

####📌sh(ata) - 큐 뒤에추가➕
```c

{
 if(->rear==pQu->queue+ARRAYSIZE)``끝났으면처음으로🔄
Qu>re=q,qu->que e 
    
    if( //->rear +생1==pQu->) {    / 꽉h찼나?q❌
1 / 1uu0)p;i tf(s der , "st ck is full\n");  ///오타!에 200  맞음
 추→[,exit(1;
 r q}
 / 0
꺼]`pQu->=*da:a;  // r동a작에9저장 +기r1pr테앞으로 empty 에러)
}
`
```c
voi#d📌npop()u-e큐u앞에서p꺼내기➖
{
pQt-pop(Qup*pQu)
{
>que f(pQu->fro   == pQu->pQu-> + ear = pQu)qu//e끝났으면u처음으로e🔄
;   // rpQu->=pQu->queue;

ifpQu->==pQu->){//비었나?❌
fpintf(std , "th-큐e에is가odaa\");
du(Q  ex Qa1u-
>que}
 R  SIZE)  // 끝났으면 처음으로 🔄
 >=urequr  (->front++front 반환i+(frontt앞으로!
}
"k`is full\n");  // 오타! queue 맞음
        exit(1);
    3과정으로이해! 
 
####   화 후:
```
*(pQur++) = da| ta;  // rear에 저장 + rear 앞으로!
  |   같은 위치 (empty)
```

#### ```100), push(
```
front| 
↑
c  ↑  (+1 위치)
int pop(Qu *pQu)
{
   # pop()(→t100=반환:ueue + ARRAYSIZE)  // 끝났으면 처음으로 🔄
 >o
nt = p→e[|200|| ...]ront앞으로!
Qrnp-r↑
`e 
    }
#   꽉찼을때(99개):
   return *(pQu->front++);  // front 데이터 반환 + front 앞으로!
front → [|||1|...]
rea`→[|||| ...]rar+1 == fron(full!)
###
#### 초기화 후:
```4 개념정리

fr개념t → [ ||코드.. ]
rear  → [ | | |]  같은 위치 (empty)
``**FIFO` | 먼저 들어온 게 먼저 나감 | push 뒤, p 앞 |
| **원형  rear 
 1칸 여유(emty와구분)
#### push0), push(200):포인터같음
```포인터증가`*(rear++)=data`저장후앞으로

### 5. 주의점 & 개선점 ⚠️
- **오타**: "stack is full" → "queue is full"
- **에러 처리**: exit(1) 강제 종료 → graceful handling 추천front → [100|200| | ... ]
-         ↑
- re테스트    main.c의 99↑push(r 101 pop → full/emptyear 확인

### 🎯+연습치문제
1. 큐에 문자열 넣기?```
2. pk() 함수 추가 (앞 데이터 확인만)?
3 두 큐 합치기?

**이가이드로원형큐완전마스터
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

