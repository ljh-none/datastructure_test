/*
id
nickname
act - enter, leave, change

모범
user's uid(immutable), nickname(mutable)
id-nick relation을 저장
key : id, value : nickname
key가 될 값 : 안바뀌는거, 중복이 거의 없는 거

기존 채팅방에 출력되어있던 메시지의 닉네임도 전부 변경됨
-> 최종적ㅈ으로 구축된 해시 테이블을 참조하여 출력하여라
-> 입력을 다시 한 번 돌면서 출력 생성(원래는 출력용 배열 하나 생성하려 했음)





*/

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

int isFirstEnter(string id, string nickname, unordered_map<string, string> id_nickMap)
{
    // 1. 해시 맵에서 str찾아 없으면 enter에 추가, 변경되었다면
    auto nick = id_nickMap.find(id);
    if (nick == id_nickMap.end())
    {
        id_nickMap[id] = nickname;
    }
    // 2. answer에 추가
}

vector<string> solution(vector<string> record)
{
    // record : 채팅방에 들어오고 나가거나, 닉네임을 변경한 기록이 담긴 문자열 배열
    // -> instruction / id / (nickname)
    // answer : 모든 기록이 처리된 후, 최종적으로 방을 개설한 사람이 보게 되는 메시지 로그
    // id_nickMap : id - nickname match
    // 닉네임 변경이 수시로 들어올 수 있으므로
    // id 님이 들어왔습니다 라고 answer에 일괄 입력하자 출력할때
    // 그럴려면 임시 answer 배열이 있어야겠다

    vector<string> answer; // 리턴할 정답 배열
    unordered_map<string, string> id_nickMap;
    vector<pair<string, string>> tempAnswer;

    // 1. 동작 기록
    for (int i = 0; i < record.size(); i++)
    {
        istringstream src(record[i]);
        string inst, id, nickname;
        getline(src, inst, ' ');
        getline(src, id, ' ');
        getline(src, nickname, ' ');
        if (inst == "enter")
        {
            isFirstEnter(id, nickname, id_nickMap);
            tempAnswer.push_back(make_pair(id, "님이 들어왔습니다"));
        }
        else if (inst == "leave")
        {
            tempAnswer.push_back(make_pair(id, "님이 나갔습니다"));
        }
        else if (inst == "change")
        {
            id_nickMap[id] = nickname;
        }
    }

    // 2. 정답 배열 작성
    for (int i = 0; i < tempAnswer.size(); i++)
    {
        answer.push_back(tempAnswer[i].first + tempAnswer[i].second);
    }

    return answer;
}