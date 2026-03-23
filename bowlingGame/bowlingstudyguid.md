# 🎳 볼링 게임 C 언어 스터디 가이드

> **대상**: C 언어 초보자 / 중급자  
> **목표**: 볼링 게임 소스 코드를 분석하며 C 언어의 핵심 개념을 학습한다

---

## 📚 목차

1. [프로젝트 구조 이해하기](#1-프로젝트-구조-이해하기)
2. [헤더 파일과 소스 파일](#2-헤더-파일과-소스-파일)
3. [구조체 (struct)](#3-구조체-struct)
4. [함수와 static 키워드](#4-함수와-static-키워드)
5. [볼링 게임 로직 분석](#5-볼링-게임-로직-분석)
6. [파일 입출력 (File I/O)](#6-파일-입출력-file-io)
7. [포인터와 메모리](#7-포인터와-메모리)
8. [표준 입출력 (scanf / printf)](#8-표준-입출력-scanf--printf)
9. [빌드 시스템: CMake](#9-빌드-시스템-cmake)
10. [버그 분석 및 개선 과제](#10-버그-분석-및-개선-과제)

---

## 1. 프로젝트 구조 이해하기

```
bowling/
├── CMakeLists.txt     ← 빌드 설정 파일 (CMake)
├── bowling.h          ← 헤더 파일 (선언)
├── bowling.c          ← 핵심 게임 로직 (구현)
└── main.c             ← 프로그램 진입점
```

### 왜 파일을 나누는가?

| 파일 | 역할 | 비유 |
|------|------|------|
| `.h` (헤더) | 무엇이 있는지 "선언" | 레스토랑 메뉴판 |
| `.c` (소스) | 실제 동작 "구현" | 주방의 요리 과정 |
| `main.c` | 프로그램 시작점 | 손님이 앉는 자리 |

---

## 2. 헤더 파일과 소스 파일

### `bowling.h` 전체 분석

```c
#ifndef BOWLING_H       // "BOWLING_H 가 정의되지 않았다면"
#define BOWLING_H       // "BOWLING_H 를 정의한다"
// ... 코드 ...
#endif // BOWLING_H     // 조건 종료
```

#### 📌 Include Guard (인클루드 가드)

위의 `#ifndef / #define / #endif` 패턴을 **인클루드 가드**라고 한다.  
같은 헤더 파일이 여러 번 포함(include)될 경우, 중복 선언으로 인한 **컴파일 에러를 방지**한다.

```c
// ❌ 가드 없을 때: 두 파일에서 include하면 중복 에러
// ✅ 가드 있을 때: 두 번째 include는 자동으로 무시됨
```

#### 📌 매크로 상수 (`#define`)

```c
#define MAX_FRAMES 10        // 볼링은 총 10 프레임
#define MAX_PLAYER_NAME 9    // 플레이어 이름 최대 9글자
```

`#define`은 컴파일 전에 텍스트를 치환하는 **전처리기 지시문**이다.  
숫자를 직접 쓰는 것보다 의미가 명확하고, 나중에 수정하기 쉽다.

```c
// ❌ 매직 넘버 (나쁜 습관)
for (int i = 0; i < 10; i++) { ... }

// ✅ 매크로 사용 (좋은 습관)
for (int i = 0; i < MAX_FRAMES; i++) { ... }
```

#### 📌 표준 라이브러리 포함

```c
#include <stdio.h>    // printf, scanf, fopen 등
#include <stdlib.h>   // 동적 메모리, exit 등
#include <string.h>   // strncpy, strcmp 등
#include <stdbool.h>  // bool, true, false 사용 가능
```

> `<stdbool.h>`는 C99 표준부터 지원되며, 이를 포함해야 `bool`, `true`, `false` 키워드를 사용할 수 있다.

---

## 3. 구조체 (struct)

### Frame 구조체

```c
typedef struct {
    int rolls[3];         // 각 투구 핀 수 (10번 프레임은 최대 3번)
    int frame_score;      // 이 프레임의 점수 (보너스 포함)
    int cumulative_score; // 이 프레임까지의 누적 점수
    bool is_strike;       // 스트라이크 여부
    bool is_spare;        // 스페어 여부
    int bonus;            // 보너스 점수 (현재 미사용)
} Frame;
```

#### 📌 배열 `rolls[3]` 이해하기

| 인덱스 | 의미 |
|--------|------|
| `rolls[0]` | 첫 번째 투구 |
| `rolls[1]` | 두 번째 투구 |
| `rolls[2]` | 10번 프레임 세 번째 투구 (스트라이크/스페어 시) |

#### 📌 typedef로 편리하게 사용하기

```c
// typedef 없이 사용할 때
struct Frame myFrame;

// typedef 있을 때 (훨씬 간결)
Frame myFrame;
```

### Game 구조체

```c
typedef struct {
    char player_name[MAX_PLAYER_NAME + 1]; // +1은 '\0' (null terminator) 공간
    Frame frames[MAX_FRAMES];              // 10개의 프레임 배열
    int current_frame;                     // 현재 진행 중인 프레임 번호
} Game;
```

#### 📌 왜 `+1`을 하는가?

C 언어에서 문자열은 마지막에 **null 종단자** `'\0'`를 포함한다.

```
"Alice"  →  ['A','l','i','c','e','\0']
             0    1   2   3   4    5    ← 인덱스
```

이름이 최대 9글자이므로, 배열 크기는 `9 + 1 = 10`이어야 한다.

---

## 4. 함수와 static 키워드

### `bowling.c` 상단의 선언들

```c
static void init_game(Game *game, const char *player_name);
static void print_scoreboard(const Game *game);
static void calculate_scores(Game *game);
static int get_pins(int max_pins);
static void save_score(const char* player_name, int score);
```

#### 📌 `static` 함수란?

`static` 키워드가 붙은 함수는 **해당 소스 파일 내에서만 사용 가능**하다.  
다른 `.c` 파일에서 이 함수를 호출할 수 없다.

```
bowling.c 내부 함수들 (외부 접근 불가):
  static init_game()
  static print_scoreboard()
  static calculate_scores()
  static get_pins()
  static save_score()

외부에서 접근 가능한 함수 (bowling.h에 선언):
  play_game()
  view_records()
```

이는 **정보 은닉(Information Hiding)** 원칙으로, 외부에서 필요 없는 함수를 감추어 코드를 안전하게 만든다.

#### 📌 함수 포인터 매개변수: `Game *game`

```c
static void init_game(Game *game, const char *player_name);
//                          ↑                  ↑
//                      포인터 (수정 가능)    const 포인터 (읽기 전용)
```

| 매개변수 형태 | 의미 |
|--------------|------|
| `Game *game` | 포인터로 전달 → 원본 수정 가능 |
| `const Game *game` | 읽기 전용 포인터 → 원본 수정 불가 |

---

## 5. 볼링 게임 로직 분석

### 5-1. 볼링 규칙 복습

```
일반 프레임 (1~9번):
  - 스트라이크: 첫 투구에 10개 → 다음 2번 투구 핀 수를 보너스로 합산
  - 스페어: 두 투구 합이 10개 → 다음 1번 투구 핀 수를 보너스로 합산
  - 그 외: 두 투구 핀 수의 합

10번 프레임:
  - 스트라이크 또는 스페어 달성 시 3번째 투구 기회 부여
  - 최대 3번 투구 가능
```

### 5-2. `play_game()` 흐름도

```
play_game()
│
├── 이름 입력 → init_game() (초기화)
│
└── for i = 0 to 9 (10 프레임)
    │
    ├── print_scoreboard() 출력
    ├── 첫 번째 투구 get_pins(10)
    │
    ├── [스트라이크?]
    │    ├── YES + 10번 프레임 → 2번째, 3번째 투구
    │    └── YES + 일반 프레임 → 다음 프레임으로
    │
    └── [스트라이크 아님]
         ├── 두 번째 투구 get_pins(10 - rolls[0])
         ├── [스페어?]
         │    ├── YES + 10번 프레임 → 3번째 투구
         │    └── YES + 일반 → 다음 프레임으로
         └── NO → 다음 프레임으로
         └── calculate_scores() 점수 계산
```

### 5-3. `calculate_scores()` 핵심 분석

```c
static void calculate_scores(Game *game) {
    for (int i = 0; i <= game->current_frame && i < MAX_FRAMES; i++) {
```

#### 📌 화살표 연산자 `->` 이해하기

```c
game->current_frame   // 포인터를 통해 구조체 멤버 접근
// 아래와 동일
(*game).current_frame
```

#### 스트라이크 점수 계산 로직

```c
if (game->frames[i].is_strike) {
    frame_score = 10;
    if (i < MAX_FRAMES - 1) {          // 1~9번 프레임
        if (game->frames[i + 1].is_strike) { // 다음 프레임도 스트라이크
            frame_score += 10;
            if (i < MAX_FRAMES - 2) {  // i+2번 프레임의 첫 투구
                frame_score += game->frames[i + 2].rolls[0];
            } else {                   // 9번 프레임 스트라이크 + 10번 스트라이크
                frame_score += game->frames[i+1].rolls[1];
            }
        } else {                       // 다음 프레임이 스트라이크 아님
            frame_score += game->frames[i+1].rolls[0] + game->frames[i+1].rolls[1];
        }
    } else {                           // 10번 프레임 스트라이크
        frame_score += game->frames[i].rolls[1];
        frame_score += game->frames[i].rolls[2];
    }
}
```

#### 누적 점수 계산

```c
if (i == 0) {
    game->frames[i].cumulative_score = game->frames[i].frame_score;
} else {
    if (game->frames[i-1].cumulative_score > 0 && game->frames[i].frame_score > 0)
        game->frames[i].cumulative_score = 
            game->frames[i-1].cumulative_score + game->frames[i].frame_score;
}
```

> ⚠️ **버그 주의**: `cumulative_score > 0` 조건이 있어서, 프레임 점수가 0점이면 누적 점수가 업데이트되지 않는 문제가 있다!

### 5-4. `init_game()` 초기화 분석

```c
static void init_game(Game *game, const char *player_name) {
    strncpy(game->player_name, player_name, MAX_PLAYER_NAME);
    game->player_name[MAX_PLAYER_NAME] = '\0';  // 안전한 null 종단
    game->current_frame = 0;
    for (int i = 0; i < MAX_FRAMES; i++) {
        game->frames[i].rolls[0] = -1;  // -1 = 아직 투구 안 함
        game->frames[i].rolls[1] = -1;
        game->frames[i].rolls[2] = -1;
        // ...
    }
}
```

#### 📌 `strncpy` vs `strcpy`

```c
// ❌ 위험: 버퍼 오버플로우 가능
strcpy(dst, src);

// ✅ 안전: 최대 n글자만 복사
strncpy(dst, src, n);
```

`strncpy`는 `n`글자까지만 복사하므로 **버퍼 오버플로우를 방지**한다.  
단, 복사한 후 반드시 `dst[n] = '\0'`을 명시적으로 설정해야 한다.

---

## 6. 파일 입출력 (File I/O)

### 점수 저장: `save_score()`

```c
static void save_score(const char* player_name, int score) {
    FILE* file = fopen("records.csv", "a");  // "a" = append 모드 (기존 내용 유지)
    if (file == NULL) {
        printf("Error opening records file.\n");
        return;
    }

    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    char date_str[20];
    strftime(date_str, sizeof(date_str), "%Y-%m-%d", tm);  // "2024-01-15" 형식

    fprintf(file, "%s,%d,%s\n", player_name, score, date_str);
    fclose(file);  // 반드시 닫아야 함!
}
```

#### 📌 파일 열기 모드

| 모드 | 의미 | 파일 없으면? |
|------|------|-------------|
| `"r"` | 읽기 전용 | 실패 (NULL 반환) |
| `"w"` | 쓰기 (덮어씀) | 새로 생성 |
| `"a"` | 추가 쓰기 (append) | 새로 생성 |
| `"r+"` | 읽기/쓰기 | 실패 |

> **중요**: `fopen`이 실패하면 `NULL`을 반환한다. 반드시 NULL 체크를 해야 한다!

#### 📌 `time_t`와 날짜 처리

```c
time_t t = time(NULL);      // 현재 시각 (Unix timestamp: 1970년 1월 1일 이후 초)
struct tm* tm = localtime(&t); // timestamp → 날짜/시간 구조체로 변환
strftime(date_str, sizeof(date_str), "%Y-%m-%d", tm); // 형식 문자열로 포맷
```

### 기록 조회: `view_records()`

```c
void view_records() {
    FILE* file = fopen("records.csv", "r");
    // ...
    char line[100];
    while (fgets(line, sizeof(line), file)) {  // 한 줄씩 읽기
        char player_name[MAX_PLAYER_NAME + 1];
        int score;
        char date[20];
        if (sscanf(line, "%[^,],%d,%s", player_name, &score, date) == 3
            && strcmp(player_name, player_name_filter) == 0) {
            printf("  %-5d %s\n", score, date);
        }
    }
}
```

#### 📌 `sscanf` 포맷 문자열 분석

```
"%[^,],%d,%s"
  ↑      ↑   ↑
  │      │   └── 문자열 읽기
  │      └────── 정수 읽기
  └───────────── ','가 아닌 문자들을 읽기 (= 쉼표 전까지)
```

#### 📌 `printf` 서식 지정자

```c
printf("  %-5d %s\n", score, date);
//          ↑
//         왼쪽 정렬, 최소 5칸 너비
```

| 서식 | 의미 |
|------|------|
| `%d` | 정수 |
| `%s` | 문자열 |
| `%f` | 실수 |
| `%-5d` | 왼쪽 정렬, 최소 5칸 |
| `%5d` | 오른쪽 정렬, 최소 5칸 |
| `%3.1f` | 총 3칸, 소수점 1자리 |

---

## 7. 포인터와 메모리

### 포인터 기본 개념

```c
int x = 10;
int *p = &x;   // p는 x의 주소를 저장

printf("%d\n", x);    // 10 (값)
printf("%p\n", p);    // 0x... (주소)
printf("%d\n", *p);   // 10 (역참조: 주소가 가리키는 값)
```

### 이 코드에서 포인터 사용 패턴

```c
// 함수 호출 시 구조체를 포인터로 전달
init_game(&game, player_name);
//         ↑ 주소를 넘김 (큰 구조체를 복사하지 않아 효율적)

// 함수 내부에서 포인터로 접근
static void init_game(Game *game, ...) {
    game->current_frame = 0;  // (*game).current_frame = 0 과 동일
}
```

#### 📌 왜 포인터를 쓰는가?

```c
// ❌ 값으로 전달 (복사본 수정 → 원본 변경 안 됨)
void bad_init(Game game) { game.current_frame = 0; }

// ✅ 포인터로 전달 (원본 수정)
void good_init(Game *game) { game->current_frame = 0; }
```

또한 `Game` 구조체는 크기가 클 수 있어, 매번 복사하면 성능이 저하된다.  
포인터를 전달하면 8바이트(64비트 시스템)만 전달하면 된다.

---

## 8. 표준 입출력 (scanf / printf)

### `get_pins()` 입력 검증

```c
static int get_pins(int max_pins) {
    int pins;
    while (1) {
        if (scanf("%d", &pins) == 1 && pins >= 0 && pins <= max_pins) {
            return pins;
        } else {
            printf("유효한 점수를 입력하세요 (0-%d): ", max_pins);
            while (getchar() != '\n'); // 입력 버퍼 비우기
        }
    }
}
```

#### 📌 입력 버퍼 비우기

```c
while (getchar() != '\n');
```

`scanf`가 실패하면 잘못된 입력이 버퍼에 남는다.  
이 코드는 개행문자(`\n`)가 나올 때까지 버퍼의 문자들을 하나씩 버린다.

#### 📌 `scanf` 반환값 확인

```c
if (scanf("%d", &pins) == 1)
//  └─────────────────────┘
//  성공하면 읽은 항목 수 반환 (여기서는 1개)
//  실패하면 0 또는 EOF 반환
```

항상 `scanf`의 반환값을 확인하는 것이 좋은 습관이다.

---

## 9. 빌드 시스템: CMake

```cmake
cmake_minimum_required(VERSION 3.10)  # 최소 CMake 버전
project(bowlingGame)                   # 프로젝트 이름

include_directories(${CMAKE_CURRENT_LIST_DIR})  # 헤더 파일 검색 경로
add_executable(bowlingGame main.c bowling.c)    # 실행 파일 생성
```

### CMake 빌드 방법

```bash
# 빌드 디렉토리 생성 및 이동
mkdir build && cd build

# CMake 설정
cmake ..

# 컴파일
make

# 실행
./bowlingGame
```

### 전통적인 gcc 직접 컴파일

```bash
gcc -o bowlingGame main.c bowling.c
./bowlingGame
```

---

## 10. 버그 분석 및 개선 과제

### 🐛 발견된 버그들

#### 버그 1: 0점 프레임의 누적 점수 미업데이트

```c
// 현재 코드 (문제)
if (game->frames[i-1].cumulative_score > 0 && game->frames[i].frame_score > 0)
    game->frames[i].cumulative_score = ...

// 프레임 점수가 0이면 누적 점수가 업데이트되지 않음!
```

**수정 제안**:

```c
// frame_score > 0 조건 제거
if (i == 0) {
    game->frames[i].cumulative_score = game->frames[i].frame_score;
} else {
    game->frames[i].cumulative_score = 
        game->frames[i-1].cumulative_score + game->frames[i].frame_score;
}
```

#### 버그 2: 스코어보드 10번 프레임 표시 누락

```c
// print_scoreboard에서 10번 프레임의 3번째 투구를 표시하지 않음
if (game->frames[i].is_strike) {
    printf("X| |");  // 3번째 투구가 표시되지 않음
}
```

#### 버그 3: 9번 프레임 연속 스트라이크 계산 엣지 케이스

```c
// 9번 프레임(i=8) 스트라이크 + 10번 프레임(i=9) 스트라이크일 때
// 10번 프레임의 rolls[1]을 사용 — 정확한가 확인 필요
if (i < MAX_FRAMES - 2) {
    frame_score += game->frames[i + 2].rolls[0];
} else { // 9번 프레임
    frame_score += game->frames[i+1].rolls[1]; // ← 검토 필요
}
```

---

### 🚀 개선 과제 (도전 문제)

#### 초급

1. **`bonus` 필드 활용**: `Frame` 구조체의 `bonus` 필드가 현재 사용되지 않는다. 보너스 점수를 별도로 저장하도록 코드를 수정해보자.

2. **입력 검증 강화**: 플레이어 이름에 공백이 있으면 `scanf("%9s")`가 제대로 처리하지 못한다. `fgets`를 사용하도록 변경해보자.

#### 중급

1. **최고 점수 보기 구현**: `main.c`의 메뉴 3번 "최고 점수 보기"를 구현해보자. `records.csv`에서 가장 높은 점수를 찾아 출력한다.

2. **월별 통계 보기 구현**: 메뉴 4번 "월별 통계 보기"를 구현해보자. 날짜별로 점수를 그룹화하여 평균을 계산한다.

3. **스코어보드 개선**: 현재 스코어보드는 10번 프레임의 3번째 투구를 표시하지 않는다. 올바르게 표시되도록 수정해보자.

#### 고급

1. **퍼펙트 게임 감지**: 모든 프레임이 스트라이크인 퍼펙트 게임(300점)을 감지하고 특별한 메시지를 출력해보자.

2. **멀티플레이어 지원**: 여러 명이 번갈아 게임을 진행할 수 있도록 코드를 확장해보자.

3. **단위 테스트 작성**: `calculate_scores` 함수가 다양한 경우(스트라이크, 스페어, 퍼펙트 게임 등)에서 올바른 점수를 계산하는지 검증하는 테스트를 작성해보자.

---

## 📝 핵심 개념 요약

| 개념 | 설명 | 이 코드에서 |
|------|------|------------|
| 구조체 (struct) | 관련 데이터를 묶는 사용자 정의 타입 | `Frame`, `Game` |
| 포인터 | 메모리 주소를 저장하는 변수 | `Game *game` |
| static 함수 | 파일 범위로 제한된 함수 | `init_game`, `calculate_scores` 등 |
| 파일 I/O | 파일 읽기/쓰기 | `save_score`, `view_records` |
| 인클루드 가드 | 헤더 중복 포함 방지 | `#ifndef BOWLING_H` |
| 매크로 상수 | 컴파일 전 텍스트 치환 | `MAX_FRAMES`, `MAX_PLAYER_NAME` |
| 입력 검증 | 잘못된 입력 처리 | `get_pins()` |
| typedef | 타입에 별칭 부여 | `typedef struct { ... } Frame;` |

---

## 🔗 참고 자료

- [C 언어 표준 라이브러리 레퍼런스](https://en.cppreference.com/w/c)
- [CMake 공식 문서](https://cmake.org/documentation/)
- [볼링 점수 계산 규칙 (Wikipedia)](https://ko.wikipedia.org/wiki/볼링)

---

*스터디 가이드 끝. 코드를 직접 수정하고 컴파일하며 학습하는 것을 강력히 권장합니다! 🎳*
