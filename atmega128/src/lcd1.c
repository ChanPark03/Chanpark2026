#include "lcd.h"
#include <avr/io.h>

int main(void)
{
    lcdInit();
    lcdClear();
    lcdGotoXY(0, 0);
    lcdDataWrite('H');
    lcdDataWrite('E');
    lcdDataWrite('L');
    lcdDataWrite('L');
    lcdDataWrite('O');
    lcdGotoXY(2,1);
    lcdPrintData("MCU World !!!!!!", 12);
    while (1) 
    {
        ;
    }
    
 return 0;   
}
    