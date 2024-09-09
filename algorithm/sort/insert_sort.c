#include <stdlib.h>
#include <stdio.h>

#include "header_sort.h"

void sort_insert(int *arr, int n)
{
    int i, j;
    int next;
    for (i = 1; i < n; i++)
    {
        next = arr[i];
        for (j = i - 1; j >= 0 && next < arr[j]; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = next;
    }
}