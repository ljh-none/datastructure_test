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


/usr/bin/clang++ -std=c++17 -o "/Users/Ljh/VScode/DSA/code_test/asgn5"
"/Users/Ljh/VScode/DSA/code_test/asgn5.cpp" 
&& /Users/Ljh/VScode/DSA/code_test/asgn5



모범

이전의 진행방과 현재의 진행방향이 다른 경우
1. 정반대
되돌아가는 코스, 체크 x
2. 나머지 다 코너

진행 방향에 대한 정보 를 queue에 집어넣어야 한다.

공간 탐색 시 필요한 기능
1. 주어진 공간을 벗어나는 경우를 체크하는 기능
2. 주어진 공간 내에서 탐색 가능한지를 체크하는 기능
3. 탐색 비용을 계산하는 기능



*/

#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

// 시작점 ~ 도착점 까지의 경로
class Route
{
public:
    int total;                         // 지금까지의 경로 총합 비용
    pair<int, int> current;            // 경로의 끝 좌표(현재 좌표). 이 좌표가 도착점이 되면 하나의 경로 완성
    map<pair<int, int>, bool> visited; // 방문 여부 체크
    pair<int, int> before = {0, 0};    // 코너 체크를 위한 두 걸음 뒤의 위치

    Route(int total, pair<int, int> pos)
    {
        this->total = total;
        this->current = pos;
    }

    bool check_visited(pair<int, int> next)
    {
        if (visited[next] == false)
            return false;
        return true;
    }

    void update_position(pair<int, int> pos)
    {
        this->current = pos;
        visited[pos] = true;
    }
};

bool check_index(pair<int, int> next, int length)
{
    if (next.first < 0 || next.first >= length)
        return false;

    if (next.second < 0 || next.second >= length)
        return false;
    return true;
}

bool check_corner(pair<int, int> before, pair<int, int> next)
{
    pair<int, int> lt = {before.first - 1, before.second - 1};
    pair<int, int> rt = {before.first - 1, before.second + 1};
    pair<int, int> lb = {before.first + 1, before.second - 1};
    pair<int, int> rb = {before.first + 1, before.second + 1};

    return (next == lt || next == rt || next == lb || next == rb);
}

int solution(vector<vector<int>> board)
{
    Route result(1000000000, {0, 0}); // 최소 비용의 route를 담을 변수
    queue<Route> que;                 // BFS를 위한 queue
    int length = board.size();

    Route start(0, {0, 0}); // 시작점 설정
    start.visited[{0, 0}] = true;

    pair<int, int> end = {length - 1, length - 1}; // 도착점 설정

    que.push(start); // BFS start
    while (!que.empty())
    {
        Route route = que.front(); // 현재 경로를 받아온다.
        pair<int, int> next;

        // 도착점일 경우 result 갱신 후 다른 경우의 수 탐색
        if (route.current.first == end.first &&
            route.current.second == end.second &&
            route.total < result.total)
        {
            result = route;
            cout << "  goal ~~~~~~~  " << result.total << endl;
            que.pop();
            continue;
        }

        // 1. 상하좌우에 따른 다음 좌표 next 갱신
        // 2. 인덱스 체크, board의 원소 체크, 방문여부 체크
        // 3. next 좌표로 이동한 새로운 경로를 queue에 삽입

        // 상
        next = {route.current.first - 1, route.current.second};
        if (check_index(next, length) &&
            board[next.first][next.second] == 0 &&
            !route.check_visited(next))
        {
            // 새 경로 생성
            Route newone = route;

            // 이동 및 방문 체크
            newone.update_position(next);

            // 비용 갱신
            newone.total += 100;
            if (check_corner(newone.before, newone.current))
                newone.total += 500;

            // 이전 좌표 정보 저장
            newone.before = route.current;

            // queue에 푸쉬
            que.push(newone);
        }

        // 하
        next = {route.current.first + 1, route.current.second};
        if (check_index(next, length) &&
            board[next.first][next.second] == 0 &&
            !route.check_visited(next))
        {
            Route newone = route;
            newone.update_position(next);
            newone.total += 100;
            if (check_corner(newone.before, newone.current))
                newone.total += 500;
            newone.before = route.current;
            que.push(newone);
        }

        // 좌
        next = {route.current.first, route.current.second - 1};
        if (check_index(next, length) &&
            board[next.first][next.second] == 0 &&
            !route.check_visited(next))
        {
            Route newone = route;
            newone.update_position(next);
            newone.total += 100;
            if (check_corner(newone.before, newone.current))
                newone.total += 500;
            newone.before = route.current;
            que.push(newone);
        }

        // 우
        next = {route.current.first, route.current.second + 1};
        if (check_index(next, length) &&
            board[next.first][next.second] == 0 &&
            !route.check_visited(next))
        {
            Route newone = route;
            newone.update_position(next);
            newone.total += 100;
            if (check_corner(newone.before, newone.current))
                newone.total += 500;
            newone.before = route.current;
            que.push(newone);
        }

        // 현재 경로를 queue에서 제거
        que.pop();
    }

    return result.total;
}