#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers)
{
    int count = 0;

    for (int target = 0; target < n; target++)
    {
        if (computers[target][target] == 0) // 이미 다른 집합에 포함된 노드일 경우
            continue;

        queue<int> que;
        que.push(target);
        computers[target][target] = 0;

        while (!que.empty())
        {
            int node = que.front();
            for (int i = 0; i < n; i++)
            {
                if (computers[node][i] == 1 && computers[i][i] == 1)
                {
                    que.push(i);
                    computers[i][i] = 0;
                }
            }
            que.pop();
        }

        count++;
    }

    return count;

    // for (int i = 0; i < n; i++)
    // {
    //     if (computers[i][i] == 0)
    //     {
    //         // 이미 집합에 포함된 노드는 패스
    //         continue;
    //     }

    //     queue<int> local_set;
    //     local_set.push(i);

    //     while (!local_set.empty())
    //     {
    //         int node = local_set.front();
    //         if(computers[node][node] == 0)
    //         {
    //             continue;
    //         }
    //         computers[node][node] = 0;
    //         for (int j = 0; j < computers[node].size(); j++)
    //         {
    //             if (computers[node][j] == 1)
    //             {
    //                 local_set.push(j);
    //             }
    //         }
    //         local_set.pop();
    //     }

    //     count++;
    // }

    // return count;
}

/*
* 0 1 2
0 0 1 0
1 1 0 1
2 0 1 1
*/