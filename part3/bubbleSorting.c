#include <stdio.h>

void swap(int *a, int *b);

int main(void){
    int nums[10] = {21, 43, 51, 43, 53, 23, 64, 25, 26, 90};
    int indexN = sizeof(nums) / sizeof(int);

    for (int i = indexN - 1; i >= 1; --i){
        for (int j = 0; j < i; ++j){
            if (nums[j] > nums[j + 1]){
                swap(&nums[j], &nums[j + 1]);
            }
        }
    }

    for (int i = 0; i < indexN; ++i){
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
