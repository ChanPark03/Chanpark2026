//피라미드 형태 출력 
//   *****
//  *******
// *********

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    system("clear");
    //system("ls -al");
    int height;
    printf("피라미드의 높이를 넣으세요: \n");
    scanf("%d", &height);

    for(int i=1; i<= height; ++i){
        for(int j = 1; j <  height - i; ++j){
            printf(" ");

         }
         for (int j = 1; j <= 2*i - 1; ++j){
            printf("*");
         }
         sleep(1); // 프로그램에 딜레이를 주는 명령어    stdilib  에 포함되어있음.
       printf("\n");
    }
    return 0;
}