#include <stdio.h>

int main(void)
{
    int nums[] = {1, 2, 3, 4, 5}; // 배열: int 5개가 연속된 메모리에 저장
    int *p;                       // int를 가리키는 포인터 선언

    // 배열 이름은 첫 번째 요소의 주소로 변환됨
    p = nums;      // nums == &nums[0]
    p = &nums[0];  // 위 줄과 동일한 의미

    // 포인터 증가: 다음 요소로 이동 (int 크기만큼 주소가 증가)
    ++p;           // p는 nums[1]을 가리킴

    // 현재 p가 가리키는 값 출력
    printf("*p : %d\n", *p); // nums[1] 값인 2가 출력됨

    return 0;
}
