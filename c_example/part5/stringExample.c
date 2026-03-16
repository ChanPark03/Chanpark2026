#include <stdio.h>
#include <string.h>

int main (void)
{
    char *ga = "dajsadjsadhasda";
    char *str = "wonderful tonight";

    int len = strlen(str);
    printf("len: %d\n", len);
    // strcpy 함수 
    char str2[200];
    strcpy(str2, ga);
    strcpy(str2, str);
    for(int i=0; i<200; ++i){
        printf("C%d: %c\n", i, str2[i]);
    }
    //strcmp 함수 string compare 
    if(strcmp(str2,str)==0){
        printf("str과 str2는 같다.\n");
    }else{
        printf("str과 str2는 다르다.\n");


    }
    // strcat 함수 //두문자를 앞뒤로 붙여놓음 
    char *str3 = "eric claption";
    strcat(str2, " - ");
    strcat(str2, str3);
    printf("str2: %s\n", str2);
    return 0;
}