/*

임계점 변수 0 설정

모범
1. 위치 정보
2. 지금까지 모은 양의 수
3. 지금까지 모은 늑대의 수
4. 지금까지 방문한 노드 집합 => 인접 노드 => BFS

깊이우선탐색은 stack 사용
일반적으로 BFS가 더 많이 사용됨

인접 리스트
상태정보 큐에 저장 -> 위치정보는 당연, 이외 어떤 정보를 저장하여야 하나

굳이 트리 구현 안해도 될라나
*/


#include <string>
#include <vector>

using namespace std;

class Node
{
public:
    int number; // number of node
    int value;  // 0 or 1
    class Node *left;
    class Node *right;

    Node(int value, int number)
    {
        value = value;
        number = number;
        left = NULL;
        right = NULL;
    }
};

Node *getParent(Node *root, int parent)
{
    
}

int solution(vector<int> info, vector<vector<int>> edges)
{
    // info : 0 or 1, 0 : 양, 1 : 늑
    // edges : (info-1)행2열의 연결 형태
    // (부모 노드 번호, 자식 노드 번호) * n행
    // tree는 bst 형태
    // edges가 정렬되어있지 않다고 가정

    // 1. 트리 형성
    Node *root;
    root->number = 0;
    root->value = 0;
    root->left = NULL;
    root->right = NULL;
    for (int i = 0; i < info.size(); i++)
    {
        // 0. define value
        int parent = edges[i][0];
        int child = edges[i][1];
        int value = info[child];
        Node *newNode = new Node(value, child);

        // 1. move to parent
        Node *temp = root;
        while (temp->number != parent)
        {
            if (temp->number < parent)
            {
                temp = temp->left;
            }
            else
            {
            }
        }
        // 2. connect child node

        if (child_num < temp->number) // child < parent
        {
        }
    }

    int answer = 0;
    return answer;
}