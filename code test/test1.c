/*
S사에서는 각 부서에 필요한 물품을 지원해 주기 위해 부서별로 물품을 구매하는데 필요한 금액을 조사하였다.
그러나, 전체 예산이 정해져 있기 때문에 모든 부서의 물품을 구매해 줄 수는 없다.
그래서 최대한 많은 부서의 물품을 구매해 줄 수 있도록 하려고 한다.
물품을 구매해 줄 때는 각 부서가 신청한 금액 만큼을 모두 지원해 줘야 한다.
예를 들어 1,000원을 신청한 부서에는 정확히 1,000원을 지원해야 하며, 1,000원보다 적은 금액을 지 원해 줄 수는 없다.
-> 0-1 knapsack
부서별로 신청한 금액이 들어있는 배열 d와 예산 budget이 매개변수로 주어질 때,
최대 몇 개의 부서에 물품을 지원할 수 있는지 return 하도록 maxBudgetDept() 함수를 완성하시오.

제한사항
d는 부서별로 신청한 금액이 들어있는 배열이며, 길이(전체 부서의 개수)는 1 이상 100 이하이다.
d의 각 원소는 부서별로 신청한 금액을 나타내며, 부서별 신청 금액은 1 이상 100,000 이하의 자 연수이다.
budget은 예산을 나타내며, 1 이상 10,000,000 이하의 자연수이다.
*/

#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    int d[] = {2, 2, 3, 3}; // 1~100
    int budget = 10;        // 1~100000

    // 1. d 정렬
    sort_insert(d, 4);

    // 2. budget 안넘을때까지 합
    int result = 0;
    for (int i = 0; i < 4; i++)
    {
        result = result + d[i];
        if (result >= budget)
        {
            printf("%d 개의 부서\n", i);
            return 0;
        }
    }
    return 0;
}