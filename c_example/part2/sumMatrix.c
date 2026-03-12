#include <stdio.h>  // 표준 입출력 라이브러리 (printf 함수 사용)

int main(void)
{
    // 2D 배열 (행렬): 행 x 열
    // 3행 4열 = 총 12개 요소
    // matrix[0] = 첫 번째 행, matrix[1] = 두 번째 행, matrix[2] = 세 번째 행
    int matrix[3][4] = {
        {1, 2, 3, 4},       // 행 0: matrix[0][0]=1, matrix[0][1]=2, matrix[0][2]=3, matrix[0][3]=4
        {11, 12, 13, 14},   // 행 1: matrix[1][0]=11, matrix[1][1]=12, matrix[1][2]=13, matrix[1][3]=14
        {21, 22, 23, 24},   // 행 2: matrix[2][0]=21, matrix[2][1]=22, matrix[2][2]=23, matrix[2][3]=24
    };
    
    // sum 변수: 모든 행렬 요소의 총합을 저장
    // 더하기 전에 0으로 초기화
    int sum = 0;
    
    // 중첩 for 문: 외부 루프는 행, 내부 루프는 열
    // i는 행 인덱스 (0, 1, 2)
    for (int i = 0; i < 3; ++i) {
        // j는 열 인덱스 (0, 1, 2, 3)
        for (int j = 0; j < 4; ++j) {
            // 현재 요소를 sum에 더함
            // matrix[i][j]는 행 i, 열 j에 있는 요소에 접근
            sum += matrix[i][j];  // sum = sum + matrix[i][j]와 동일
        }
    }
    
    // 총합 출력
    printf("총합: %d\n", sum);
    
    return 0;  // 프로그램 정상 종료
}
