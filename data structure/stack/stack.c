/*
- operation
push
pop
top or peek
isEmpty
isFull
*/

#include <stdlib.h>
#include <stdio.h>

struct Stack
{
    int data;
    struct Stack *below;
};

void print_stack(struct Stack *top)
{
    printf("[current stack top to down]\n");
    while (top != NULL)
    {
        printf("%d\n", top->data);
        top = top->below;
    }
    return;
}

void push(struct Stack **top, int data)
{
    struct Stack *node = malloc(sizeof(struct Stack));
    node->data = data;
    node->below = *top; // stack의 top 위에 새 노드 추가
    *top = node;        // top 갱신
    printf("%d pushed\n", node->data);
    return;
}

int pop(struct Stack **top)
{
    int popped = (*top)->data; // 데이터 추출
    struct Stack *temp = *top; // 지울 노드
    *top = (*top)->below;      // 하강
    free(temp);                // 해제
    printf("%d popped\n", popped);
    return popped;
}

int main()
{
    struct Stack *top = NULL;
    push(&top, 1);
    push(&top, 2);
    push(&top, 3);
    push(&top, 4);
    push(&top, 5);
    print_stack(top);
    int a = pop(&top);
    print_stack(top);
    return 0;
}