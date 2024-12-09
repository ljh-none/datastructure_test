/*
n * n 공간
퀸 n개

  0 1 2 3 4
0 q 0 0 0 0
1 0 0 q 0 0
2 0 0 0 0 q
3 0 q 0 0 0
4 0 0 0 q 0


모범
유망 함수? (promising func) 특정 탐색 조건을 정의한 함수
8페이지 별표
pruning, 많이 쓰인다. 
상태 공간 트리

백트래킹 핵심
1. 상태 공간 트리 그리기
2. 탐색 종료 조건 파악

완전 탐색
-> O(n^n) -> ㄴㄴ

가로세로대각에 퀸 있는지 확인, 굳이 모든 보드에 마스킹 필요없다
-> width, col 배열로 체크. 어떻게 이게 가능? 퀸의 특성으로 인해.
-> diagonal  배열도 생성. 행렬의 크기에 따라 대각선의 길이는 정해져있으므로(if n by n, 2n-1)
    width, col처럼 쓰일 수 있다
체스판 방문여부 행렬 만들어도 되는데, 백트래킹은 brute-force이므로 시간이 오래 걸린다.


*/

#include <string>
#include <vector>
#include <queue>
#include <cstdlib> // for abs

using namespace std;

int gn;

bool check_diagonal(pair<int, int> before, pair<int, int> after)
{
    return (abs(before.first - after.first) == abs(before.second - after.second));
}

bool check_range(pair<int, int> pos)
{
    if (pos.first < 0 || pos.first >= gn)
        return false;
    if (pos.second < 0 || pos.second >= gn)
        return false;
    return true;
}

pair<int, int> return_direction(int offset, pair<int, int> pos)
{
    switch (offset)
    {
    case 0: // 2up-1left
        return {pos.first - 1, pos.second - 2};
    case 1: // 2up-1right
        return {pos.first + 1, pos.second - 2};

    case 2: // 2right-1up
        return {pos.first + 2, pos.second - 1};
    case 3: // 2right-1down
        return {pos.first + 2, pos.second + 1};

    case 4: // 2down-1right
        return {pos.first + 1, pos.second + 2};
    case 5: // 2down-1left
        return {pos.first - 1, pos.second + 2};

    case 6: // 2left-1down
        return {pos.first - 2, pos.second + 1};
    case 7: // 2left-1up
        return {pos.first - 2, pos.second - 1};
    default:
        break;
    }
}

int getDFS(int sum, int queen_count, vector<int> row_col, pair<int, int> current)
{
    if (queen_count == 5)
    {
        return sum + 1;
    }

    // 8방향에 대한 direction 받아온다
    for (int offset = 0; offset < 8; offset++)
    {
        pair<int, int> next = return_direction(offset, current);
        // 조건 체크
        if (check_range(next) || check_diagonal(current, next))
            continue;
        // masking 체크
        if (row_col[next.second] == 1 || row_col[gn + next.first] == 1)
            continue;
        vector<int> newone = row_col;
        newone[next.second] = 1;
        newone[gn + next.first] = 1;

        sum = getDFS(sum, queen_count + 1, row_col, next);
    }
    return sum;
}

////////////////// 구현 실패 //////////////////////

int solution(int n)
{
    gn = n;
    int result = 0;
    // 모든 좌표에 대한 첫 수를 고려한다.
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            // for masking
            vector<int> row_col(n * 2, 0);
            row_col[row] = 1;
            row_col[n + col] = 1;
            int queen_count = 1;

            result += getDFS(0, queen_count, row_col, {col, row});
        }
    }

    return result;
}
