
#include <stdio.h>
#include <stdlib.h>

int main(void)
{ 
    int score;
    char grade = 'F'; // grade 변수를 선언하고 초기값으로 'F'를 할당합니다. 이 변수는 점수에 따른 등급을 저장하는 데 사용됩니다. 예를 들어, score가 95인 경우, grade는 'A'로 변경됩니다. 만약 score가 85인 경우, grade는 'B'로 변경됩니다. 이렇게 하면 기본적으로 모든 점수는 'F'로 시작하지만, 조건에 따라 등급이 업데이트됩니다.
    printf("점수를 입력하세요 : \n");
    scanf("%d", &score);

    if (score >= 90)
    {
        grade ='A';
    }

    else if (score >= 80)
    {
        grade = 'B';
    
    }
    else if (score >= 70)
    {
        grade = 'C';
    
    }
    else if (score >= 60)
    
    {
        grade = 'D';
    }
    
   
    

    printf("%d 는 %c 등급입니다.\n", score, grade);
    return 0;
}