#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Node
{
    // root must be externel variable
public:
    int data;
    vector<Node *> children;

    // generator
    Node(int data)
    {
        this->data = data;
    }

    // function
    void insert(int data)
    {
        Node *node = new Node(data);
        children.push_back(node);
    }

    void print_children()
    {
        cout << data << "'s children :";
        for (int i = 0; i < children.size(); i++)
        {
            cout << " " << children[i]->data;
        }
        cout << endl;
    }

    Node *get_child(int data)
    {
        for (int i = 0; i < children.size(); i++)
        {
            if (children[i]->data == data)
            {
                return children[i];
            }
        }
        return nullptr;
    }
};

void do_simple_union(int i, int j, int *parent)
{
    // i 번째 노드의 부모를 j로 삼아서 합집합 연산
    parent[i] = j;
}

int do_simple_find(int i, int *parent)
{
    // i : 자식 노드
    int temp = i;

    while (parent[temp] >= 0)
    {
        temp = parent[temp]; // move to parent
    }

    return temp;
}

void do_advanced_union(int i, int j, int *parent)
{
    // 가중 규칙을 적용한 union 연산
    // i : i번째 노드
    // j : j번째 노드

    // 1. 각 노드가 속한 집합의 루트 노드를 찾는다.
    while (parent[i] >= 0)
    {
        i = parent[i];
    }
    while (parent[j] >= 0)
    {
        j = parent[j];
    }
    if (i == j)
    {
        //같은 root의 집합인 경우
        return;
    }

    // 2. 원소의 갯수가 더 많은 트리가 적은 트리를 자식으로 받는다
    int temp = parent[i] + parent[j]; // 총 원소의 갯수 계산
    if (-parent[i] < -parent[j])      // 집합 i의 원소 수가 집합 j보다 적다면
    {
        // 노드 j를 "노드 i의 부모 노드"로 지정
        // == "집합 i의 루트 노드"를 "집합 j의 루트 노드"로 지정
        parent[i] = j;
        parent[j] = temp; // 집합 j의 원소 수 업데이트
    }
    else
    {
        parent[j] = i;
        parent[i] = temp;
    }
}

int do_advanced_find(int i, int *parent)
{
    // 붕괴 규칙이 적용된 find연산
    int root = i; // root를 i로 초기화
    int trail = i;
    int lead;

    // 1. 먼저 노드 i가 속한 트리의 root를 찾는다.
    while (parent[root] >= 0)
    {
        root = parent[root];
    }

    // trail이 따라 올라가며 자식 노드의 원소를 현재 루트 노드의 값으로 갱신
    while (trail != root)
    {
        lead = parent[trail];
        parent[trail] = root;
        trail = lead;
    }

    return root;
}

int main()
{
    // -1 : root
    // 양수 : 자식 노드, 부모 노드 = 원소 값
    // int parent[] = {-1, 4, -1, 2, -1, 2, 0, 0, 0, 4};
    // int parent2[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1}; // 변질 트리 케이스
    // 음수 : root, 값은 해당 트리가 포함하는 원소의 총 개수
    // 양수 : 자식 노드, 부모 노드 = 원소 값
    int parent3[] = {-4, 4, -3, 2, -3, 2, 0, 0, 0, 4};

    // 초기 상태 출력
    cout << "Initial parent array: ";
    for (int i = 0; i < 10; i++)
    {
        cout << parent3[i] << " ";
    }
    cout << endl;

    // 몇 개의 union 연산을 수행하여 집합을 결합
    do_advanced_union(0, 1, parent3);
    cout << "done" << endl;
    do_advanced_union(2, 3, parent3);
    cout << "done" << endl;
    do_advanced_union(4, 5, parent3);
    cout << "done" << endl;
    do_advanced_union(0, 2, parent3); // (0, 1)과 (2, 3)의 집합을 결합
    cout << "done" << endl;
    do_advanced_union(4, 0, parent3); // 모든 노드를 하나의 집합으로 결합
    cout << "done" << endl;

    cout << "after union parent array: ";
    for (int i = 0; i < 10; i++)
    {
        cout << parent3[i] << " ";
    }
    cout << endl;

    // find 연산 수행 및 경로 압축 확인
    for (int i = 0; i < 10; i++)
    {
        int temp = do_advanced_find(i, parent3);
        cout << "Root of node " << i << ": " << temp << endl;
    }

    // 최종 parent 배열 출력
    cout << "Final parent array: ";
    for (int i = 0; i < 10; i++)
    {
        cout << parent3[i] << " ";
    }
    cout << endl;

    return 0;

    // //간단한 유니온 연산 케이스
    // int root = do_simple_find(0, parent);
    // cout << "root : " << root << endl;
    // // 0번 노드의 루트 노드는 0

    // do_simple_union(0, 2, parent);
    // root = do_simple_find(0, parent);
    // cout << "root : " << root << endl;
    // // 합집합 연산 후, 0번 노드의 부모는 2가 됨.

    // //간단한 유니온 연산에 의한 변질 트리 케이스
    //  for (int i = 0; i < 10 - 1; i++)
    //  {
    //      do_simple_union(i, i + 1, parent2);
    //      root = do_simple_find(0, parent2);
    //      cout << "root : " << root << endl;
    //  }
    //  root = do_simple_find(0, parent2);
    //  cout << "root : " << root << endl;
}