//입력받은 char가 알파벳인지 아닌지 출력하세요!
#include<stdio.h>
#include<stdbool.h>

int main(void) 
{
  char ch;
  printf("char를 입력하세요:"); // 사용자에게 char 입력을 요청하는 메시지를 출력
    scanf("%c", &ch); 
bool isalphabet;
isalphabet = ('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z'); 
printf("%c 는 %s입니다", ch, isalphabet ? "알파벳" : "알파벳이 아님"); 

return 0;
}   