#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *left, *right;
};

bool compare(Node *root1, Node *root2)
{
    if(root1 == NULL && root2 == NULL)
        return true;
    if(root1 == NULL || root2 == NULL)
        return false;
    return (root1->data == root2->data) && compare(root1->left, root2->left) && compare(root1->right, root2->right);
}

bool isSubtree(Node *root1, Node *root2)
{
    if(root2 == NULL)
        return true;
    if(root1 == NULL)
        return false;
    if(compare(root1, root2))
        return true;
    return isSubtree(root1->left, root2) || isSubtree(root1->right, root2);
}

int main()
{
    for (int i = 1; i <= 12; i ++) cout << 1000 * (int)pow(i, 12 - i) << endl;
    return 0;
}