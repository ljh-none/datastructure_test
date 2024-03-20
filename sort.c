#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void display(int *arr)
{
    printf("[ ");
    for (int i = 0; i < MAX; i++)
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

void bubble_sort(int ary[MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ary[i] > ary[j])
            {
                int temp = ary[i];
                ary[i] = ary[j];
                ary[j] = temp;
            }
        }
    }
}

void insertion_sort(int ary[MAX], int n)
{
    int i, j;
    int next;
    for (i = 1; i < n; i++)
    {
        next = ary[i];
        for (j = i - 1; j >= 0 && next < ary[j]; j--)
        {
            ary[j + 1] = ary[j];
        }
        ary[j + 1] = next;
    }
}

int divide_partition(int *arr, int left, int right)
{
    int pivot = arr[left];
    int low = left + 1;
    int high = right;
    printf("pivot: %d\n", pivot);
    while (low <= high)
    {
        while (pivot >= arr[low] && low <= right)
        {
            low++;
        }
        while (pivot <= arr[high] && high >= (left + 1))
        {
            high--;
        }
        if (low <= high)
        {
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }
    }
    int temp = arr[left];
    arr[left] = arr[high];
    arr[high] = temp;
    display(arr);
    return high;
}

int divide_partition_random(int *arr, int low, int high)
{
    srand(time(NULL));
    int pivot = rand() % 10;    // pivot의 인덱스, 0 ~ 9
    printf("pivot : %d\n", arr[pivot]);
    swap(&arr[low], &arr[pivot]); // pivot을 배열 젤앞으로 땡김
    printf("swaped array : ");
    display(arr);
    low++;                      // 인덱스 구성 : [pivot, low, low+1, ... , high-1, high]
    printf("current low & high : %d %d\n", low, high);
    while (1)
    {
        for (; low < high; low++)
        {
            if(arr[0] < arr[low])
                break;
        }
        for(; high > low; high--)
        {
            if(arr[0] > arr[high])
                break;
        }

        if(low >= high) //종료조건, while문 종료
            break;
        
        printf("[log] low : %d - high : %d\n", low, high);
        swap(&arr[low], &arr[high]);  //피봇 기준으로 분할.
        printf("[log] sort : ");  //중간 결과 출력
        display(arr);
    }
    swap(&arr[pivot], &arr[0]); //pivot의 값 복귀
    printf("[log] result :");
    display(arr);
    return pivot;   //pivot 인덱스 반환
}

// int arr[] == int *arr
void quick_sort(int *arr, int left, int right)
{
    int q = divide_partition_random(arr, left, right);
    // if (left < right)
    // {
    //     int q = divide_partition_random(arr, left, right); // q = pivot index
    //     quick_sort(arr, left, q - 1);
    //     quick_sort(arr, q + 1, right);
    // }
}

int main()
{
    int arr[MAX] = {5, 8, 3, 1, 10, 15, 2, 9, 12, 18};
    printf("원래 리스트 ");
    display(arr);
    quick_sort(arr, 0, MAX - 1);
    return 0;
}
