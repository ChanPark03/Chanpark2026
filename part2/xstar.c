//*   *
// * *
//  *
// * *
//*   *
#include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 5; ++i){ 
        for (int j = 1; j <= 5; ++j){
            if(i+j ==6 || i ==j){
                printf("*");
            }else{
                printf(" ");
            }
        }
        //printf((i+j==6||i==j)?"*" : " "); 삼항 연산자를 이용한 코드. 위에 코드와 동일하지만 가독성이 떨어짐 . 대신 짧음
        printf("\n");
    }
    return 0;
}







