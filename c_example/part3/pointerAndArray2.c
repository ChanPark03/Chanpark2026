#include<stdio.h>

int main(void)
{
    int nums[] = {1, 2, 3, 4, 5}; // 정수 배열 선언 (연속된 메모리에 저장)
    int *p; // int를 가리키는 포인터 변수

    p = nums; // 배열 이름은 첫 번째 요소의 주소로 변환됨 (p == &nums[0])
    p=p; // 자기 대입 (동작 변화 없음)
    *(p+1) = *(p + 2); // nums[1]에 nums[2] 값을 복사
    (p)= (p+1); // 포인터를 한 칸 이동 (이제 nums[1]을 가리킴)
    for (int i = 0; i < 5; ++i) // 값 출력 루프
    {
        printf("nums[%d] : %d\t", i , nums[i]); // 배열 인덱스 접근
        printf("*(p+%d) : %d\t", i, *(p + i)); // 포인터 산술 접근
        printf("*(nums+%d): %d\t", i, *(nums + i)); // 배열명으로 포인터 산술
        printf("p[%d] : %d\n", i , p[i]); // 포인터도 배열처럼 인덱싱 가능

    }
     for (int i = 0; i < 5; ++i) // 주소 출력 루프
     {
        // nums는 배열의 시작 주소(&nums[0])이므로 항상 같은 주소가 출력됨
        printf("nums: %p\t",  nums);

        // p는 nums[1]을 가리키고 있으므로 p+i는 그 다음 요소들의 주소
        printf("*(p+%d) : %p\t", i, (p + i)); // 포인터 산술 결과 주소

        // nums+i는 배열 시작 주소에서 i만큼 이동한 주소
        printf("*(nums+%d): %p\t", i, (nums + i));

        // p[i]의 실제 주소 ( == p+i )
        printf("p[%d] : %p\n", i , &p[i]);
     }
    return 0;
}
