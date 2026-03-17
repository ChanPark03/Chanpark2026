#include <stdio.h> // FILE, fopen, fputs, fclose, printf 선언

int main (void)
{
    FILE *a; // 파일 포인터 (FILE 구조체를 가리키는 포인터)
    a = fopen("test2.dat", "w"); // 쓰기 모드로 파일 열기(없으면 생성, 있으면 내용 덮어씀)
    // 주의: fopen 실패 시 a는 NULL -> NULL 체크 전에 접근하면 오류 위험
    printf("%d\n", a->_fileno); // 내부 파일 디스크립터 출력(구현체 의존, 표준 C 아님)
    if (a == NULL) // 열기 실패 처리
    {
        printf("파일을 열 수 없습니다. \n");
        return -1;


    }
    // fprintf(a, "..."); // 형식 지정 출력(여기서는 문자열만이라 fputs 사용 가능)
    fputs("이것은 파일포인터로 저장되는 예시 데이터 입니다.", a); // 문자열 쓰기(개행 없음)
    fclose(a); // 파일 닫기(버퍼 flush 포함)
    return 0; // 정상 종료
}
