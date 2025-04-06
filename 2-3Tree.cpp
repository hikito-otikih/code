#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    int data[10], numNode, numChild;
    Node *child[10];
    Node ()
    {
        numNode = 0;
        numChild = 0;
        for (int i = 0; i < 10; i++)
        {
            data[i] = 0;
            child[i] = NULL;
        }
    }
};

void insert(Node *root, int data)
{
    for (int i = 0; i < root -> numNode; i ++) 
        if (data == root -> data[i]) return;
    if (root -> numChild == 0) 
    {
        root -> data[root -> numNode] = data;
        root -> numNode++;
        sort(root->data, root -> data + root -> numNode);
    }
    else
    {
        for (int i = 0; i < root -> numNode; i ++)
            if (data < root -> data[i])
            {
                insert(root -> child[i], data);
                return;
            }
        insert(root -> child[root -> numNode], data);
    }
}

void balance(Node *root)
{
    for (int i = 0; i < root -> numChild; i ++) balance(root -> child[i]);
    for (int i = 0; i < root -> numChild; i ++)
        if (root -> child[i] -> numChild == 3)  
        {
            root -> numChild ++;
            for (int j = i + 1; j < root -> numChild; j ++)
                root -> child[j] = root -> child[j - 1];
            root -> child[i] = new Node;
            root -> child[i + 1] = new Node;
        }
}

Node *root = new Node;

int main()
{
}