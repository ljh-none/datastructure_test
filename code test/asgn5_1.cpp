/*
N x N 크기의 정사각형, 3 <= N <= 25
0 : 칸이 비어 있음
1 : 해당 칸이 벽으로 채워져 있음

출발점은 (0, 0)
도착점은 (N-1, N-1)
중간에 끊기지 않도록, 막히는 케이스 없음
상, 하, 좌, 우로 인접한 두 빈 칸을 연결 : 직선 도로로 카운트, 100원
두 직선 도로가 서로 직각으로 만나는 지점 : 코너로 카운트, 500원
경주로를 건설하는 데 필요한 최소 비용

경우의 수 queue

*/

#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Route
{
    int total;
    pair<int, int> pos;
    map<pair<int, int>, bool> isVisited;
};

bool isCorner(pair<int, int> before, pair<int, int> newone)
{
    pair<int, int> lt = {before.first - 1, before.second - 1};
    pair<int, int> rt = {before.first - 1, before.second + 1};
    pair<int, int> lb = {before.first + 1, before.second - 1};
    pair<int, int> rb = {before.first + 1, before.second + 1};

    return (newone == lt || newone == rt || newone == lb || newone == rb);
}

int solution(vector<vector<int>> board)
{
    Route result;

    queue<Route> que;

    Route start;
    start.total = 0;
    start.pos = {0, 0};
    start.isVisited[{0, 0}] = true;
    que.push(start);

    pair<int, int> before = start.pos;
    while (!que.empty())
    {
        Route route = que.front();
        pair<int, int> current = route.pos;

        // 조건으로 경로 탐색 및 이동
        // 상, 인덱스 범위 체크                 요소 체크
        if ((current.first - 1) >= 0 && board[current.first - 1][current.second] == 0)
        {
            // 직선일 경우
            Route newone = route;
            newone.pos.first--;

            if (isCorner(before, newone.pos))
            {
                newone.total += 500;
            }
            else
            {
                newone.total += 100;
            }

            newone.isVisited[newone.pos.first, newone.pos.second] = true;
            que.push(newone);
        }

        // 하
        if ((current.first + 1) < board.size() && board[current.first + 1][current.second] == 0)
        {
            Route newone = route;
            newone.pos.first++;

            if (isCorner(before, newone.pos))
            {
                newone.total += 500;
            }
            else
            {
                newone.total += 100;
            }

            newone.isVisited[newone.pos.first, newone.pos.second] = true;
            
            que.push(newone);
        }

        // 좌
        if ((current.second - 1) < board.size() && board[current.first][current.second - 1] == 0)
        {
            Route newone = route;
            newone.pos.second--;

            if (isCorner(before, newone.pos))
            {
                newone.total += 500;
            }
            else
            {
                newone.total += 100;
            }

            newone.isVisited[newone.pos.first, newone.pos.second] = true;

            que.push(newone);
        }

        before = current;
        que.pop();
    }

    int answer = 0;
    return answer;
}