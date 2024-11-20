#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *Next;
};


struct LinkedList
{
    Node *Head;
    Node *Tail;
    void Insert(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->Next = NULL;
        if (Head == NULL)
        {
            Head = Tail = newNode;
        }
        else
        {
            Tail->Next = newNode;
            Tail = newNode;
        }
    }
    void insertAfterX(int x, int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        Node *p = Head;
        while (p != NULL && p->data != x)
        {
            p = p->Next;
        }
        if (p == NULL)
        {
            cout << "Not found " << x << endl;
        }
        else
        {
            newNode->Next = p->Next;
            p->Next = newNode;
        }
    }
};

int main()
{
    LinkedList List = {NULL, NULL};  
    return ;    
}