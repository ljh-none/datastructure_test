#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int number; // index + 1
    int value;  // x
    int order;  // y
    Node *left = NULL;
    Node *right = NULL;
};

// bst insert
void insert(Node **root, Node node)
{
    if (*root == NULL)
    {
        *root = new Node(node);
        return;
    }

    if ((*root)->value < node.value)
    {
        insert(&(*root)->right, node);
    }
    else
    {
        insert(&(*root)->left, node);
    }
}

// call by reference
void preorder(Node *root, vector<int> &list)
{
    if (root == NULL)
        return;

    list.push_back(root->number);
    preorder(root->left, list);
    preorder(root->right, list);
}

// call by reference
void postorder(Node *root, vector<int> &list)
{
    if (root == NULL)
        return;

    postorder(root->left, list);
    postorder(root->right, list);
    list.push_back(root->number);
}

// for cpp sort, descending order
bool cmp(Node a, Node b)
{
    return a.order > b.order;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    // node number : index + 1
    // node weight : x
    // node order : y

    // 1. sort
    // make node list for sort
    vector<Node> node_list;
    for (int i = 0; i < nodeinfo.size(); i++)
    {
        Node temp;
        temp.number = i + 1;
        temp.value = nodeinfo[i][0];
        temp.order = nodeinfo[i][1];
        node_list.push_back(temp);
    }
    sort(node_list.begin(), node_list.end(), cmp);

    // 2. write tree
    Node *root = NULL;
    for (int i = 0; i < node_list.size(); i++)
    {
        insert(&root, node_list[i]);
    }

    // 3. do dfs
    vector<vector<int>> answer;
    vector<int> preorder_list;
    vector<int> postorder_list;

    preorder(root, preorder_list);
    postorder(root, postorder_list);

    answer.push_back(preorder_list);
    answer.push_back(postorder_list);

    return answer;
}