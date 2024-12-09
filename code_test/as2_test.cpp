#include <string>
#include <vector>
#include <map>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

map<string, int> counts;

void countAllCombination(int start, int end, int r, int index, int buf[], string str)
{
    // [start, end] 구간 사이에서 r개를 뽑는 경우의 수를 구하고, 이를 해시 테이블에 기록한다.
    // index는 함수 내부에서 재귀를 위해 작용한다. 첫 호출 시 0으로 고정한다.
    // buf : 하나의 경우를 저장할 버퍼. 길이는 r이다. 외부에서 받아야 한다.
    // str : 호출한 함수로부터 주문 문자열을 하나씩 받아 처리한다.

    // 종료 조건
    if (index == r)
    {
        // 버퍼로부터 조합 산출
        string key;
        for (int i = 0; i < r; i++)
        {
            key += str[buf[i]];
        }

        // 산출한 조합을 기록한다.
        if (counts.count(key) > 0)
        {
            counts[key]++;
        }
        else
        {
            counts[key] = 1;
        }

        return;
    }

    // 버퍼에 한 문자씩 저장하고 재귀 호출
    for (int i = start; i < end; i++)
    {
        buf[index] = i;
        countAllCombination(i + 1, end, r, index + 1, buf, str);
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;

    //모든 코스 순회
    for (int i = 0; i < course.size(); i++)
    {
        int num = course[i];

        //course배열의 원소 하나 당 모든 주문 순회
        for (int j = 0; j < orders.size(); j++)
        {
            if (orders[j].length() < num)
            {
                continue;
            }

            string str = orders[j];
            sort(str.begin(), str.end());
            int buf[num];
            countAllCombination(0, str.length(), num, 0, buf, str);
        }

        // 가장 많이 주문된 조합을 answer 배열에 삽입한다.
        int max = 0;
        vector<string> tempVector;
        for (map<string, int>::iterator it = counts.begin(); it != counts.end(); it++)
        {
            if (it->second == 1)
            {
                continue;
            }

            if (it->second > max)
            {
                max = it->second;
                tempVector.clear();
                tempVector.push_back(it->first);
            }
            else if (it->second == max)
            {
                tempVector.push_back(it->first);
            }
        }

        for (int i = 0; i < tempVector.size(); i++)
        {
            answer.push_back(tempVector[i]);
        }

        //해시 맵의 데이터를 지우고 다음 course로 넘어간다.
        counts.clear();
    }

    // 정답을 정렬 후 반환
    sort(answer.begin(), answer.end());
    return answer;
}
