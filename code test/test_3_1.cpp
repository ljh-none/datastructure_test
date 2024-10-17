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


#include <stdlib.h>
#include <stdio.h>




char *solution1(char *participant, char *completion, int length)
{
    char *failed;
    int failed_index = 0;
    //make hash table with participant and completion
    for (int i = 0; i < length; i++)
    {
        
    }
    return failed;
}