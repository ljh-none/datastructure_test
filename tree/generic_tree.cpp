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

int main()
{
    Node *root = new Node(0); // new는 포인터이므로 붙여줌

    root->insert(1);
    root->insert(2);
    root->insert(3);

    cout << "Root data: " << root->data << endl;
    root->print_children();

    Node *child = root->get_child(2);
    if (child == nullptr)
    {
        cout << "child not found" << endl;
        return 0;
    }
    cout << "child data: " << child->data << endl;
    child->insert(4);
    child->insert(5);
    child->insert(6);
    child->print_children();

    // 동적 할당 해제
    delete root;
    return 0;

    // tree.addChild(root, 2);
    // tree.addChild(root, 3);
    // tree.addChild(root, 4);

    // // 2번 노드의 자식 추가
    // tree.addChild(root->children[0], 5);
    // tree.addChild(root->children[0], 6);

    // // 3번 노드의 자식 추가
    // tree.addChild(root->children[1], 7);

    // // 4번 노드의 자식 추가
    // tree.addChild(root->children[2], 8);
    // tree.addChild(root->children[2], 9);

    // // 트리 출력 (DFS)
    // cout << "Tree structure (DFS):" << endl;
    // tree.printTreeDFS(root);

    // return 0;
}