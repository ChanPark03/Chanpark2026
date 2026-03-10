#include <stdio.h>

int main(void) 
 {
    int length;
    int height;
    int area;

    printf("삼각형의  길이와 높이를 입력하세요: ");
    scanf("%d %d", &length, &height); // 사용자로부터 삼각형의 밑변 길이와 높이를 입력받아 length와 height 변수에 저장
    area = (length * height) / 2; // 삼각형의 면적을 계산하여 area 변수에 저장 // 삼각형의 면적 공식: (밑변 길이 * 높이) / 2
    printf("삼각형의 넓이는: %d\n", area); // 계산된 삼각형의 면적을 출력 // %d는 정수를 출력하는 서식 지정자

    return 0; // 프로그램 종료
    
    
}