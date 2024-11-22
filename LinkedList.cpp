#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *Next;
};

struct linkedList
{
    Node *Head;
    Node *Tail;
    void addBeforeX(int x, int y)
    {
        Node *newNode = new Node;
        newNode->data = y;
        newNode->Next = NULL;
        Node *current = Head;
        Node *prev = NULL;
        while (current != NULL)
        {
            if (current->data == x)
            {
                if (prev == NULL)
                {
                    newNode->Next = Head;
                    Head = newNode;
                }
                else
                {
                    prev->Next = newNode;
                    newNode->Next = current;
                }
                return;
            }
            prev = current;
            current = current->Next;
        }
    }
};

int main()
{
    linkedList *list = new linkedList;
    list->Head = NULL;
    list->Tail = NULL;
    while(true)
    {
        int x;
        cin >> x;
        if (x == 0) break;
        Node *newNode = new Node;
        newNode->data = x;  
        newNode->Next = NULL;
        if (list->Head == NULL)
        {
            list->Head = newNode;
            list->Tail = newNode;
        }
        else
        {
            list->Tail->Next = newNode;
            list->Tail = newNode;
        }
    }
    list->addBeforeX(7, 5);
    Node *current = list->Head;
    while (current != NULL)
    {
        cout << current->data << ' ';
        current = current->Next;
    }
    return 0;    
}