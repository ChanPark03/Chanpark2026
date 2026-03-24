#include <avr/io.h>

int main (void)
{
    DDRC = 0x0F; // led 설정
    DDRE = 0x00; // 스위치 설정 
    uint8_t switch0;

    while(1){
       switch0 = PINE;
        PORTC = switch0 >> 4;
    }
    return 0;

}