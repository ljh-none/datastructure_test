/*



해시 테이블 2개로?
id - 나를 신고한 id
id - 신고된 횟수 누적 수
id - 처리 메일 수

아니면
id - 내가 신고했는데 k를 넘어선 애들만

모범
1. 신고한 사람 - 신고당한 사람
2. 신고당한 사람이 당한 횟수
3. k번 이상 신고당한 사람 => 신고한 사람

*집합과 리스트의 차이?
순서를 중요시하는지, 집합은 중복허용 x

해시테이블 구성
1. 위 1번의 관계를 나타낸 테이블
key : 신고 당한 사람
value : 신고한 사람(들의 집합/리스트)

2. 위 2번을 카운트하는 테이블
key : 신고한 사람
value : 정지먹인 사람 수

*/
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    map<string, vector<string>> table; // key : 신고 당한 사람 value : 신고한 사람(들의 집합/리스트)
    map<string, int> count;            // key : 신고한 사람 value : 정지먹인 사람 수

    // 1. write table
    for (int i = 0; i < report.size(); i++)
    {
        istringstream iss(report[i]);
        string isReport;
        iss >> isReport;
        string isReported;
        iss >> isReported;

        auto it = find(table[isReported].begin(), table[isReported].end(), isReport);
        if (it != table[isReported].end())
            continue;
        table[isReported].push_back(isReport);
    }

    // 2. write count
    for (auto it = table.begin(); it != table.end(); ++it)
    {
        if (it->second.size() < k)
            continue;

        vector<string> temp = it->second;
        for (int i = 0; i < temp.size(); i++)
        {
            count[temp[i]]++;
        }
    }

    // 3. write answer
    vector<int> answer;
    for (int i = 0; i < id_list.size(); i++)
    {
        answer.push_back(count[id_list[i]]);
    }

    return answer;
}