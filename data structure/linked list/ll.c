#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; // struct Node 타입의 variable의 주소 저장
};

int main()
{
    struct Node *head;                  // 초기화되지 않았으므로 쓰레기값
    head = malloc(sizeof(struct Node)); // 여기도 아직 초기화되지 않았으므로 쓰레기값
    head->data = 1;
    head->next = NULL;
    struct Node *node1 = malloc(sizeof(struct Node));
    node1->data = 2;
    node1->next = NULL;
    head->next = node1;

    // print
    struct Node *current = head;
    while (current != NULL)
    {
        printf("value : %d\n", current->data);
        current = current->next;
    }
}