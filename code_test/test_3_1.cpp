/*
10만명 이하 -> n^2 x

방법 1. 정렬 & 비교
방법 2. 해싱
키값 : 참가자의 이름(동명이인 가능)
value : 참가자의 명수
완주자 명단과 해싱 테이블을 대조


쟁점
동명이인

*/
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    map<string, int> table;
    for (int i = 0; i < participant.size(); i++)
    {
        if (table[participant[i]] > 0)
        {
            table[participant[i]]++;
        }
        else
        {
            table[participant[i]] = 1;
        }
    }

    for (int i = 0; i < completion.size(); i++)
    {
        table[completion[i]]--;
    }

    for (int i = 0; i < participant.size(); i++)
    {
        if (table[participant[i]] > 0)
            return participant[i];
    }

    return "";
}