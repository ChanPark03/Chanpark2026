# Chanpark2026

고려대 개발자 양성과정 저장소입니다.

## 저장소 구성

- `c_example/`: C 언어 기초 예제
- `ds/`: 스택, 큐, 리스트 등 자료구조 실습
- `network/`: 네트워크 및 소켓 통신 예제
- `atmega128/`: AVR ATmega128 실습 코드
- `bowlingGame/`: 볼링 점수 계산 실습

## 학습 기록

### 2026-03-09

- 구글 슬라이드 설치
- WSL 설치
- VS Code, Git 설치
- OS 설명: 리눅스, WSL2 사용
- VS Code Remote 연결
- `hello world` C 프로그램 작성
- `literal` 프로그램 작성
- `limit` 프로그램 작성

### 2026-03-10

- 연산자 프로그램 작성
- 보수의 개념 이해
- `?:`는 조건 연산자
- 예시:

```c
printf("%c 는 %s입니다", ch, isalphabet ? "알파벳" : "알파벳이 아님");
```

- `%c`는 사용자에게 전달받는 값
- 조건식 결과가 참이면 앞 문자열, 거짓이면 뒤 문자열 사용
- `||`는 OR 연산으로 두 조건 중 하나만 참이어도 참
- 예시:

```c
isalphabet = ('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z');
```

