// 표준 입출력 함수(printf 등)를 사용하기 위한 헤더
#include <stdio.h>

// 자기 자신을 가리킬 수 있는 연결 리스트 노드 구조체 정의
typedef struct list{
    int num;               // 노드에 저장할 데이터(정수)
    struct list *next;     // 다음 노드를 가리키는 포인터(자기 참조)
}List;                     // 구조체 별칭 이름

int main(void)
{
    // 3개의 노드를 스택 영역에 생성하고 초기화
    // next 필드는 아직 연결하지 않았으므로 0(NULL)로 초기화
    List a = {10, 0}, b = {20, 0}, c = {30, 0};
    // head는 리스트의 시작 노드를 가리키는 포인터
    // current는 리스트를 순회할 때 사용할 포인터
    List *head = &a, *current;
    // 링크드 리스트 연결: a -> b -> c 순서로 연결
    a.next = &b;
    b.next = &c;

    // head가 가리키는 첫 번째 노드의 num 출력
    printf("head->num : %d\n", head->num);
    // head의 next가 가리키는 두 번째 노드의 num 출력
    printf("head->next->num : %d\n", head->next->num);

    printf("list all : ");       // 전체 리스트 출력 시작
    current = head;              // current를 head로 초기화(첫 노드부터 순회)
    // current가 NULL이 될 때까지(마지막 노드의 next가 NULL) 반복
    while (current != NULL)
    {
        // 현재 노드의 num 출력 (공백 없이 이어 출력됨)
        printf("%d", current->num);
        // 다음 노드로 이동: current가 가리키는 주소를 next로 갱신
        current = current->next;
    }
    printf("\n");               // 줄바꿈
    return 0;                   // 정상 종료
}
