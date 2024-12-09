/*

트리 및 삽입 검색 연산 구축
이를 이용한 자료구조설계 및 해결
유니온파인드? 분리집합표 트리로표현
트리를 굳이 구현 안해도 해결로직에 개념적으로 트리가 있다면 ㄱㅊ


참가자 N명, 1번 ~ N번
바로 뒤에사람과 배정
게임 후 번호 다시배정

풀이
라운드 수 = 층
bst로 선수망 구축
                    1
        1                      2
    1        2           3            4
 1    2    3    4    5      6     7       8
1 2  3 4  5 6  7 8  9 10  11 12  13 14  15 16

힙, 우선순위 큐
힙 : 이진 트리를 배열로 구현, i 의 부모 = i/2, i자식은 i*2, i*2 +1

모범
index / 2, 올림
승자/패자 트리
인덱스 변화에 주목

내가 고생한 이유
이겨서 올라왔을 때 4번과 5번이면 맞붙지 않아도 1차이가 남
round 카운트 위치를 변경하고 /가 같아질 시점까지 진행하면 쉽게 됨

*/

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

int solution(int n, int a, int b)
{
    int round = 0;
    while (true)
    {
        // 1. round 시작
        round++;

        // 2. 서로 붙었는지 체크
        // a=4, b=5 일 때 실패

        if (a % 2 == 0 && a - 1 == b)
        {
            return round;
        }
        else if (b % 2 == 0 && b - 1 == a)
        {
            return round;
        }

        // 3. 진출
        // case a
        if (a % 2 == 0) // 짝수라면
        {
            a = a / 2;
        }
        else // 홀수라면
        {
            a = a / 2;
            a++;
        }

        // case b
        if (b % 2 == 0)
        {
            b = b / 2;
        }
        else
        {
            b = b / 2;
            b++;
        }
    }

    return round;
}
