# 리스트(Linked List) 공부 가이드 - list1.c 분석

## 누구나 쉽게 이해할 수 있도록 설명! 초보자도 OK!

### 1. 연결 리스트(Linked List)란? 🤔
```
배열(Array)처럼 순서대로 데이터가 있지만, 
**연결 고리(링크)**로 서로 연결된 구조예요!

- 배열: 연속된 메모리 (인덱스로 바로 접근)
- 리스트: 흩어진 메모리 + 화살표(포인터)로 연결
```

**비유**: 기차 연결! 🚂 각 칸(노드)이 서로 연결되어 있어요.
```
첫번째 칸(100) → 두번째 칸(200) → 세번째 칸(300) → 네번째 칸(400)
```

### 2. list1.c 코드 구조 이해하기 📝

#### 📌 Node 구조체 (데이터 저장 상자)
```c
typedef struct node{
    int data;      // 데이터 (예: 100, 200)
    struct node *next;  // 다음 노드 주소 (화살표!)
} Node;
```
- `data`: 숫자 넣는 곳
- `next`: "다음 칸은 여기!" 주소

#### 📌 main()에서 리스트 만들기
```c
Node *p = malloc(sizeof(Node));  // 첫번째 칸 만들기
p->data = 100;                   // 첫 칸에 100 넣기
p->next = malloc(sizeof(Node));  // 두번째 칸 만들고 주소 연결
p->next->data = 200;
// ... 계속 연결 (100 → 200 → 300 → 400)
```
**결과**: `p`가 기차 머리(100)를 가리킴!

#### 📌 insertNode(30, p) - 노드 삽입 🆕
```c
void insertNode(int data, Node *p)
{
    Node*tmp = malloc(sizeof(Node));  // 새 칸(30) 만들기
    tmp->data = data;
    tmp->next = p->next;              // 새 칸의 다음 = 기존 두번째(200)
    p->next = tmp;                    // 첫 칸의 다음 = 새 칸(30)
}
```
**변화**: `100 → 30 → 200 → 300 → 400`

#### 📌 deleteNode(p, 300) - 노드 삭제 🗑️
```c
// tmp: 찾는 노드(300), tmp2: 그 전 노드 가리킴
while(tmp){
    if(tmp->data == 300) break;    // 300 찾음!
    tmp = tmp->next;               // 다음으로
    tmp2 = tmp2->next;
}
// 연결 끊기: tmp2->next = tmp->next (200 → 400)
// free(tmp3); 노드 메모리 해제
```
**결과**: `100 → 30 → 200 → 400`

#### ❌ 세그먼테이션 폴트(Segfault) 원인! 💥
```c
Node *tmp = p;
while(p){              // ❌ 문제! p는 계속 HEAD(100)를 가리킴
    printf("%d\n", tmp->data);
    tmp = tmp->next;   // tmp는 끝없이 앞으로 감
}
```
**무한 루프** → 메모리 끝 넘어감 → **세그폴트!**

**✅ 수정**:
```c
Node *tmp = p;
while(tmp){           // tmp가 NULL 될 때까지!
    printf("%d\n", tmp->data);
    tmp = tmp->next;
}
```
**출력**: 100\n30\n200\n400\n

### 3. 핵심 개념 정리 💡

| 개념 | 설명 | 코드 예시 |
|------|------|-----------|
| **malloc** | 새 노드 메모리 할당 | `malloc(sizeof(Node))` |
| **->data** | 노드 데이터 읽기/쓰기 | `p->data = 100` |
| **->next** | 다음 노드 주소 | `p->next = 새노드` |
| **while(tmp)** | 리스트 끝(NULL)까지 순회 | 리스트 출력/검색/삭제 |

### 4. 메모리 해제(중요!) 🧹
```c
Node *curr = p;
while(curr){
    Node *next = curr->next;  // 다음 주소 미리 저장
    free(curr);               // 현재 노드 해제
    curr = next;
}
```
**메모리 누수 방지!**

### 5. 그림으로 이해하기 🖼️
```
초기: 100 → 200 → 300 → 400 → NULL
      ↑
      p

삽입 후: 100 → 30 → 200 → 300 → 400 → NULL
            ↑
            p->next

삭제 후: 100 → 30 → 200 → 400 → NULL
```

### 🎯 연습 문제
1. 50을 맨 끝에 추가하려면?
2. 맨 앞(100)을 삭제하려면?
3. 리스트를 역순으로 출력하려면?

**이 가이드로 연결 리스트 완전 정복!** 🚀

