#include <stdio.h>

int main (void)
{
    char ch;          // 단일 문자 저장용 변수
    char str[100];    // 문자열 입력을 받을 버퍼
    printf("문자를 입력하세요: ");
    ch = getc(stdin); // ch = fgetc(stdin); // ch = getchar(); // 표준 입력에서 문자 하나를 읽어 ch에 저장
    //ch = fgetc(stdin); // ch = getchar(); // 표준 입력에서 문자 하나를 읽어 ch에 저장 // getchar()는 버퍼링 없이 바로 입력을 받는 함수로, 엔터키를 누르지 않아도 입력이 처리됩니다. 하지만 getc(stdin)이나 getchar()는 버퍼링이 되어 있어 엔터키를 눌러야 입력이 처리됩니다.

    printf("%d, %d, %d", stdin->_fileno, stdout->_fileno, stderr->_fileno); // 각 스트림의 파일 디스크립터 번호 출력
    printf("입력한 문자는 %c입니다.\n", ch); 
    while (getchar() != '\n') // \n는 엔터키를 의미하며, 입력 버퍼에 남아있는 문자를 모두 제거하는 역할을 합니다. 이 루프는 사용자가 엔터키를 누를 때까지 계속해서 getchar()를 호출하여 입력 버퍼에서 문자를 읽어들이고, 그 문자가 '\n'이 될 때까지 반복합니다. 이렇게 함으로써 입력 버퍼에 남아있는 불필요한 문자들을 제거할 수 있습니다.
    {
        ch = fgetc(stdin); // 다음 문자를 하나 더 읽어보기
        printf("입력한 문자는 %c 입니다.\n", ch);
        scanf("%s", str); // 공백 전까지 문자열 읽기
        printf("입력한 문자열은 %s입니다.\n", str);
    }
    
    return 0;
}

/*
표준 입출력 함수 요약
- getchar(): 표준 입력(stdin)에서 문자 1개를 읽어 int로 반환. EOF(-1) 가능.
- getc(stream): 지정한 스트림에서 문자 1개를 읽어 int로 반환. stdin에 쓰면 getchar와 유사.
- fgetc(stream): getc과 동일 계열. 표준에선 동일 동작을 기대.
- putchar(c): 표준 출력(stdout)에 문자 1개를 출력.
- putc(c, stream): 지정한 스트림에 문자 1개를 출력.
- fputc(c, stream): putc과 동일 계열.
- printf(...): 서식 지정 출력. stdio 버퍼링의 영향을 받음.
- scanf(...): 서식 지정 입력. 공백 기준으로 잘라 읽는 동작에 주의.

추가 개념
- stdin, stdout, stderr: 표준 입력/출력/에러 스트림(파일 스트림 포인터).
- 버퍼링: 대부분 입력은 엔터(개행)를 기준으로 버퍼에 쌓였다가 읽힘.
- EOF: 입력 끝을 의미하며 함수 반환값으로 확인.
*/
