#include<fcntl.h>   // open(), O_* 플래그
#include<stdio.h>   // printf(), sprintf()
#include<unistd.h>  // write(), close()

int main(void)
{
    int fd;  // 파일 디스크립터 (파일을 가리키는 정수 핸들)
    char* path ="/home/chan/Chanpark2026/c_example/part6";  // 기본 디렉터리
    char fPath[100];  // 최종 파일 경로를 담을 버퍼
    sprintf(fPath, "%s%s", path, "/test.dat");  // 경로+파일명 합치기

    // 파일 열기: 쓰기 전용, 없으면 생성, 있으면 내용 비움, 권한 0644
    fd = open(fPath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)  // 실패 시 -1 반환
        printf("파일을 열 수 없다.\n");

    // 지정한 바이트 수(62)만큼 파일에 씀
    write(fd, "이것은 파일로 저장되는 예시 데이터 입니다.!", 62);

    close(fd);  // 열어둔 파일 닫기

}

/*
명령어(함수) 정리
- open(path, flags, mode): 파일 열기/생성, 성공 시 fd 반환
- write(fd, buf, count): fd에 count 바이트 쓰기
- close(fd): fd 닫기
*/
