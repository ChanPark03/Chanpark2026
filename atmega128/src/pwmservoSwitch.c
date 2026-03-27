// 버튼을 누르면 0도, 45도, 90도, 135 도 로 이동하게 작성하고 
//lcd 에도 각도가 표시되게 만들기. 

#include <lcd.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>

int main(void)
{
    // 서보 PWM 선 PE3
    DDRE = _BV(PE3);
    DDRA = 0xFF;
   PORTE |= _BV(PE4) | _BV(PE5);

    TCCR3A = _BV(COM3A1) | _BV(WGM31);
    TCCR3B = _BV(WGM33) | _BV(WGM32) | _BV(CS31);
    // 분주비 8, fast pwm , timer3 oc 3a

    ICR3 = 40000; // 20ms 50hz .. 2000000-> 1초 ?? -> 0.02초
    OCR3A = 3000; // 40000 : 20 ? : 2 2000 ~ 4000

    lcdInit();
    lcdClear();
    char buffer[16];
    uint8_t switch_flag = 0x03;
    int8_t degree = 0;
    int pulse_table[] = {2000, 2700, 3800, 4500};
    OCR3A = pulse_table[degree];

    while (1)
    {
         if(switch_flag != PINE >> 4){
        switch_flag = PINE >> 4;
        if (switch_flag == 0x01)
        {
            degree++;
        }
        else if(switch_flag == 0x02){
            degree--;
        }
        degree = degree % 4;
        if(degree < 0){
            degree = 3;
        }

        OCR3A = pulse_table[degree];
        lcdGotoXY(0, 0);
        lcdClear();  
        itoa(degree*45,buffer, 10);
        lcdPrint(buffer);
        _delay_ms(20);
        }
        
    }
    return 0;
}