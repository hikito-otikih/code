#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node *left, *right;
        int height;
        Node(int _data)
        {
            data = _data;
            left = right = NULL;
            height = 1;
        }
        int getBalanceFactor()
        {
            int leftHeight = (left == NULL) ? 0 : left->height;
            int rightHeight = (right == NULL) ? 0 : right->height;
            return leftHeight - rightHeight;
        }
        int getHeight()
        {
            int leftHeight = (left == NULL) ? 0 : left->height;
            int rightHeight = (right == NULL) ? 0 : right->height;
            return 1 + max(leftHeight, rightHeight);
        }
};

class AVL
{
    public:
        Node *root;
        AVL()
        {
            root = NULL;
        }
        Node* insert(Node *root, int data);
        Node* rotateRight(Node *root);
        Node* rotateLeft(Node *root);
};

int main()
{
    return 0;
}

Node *AVL::rotateRight(Node *root)
{
    Node *newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    root->height = root->getHeight();
    newRoot->height = newRoot->getHeight();
    return newRoot;
}

Node *AVL::rotateLeft(Node *root)
{
    Node *newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    root->height = root->getHeight();
    newRoot->height = newRoot->getHeight();
    return newRoot;
}

Node *AVL::insert(Node *root, int data)
{   
    if (root == NULL)
        return new Node(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root;
    root->height = root->getHeight();
    int balanceFactor = root->getBalanceFactor();
    if (balanceFactor > 1)
    {
        if (data < root->left->data)
            return rotateRight(root);
        else
        {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }   
    }
    if (balanceFactor < -1)
    {
        if (data > root->right->data)
            return rotateLeft(root);
        else
        {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }
    return root;
}