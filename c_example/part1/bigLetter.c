// 대문자인지 소문자인지 확인하기
#include <stdio.h> //stdio.h는 표준 입출력 함수들을 사용하기 위해 포함하는 헤더 파일입니다. printf와 scanf 함수를 사용하기 위해 필요합니다.
#include <stdbool.h>
int main(void)
{
    char ch;
    printf("char를 입력하세요:"); // 
    scanf("%c", &ch); 

    bool isBig; 
    isBig = ('A' <= ch && ch <= 'Z'); //  &&는 
    printf("%c 는 %s입니다. :", ch, isBig ? "대문자" : "소문자");
    return 0;
}

