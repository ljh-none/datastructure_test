#include <string>
#include <vector>
#include <unordered_map>
#include <cassert>
#include <iostream>

using namespace std;

unordered_map<string, int> counts;

void getCounts(int start, int end, int r, int index, int buf[], string str)
{
    // start <= x <= end 사이에서 r개의 경우의 수를 구하는 함수
    //  index : r개의 수 중에서 몇 번째 수인지. 첫 호출 시 0으로 설정해야 함
    //  buf : 각 경우의 수의 결과를 담는 버퍼. 첫 호출 시 r로 초기화 후 받아야 함
    //  str : 버퍼에 담긴 결과(인덱스들)로부터 해시 맵에 카운팅한다.

    // 종료 조건
    if (index == r)
    {
        string key;
        for (int i = 0; i < r; i++)
        {
            key += str[buf[i]];
        }
        //cout << key << endl;
        return;
    }

    for (int i = start; i <= end; i++)
    {
        buf[index] = i;
        getCounts(i + 1, end, r, index + 1, buf, str);
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;

    for (int i = 0; i < course.size(); i++)
    {
        int num = course[i]; // 코스요리 갯수

        for (int j = 0; j < orders.size(); j++)
        {
            if (orders[j].length() < num)
            {
                continue;
            }
            string str = orders[j];
            int buf[num];
            getCounts(0, str.length(), num, 0, buf, str);
        }
    }

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
    orders2.push_back("ABC");
    orders2.push_back("BCA");
    orders2.push_back("CAB");
    orders2.push_back("ABC");
    orders2.push_back("AC");

    vector<int> course2;
    course2.push_back(2);
    course2.push_back(3);

    vector<string> expectedResult2;
    expectedResult2.push_back("AB");
    expectedResult2.push_back("AC");
    expectedResult2.push_back("BC");
    expectedResult2.push_back("ABC");

    vector<string> result2 = solution(orders2, course2);
    assert(result2 == expectedResult2);

    // 테스트 케이스 3: 주문에서 메뉴가 겹치지 않는 경우
    vector<string> orders3;
    orders3.push_back("XYZ");
    orders3.push_back("WXY");
    orders3.push_back("WYZ");
    orders3.push_back("XWY");

    vector<int> course3;
    course3.push_back(2);
    course3.push_back(3);

    vector<string> expectedResult3;
    expectedResult3.push_back("WX");
    expectedResult3.push_back("XY");
    expectedResult3.push_back("WXY");
    expectedResult3.push_back("YZ");

    vector<string> result3 = solution(orders3, course3);
    assert(result3 == expectedResult3);

    cout << "모든 테스트 통과!" << endl;
}

int main()
{
    runTests();
    return 0;
}