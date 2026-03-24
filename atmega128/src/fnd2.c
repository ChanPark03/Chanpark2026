#include<avr/io.h>
#include<avr/interrupt.h>

// delay() 함수를 쓰지 않음!!!
//_delay_ms();
volatile uint8_t millisconds = 0;

ISR(TIMER0_OVF_vect)
{
    ++millisconds;
}

void timer0_init()
{
    TCCR0 = _BV(CS02) | _BV(CS01) | _BV(CS00);
    TIMSK |= _BV(TOIE0);
    sei();
}

int main()
{
    timer0_init();
    uint8_t numbers[] = {
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
    int count = 0;
    DDRA = 0xFF;
    
    while(1)
    {
        if(millisconds >= 32)
        {
            millisconds = 0;
            count++;
            count = count % 10;
            PORTA = numbers[count];
        }

    }
    return 0;
}