#include <stdio.h>

// 문자열 복사를 직접 구현한 함수의 선언
// pDes: 복사 대상(목적지), pSrc: 원본 문자열
// 반환값: 복사 시작 주소(pDes의 원래 값)
char *myStrcpy(char *pDes, const char *pSrc);

int main(void)
{
    // 충분한 크기의 버퍼를 만들고 초기 문자열을 넣음
    char str2[200] = "strawberry";

    // "apple"을 str2로 복사
    myStrcpy(str2, "apple");
    printf("str2: %s\n", str2);

    // "banana"를 str2로 복사
    myStrcpy(str2, "banana");
    printf("str2: %s\n", str2);

    // 함수의 반환값(복사 시작 주소)을 그대로 printf에 넘겨 출력
    printf("str2: %s\n", myStrcpy(str2, "pineapple"));

    return 0;
}

// 문자열 복사 함수 구현
// pSrc가 가리키는 문자를 하나씩 pDes에 복사하고 끝에 '\0'을 붙임
char *myStrcpy(char *pDes, const char *pSrc)
{
    char *pA = pDes; // 원래 목적지 시작 주소를 저장

    // 널 문자('\0')를 만날 때까지 문자 복사
    while (*pSrc != '\0')
    {
        *pDes = *pSrc; // 현재 문자 복사
        pDes++;        // 목적지 포인터 이동
        pSrc++;        // 원본 포인터 이동
    }
    *pDes = '\0'; // 문자열 끝 표시
    return pA;    // 복사 시작 주소 반환
}
