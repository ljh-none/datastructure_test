/*
costs
    0   1   2
0  is1 is2 cost
1  is1 is3 cost
2  is1 is4 cost
3  is2 is3 cost
4  is2 is4 cost

use dfs & get tree's height

모범
minimum spanning tree
-> "모든 섬"을 연결하여야됨. 위 방식은 모든 섬이 연결되지 않는다.
모든 nodes를 weight를 가진 edge로 연결한 경우의 최소값

최소신장트리의 가장 중요한 조건 : cycle이 존재하면 안된다.
node count : N
edge count : maximum N-1

인접행렬?

크루스컬 : 간선 오름차순 정렬 후 greedy하게 구축. 이 때 사이클 형성 여부 체크(union find)
프리마 : 정점 중심 구축. 구축 시 사이클이 형성되지 않는다. 

*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Node
{
public:
    int number;
    int cost; // parent -> this
    vector<Node *> children;
};

int solution(int n, vector<vector<int>> costs)
{
    sort(costs.begin(), costs.end());
    int sum = 0;
    int is1 = costs[0][0];
    int buf = costs[0][2];
    for (int i = 0; i < costs.size(); i++)
    {
        if (is1 != costs[i][0])
        {
            is1 = costs[i][0];
            sum += buf;
        }

        if (costs[i][2] < buf)
        {
            buf = costs[i][2];
        }
    }

    return sum;
}