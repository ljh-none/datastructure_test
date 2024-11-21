#include <iostream>
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

void inorder(Node *root)
{
    // 처음부터 빈 트리 or leaf node일 때
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
    //재귀함수 호출 순서를 바꿈으로써 preorder, postorder가 된다.
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    inorder(root);
    return 0;
}