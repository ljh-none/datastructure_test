// 일단 정답 나온 코드의 복사본



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
#include <iostream>

using namespace std;

class Route
{
public:
    int total;                         // 지금까지의 경로 총합 비용
    pair<int, int> current;            // 경로의 끝 좌표. 이 좌표가 도착점이 되면 리턴
    map<pair<int, int>, bool> visited; // 방문 여부 체크
    pair<int, int> before = {0, 0};    // next의 코너 체크를 위한 두 걸음 뒤의 위치
    int flag = 0;

    Route(int total, pair<int, int> pos)
    {
        this->total = total;
        this->current = pos;
    }

    bool check_visited(pair<int, int> next)
    {
        if (visited[next] == false)
        {
            // cout << "not visited" << endl;
            return false;
        }
        // cout << "visited, return" << endl;
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
    {
        // cout << "index check false, return" << endl;
        return false;
    }

    if (next.second < 0 || next.second >= length)
    {
        // cout << "index check false, return" << endl;
        return false;
    }
    // cout << "index check true" << endl;
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
    queue<Route> que;                 // BFS를 위한 대기열
    int length = board.size();        // 정사각형의 변의 길이
    int flag = 0;

    Route start(0, {0, 0}); // 시작점 설정
    start.visited[{0, 0}] = true;
    pair<int, int> end = {length - 1, length - 1}; // 도착점 설정

    start.before = start.current;

    que.push(start); // BFS start
    while (!que.empty())
    {
        Route route = que.front();
        cout << "\ncurrent : " << route.current.first << "," << route.current.second;
        cout << " actions | flag : " << route.flag << "  ";
        cout << " before : " << route.before.first << "," << route.before.second << "  ";
        pair<int, int> next;

        // 도착점일 경우 비용 갱신 후 다른 경우의 수 탐색
        if (route.current.first == end.first &&
            route.current.second == end.second &&
            route.total < result.total)
        {
            result = route;
            cout << "  goal ~~~~~~~  " << result.total << endl;
            que.pop();
            continue;
        }

        if (route.total > 6400)
        {
            que.pop();
            continue;
        }

        // 인덱스 체크, 요소 체크, 방문여부 체크 후 이동

        // 상
        // cout << "== up case ===" << endl;
        next = {route.current.first - 1, route.current.second};
        if (check_index(next, length) &&
            board[next.first][next.second] == 0 &&
            !route.check_visited(next))
        {
            // cout << "move up" << endl;
            Route newone = route;
            newone.update_position(next); // 좌표 갱신 및 방문 체크
            cout << "  next : " << newone.current.first << "," << newone.current.second;

            // 비용 갱신을 위한 코너 체크
            newone.total += 100;
            if (check_corner(newone.before, newone.current))
            {
                cout << "turn corner!" << endl;
                newone.total += 500;
            }

            newone.before = route.current;
            que.push(newone);
        }

        // 하
        // cout << "== down case ===" << endl;
        next = {route.current.first + 1, route.current.second};
        // cout << "board element : " << board[next.first][next.second] << endl;
        if (check_index(next, length) &&
            board[next.first][next.second] == 0 &&
            !route.check_visited(next))
        {
            // cout << "move down" << endl;
            Route newone = route;
            newone.update_position(next); // 좌표 갱신 및 방문 체크
            if (flag == 0)
            {
                flag = 1;
                newone.flag = 1;
            }
            cout << "  next : " << newone.current.first << "," << newone.current.second;

            // 비용 갱신을 위한 코너 체크
            newone.total += 100;
            if (check_corner(newone.before, newone.current))
            {
                cout << "turn corner!" << endl;
                newone.total += 500;
            }

            newone.before = route.current;
            que.push(newone);
        }

        // 좌
        // cout << "== left case ===" << endl;
        next = {route.current.first, route.current.second - 1};
        if (check_index(next, length) &&
            board[next.first][next.second] == 0 &&
            !route.check_visited(next))
        {
            // cout << "move left" << endl;
            Route newone = route;
            newone.update_position(next); // 좌표 갱신 및 방문 체크
            cout << "  next : " << newone.current.first << "," << newone.current.second;

            // 비용 갱신을 위한 코너 체크
            newone.total += 100;
            if (check_corner(newone.before, newone.current))
            {
                cout << "turn corner!" << endl;
                newone.total += 500;
            }

            newone.before = route.current;
            que.push(newone);
        }

        // 우
        // cout << "== right case ===" << endl;
        next = {route.current.first, route.current.second + 1};
        if (check_index(next, length) &&
            board[next.first][next.second] == 0 &&
            !route.check_visited(next))
        {
            // cout << "move right" << endl;
            Route newone = route;
            newone.update_position(next); // 좌표 갱신 및 방문 체크
            cout << "  next : " << newone.current.first << "," << newone.current.second;

            // 비용 갱신을 위한 코너 체크
            newone.total += 100;
            if (check_corner(newone.before, newone.current))
            {
                cout << "turn corner!" << endl;
                newone.total += 500;
            }

            newone.before = route.current;
            que.push(newone);
        }

        // que 제거
        que.pop();
    }

    return result.total;
}

int main()
{
    // 테스트 케이스를 생성합니다.
    vector<vector<int>> board = {
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0}};

    // solution 함수 호출 (여기서는 구현된 solution 함수가 있어야 합니다)
    cout << "    Test Case     \n"
         << solution(board) << endl; // 예상 출력은 최단 비용

    return 0;
}