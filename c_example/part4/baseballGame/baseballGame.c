#include "baseballGame.h"

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
   // for (int i = 0; i < SIZE; ++i){
        //printf("%d", question[i]);
   // }
}
void input_numbers(int* answer)
{

       printf( "1부터9까지 서로다른 %d가지 숫자를 입력하시오:\n ", SIZE);
       for (int i = 0; i < SIZE; ++i){
            scanf("%d", &answer[i]);
       }

        
}

bool check_result(const int* question, const int* answer, int* strike, int* ball)
{
  *strike = 0;
  *ball = 0;

  for (int i = 0; i < SIZE; ++i){
    for (int j = 0; j < SIZE; ++j){
        if (question[i] == answer[j]){
            if (i == j){
                ++(*strike);

            }
            else ++(*ball);
        }
    }
  

}

    
    return (*strike == SIZE);
}