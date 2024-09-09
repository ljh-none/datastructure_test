#include <stdlib.h>
#include <stdio.h>

#include "header_sort.h"

void sort_merge(int *arr, int low, int high)
{
    // 1. exit condition
    if (low == high)
        return; // 원소가 하나면 이미 정렬된 것으로 취급

    // 2. divide
    int mid = (low + high) / 2;

    // 3. conquer(recursion)
    sort_merge(arr, low, mid);
    sort_merge(arr, mid + 1, high);
    print_mylog(arr, low, high, "current array");
    // 이 시점부터 배열의 왼편과 오른편은 정렬된 상태로 취급

    // 4. combine(sort sorted parts)
    int left = low; // 두 배열의 시작지점 설정
    int right = mid + 1;
    int length = high - low + 1; // 임시 배열 크기
    int arr_temp[length];

    print_mylog(arr, left, mid, "left side");
    print_mylog(arr, right, high, "right side");

    // // 두 배열의 원소 중 작은 값 대입
    // // 그 후 대입한 쪽의 인덱스를 증가시킴
    // //-> 반복
    for (int i = 0; i < length; i++)
    {
        // 왼쪽 배열의 모든 요소를 사용한 경우
        if (left > mid)
        {
            arr_temp[i] = arr[right];
            right++;
        }
        // 오른쪽 배열의 모든 요소를 사용한 경우
        else if (right > high)
        {
            arr_temp[i] = arr[left];
            left++;
        }
        // 왼쪽 배열의 요소가 클 경우
        else if (arr[left] > arr[right])
        {
            arr_temp[i] = arr[right];
            right++;
        }
        // 오른쪽 배열의 요소가 클 경우
        else if (arr[left] < arr[right])
        {
            arr_temp[i] = arr[left];
            left++;
        }
    }

    // // 5. copy(원래 배열에)
    int j = 0;
    for (int i = low; i <= high; i++)
    {
        arr[i] = arr_temp[j];
        j++;
    }
    return;
}