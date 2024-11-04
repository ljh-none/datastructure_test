#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget)
{
    // 예산이 한참 남았을 때, 이 코드는 동작하지 않음!

    // 1. 정렬
    sort(d.begin(), d.end());

    // 2. budget 계산
    int sum = 0;
    for (int i = 0; i < d.size(); i++)
    {
        sum += d[i];
        cout << "current : " << d[i] << endl;
        cout << "sum : " << sum << endl;

        if (sum > budget)
        {
            printf("%d개의 부서\n", i);
            return i;
        }
        else if (sum == budget)
        {
            printf("%d개의 부서\n", i + 1);
            return i + 1;
        }
    }

    return -1;
}

int solution2(vector<int> d, int budget)
{
    // 1. 정렬
    sort(d.begin(), d.end());

    // 2. budget 계산
    int count = 0;
    int budget = budget;
    for (int i = 0; i < d.size(); i++)
    {
        cout << "current : " << d[i] << endl;
        if (d[i] > budget)
        {
            break;
        }
        budget -= d[i];
        count += 1;
    }

    if (budget >= 0)
    {
        return count;
    }
    else
    {
        return count - 1;
    }
}

int main()
{
    vector<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_back(5);
    int budget = 15; // 1~100000

    int num = solution(d, budget);
    return 0;
}