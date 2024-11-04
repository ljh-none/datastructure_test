/*
연속된 자연수의 합

문제 분석
이 문제는 구간 합 문제임
선형 리스트로 풀이 -> 최소 O(n)으로 풀어야 함
현재 리스트는 정렬되어있는상태

*/

#include <stdio.h>
#include <stdlib.h>

int solution1(int n)
{
    // 1. 자연수 배열 생성
    int ary[n];
    for (int i = 0; i < n; i++)
    {
        ary[i] = i + 1;
    }
    //-> O(n)

    // 2. 투포인터로 큰 수부터 계산
    int count = 1;
    int right = n - 2;
    int left = n - 3;
    while (left != -1)
    {
        int sum = 0;
        for (int i = right; i >= left; i--)
        {
            sum += ary[i];
        }
        if (sum > n)
        {
            left--;
            right--;
        }
        else if (sum == n)
        {
            // printf("left : %d, right : %d\n", ary[left], ary[right]);
            count++;
            left--;
            right--;
        }
        else if (sum < n)
        {
            left--;
        }
    }
    printf("%d", count);
    return count;
}

int main()
{
    int number;
    scanf("%d", &number);
    solution1(number);
    return 0;
}