- `double`은 실수형 자료형
- 참고 자료: [C언어 기초 공부](https://opentutorials.org/module/3921/23508)

### 2026-03-11

#### 흐름 제어

##### 조건문

###### 1. `if ~ else` 문

- 조건의 참과 거짓에 따라 다른 코드 블록 실행
- 형식:

```c
if (조건) {
    // 조건이 참일 때 실행
} else {
    // 조건이 거짓일 때 실행
}
```

- 중첩 가능: `if` 안에 또 다른 `if` 사용 가능
- 삼항 연산자: `조건 ? 참값 : 거짓값`

###### 2. `switch` 문

- 하나의 값에 대해 여러 `case`를 비교
- `break`가 없으면 아래 `case`도 계속 실행
- 형식:

```c
switch (값) {
    case 1:
        // 값이 1일 때
        break;
    case 2:
        // 값이 2일 때
        break;
    default:
        // 어떤 case도 매칭되지 않을 때
        break;
}
```

- `if`문과 다르게 매칭된 `case`부터 실행
- `break`를 빼먹지 않기

##### 반복문

###### 1. `for` 문

- 횟수가 정해진 반복에 적합
- 형식: `for (초기화; 조건; 증감식)`
- 실행 흐름: 초기화 -> 조건검증 -> 본문 -> 증감식 -> 조건검증

```c
for (int i = 0; i < 10; ++i) {
    // i가 0부터 9까지 10번 실행
}
```

- `++i`: 선행 증가
- `i++`: 후행 증가

###### 2. `while` 문

- 조건이 참인 동안 반복
- 형식: `while (조건)`
- 조건이 처음부터 거짓이면 한 번도 실행 안 함

```c
while (조건) {
    // 조건이 true인 동안 반복
}
```

###### 3. `do ~ while` 문

- 최소 한 번은 실행 보장
- 형식: `do { ... } while (조건);`
- 조건이 뒤에 위치

```c
do {
    // 최소 한 번 실행
} while (조건);
```

###### 4. 중첩 `for` 문

- `for` 문 안에 또 다른 `for` 문
- 주로 2차원 배열, 구구단 등에서 사용

##### 제어 키워드

- `break`: 현재 반복문 또는 `switch` 블록 탈출
- `continue`: 현재 반복을 건너뛰고 다음 반복으로 이동
- `return`: 함수 종료 및 값 반환

##### 실습 예제

- `passFail.c`: `if ~ else`로 합격/불합격 판단
- `scoreGradeSwitch.c`: `switch`로 점수 등급 매기기
- `one2TenSum.c`: `for` 문으로 1~10 합계
- `one2TenWhile.c`: `while` 문으로 1~10 출력

##### 변수

###### 전역 변수

- 함수 외부에서 선언
- 프로그램 전체에서 사용 가능
- 메모리의 Data 영역에 저장

###### 지역 변수

- 함수 내부에서 선언
- 해당 함수 내에서만 사용 가능
- 메모리의 Stack 영역에 저장

###### 범위

- 변수가 접근 가능한 영역
- 중괄호 `{}` 내에서 선언된 변수는 그 블록 내에서만 유효

##### 프로그래머스 사이트 난이도 0 C 언어 문제 풀이

배열 `array`

- 타입의 묶음
- 예: `int`, `char`, `float`, 사용자 정의 타입도 묶을 수 있음
- 변수명 뒤에 `[]`를 사용
- 예: `int arr[10]`
- 메모리 범위를 넘으면 안 됨
- `n`개의 원소면 접근 범위는 `0 ~ n - 1`

#### 배열 간략 설명

##### 정의

- 동일한 타입의 여러 값을 하나의 변수에 저장하는 자료구조
- 메모리에 연속적으로 배치됨

##### 선언 및 사용

```c
int arr[5];
arr[0] = 10;
arr[4] = 50;
```

##### 중요 특성

- 인덱스는 0부터 시작
- `n`개 요소의 인덱스 범위는 `0 ~ n - 1`
- 선언한 크기를 초과하면 버그 발생
- 초기화 예시:

```c
int arr1[5] = {1, 2, 3, 4, 5};
int arr2[] = {1, 2, 3};
```

##### 실습 예제: `lotto.c`

```c
int lotto[6];
lotto[i] = (rand() % 45) + 1;
```

#### 오늘 작성한 배열 활용 코드 예제

##### 1. `lotto.c` - 중복 없는 로또 번호 생성

```c
int lotto[6];

for (int i = 0; i < 6; ++i) {
    lotto[i] = (rand() % 45) + 1;

    for (int j = 0; j < i; j++) {
        if (lotto[i] == lotto[j]) {
            i--;
            break;
        }
    }
}
```

- 배열에 생성된 번호를 저장하고 이전 번호와 비교해 중복 제거

##### 2. `finMax.c` - 배열에서 최대값 찾기

```c
#define MAXINDEX 50
int nums[MAXINDEX];

for (int i = 0; i < MAXINDEX; ++i) {
    nums[i] = rand() % 1000;
}

int max = nums[0];
for (int i = 0; i < MAXINDEX; ++i) {
    if (max < nums[i]) {
        max = nums[i];
    }
}
```

- 배열을 순회하며 최대값 탐색

##### 3. `sumArray.c` - 배열 요소 총합 구하기

```c
int num[10];

for (int i = 0; i < 10; ++i) {
    num[i] = rand() % 6 + 1;
}

int sum = 0;
for (int i = 0; i < 10; ++i) {
    sum += num[i];
}
```

- 배열 전체를 순회하며 누적합 계산

##### 4. `sumMatrix.c` - 2D 배열의 총합

```c
int matrix[3][4] = {
    {1, 2, 3, 4},
    {11, 12, 13, 14},
    {21, 22, 23, 24}
};

int sum = 0;
for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 4; ++j) {
        sum += matrix[i][j];
    }
}
```

- 중첩 `for` 문으로 2차원 배열 순회

### 2026-03-12

#### 정렬

- `swap`은 데이터의 순서를 바꾸는 동작

함수 원형의 규칙:

- `TYPE 식별자`
- 식별자 예: `printf(type 변수명)`
- `()` 괄호 안은 argument
- `TYPE`은 return type

```c
TYPE 식별자(argument)
{
    실제코드
    return 값;
}
```

#### 메모리

- 스택 메모리: 프로그램 실행 중 함수 호출 시 쌓이는 메모리
- `return` 키워드가 변수를 메인으로 넘겨주고 함수가 끝나면 지역 변수 메모리는 사라짐

#### 선택 정렬

1. 첫 자리를 알맞게 배치하기 위해 `n - 1`번 순회
2. 두 번째 자리를 알맞게 배치하기 위해 `n - 2`번 순회
3. 10개의 데이터라면 1부터 9까지의 합만큼 연산이 이루어짐

#### 버블 정렬

- 선택 정렬은 하나의 인덱스를 기준으로 탐색
- 버블 정렬은 비교하는 인덱스가 위로 올라감
- 대략 `n^2 / 2`

#### 포인터

- 무언가를 가리키는 변수
- 주소를 가지고 있어야 가리킬 수 있음
- 주소값을 저장하는 변수

포인터 변수 선언 예시:

```c
int *a;
```

기본 사용 흐름:

1. 주소 얻기: `a = &x`
2. 값 접근: `*a`

왜 쓰나:

- 함수에서 값 변경
- 배열/문자열 접근
- 동적 메모리 처리

주의:

- 초기화하지 않은 포인터 사용 금지
- 해제된 메모리를 가리키면 오류 발생

참조 연산자:

- `&`: 주소 연산자
- `*`: 역참조 연산자

참고 자료: [포인터 개념](https://sejong-kr.libguides.com/c.php?g=942235&p=6822366)

포인터를 사용한 구조:

1. 함수: 함수 포인터는 함수를 가리킴
2. 배열: 배열명은 포인터처럼 동작

함수의 인자로 `*`를 쓰는 5가지 상황:

1. 호출하는 쪽의 변수를 호출당하는 쪽에서 변경할 때
2. 배열을 인자로 넘길 때
3. 구조체를 인자로 넘길 때
4. 사용자 정의 연산 함수를 인자로 넘길 때
5. 임의의 자료를 `void *`로 넘길 때

예시:

```c
int main(void) {
    int x = 10, y = 20;
    swap(&x, &y);

    int arr[5] = {1, 2, 3, 4, 5};
    int sum = sum_array(arr, 5);

    struct Point p = {0, 0};
    move_point(&p, 3, 4);

    int result = apply(add, 3, 4);

    dump_bytes(&x, sizeof(x));

    return 0;
}
```

### 2026-03-13

- `type* 식별자`
- `type *식별자`
- 둘 다 사용 가능
- 배열을 인자로 넘길 때는 index 또는 크기를 같이 넘겨야 한다

정렬과 자료구조:

- 선택 정렬: `n^2 / 2`
- 버블 정렬: `n^2 / 2`
- `qsort`: `n ~ n^2 / 2`
- indexing 개념 정리

### 2026-03-16 week 2

#### 분할 컴파일

- 기능별로 파일을 관리할 수 있다
- 코드 재사용을 쉽게 할 수 있다
- 라이브러리 배포로도 이어질 수 있다

#### 구조체와 타입

- 구조체 -> 객체 지향 언어의 class와 비슷한 역할
- `struct`: 사용자 정의 타입
- 데이터를 묶어서 다룰 때 사용
- 새로운 데이터 형태를 만들고 싶을 때 사용
- `typedef`: 타입에 별명을 붙여 가독성을 높여준다
- 사용자 정의 타입은 대문자로 작성

#### 공용체 `union`

- 두 가지 이상의 타입 사용 가능
- 메모리를 최대한 아낄 때 사용
- 하나의 메모리에 여러 방식으로 접근

#### 열거형 `enum`

- `switch case` 문과 많이 쓰인다
- `enum`으로 작성되는 상수들은 기본적으로 `int`

#### 파일 디스크립터 `fd`

- 리눅스에서 열려 있는 파일을 다룰 때 사용
- 파일을 열면 `int` 값으로 관리

기본 표준 입출력 번호:

- `0`: 입력, 키보드
- `1`: 출력, 화면
- `2`: 에러 출력

#### 표준 입출력 함수

- 헤더: `<stdio.h>`
- 입력: `scanf`, `fscanf`, `getchar`, `fgetc`
- 출력: `printf`, `fprintf`, `putchar`, `fputc`

### 2026-03-17

- 구조체는 선언을 따로 하지 않아도 되는 경우가 있다
- 변수 선언만 해주면 된다

#### 표준 입출력 함수 정리

- 헤더: `#include <stdio.h>`
- 입력/출력 스트림: `stdin`, `stdout`, `stderr`

문자/문자열 입력:

- `getchar()`: 표준 입력에서 문자 1개 읽기
- `fgetc(FILE *fp)`: 지정 파일에서 문자 1개 읽기
- `gets()`: 사용 금지
- `fgets(char *buf, int n, FILE *fp)`: 안전한 문자열 입력
- `scanf("형식", &var)`: 형식 입력
- `fscanf(FILE *fp, "형식", &var)`: 파일 형식 입력

문자/문자열 출력:

- `putchar(int c)`: 문자 1개 출력
- `fputc(int c, FILE *fp)`: 파일에 문자 1개 출력
- `puts(const char *s)`: 문자열 출력 후 개행
- `fputs(const char *s, FILE *fp)`: 파일에 문자열 출력
- `printf("형식", ...)`: 형식 출력
- `fprintf(FILE *fp, "형식", ...)`: 파일에 형식 출력

버퍼/스트림 제어:

- `fflush(FILE *fp)`: 출력 버퍼 비우기
- `fopen`, `fclose`: 파일 열기/닫기

간단 사용 예:

```c
char name[32];
printf("name: ");
fgets(name, sizeof(name), stdin);
printf("hello %s", name);
```

#### 동적 할당

- `dynamic allocate`
- heap 영역에 메모리를 확보할 때 사용
- 메모리는 runtime에서 할당된다

### 2026-03-18

- file descriptor를 붙여서 디바이스를 관리한다
- `FILE`은 핵심적인 built-in 구조체
- `malloc`을 사용한 후 `free`를 반드시 써야 한다
- 그렇지 않으면 메모리 누수가 일어난다

추가 함수:

- `calloc`
- `realloc`: 큰 메모리 확보, 데이터 이동, 기존 메모리 해제

자료구조:

- 선형 자료구조
- 배열
- 리스트 `linked list`
- 스택 `stack`: first in last out
- 큐 `queue`: first in first out

비선형 자료구조:

- 트리
- 그래프

### 2026-03-19

- IOT (Internet of Things) 펌웨어 -> MCU

### 2026-03-23

#### ATmega128A

![avr_microcontroller_summary](https://github.com/user-attachments/assets/e1d1d39d-ad86-49bc-8557-863d951dbc89)

##### 마이크로프로세서와 마이크로컨트롤러 비교

| 구분 | 마이크로프로세서 (MPU) | 마이크로컨트롤러 (MCU) |
| --- | --- | --- |
| 구성 | CPU를 단일 IC 칩으로 집적 | CPU + 메모리 + I/O를 한 칩에 집적 |
| 주변장치 | 별도 하드웨어 필요 | 내부에 함께 포함 |
| 용도 | 범용 컴퓨터 | 특수 목적 기기 제어 |
| 역사 | 1971년 Intel 4004 | 1975년 TI TMS1000 |

##### MCU 주요 특징 및 응용 분야

특징:

- I/O 강화
- 타이머/카운터 내장
- Bit 조작
- 소형화
- 저가
- 높은 신뢰성

응용:

- 산업: 모터, 로봇
- 가전: 밥솥, 세탁기
- 자동차: 점화, 연료 제어
- 통신: 휴대폰
- 군사 분야

발전 방향:

- 고성능: 32bit ARM
- 다기능
- 소형화
- 저전력
- 저가격

##### AVR 마이크로컨트롤러

개요:

- ATMEL사가 1997년 발표한 8비트 제어용 마이크로프로세서
- Alf-Egil Bogen + Vegard Wollan의 RISC 기술에서 AVR 명명
- 단기간에 8051, PIC을 능가하는 인기 획득

주요 특징:

- RISC 구조
- Harvard Architecture
- 32개 8bit 범용 레지스터
- CMOS (1.8~5.5V, 저전력)
- 1MHz당 1MIPS 처리속도
- ISP 기능

시리즈 종류:

| 시리즈 | 특징 |
| --- | --- |
| Tiny | 8~24핀, 1K~2K Flash, 저속/저가 |
| Mega | 28~100핀, 8K~256K Flash, 고성능 |

##### ATMega128A 마이크로컨트롤러

핵심 사양:

- 8비트 AVR CPU
- 최대 16MHz 동작
- 동작 전압: 2.7~5.5V
- 패키지: 64핀 TQFP/MLF

메모리 구성:

- Flash: 128KB
- SRAM: 4KB
- EEPROM: 4KB
- 외부 메모리: 최대 64K
- Harvard 구조
- JTAG 포트 지원

주변장치:

- 타이머: 8bit x 2, 16bit x 2
- PWM: 8채널
- ADC: 8채널 10bit
- USART: 2개
- SPI, TWI(I2C)
- Watchdog 타이머

I/O 포트:

| 포트 | 기능 |
| --- | --- |
| 포트A | 주소/데이터 버스 |
| 포트B | SPI/PWM |
| 포트C | 주소 버스 |
| 포트D | 타이머/인터럽트 |
| 포트E | USART/비교기 |
| 포트F | ADC/JTAG |
| 포트G | 5bit/RTC |

Sleep modes:

- Idle
- ADC Noise
- Power-save
- Power-down
- Standby
- Extended Standby

정리 출처 메모:

- 엣지아이랩 AVR 마이크로 컨트롤러 1~15p 요약

### 2026-03-24

![실습 이미지 1](image.png)

![실습 이미지 2](image-1.png)

### 2026-03-25

## 인터럽트

### 개념

- CPU가 현재 실행 중인 작업을 잠시 멈추고 긴급한 이벤트를 먼저 처리한 후 원래 작업으로 돌아오는 메커니즘
- 폴링과 달리 CPU가 계속 상태를 확인할 필요 없이 이벤트 발생 시에만 반응

### ATmega128 외부 인터럽트 관련 레지스터

| 레지스터 | 역할 |
| --- | --- |
| `EICRA` | 외부 인터럽트 0~3 트리거 방식 설정 |
| `EICRB` | 외부 인터럽트 4~7 트리거 방식 설정 |
| `EIMSK` | 각 외부 인터럽트 허용/차단 |
| `EIFR` | 인터럽트 플래그 |
| `SREG` | 상태 레지스터, I 비트가 전역 인터럽트 허용 플래그 |

### 트리거 방식 (ISCn1:ISCn0)

| 값 | 의미 |
| --- | --- |
| `00` | Low 레벨 |
| `01` | 변화 감지 |
| `10` | 하강 엣지 |
| `11` | 상승 엣지 |

### 주요 함수와 매크로

```c
sei();          // 전역 인터럽트 허용
cli();          // 전역 인터럽트 차단
_BV(비트이름)   // 해당 비트를 1로 설정하는 매크로
ISR(벡터이름)   // 인터럽트 서비스 루틴 정의
```

### 실습 예제 요약

`interrupt1.c`

- 버튼(INT4, 상승 엣지)으로 LED 이동 일시정지/재개

```c
EICRB = _BV(ISC41) | _BV(ISC40);
EIMSK = _BV(INT4);
sei();

ISR(INT4_vect) {
    cli();
    time_stop = !time_stop;
    sei();
}
```

`interrupt_fnd.c`

- 버튼 두 개(INT4 증가, INT5 감소)로 FND 숫자 제어

```c
EICRB = _BV(ISC41) | _BV(ISC40) | _BV(ISC51) | _BV(ISC50);
EIMSK |= _BV(INT4) | _BV(INT5);
sei();

ISR(INT4_vect) { cnt = (cnt + 1) % 10; }
ISR(INT5_vect) { cnt = (cnt - 1 + 10) % 10; }
```

### `volatile` 키워드

- 인터럽트 핸들러와 메인 루프가 공유하는 변수에는 반드시 `volatile` 선언
- 컴파일러 최적화로 변수 값이 캐시되는 것을 방지

```c
volatile uint8_t time_stop = 0;
volatile int8_t cnt = 0;
```

## 2026-03-26

### 타이머/PWM

- `timer2ledleftright.c`: Timer2 오버플로우 ISR, LED 비트 좌우 시프트 (PORTC 0~3비트, 1024분주, 0.3초 주기)
- `pwmled.c`: Timer0 Fast PWM, LED 밝기 페이드 (`OCR0 = 0~255` 자동 왕복)
- `cds_fnd.c`: Timer0 PWM + CDS ADC 연동 밝기 자동조절 + FND/LCD 표시

### 통신

- `uart1.c`: UART0(115200bps) 수신 -> `'0' ~ '9'` FND 7세그먼트 출력 (PORTA)
- `uart2.c`, `uart3.c`: USART 추가 실습

### 메모리/디스플레이

- `external_eeprom2.c`: SPI(AT25160) 3버퍼 읽기(`0x0100 ~ 0x0300`) -> LCD 라인별 스크롤 출력

### 센서/모터

- `dc_pwm_vr.c`, `dcpwm.c`, `dc_motor.c`: DC 모터 PWM 속도/방향 제어 (VR 연동)
- `i2c_tempHumi.c`: I2C SHT20 온습도 센서 (TWI_driver 활용)

### 기타

- `pwmbuzzer.c`: PWM 부저 사운드 출력
- `lcd1.c`: LCD 기본 테스트

### 2026-03-27

- 모터의 종류
- dc, 서보, 스텝, 하모닉 드라이브, QDD 등  
  