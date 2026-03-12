#include <stdio.h>

int main(void)
{
    printf("%d %d %d\n", 100, 0144, 0x64); 
    printf("%d 0%o 0x%x\n", 100, 100,100); // 100 is a decimal literal, 0144 is an octal literal, and 0x64 is a hexadecimal literal
    
    printf("%11dLL\n", 1000000000LL); // 1000000000LL is a long long literal

    printf("%f %f\n", 2.718, 3.141592F); // 2.718 is a double literal, 3.141592F is a float literal
    printf("%d %d %d\n", 'A', 'a', '0'); // ASCII code for 'A', 'a', and '0'
    printf("%c %c %c\n", 65, 97, 48);
    printf("%c %c %c\n", 'A', 'A' + 1, 'A' + 2); 
    printf("%s\n", "ABCD"); // "ABCD" is a string literal
    return 0;
}

