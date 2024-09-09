# linked list
포인터를 사용하여 연결된 node들로 구성된 배열
데이터 & 포인터(다음 노드의 메모리 주소)

1. 단일 연결 리스트
2. 이중 연결 리스트 : 각 노드는 다음 노드와 이전 노드에 대한 포인터를 모두 포함. 이를 통해 앞뒤 방향으로 순회할 수 있지만, 역방향 참조를 위해 추가 메모리 필요
3. 원형 연결 리스트 : tail node가 head node로 연결됨. 단일 or 이중 연결

### operation
on linked_list_2
삽입
삭제
검색
길이 측정
반대로 바꾸기

### 포인터 추적
1. initialize
struct Node *head = malloc(sizeof(struct Node));
-> * : head는 주솟값을 저장하는 포인터 변수.
-> struct Node : 해당 주소에 존재하는 변수의 타입이 struct Node 타입이란 뜻

2. argument
void print_list(struct Node *head)
{
    struct Node *current = head;  
    ..
}
여기서 head를 그냥 그대로 써도 될까?

struct Node *current = head;
포인터 변수를 선언하고 head를 대입. 이 때 head의 값은
head : struct Node 변수의 주소
&head : head변수의 주소
*head : struct Node 변수의 값

c는 call by value이므로 head의 값을 current에 그대로 복사.
하지만 함수 호출 시 argument로 전달받았을 때 이미 local head변수가 main head 변수의 값을 복사했으므로
굳이 current를 할당할 필요 없다.