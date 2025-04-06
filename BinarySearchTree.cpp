#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *left, *right;
        Node(int _data)
        {
            data = _data;
            left = right = NULL;
        }
};

Node* insert(Node *root, int data)
{
    if (root == NULL)
        return new Node(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

Node* search(Node *root, int data)
{
    if (root == NULL || root->data == data)
        return root;
    if (root->data < data)
        return search(root->right, data);
    return search(root->left, data);
}

void displayLNR(Node *root)
{
    if (root != NULL)
    {
        displayLNR(root->left);
        cout << root->data << " ";
        displayLNR(root->right);
    }
}

void displayNLR(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        displayNLR(root->left);
        displayNLR(root->right);
    }
}

void displayLRN(Node *root)
{
    if (root != NULL)
    {
        displayLRN(root->left);
        displayLRN(root->right);
        cout << root->data << " ";
    }
}

Node* findMin(Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node *root, int key)
{
    if (root == NULL) return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
        else
        {
            if (root -> left == NULL || root -> right == NULL)
            {
                Node *temp = root->left ? root->left : root->right;
                delete root;
                root = temp;
            }
            else
            {
                Node *temp = findMin(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
    return root;
}

void deleteTree(Node *root)
{
    if (root != NULL)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main()
{
    Node *root = NULL;
    return ;
}