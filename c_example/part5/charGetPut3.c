// 표준입출력 - POSIX 표준을 지키는가? 지원하는가 ?

#include<stdio.h>

int main(void)
{
    //출력합니다.
    char *string1 = "배열입니다";
    char string2[100];
    printf("printf로 터미널에 출력합니다.! %s\n", string1);
    fprintf(stderr,"printf로 터미널에 출력합니다.! %s\n", string1 );
    sprintf(string2, "배열에 문자열을 출력합니다.%d\n", 15); //strcpy 와비슷하게 배열에 출력을 집어 넣는다 
    printf("%s", string2);
    return 0;
}