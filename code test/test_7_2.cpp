/*

모범

트리 탐색 알고리즘

전체 노드 갯수가 n이고, 한쪽 트리의 노드의 갯수가 m일 때, 나머지는 자동으로 나온다.
BFS는 최적 or 최소를 요구할 때 보통 쓰임

*/


#include <string>
#include <vector>

using namespace std;

struct Tree
{
    int number;
    vector<Tree *> children;
};

struct Tree *get_leaf(struct Tree *root, int number)
{
    if (root->number == number)
    {
        return root;
    }
    while (root->number != number)
    {
        for (int i = 0; i < root->children.size(); i++)
        {
            struct Tree *result = get_leaf(root->children[i], number);
        }
    }
}

int solution(int n, vector<vector<int>> wires)
{
    // input list : [[1,3],[2,3],[3,4],[4,5],[4,6],[4,7],[7,8],[7,9]]
    // n : 송전탑 갯수, wires : 연결 정보
    struct Tree *root;
    root->number = wires[0][0];

    for (int i = 0; i < wires.size(); i++)
    {
        struct Tree *temp = root;
        struct Tree *node;
        node->number = wires[i][1];
        temp = get_leaf(temp, wires[1]);
        temp->children.push_back(node);
    }

    int min = n;
    for (int i = 0; i < wires.size(); i++)
    {
        vector<int> edge = wires[i];
        int left_tree_node = edge[0];
        int left_total;
        int right_tree_node = edge[1];
        int right_total;

        // get left tree total
        // count all children, root ~ cutted

        // get right tree total
        // 1. get count all children, cutted as root
    }

    int answer = -1;
    return answer;
}