#include <avr/io.h>
#include <util/delay.h>

int main()
{
    DDRE = 0x00;
    DDRC = 0x0F;

    
    while (1)
    {
        if (PINE & _BV(PE0))
        {
            PORTC = 0x0F;
        }  else {
            PORTC = 0x00;
        }  
    }
    
    return 0;
}