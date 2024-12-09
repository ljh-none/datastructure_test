/*
1. enroll
판매원 목록(center 제외)
조직에 참여한 시간 순 오름차순 정렬
=> referral의 i 번째는 이미 enroll의 j번째 (j < i)에 등장했음

2. referral
추천인 목록
referral의 i번째 사람은 enroll의 i번째 사람을 조직에 참여시킴
중복 있음, empty(-) 있음
enroll과 같은 length

3. amount
판매 집계 데이터 배열

4. seller
amount의 i번째 데이터에 기록된 판매액을 누가 판매했는지 기록한 배열



모범
원 단위 절사 -> 소숫점 버림
hash 1. child - parent -> key : enrol, value : referral, 상향식
hash 2 seller - amount -> key : name, value : 0, + amount

*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(
    vector<string> enroll,
    vector<string> referral,
    vector<string> seller,
    vector<int> amount)
{
    vector<int> answer;
    return answer;
}