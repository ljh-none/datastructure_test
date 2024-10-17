/*

Node value

모범
레버 주목
최단거리 문제와 비슷
양가중치로만 - 다익스
음가중치까지 - 플루이드
그러나 가중치가 없기 때문에 사용 불가

DFS? 너비? -> 최단거리를 찾아야하므로 너비우선

1. S -> L 까지의 너비우선탐색
2. L -> E 까지의 너비우선탐색

큐에 넣어서 해결

팁 : 그냥 que보단 덱(deque) 써라


*/

#include <string>
#include <vector>

using namespace std;

class Node
{
public:
    char value; // S, L, E, O, X 중 하나
    class Node *up;
    class Node *down;
    class Node *left;
    class Node *right;
};

int solution(vector<string> maps)
{

    int answer = 0;
    return answer;
}
