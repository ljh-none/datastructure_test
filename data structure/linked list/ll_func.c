#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; // struct Node 타입의 variable의 주소 저장
};

void print_list(struct Node *head)
{
    printf("[ print current list ]\n");
    struct Node *current = head;
    while (current != NULL)
    {
        printf("value : %d\n", current->data);
        current = current->next;
    }
}

struct Node *initialize()
{
    struct Node *head = malloc(sizeof(struct Node));
    head->data = -1;
    head->next = NULL;
    return head;
}

void insert_head(struct Node **head_p, int data)
{
    // 1. 이중 포인터로 포인터 변수의 포인터를 만듭니다.
    // head, 포인터
    // head : struct Node 인스턴스의 주소
    // &head : head 변수의 주소
    // *head : struct Node 변수의 인스턴스

    // head_p, 이중 포인터
    // head_p : head 변수의 주소 = &head
    // &head_p : head_p 변수의 주소
    // *head_p : head 변수의 값 = struct Node 인스턴스의 주소 = head

    // 2. 새 node를 생성합니다.
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;

    // 3. 연결 작업을 합니다.
    node->next = *head_p; // 새 노드를 기존 head에 연결
    *head_p = node;       // head를 새 노드로 변경
    return;
}

void insert_middle(struct Node **head_p, int pos, int data)
{
    // 0. 조건 체크, 0 < pos
    if (pos < 1)
    {
        printf("out of range\n");
        return;
    }
    // 1. 원하는 위치까지 이동
    // 삽입을 원하는 위치의 전까지 이동해야 함!
    struct Node *current = *head_p;
    for (int i = 0; i < pos - 1; i++)
    {
        if (current->next == NULL)
        {
            // 위치에 도착하기 전에 끝나는 경우
            printf("index not exist\n");
            return;
        }
        current = current->next;
    }
    //끝 노드일 경우
    if (current->next == NULL)
    {
        printf("tail node, use insert_tail func\n");
        return;
    }

    // 2. 교체 작업
    printf("insert between %d and ~\n", current->data);
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = current->next;
    current->next = node;
    return;
}

void insert_tail(struct Node *head, int data)
{
    // move to last node
    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    printf("insert after %d\n", current->data);

    // node generate
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;

    // connect
    current->next = node;
    return;
}

void search(struct Node *head, int data)
{
    printf("searching %d...\n", data);
    struct Node *current = head;
    while (current->next != NULL)
    {
        if (current->data == data)
        {
            printf("find it!\n");
            return;
        }
        current = current->next;
    }
    printf("fail!\n");
    return;
}

void delete(struct Node *head)
{
    // move to last node
    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    printf("delete %d\n", current->data);

    // delete
    free(current);
}

int main()
{
    struct Node *head = initialize();
    insert_tail(head, 0);
    insert_tail(head, 1);
    insert_tail(head, 2);
    insert_tail(head, 3);
    insert_tail(head, 4);
    print_list(head);
    insert_middle(&head, 1, 100);
    insert_tail(head, 5);
    insert_tail(head, 6);
    print_list(head);
    // search(head, 7);
}