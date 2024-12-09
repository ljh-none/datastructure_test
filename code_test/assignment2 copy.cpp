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
    // start <= x <= end 사이에서 r개의 경우의 수를 구하는 함수
    //  index : r개의 수 중에서 몇 번째 수인지. 첫 호출 시 0으로 설정해야 함
    //  buf : 각 경우의 수의 결과를 담는 버퍼. 첫 호출 시 r로 초기화 후 받아야 함
    //  str : 버퍼에 담긴 결과(인덱스들)로부터 해시 맵에 카운팅한다.

    // 종료 조건
    if (index == r)
    {
        // cout << "start : " << start << endl;
        // cout << "index : " << index << endl;
        string key;
        for (int i = 0; i < r; i++)
        {
            key += str[buf[i]];
        }

        if (counts.count(key) > 0)
        {
            // cout << "Key exists." << endl;
            counts[key]++;
        }
        else
        {
            // cout << "Key does not exist." << endl;
            counts[key] = 1;
        }

        return;
    }

    for (int i = start; i < end; i++) // start가 5까지만 가야댐(end까지만)
    {
        buf[index] = i;
        countAllCombination(i + 1, end, r, index + 1, buf, str);
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;

    for (int i = 0; i < course.size(); i++)
    {
        int num = course[i]; // 코스요리 갯수

        // 문자열마다 경우의 수에 따라 카운팅
        for (int j = 0; j < orders.size(); j++) // orders배열 내 모든 문자열에 대해
        {
            if (orders[j].length() < num) // ex) course = 3, orders의 문자열 길이가 2일 때
            {
                continue;
            }

            string str = orders[j];
            int buf[num]; // getCounts에서 인덱스의 경우의 수를 저장할 버퍼
            cout << "===== current string : " << str << "order : " << j << " =====" << endl;
            countAllCombination(0, str.length(), num, 0, buf, str);
        }

        // 제일 많은 거 저장
        int max = 0;
        vector<string> tempVector;
        for (map<string, int>::iterator it = counts.begin(); it != counts.end(); it++)
        {
            cout << it->first << it->second << endl;
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

        // cout << "max : " << max << endl;
        // for (size_t i = 0; i < tempVector.size(); i++)
        // {
        //     cout << tempVector[i] << " ";
        // }
        // cout << endl;
        counts.clear();
    }

    sort(answer.begin(), answer.end());
    for (size_t i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;
    return answer;
}

void runTests()
{
    // 테스트 케이스 1: 주어진 예시 데이터
    vector<string> orders1;
    orders1.push_back("ABCFG");
    orders1.push_back("AC");
    orders1.push_back("CDE");
    orders1.push_back("ACDE");
    orders1.push_back("BCFG");
    orders1.push_back("ACDEH");

    vector<int> course1;
    course1.push_back(2);
    course1.push_back(3);
    course1.push_back(4);

    vector<string> expectedResult1;
    expectedResult1.push_back("AC");
    expectedResult1.push_back("ACDE");
    expectedResult1.push_back("BCFG");
    expectedResult1.push_back("CDE");

    // 실제 함수 호출
    vector<string> result1 = solution(orders1, course1);
    assert(result1 == expectedResult1);

    // 테스트 케이스 2: 코스 길이가 더 긴 경우
    vector<string> orders2;
    orders2.push_back("ABCDE");
    orders2.push_back("AB");
    orders2.push_back("CD");
    orders2.push_back("ADE");
    orders2.push_back("XYZ");
    orders2.push_back("XYZ");
    orders2.push_back("ACD");

    vector<int> course2;
    course2.push_back(2);
    course2.push_back(3);
    course2.push_back(5);

    vector<string> expectedResult2;
    expectedResult2.push_back("ACD");
    expectedResult2.push_back("AD");
    expectedResult2.push_back("ADE");
    expectedResult2.push_back("CD");
    expectedResult2.push_back("XYZ");
    sort(expectedResult2.begin(), expectedResult2.end());

    vector<string> result2 = solution(orders2, course2);
    assert(result2 == expectedResult2);

    // // 테스트 케이스 3: 주문에서 메뉴가 겹치지 않는 경우
    vector<string> orders3;
    orders3.push_back("XYZ");
    orders3.push_back("WXY");
    orders3.push_back("WXA");

    vector<int> course3;
    course3.push_back(2);
    course3.push_back(3);
    course3.push_back(4);

    vector<string> expectedResult3;
    expectedResult3.push_back("WX");
    expectedResult3.push_back("XY");

    vector<string> result3 = solution(orders3, course3);
    sort(expectedResult3.begin(), expectedResult3.end());

    assert(result3 == expectedResult3);

    cout << "모든 테스트 통과!" << endl;
}

int main()
{
    runTests();
    return 0;
}

// for (const auto &pair : counts)
// {
//     if (pair.first.length())
//         cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
// }