#include <stdio.h>

typedef struct 
{
  int year;
  int month;
  int day;  
}Date;

int main(void)
{
    Date d;
    d.year = 2026;
    d.month = 7;
    d.day = 19;
    
    printf("%d-%d-%d\n", d.year, d.month, d.day);
    return 0;
}
