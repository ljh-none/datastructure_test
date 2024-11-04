#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int main()
{
    int n;
    int k;

    cin >> n;
    cin >> k;

    queue<int> que;
    for (int i = 1; i <= n; i++)
    {
        que.push(i);
    }

    cout << "<";
    while (!que.empty())
    {
        for (int i = 0; i < k - 1; i++)
        {
            int temp = que.front();
            que.pop();
            que.push(temp);
        }
        cout << que.front() << ", ";
        que.pop();
    }
}

