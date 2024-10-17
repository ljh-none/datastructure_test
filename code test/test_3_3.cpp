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


#include <iostream>
#include <unordered_map>
#include <string>

void solution3(std::string *id_list, std::string *report, int k, int length)
{
    std::unordered_map<std::string, std::pair<int, int> > hash;
    std::unordered_map<std::string, std::[] > hash;

    for (int i = 0; i < length; i++)
    {

    }
    // return : 각 유저별로 처리 결과 메일을 받은 횟수를 배열에 담아 반환
}