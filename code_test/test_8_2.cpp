/*
모범



*/

#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

void dive(int current, int count, vector<int> visited, int &answer, vector<vector<int>> &dungeons)
{
    stack<int> index; // brute-force니까 소모도 정렬은 필요없다.
    for (int i = 0; i < dungeons.size(); i++)
    {
        if (dungeons[i][0] <= current && visited[i] == 0)
            index.push(i);
    }

    if (index.empty())
    {
        if (answer < count)
            answer = count;
        return;
    }

    while (!index.empty())
    {
        int i = index.top();
        int param_cur = current - dungeons[i][1]; // 현재 피로도 소모, 음수가 되도 위의 조건에 걸린다.
        int param_cnt = count + 1;                // 탐험 수 카운트
        visited[i] = 1;                           // 방문 체크

        cout << "== current : " << param_cur << ", count : " << param_cnt << endl;
        dive(param_cur, param_cnt, visited, answer, dungeons);
        index.pop();
    }
}

int solution(int k, vector<vector<int>> dungeons)
{
    int answer = -1;
    vector<int> visited(dungeons.size(), 0);
    dive(k, 0, visited, answer, dungeons);
    return answer;
}