/* ========================================
   main.c - 시리얼 넘버 테스트 메인 파일
   ======================================== */

#include <stdio.h>
#include "serial.h"

/* 시리얼 넘버 생성기를 10회 호출해 출력
   - 현대자동차 스타일 포맷: HYUNDAI_MOTOR_0000000000 ~ 0000000009 */
int main()
{
    for (int i = 0; i < 10; ++i)
    {
        int num = getSerialNumber();
        printf("HYUNDAI_MOTOR_%010d\n", num);
    }
    return 0;
}
