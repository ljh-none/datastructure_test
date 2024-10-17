/*
노래 저장 사이트
index : 노래 고유 번호
genres[i] : 해당 노래의 장르.
plays[i] : 해당 노래가 재생된 횟수
dic_genre[~100] : 장르의 종류

목표 : 베스트 앨범 출시
조건
0. 각 노래 당 장르(dic_genre) 하나 할당 << 이걸 전제로 생각해야 함
1. 각 장르 별(dic_genre) 가장 많이 재생된(plays) 노래 두 개 선정
2. 속한 노래가 많이 재생된 장르(dic_genre)를 먼저 수록한다
-> "classic"에 속한 노래들의 총 plays를 계산하여
가장 많이 play된 장르(dic_genre)를 배열의 맨 앞에 놓는다.
3. 장르(dic_genre) 내에서 많이 재생된 노래를 먼저 수록한다.
4. 장르(dic_genre) 내에서 재생 횟수가 같은 노래 중 고유 번호가 낮은 노래를 먼저 수록한다.

h(genres) = index가 이상적일거 같은데
genres는 dic_genre의 원소들로만 이루어진 배열이라 중복이 많을것임
그럼 "일 대 다"로 연결이 되어서 함수가 아닌 관계로 정의될텐데
아니야 어차피 같은 문자열이면 같은 원소로 취급받아서 일대일 함수가 될듯?
그럼 collision을 해결하는게 이 문제의 핵심일듯

1. h(genres) = index, 해당 index에 plays 저장
2. h(genres) = plays, 해당 plays에 index 저장

만약 각 노래마다 재생 횟수가 다르다면
h(plays) = genres, 해당 genres에 인덱스 저장?
h(plays) = index, 해당 index에 genres 저장?
둘 다 다대일 함수 성립

* 문제에서 인풋아웃풋을 먼저 파악하기

모범
해시테이블 2개
input : index, genres[index], plays[index]
outputs : 선곡 리스트
노래 정렬 시 기준이 2개 있다
1. 특정 장르의 총 재생 횟수, 내림차순 -> [장1, 장2, 장3]
2. 특정 장르에 속하는 노래들을 내림차순 정렬 -> 장1 내에서 내림차순 정렬
=> 2번 결과에서 상위 2개 노래 추출. 이를 1번 결과의 모든 요소들에 대해 수행

해시 구성, 각 기준에 대응할 해시 테이블 구성은 다음과 같다
1. 장르 - 속한 노래들의 총 재생 횟수
2. 장르 - id, 재생 횟수 => 장르 = key, 튜플 = value 
해시 2에 추가될 때마다 해시 1을 업뎃하면 한번의 for문으로 가능

*/

#include <iostream>
#include <unordered_map>
#include <string>

void solution2()
{

}

int main()
{
    std::string genres[5] = {"classic", "pop", "classic", "classic", "pop"};
    int plays[5] = {500, 600, 150, 800, 2500};

    std::unordered_map<std::string, std::pair<int, int> > hash;
    for (int i = 0; i < 5; i++)
    {
        hash[genres[i]] = std::make_pair(i, plays[i]);
    }

    std::cout << hash["classic"].second << std::endl; // 출력: 1
}