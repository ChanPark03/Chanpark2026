#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define SIZE 3 

void generate_number(int* question);
void input_numbers(int* answer);
bool check_result(const int* question, const int* answer, int* strike, int* ball);



int main(){

    int question[SIZE] = {0};

    int answer[SIZE];
    int count = 0;
    int strike, ball = 0;
    int i, j, temp;
    
    generate_number(question);  
    
    

    while(true){
    input_numbers(answer);
    count++;

        if (check_result(question, answer, &strike, &ball))
        {break;}

    }

    printf("축하합니다. 시도횟수는 %d 입니다.\n", count);
    return 0;
}

void generate_number(int* question)
{
    srand(time(NULL));
    for(int i=0 ; i < SIZE; ++i)
    {
        question[i] = rand() % 9 + 1;
        for(int j=0; j< SIZE; ++j){
            if ( i == j ){
                continue;
            }
            if (question[j] == question[i]){
                --i;
                break;
            }
        }
    }
    for (int i = 0; i < SIZE; ++i){
        printf("%d", question[i]);
    }
}
void input_numbers(int* answer)
{

       printf("1부터9까지 서로다른 %d가지 숫자를 입력하시오:\n ", SIZE);
       for (int i = 0; i < SIZE; ++i){
            scanf("%d", &answer[i]);
       }

        
}

bool check_result(const int* question, const int* answer, int* strike, int* ball)
{
    if ((question[1]== answer[1]) || (question[2] == answer [2]) || (question[3] == answer [3])) {
        ++strike;
    }
    
    if ((question[1]== answer[2] ) ||  (question[1]== answer[3]) ||  (question[3]== question[2])) {
        ++ball;
    }

    
    
    
    
    return true;
}