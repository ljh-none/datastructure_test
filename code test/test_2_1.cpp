#include <string>
#include <vector>
#include <iostream>

using namespace std;

void solution(int number)
{
    if (number == 1)
    {
        cout << 1 << endl;
        return;
    }

    // number = max
    int start = 1;
    int end = start + 1;
    int count = 1; // 자기자신의 경우 포함

    while (end != number)
    {
        // 1. get sum
        int sum = 0;
        for (int i = start; i <= end; i++)
        {
            sum = sum + i;
        }

        // offset setting
        if (sum > number)
        {
            start++;
        }
        else if (sum == number)
        {

            count++;
            end++;
        }
        else if (sum < number)
        {
            end++;
        }
    }

    cout << count << endl;
    return;
}

int main()
{
    int number;
    cin >> number;
    solution(number);
    return 0;
}