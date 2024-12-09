/*


모범
두명 짝짓는 기준?
1. 가장 무거운 사람 2명 -> 직관적으로 안됨
2. 가장 가벼운 사람 2명 -> 여유공간 낭비됨
3. 1, 2 각 1명씩

한 벡터를 정렬 후, 양 끝 포인터 지정 후, 가운데로 향하면서 카운팅
limit 넘길 경우 무거운 쪽을 카운팅 후 포인터 이동

왜? limit을 꽉꽉 채워서 카운팅하나, 약간 남겨서 카운팅하나(70, 30, 20) 갯수에 차이 없음.
또한 그리디는 근사 해 도출 알고리즘임.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    sort(people.begin(), people.end(), greater<int>());

    for (int i = 0; i < people.size(); i++)
    {
        // exit condition
        if (people[i] == -1)
            continue;

        // get big one
        int current_limit = limit - people[i];
        people[i] = -1;

        // get second big one
        for (int j = people.size(); j >= people.size(); j--)
        {
            if (people[j] == -1)
                continue;
            if (current_limit - people[j] < 0)
                continue;
            people[j] = -1;
            break;
        }
        answer++;
    }
    return answer;
}

// 알고리즘패러다임
// 그리디는 근사최적해 발견