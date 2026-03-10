#include <stdint.h>
#include <stdio.h>
#define BOLD (0x01 << 1)
#define ITALIC (0x01 << 2)
#define UNDERLINE (0x01 << 3)
#define SHADOW (0x01 << 4) 


int main(void)
{
   
    uint8_t attr; 
    attr = attr ^ attr; 
    attr = attr | BOLD; 
    printf("attr: 0x%02x\n", attr); 
    attr = attr | (ITALIC + SHADOW); 
    printf("attr: 0x%02x\n", attr); 
    attr = attr & (~BOLD); 
    printf("attr: 0x%02x\n", attr); 
    if (attr & BOLD) // attr의 BOLD 비트가 1인지 여부를 판단하여 조건문 실행 // attr과 BOLD를 AND 연산하여 BOLD 비트가 1이면 참이 되고, 그렇지 않으면 거짓이 됨
    {
        printf("BOLD 옵션이 활성화 되었습니다.");
    }else // attr의 BOLD 비트가 0인 경우 실행
    {
        printf("BOLD 옵션이 비활성화 되었습니다.");
    }

    if ((attr & ITALIC) >>1) // >>1은 attr과 ITALIC을 AND 연산하여 ITALIC 비트가 1인지 여부를 판단한 후, 결과를 1비트 오른쪽으로 시프트하여 ITALIC 비트의 값을 얻음 // ITALIC 비트가 1이면 참이 되고, 그렇지 않으면 거짓이 됨
      {  printf("ITALIC 옵션이 활성화 되었습니다.");
    }else // attr의 ITALIC 비트가 0인 경우 실행
    {
        printf("ITALIC 옵션이 비활성화 되었습니다.");
    }
    return 0; 

}
