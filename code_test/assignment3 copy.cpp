#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int number;
    int value;
    int order;
    Node *left = NULL;
    Node *right = NULL;
};

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

vector<int> preorder(Node *root, vector<int> list)
{
    if (root == NULL)
        return list;

    list.push_back(root->number);
    list = preorder(root->left, list);
    list = preorder(root->right, list);

    return list;
}

vector<int> postorder(Node *root, vector<int> list)
{
    if (root == NULL)
        return list;

    list = postorder(root->left, list);
    list = postorder(root->right, list);
    list.push_back(root->number);

    return list;
}

bool cmp(Node a, Node b)
{
    return a.order > b.order;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    // node number : index + 1
    // node weight : x
    // node order : y

    // 1. make node list
    vector<Node> node_list;
    for (int i = 0; i < nodeinfo.size(); i++)
    {
        Node temp;
        temp.number = i + 1;
        temp.value = nodeinfo[i][0];
        temp.order = nodeinfo[i][1];
        node_list.push_back(temp);
    }

    // 2. sort
    sort(node_list.begin(), node_list.end(), cmp);

    // 3. write tree
    Node *root = NULL;
    for (int i = 0; i < node_list.size(); i++)
    {
        insert(&root, node_list[i]);
    }

    // 3. do dfs
    vector<vector<int>> answer;
    vector<int> preorder_list;
    vector<int> postorder_list;

    preorder_list = preorder(root, preorder_list);
    postorder_list = postorder(root, postorder_list);

    answer.push_back(preorder_list);
    answer.push_back(postorder_list);

    return answer;
}