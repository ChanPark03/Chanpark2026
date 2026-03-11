int main()
{   
    int fahr;
    printf("F 온도를 입력하세요:");
    scanf("%d", &fahr); // 사용자로부터 화씨 온도를 입력받아 fahr 변수에 저장
    double celsius; // 섭씨 온도를 저장할 변수 선언
    printf("C 온도는 %f\n입니다:", ((double)fahr - 32) * 5.0 / 9.0); // 화씨 온도를 섭씨 온도로 변환하여 출력 // 섭씨 온도 공식: (화씨 온도 - 32) * 5/9 // %f는 실수를 출력하는 서식 지정자
    return 0;
}

#