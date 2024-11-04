#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->value = data;
        this->left = this->right = nullptr;
    }
};

void bfs(Node *root)
{
    // 입력 체크
    if (root == nullptr)
        return;

    queue<Node *> que;
    que.push(root);

    // 재귀함수가 아님에 주의!
    while (!que.empty())
    {
        Node *temp = que.front();
        que.pop();
        cout << temp->value << " ";
        if (temp->left != nullptr)
            que.push(temp->left);
        if (temp->right != nullptr)
            que.push(temp->right);
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    bfs(root);
    return 0;
}