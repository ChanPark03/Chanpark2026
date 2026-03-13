/* ========================================
   serial.c - 시리얼 넘버 생성 구현 파일
   ======================================== */

#include "serial.h"

/* 전역 static 카운터를 사용해 증가하는 시리얼 넘버 반환
   - count는 이 파일 내에서만 접근 가능 (static)
   - 매 호출마다 count 증가 후 반환 */
int getSerialNumber(void)
{
    static int count = 0; 
    int result = count;
    ++count;
    return result;
}
