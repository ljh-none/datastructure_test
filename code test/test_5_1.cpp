/*
중복 제거 -> 집합 이용
*/

#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<int> nums)
{
    int max = nums.size() / 2;
    int total = 0;
    map<int, int> table;
    for (int i = 0; i < nums.size(); i++)
    {
        int key = nums[i];
        if (table.count(key) > 0)
        {
            table[key]++;
        }
        else
        {
            table[key] = 1;
            total++;
            if (total == max)
            {
                return max;
            }
        }
    }

    return table.size();
}