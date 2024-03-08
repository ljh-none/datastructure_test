#include <stdio.h>

#include <stdlib.h>

#include <iostream>

#include <cstring>

using namespace std;

 

typedef struct node {

    int data;

    node *next;

}node;

 

void Print(node *tail)

{

    node *temp = tail->next;

    printf("<");

    while (temp->next != tail->next)

    {

        printf("%d ", temp->data);

        temp = temp->next;

    }

    printf("%d>\n", temp->data);

}

 

node *Input(node *tail, int n)

{

    node *temp = (node*)malloc(sizeof(node));

    temp->data = n;

    if (tail == NULL)

    {

        tail = temp;

        temp->next = temp;

        return tail;

    }

    else

    {

        temp->next = tail->next;

        tail->next = temp;

        tail = temp;

        return tail;

    }

}

 

node *Delete(node *tail, int n)

{

    node *temp_bef = tail;

    node *temp_cur = tail->next;

    if (temp_cur->data == n)

    {

        temp_bef->next = temp_cur->next;

        free(temp_cur);

        return tail;

    }

 

    while (temp_cur->next != tail)

    {

        if (temp_cur->data == n)

            break;

        temp_cur = temp_cur->next;

        temp_bef = temp_bef->next;

    }

    if (temp_cur->data == n)

    {

        temp_bef->next = temp_cur->next;

        free(temp_cur);

        return tail;

    }

    else

    {

        temp_cur = temp_cur->next;

        temp_bef = temp_bef->next;

        if (temp_cur->data == n)

        {

            temp_bef->next = temp_cur->next;

            tail = temp_bef;

            free(temp_cur);

            return tail;

        }

        else

        {

            printf("삭제할 데이터가 없습니다.");

            return tail;

        }

    }

}

 

void main()

{

    node *tail = NULL;

    tail = Input(tail, 1);

    Print(tail);

    tail = Input(tail, 2);

    Print(tail);

    tail = Input(tail, 3);

    Print(tail);

    tail = Input(tail, 4);

    Print(tail);

    tail = Input(tail, 5);

    Print(tail);

 

 

    tail = Delete(tail, 1);

    tail = Delete(tail, 3);

    tail = Delete(tail, 5);

    tail = Delete(tail, 7);

    Print(tail);

}

/*
#include <stdio.h>

#include <stdlib.h>

typedef struct Node

{

    int item;

    Node *next;

}Node;

 

typedef struct Q 

{

    Node *f;

    Node *r;

}Q;

 

void init(Q *q)

{

    q->f = NULL;

    q->r = NULL;

}

 

void enque(Q *q,int n)

{

    Node *newnode = (Node*)malloc(sizeof(Node));

    if (q->r == NULL)

    {

        q->r = newnode;

        q->f = newnode;

        newnode->item = n;

        newnode->next = q->f;

        printf("%3c", q->r->item);

    }

    else

    {

        newnode->item = n;

        newnode->next = q->f;

        q->r->next = newnode;

        q->r = newnode;

        printf("%3c", q->r->item);

    }

}

 

void deque(Q *q)

{

    Node *temp;

    if (q->f == q->r)

    {

        if (q->f == NULL)

            printf("NULL");

        else

        {

            printf("%3c", q->f->item);

            temp = q->f;

            free(temp);

            q->f = NULL;

            q->r = NULL;

        }

    }

    else

    {

        printf("%3c", q->f->item);

        temp = q->f;

        q->f = q->f->next;

        free(temp);

    }

}

 

int main()

{

    Q q;

    int temp = 'A';

    init(&q);

    for (int j = 0; j < 2; j++)

    {

        for (int i = 0; i < 5; i++)

        {

            enque(&q, temp++);

        }

        for (int i = 0; i < 6; i++)

        {

            deque(&q);

        }

    }

}

*/