#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
    int key;
    Tree *L;
    Tree *R;
} Tree;

Tree *Search(Tree *tree, int key) // 재귀함수를 이용한 값 탐색 함수
{
    if (tree == NULL)
        return NULL;

    if (key == tree->key) // 찾는값이 현재값이랑 같으면
        return tree;
    else if (key < tree->key)        // 찾는값이 현재값보다 작으면
        return Search(tree->L, key); // 트리의 왼쪽으로감. 재귀함수 사용. 이진 탐색 트리에서 왼쪽 트리는 루트값보다 작음
    else
        return Search(tree->R, key);
}

Tree *NewNode(int key) // 새로운 노드 생성 함수
{
    Tree *newnode = (Tree *)malloc(sizeof(Tree));
    newnode->key = key;
    newnode->L = NULL;
    newnode->R = NULL;
    return newnode;
}

Tree *Insert(Tree *tree, int key) // 트리 삽입 함수
{
    if (tree == NULL)
        return NewNode(key);

    if (key < tree->key)                // 입력값이 현재값보다 작으면
        tree->L = Insert(tree->L, key); // 재귀함수 사용, 트리의 왼쪽으로 감.
    else if (key > tree->key)
        tree->R = Insert(tree->R, key);

    return tree;
}

Tree *FindMin(Tree *tree) // 루트를 기준, 왼쪽 서브트리의 가장 큰 값을 찾는 함수
{
    Tree *cur = tree;
    while (cur->L != NULL)
        cur = cur->L;

    return cur;
}

Tree *Delete(Tree *tree, int key) // 삭제함수
{
    if (tree == NULL)
        return tree;

    if (key < tree->key)
        tree->L = Delete(tree->L, key); // 재귀함수 사용, 삭제하려는 값을 찾는 과정. 값을 삭제하고 남는 값을 연결해줌
    else if (key > tree->key)
        tree->R = Delete(tree->R, key);
    else // 값을 삭제하는 과정
    {
        if (tree->L == NULL) // 삭제할 값의 왼쪽 방향이 비어있으면
        {
            Tree *temp = tree->R; // 남겨질 값을 지정함
            free(tree);           // 값 삭제
            return temp;          // 남겨진 값 리턴
        }
        else if (tree->R == NULL)
        {
            Tree *temp = tree->L;
            free(tree);
            return temp;
        }

        Tree *temp = FindMin(tree->R); // 왼쪽 서브트리의 가장 큰 값 찾음
        tree->key = temp->key;         // 서로 값을 바꿈
        tree->R = Delete(tree->R, tree->key);
    }
    return tree;
}

void display(Tree *tree)
{
    if (tree != NULL)
    {
        display(tree->L);
        printf("%d->", tree->key);
        display(tree->R);
    }
}

void main()
{
    Tree *tree = NULL;

    tree = Insert(tree, 8);
    tree = Insert(tree, 5);
    tree = Insert(tree, 7);
    tree = Insert(tree, 1);
    tree = Insert(tree, 2);
    tree = Insert(tree, 6);
    tree = Insert(tree, 3);
    tree = Insert(tree, 9);
    tree = Insert(tree, 4);
    display(tree);
    printf("\n");

    tree = Delete(tree, 5);
    display(tree);
    printf("\n");
    tree = Delete(tree, 9);
    display(tree);
    printf("\n");
    tree = Delete(tree, 3);
    display(tree);
    printf("\n");
}