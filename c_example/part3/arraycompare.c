#include <stdio.h>   // printf 함수를 쓰기 위한 표준 입출력 헤더
#include <stdbool.h> // bool, true, false를 쓰기 위한 헤더

// 배열을 비교하는 함수 선언(원형)
// int *array  : 첫 번째 배열의 시작 주소(첫 요소의 주소)
// int *array2 : 두 번째 배열의 시작 주소
// int index   : 비교할 요소 개수(배열 길이)
// int *diff   : 서로 다른 위치(인덱스)를 저장할 변수의 주소
// 반환값      : 모두 같으면 true, 하나라도 다르면 false
bool arrayCompare(int *array, int *array2, int index, int *diff);

int main(void)
{
    // 첫 번째 배열: 5개의 정수가 순서대로 저장됨
    int nums1[] = {1, 3, 7, 4, 9};

    // 두 번째 배열: nums1과 같은 값
    int nums2[] = {1, 3, 7, 4, 9};

    // 세 번째 배열: nums2와 일부 값이 다름
    int nums3[] = {1, 3, 7, 9, 5};

    // (nums1 == nums2) 같은 배열 전체 비교는 C에서 불가능
    // 따라서 함수를 통해 요소를 하나씩 비교해야 함

    int diff = 0; // 다른 인덱스를 저장할 변수 (처음은 0으로 초기화)

    // nums1과 nums2를 길이 5로 비교
    // diff의 주소(&diff)를 넘겨 함수가 값을 바꾸도록 함 (참조 전달)
    if (arrayCompare(nums1, nums2, 5, &diff))
    {
        // true이면 모든 요소가 같다는 뜻
        printf("두 배열은 같다.\n");
    }
    else
    {
        // false이면 diff에 저장된 위치에서 다름
        printf("두 배열은 같지 않다. %d index가 다르다.\n", diff);
    }

    // nums2와 nums3도 같은 방식으로 비교
    if (arrayCompare(nums2, nums3, 5, &diff))
    {
        printf("두 배열은 같다.\n");
    }
    else
    {
        printf("두 배열은 같지 않다. %d index가 다르다.\n", diff);
    }

    return 0; // main 함수 정상 종료
}

// 배열 비교 함수 정의
bool arrayCompare(int *array, int *array2, int index, int *diff)
{
    int i; // 반복 인덱스 선언

    // 0부터 index-1까지 순서대로 값 비교
    for (i = 0; i < index; ++i)
    {
        // 같은 위치의 값이 다르면 즉시 중단
        if (array[i] != array2[i])
        {
            break; // 다른 값을 발견했으므로 루프 종료
        }
    }

    // 루프가 끝난 시점의 i를 diff에 저장
    // - 모두 같으면 i == index
    // - 다르면 i는 첫 번째로 다른 위치
    *diff = i;

    // i가 index이면 끝까지 모두 같았다는 뜻
    if (i == index)
    {
        return true; // 두 배열이 동일
    }
    else
    {
        return false; // 한 요소라도 다름
    }
}
