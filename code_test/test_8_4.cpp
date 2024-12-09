/*
조합 계산하기
• 정수 N을 입력받아 1부터 N까지의 숫자 중에서 합이 10이 되는 조합을 리스트로 반환하는 solution4 함수를 작성하시오.
• 제약 조건
➢ 백트래킹을 활용할 것.
➢ 숫자 조합은 오름차순으로 정렬되어야 함.
➢ 같은 숫자는 한 번만 선택할 수 있음.
➢ 1 <= n <= 10
*/

#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

void printVector(const vector<int> &vec)
{
    cout << "vector : ";
    for (int value : vec)
    {
        cout << value << " ";
    }
    cout << endl;
}

void permute_back(int n, int current_sum, vector<int> current, vector<vector<int>> &answer)
{
    int last = current.back();

    for (int i = last + 1; i <= n; i++)
    {
        vector<int> vec = current;
        // exit condition
        if ((current_sum + i) == 10)
        {
            vec.push_back(i);
            answer.push_back(vec);
            printVector(vec);
            return;
        }
        else if ((current_sum + i) < 10)
        {
            vec.push_back(i);
            permute_back(n, current_sum + i, vec, answer);
        }
        else
        {
            //pruning
            return;
        }
    }
}

void solution(int n)
{
    vector<vector<int>> answer;

    for (int i = 1; i <= n; i++)
    {
        vector<int> start;
        start.push_back(i);
        permute_back(n, i, start, answer);
    }
    return;
}

int main()
{
    solution(7);
}