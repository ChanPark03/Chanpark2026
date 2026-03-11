#include <stdio.h>      // 표준 입출력 라이브러리
#include <stdlib.h>    // rand(), srand() 사용
#include <time.h>      // time() 사용

int main(void)
{
    int lotto[6];      // 로또 번호 6개 저장할 배열
    int i, j, temp;      // i: 루프 인덱스, j: 중복 검사용, temp: 임시 저장 (현재 미사용)
    
    srand(time(NULL)); // 랜덤 시드 설정 (현재 시간 기준)

    for(int i=0; i < 6; ++i){           // 6번 반복
        lotto[i] = (rand() % 45) + 1;  // 1~45 랜덤 번호 생성
        //중복검사
        for (int j = 0; j < i; j++){   // 기존 번호와 비교
                if(lotto[i] == lotto[j]){  // 중복이면
                    i --;              // 다시 생성
                    break;
                }
        }
    }
    for(int i=0; i<6; i++) {
   printf("%d ", lotto[i]);
    }  // 각 번호 출력
    printf("\n");
    return 0;
}
