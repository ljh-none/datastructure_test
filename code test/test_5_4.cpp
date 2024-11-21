/*
좌표평면이 주어졌다 -> 범위 체크 함수 생성
경로를 표현하는 방법 -> (x, y, nx, ny) (current, x축과 y축으로 이동한 좌표)
-> (nx, ny, x, y) -> table 길이의 반
*/

#include <string>
#include <map>
#include <tuple>
#include <iostream>

using namespace std;

int solution(string dirs)
{
    map<tuple<int, int, int, int>, bool> table; // current x, current y, after x, after y
    pair<int, int> current = make_pair(0, 0);
    int total = 0;

    for (int i = 0; i < dirs.size(); i++)
    {
        pair<int, int> before;              // fore save before state
        tuple<int, int, int, int> dist;     // check route for counting
        tuple<int, int, int, int> dist_inv; // check route for counting

        before = make_pair(current.first, current.second); // backup current

        switch (dirs[i])
        {
        case 'U':
            // scope check
            if (current.second == 5)
            {
                break;
            }
            current.second++;
            break;
        case 'D':
            if (current.second == -5)
            {
                break;
            }
            current.second--;
            break;
        case 'R':
            if (current.first == 5)
            {
                break;
            }
            current.first++;
            break;
        case 'L':
            if (current.first == -5)
            {
                break;
            }
            current.first--;
            break;
        default:
            break;
        }
        dist = make_tuple(before.first, before.second, current.first, current.second);
        dist_inv = make_tuple(current.first, current.second, before.first, before.second);
        if (table[dist] == false)
        {
            table[dist] = true;
            table[dist_inv] = true;
            total++;
        }

        // check
        cout << "(" << current.first << ", " << current.second << "), total : " << total << endl;
    }
    cout << table.size() / 2 << endl;
    return table.size() / 2;
}

int main()
{
    string str = "LLLLLLUURRRDDLURL";
    solution(str);
}