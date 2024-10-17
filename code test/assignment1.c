#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void assignment1(int n, int l, int *num, int *d)
{
    // index 기준으로 숫자 설정
    for (int end = 0; end < n; end++) // end index 세팅. 문제의 i
    {
        // start index setting
        int start = end - l + 1; // 문제의 i-L+1
        if (start < 0)
        {
            start = 0;
        }

        // find min value
        d[end] = -1;
        for (int i = start; i <= end; i++) // start ~ end 구간 내에서 최솟값 찾기
        {
            if (num[i] < d[end] || d[end] == -1) // 현재 저장된 최솟값보다 작다면 그 값을 저장
            {
                d[end] = num[i];
            }
        }
    }
    return;
}

void set_value(int n, int *num, int *d)
{
    for (int i = 0; i < n; i++)
    {
        num[i] = (rand() % 10) + 1;
        d[i] = 0;
    }
    return;
}

void print_value(int n, int *num, int *d)
{
    printf("숫자 배열 : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n최솟값 배열 d : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", d[i]);
    }
    printf("\n");
    return;
}

void check_range(int n, int l)
{
    // index 기준
    printf("[range]\n");
    for (int i = 0; i < n; i++)
    {
        int sum = i - l + 1;
        if (sum < 0)
        {
            printf("0 ~ %d\n", i);
        }
        else
        {
            printf("%d ~ %d\n", sum, i);
        }
    }
    return;
}

int main()
{
    srand(time(0));

    int n = 12; // n개의 수
    int l = 3;  // 이 길이의 구간 사이에서 최솟값을 구한다. 즉 슬라이딩 윈도우의 크기
    int num[n]; // 숫자 배열
    int d[n];   // 최솟값 배열
    int test[12] = {1, 5, 2, 3, 6, 2, 3, 7, 3, 5, 2, 6};

    // set_value(n, num, d);
    // assignment1(n, l, num, d);
    // print_value(n, num, d);
    check_range(12, 3);

    return 0;
}
