#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    int capacity;
    struct Node *front;
    struct Node *rear;
};

void enqueue(struct Queue **que_p, int data)
{
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    if ((*que_p)->rear == NULL)
    {
        (*que_p)->rear = (*que_p)->front = node;
        return;
    }

    (*que_p)->rear->next = node;
    (*que_p)->rear = node;

    printf("enqueue %d\n", data);
    return;
}

int main()
{
    // init
    struct Queue *que = malloc(sizeof(struct Queue));
    que->capacity = 10;
    que->front = NULL;
    que->rear = NULL;

    enqueue(&que, 1);
    enqueue(&que, 2);
    enqueue(&que, 3);
    enqueue(&que, 4);
    enqueue(&que, 5);
}