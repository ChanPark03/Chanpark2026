#include <stdio.h>

int main (void)
{
    char ch;
    char str[100];
    printf("문자를 입력하세요: ");
    ch = getc(stdin); // ch = fgetc(stdin); // ch = getchar(); // 표준 입력에서 문자 하나를 읽어 ch에 저장
    //ch = fgetc(stdin); // ch = getchar(); // 표준 입력에서 문자 하나를 읽어 ch에 저장 // getchar()는 버퍼링 없이 바로 입력을 받는 함수로, 엔터키를 누르지 않아도 입력이 처리됩니다. 하지만 getc(stdin)이나 getchar()는 버퍼링이 되어 있어 엔터키를 눌러야 입력이 처리됩니다.

    printf("%d, %d, %d", stdin->_fileno, stdout->_fileno, stderr->_fileno);
    printf("입력한 문자는 %c입니다.\n", ch); 
    while (getchar() != '\n') // \n는 엔터키를 의미하며, 입력 버퍼에 남아있는 문자를 모두 제거하는 역할을 합니다. 이 루프는 사용자가 엔터키를 누를 때까지 계속해서 getchar()를 호출하여 입력 버퍼에서 문자를 읽어들이고, 그 문자가 '\n'이 될 때까지 반복합니다. 이렇게 함으로써 입력 버퍼에 남아있는 불필요한 문자들을 제거할 수 있습니다.
    {
        ch = fgetc(stdin);
        printf("입력한 문자는 %c 입니다.\n", ch);
        scanf("%s", str);
        printf("입력한 문자열은 %s입니다.\n", str);
    }
    
    return 0;
}