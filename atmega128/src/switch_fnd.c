// 스위치를 눌렀을때 숫자가 증가하는 코드 작성
// PINE0 -> +1 , PINE1-> -1 
//숫자 범위는 0~9까지 
// 0 아래로 가면 9 표시. 
//스위치를 오래눌러도 한번만 변하게. 
#include <avr/io.h>
#include <util/delay.h>


int main (void)
{
    uint8_t FND_DATA_TBL[] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};
    int8_t cnt = 0;

    DDRA = 0xFF;
    DDRE = 0x00; // 스위치 설정 
    
    uint8_t switch_flag = 0;
    uint8_t switch_flag_pre = 0;
    while (1)
    {
        if(switch_flag != PINE >> 4){
        switch_flag = PINE >> 4;
        if (switch_flag == 0x01 || switch_flag == 0x02 )
        {
            switch_flag_pre = switch_flag;
        
        }
        if(switch_flag == 0x01){
            cnt++;

        }
        else if(switch_flag == 0x02){
            cnt--;
        }
        cnt = cnt % 10;
        // cnt 범위를 0부터 9까지로 제한
        if(cnt < 0){
            cnt = 9;
        }
    }
        PORTA = FND_DATA_TBL[cnt];
    
    }
    return 0;
       
    }
