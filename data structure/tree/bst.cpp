#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    class Node *left;
    class Node *right;

    Node(int data)
    {
        value = data;
        left = NULL;
        right = NULL;
    }
};

void printBST(Node *node)
{
    if (node != NULL)
    {
        printBST(node->left);
        cout << node->value << " ";
        printBST(node->right);
    }
}

void insert(Node *root, int value)
{
    // call by value
    //  root must be defined

    // 1. generate new node
    Node *newnode = new Node(value);
    newnode->right = NULL;
    newnode->left = NULL;

    // 2. goto leaf node
    while (root != NULL)
    {
        if (root->value > value)
        {
            if (root->left == NULL)
            {
                root->left = newnode;
                return;
            }
            root = root->left;
        }
        else if (root->value < value)
        {
            if (root->right == NULL)
            {
                root->right = newnode;
                return;
            }
            root = root->right;
        }
    }
    cout << "err" << endl;
    return;
}

int main()
{
    Node *root = new Node(10);
    // root->left = new Node(5);
    // root->right = new Node(15);
    // root->right->left = new Node(12);
    // root->right->right = new Node(18);
    insert(root, 5);
    insert(root, 15);
    insert(root, 12);
    insert(root, 18);
    printBST(root);
    return 0;
}