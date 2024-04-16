#include <stdlib.h>
#include <stdio.h>

#include "header_sort.h"

void sort_quick(int *arr, int low, int high)
{
    // exit condition
    if (low >= high)
        return;

    // init condition    (실수했는데 고치기귀찮아서 따로받음.)
    int low_ = low;
    int high_ = high;

    // select pivot
    srand(time(NULL));
    int pivot = (rand() % (high - low + 1) + low); // pivot을 low ~ high 중 하나로 선정
    //printf("[log] pivot : %d\n", arr[pivot]);

    // swap pivot to start of array
    swap(&arr[low], &arr[pivot]); // pivot을 배열의 맨 앞으로 땡긴다.
    pivot = low++;                // pivot의 값을 갱신한다(pivot의 위치가 이동했으므로), low를 정렬시작지점으로 위치시킨다.
    //print_mylog(arr, 0, ARRAY_MAX - 1, "after swap");
    //printf("[log] low : %d, high : %d pivot : %d\n", low, high, pivot);

    // 3. sort
    while (1)
    {
        for (; low < ARRAY_MAX; low++) // 0~9
        {
            if (arr[pivot] < arr[low])
                break;
        }
        for (; high >= 0; high--)
        {
            if (arr[pivot] >= arr[high])
                break;
        }
        // high부분 if에만 =을 추가하는 이유
        // low는 하늘 뚫어도 상관없음. 비교할때만 인덱스가 올바르면 됨.
        // 근데 high는 pivot과 스왑해야되기때문에 멈출 필요가 있음.
        // 그래서 인덱스 0일 때 멈추도록 = 추가함.
        if (low < high)
        {
            swap(&arr[low], &arr[high]);
            //print_mylog(arr, 0, ARRAY_MAX - 1, "ing..");
        }
        else
            break;
    }
    //printf("[log] current low : %d high : %d\n", low, high);

    // 4. swap pivot to own
    swap(&arr[pivot], &arr[high]); // 피봇을 high자리에 위치.
    pivot = high;                  // pivot 값 갱신.
    //print_mylog(arr, 0, ARRAY_MAX - 1, "after sort");
    // 이후 피봇 기준 왼오른쪽이 정렬된 상태.
    // 또한 이 때 피봇은 완전히 정렬 되었을 때 기준으로 제자리에 위치하게 됨.

    // 5. recursion
    sort_quick(arr, low_, pivot - 1);
    sort_quick(arr, pivot + 1, high_);
}