#include "bowling.h"
#include <stdio.h>

void print_main_menu();

int main(void) {
    int choice;

    while (1) {
        print_main_menu();
        if (scanf("%d", &choice) != 1) {
            printf("잘못된 입력입니다. 숫자를 입력해주세요.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                play_game();
                break;
            case 2:
                view_records();
                break;
            case 3:
                printf("'최고 점수 보기'는 아직 구현되지 않았습니다.\n");
                break;
            case 4:
                printf("'월별 통계 보기'는 아직 구현되지 않았습니다.\n");
                break;
            case 0:
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 선택입니다. 0-4 사이의 숫자를 입력해주세요.\n");
        }
        printf("\n");
    }

    return 0;
}

void print_main_menu() {
    printf("=== 볼링 게임 시스템 ===\n");
    printf("1. 게임 플레이\n");
    printf("2. 내 기록 보기\n");
    printf("3. 최고 점수 보기\n");
    printf("4. 월별 통계 보기\n");
    printf("0. 종료\n");
    printf("선택: ");
}
