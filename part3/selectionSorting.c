#include <stdio.h> // printf 사용을 위한 표준 입출력 헤더

void swap(int *a, int *b); // 두 정수의 값을 서로 바꾸는 함수 선언

int main(void){
    int nums[10] = {21, 43, 51, 43, 53, 23, 64, 25, 26, 90}; // 정렬할 배열
    int indexN = sizeof(nums) / sizeof(int); // 배열의 원소 개수 계산

    for (int i = 0; i < indexN; ++i){ // 기준 위치 i를 하나씩 이동
        for (int j = i + 1; j < indexN; ++j){ // i 뒤쪽에서 더 작은 값을 찾음
            if (nums[i] > nums[j]){ // 현재 값보다 작은 값이 있으면
                swap(&nums[i], &nums[j]); // 두 값을 교환하여 더 작은 값을 앞으로 보냄
            }
        }
    } // 결과적으로 오름차순 정렬됨

    for (int i = 0; i < indexN; ++i){ // 정렬된 결과 출력
        printf("%d ", nums[i]);
    }
    printf("\n"); // 줄바꿈
    return 0; // 정상 종료
}

void swap(int *a, int *b){
    int tmp = *a; // a가 가리키는 값을 임시로 저장
    *a = *b; // b의 값을 a로 복사
    *b = tmp; // 임시값을 b로 복사하여 교환 완료
}
