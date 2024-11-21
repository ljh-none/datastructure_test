#include <stdlib.h>
#include <stdio.h>

#include "header_sort.h"

// 가장 베이직한 정렬
void sort_selection(int *arr)
{ 
    for (int left = 0; left < ARRAY_MAX - 2; left++)
    {
        for (int right = left + 1; right < ARRAY_MAX - 1; right++)
        { // Right인덱스가 left포함 왼편을 제외한 나머지를 쭉 돌면서 작은거 교환
            if (arr[left] > arr[right])
                swap(&arr[left], &arr[right]);
        }
    }
    return;
}
