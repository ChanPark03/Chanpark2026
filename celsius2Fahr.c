int main()
{
    int celsius;
    printf("C  온도를 넣으세요 : \n");
    scanf("%d", &celsius); // 사용자로부터 섭씨 온도를 입력받아 celsius 변수에 저장
    double fahr; 
    fahr = 9.0 / 5.0 * (double)celsius + 32.0; // 섭씨 온도를 화씨 온도로 변환하여 fahr 변수에 저장 // 화씨 온도 공식: (섭씨 온도 * 9/5) + 32
    printf("F(fahr) 온도 : %f\n", fahr); // 계산된 화씨 온도를 출력 // %f는 실수를 출력하는 서식 지정자
    return 0; // 프로그램 종료
    
}