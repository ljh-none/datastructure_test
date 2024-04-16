#include <stdlib.h>
#include <stdio.h>

#include "header_sort.h"

void display(int *arr)
{
    printf("[ ");
    for (int i = 0; i < ARRAY_MAX; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");
    return;
}

void print_mylog(int *arr, int start, int end, char *content)
{
    printf("[log] %s : [ ", content);
    for (int i = start; i <= end; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}