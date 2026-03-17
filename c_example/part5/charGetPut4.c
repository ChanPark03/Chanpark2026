#include <stdio.h>   // 표준 입출력 함수(printf, putchar, putc, puts, fputs, fflush 등)를 사용하기 위한 헤더
#include <unistd.h>  // POSIX 함수(sleep)를 사용하기 위한 헤더

int main(void)
{
    char ch = 'a'; // 출력할 단일 문자

    printf("프로그램 시작\n"); // 시작 메시지 출력(줄바꿈 포함)

    putchar(ch);              // 표준 출력으로 문자 1개 출력(파일 스트림 지정 없음)
    fflush(stdout);           // 버퍼에 남아 있을 수 있는 출력 내용을 즉시 화면에 반영
    sleep(1);                 // 1초 대기(출력 타이밍을 구분하기 위함)

    printf("putchar 실행후\n"); // putchar 실행 후 메시지 출력

    putc(ch, stdout);         // stdout 스트림에 문자 1개 출력(putchar와 유사하지만 스트림 지정)
    fflush(stdout);           // stdout 버퍼 비우기
    sleep(1);                 // 1초 대기

    char *string1 = "스트링1 배열입니다."; // 출력할 문자열 리터럴(문자열 상수)

    puts(string1);            // 문자열 출력 후 자동으로 개행('\n')을 추가
    sleep(1);                 // 1초 대기

    printf("프로그램 끝입니다."); // 끝 메시지 출력(개행 없음)
    fputs(string1, stdout);    // 문자열 출력(개행 자동 추가 없음, 스트림 지정)

    return 0;
}

/*
표준 출력 함수 요약
- putchar(c): 표준 출력(stdout)에 문자 1개를 출력한다.
- putc(c, stream): 지정한 스트림에 문자 1개를 출력한다. (stdout이면 putchar와 유사)
- puts(s): 문자열을 출력하고 마지막에 자동으로 개행('\n')을 추가한다.
- fputs(s, stream): 지정한 스트림에 문자열을 출력한다. 개행은 자동 추가되지 않는다.
- printf(format, ...): 서식 지정자를 사용해 값을 문자열로 변환하여 출력한다.
- fflush(stream): 출력 버퍼를 즉시 비운다. stdout은 버퍼링되어 있어 필요 시 사용한다.
*/
