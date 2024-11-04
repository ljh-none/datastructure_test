/*

Node value

모범
레버 주목
최단거리 문제와 비슷
양가중치로만 - 다익스
음가중치까지 - 플루이드
그러나 가중치가 없기 때문에 사용 불가

DFS? 너비? -> 최단거리를 찾아야하므로 너비우선

1. S -> L 까지의 너비우선탐색
2. L -> E 까지의 너비우선탐색

큐에 넣어서 해결

팁 : 그냥 que보단 덱(deque) 써라


*/

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Mov
{
public:
    int row;
    int col;
    int moves = 0;

    // 기본 생성자
    Mov() : row(0), col(0) {} // 기본값 설정

    Mov(int row, int col)
    {
        this->row = row;
        this->col = col;
    }
};

int solution(vector<string> maps)
{
    queue<Mov> que;
    vector<vector<bool> > isVisited(maps.size(), vector<bool>(maps[0].size(), false));
    Mov lever;
    int toRow[4] = {1, -1, 0, 0};
    int toCol[4] = {0, 0, 1, -1};

    // 0. S의 위치를 구한다
    for (int i = 0; i < maps.size(); i++)
    {
        string temp = maps[i];
        for (int j = 0; j < temp.size(); j++)
        {
            if (temp[j] == 'S')
            {
                Mov m(i, j);
                que.push(m);
                isVisited[i][j] = true;
                cout << "start index : {" << i << ", " << j << "}" << endl;
            }
        }
    }

    // 1. L까지의 최단거리를 구한다

    while (!que.empty())
    {
        // get from queue
        Mov mov = que.front();

        // move
        for (int i = 0; i < 4; i++)
        {
            int row = mov.row + toRow[i];
            int col = mov.col + toCol[i];
            if (row < 0 || col < 0 || row >= maps.size() || col >= maps[0].size())
            {
                continue;
            }

            if (maps[row][col] == 'X')
            {
                continue;
            }
            else if (maps[row][col] == 'L')
            {
                lever = Mov(row, col);
                lever.moves = mov.moves + 1;
                cout << "lever : {" << row << ", " << col << "} ~ " << lever.moves << endl;
                cout << "mov : " << mov.moves << endl;
                break;
            }
            else
            {
                if (isVisited[row][col] == true)
                    continue;
                Mov temp(row, col);
                temp.moves = mov.moves + 1;
                que.push(temp);
                isVisited[row][col] = true;
            }
        }

        // if found lever
        if (lever.moves > 0)
        {
            queue<Mov> emptyQueue;
            que.swap(emptyQueue);
            break;
        }

        // pop queue
        que.pop();
    }
    // if lever not found
    if (lever.moves == 0)
        return -1;

    // 2. E까지의 최단거리를 구한다
    isVisited.assign(maps.size(), vector<bool>(maps[0].size(), false));
    que.push(lever);
    while (!que.empty())
    {
        Mov mov = que.front();

        for (int i = 0; i < 4; i++)
        {
            int row = mov.row + toRow[i];
            int col = mov.col + toCol[i];
            if (row < 0 || col < 0 || row >= maps.size() || col >= maps[0].size())
            {
                continue;
            }

            if (maps[row][col] == 'X')
            {
                continue;
            }
            else if (maps[row][col] == 'E')
            {
                return mov.moves + 1;
            }
            else
            {
                if (isVisited[row][col] == true)
                    continue;
                Mov temp(row, col);
                temp.moves = mov.moves + 1;
                que.push(temp);
                isVisited[row][col] = true;
            }
        }

        que.pop();
    }

    return -1;
}

int main()
{
    // 테스트 케이스 설정
    vector<string> maps;
    maps.push_back("LOOXS");
    maps.push_back("OOOOX");
    maps.push_back("OOOOO");
    maps.push_back("OOOOO");
    maps.push_back("EOOOO");

    // solution 함수 호출 및 결과 출력
    int result = solution(maps);
    cout << "최단 거리: " << result << endl; // 결과를 출력합니다.

    return 0;
}