#include <stdio.h>
#include <stdlib.h> //atoi 함수를 사용하기 위해 stdlib.h 헤더 파일을 포함합니다. atoi 함수는 문자열을 정수로 변환하는 함수입니다. 예를 들어, "123"이라는 문자열을 atoi 함수에 전달하면, 123이라는 정수로 변환됩니다.

    int main(int argc, char *argv[]) //main 함수의 매개변수로 argc와 argv를 사용합니다. argc는 명령줄 인자의 개수를 나타내며, argv는 명령줄 인자들을 문자열 배열로 저장하는 포인터입니다. 예를 들어, 명령줄에서 "myprogram 85"와 같이 실행하면, argc는 2가 되고, argv[0]은 "myprogram"이 되며, argv[1]은 "85"가 됩니다.
    //printf("점수를 입력하시오 : \n");
    //scanf("%d", &score);
{
    int score = atoi(argv[1]); // atoi 함수를 사용하여 argv[1]에 저장된 문자열을 정수로 변환하여 score 변수에 저장합니다. 예를 들어, 명령줄에서 "myprogram 85"와 같이 실행하면, argv[1]은 "85"가 되고, atoi("85")는 85라는 정수로 변환되어 score 변수에 저장됩니다.
    if (score >= 60)
    {
        printf("점수: %d --- 합격\n", score);

    }
    else
    {
        printf("점수: %d --- 불합격\n", score);
    }
   
    return 0;
}