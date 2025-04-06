#include <iostream>

using namespace std;


namespace linearProbing
{
    const int P = 97;
    int hashTable[P] = {0};
    void insert(int x)
    {
        int i = x % P;
        while (hashTable[i] != 0)
        {
            i = (i + 1) % P;
        }
        hashTable[i] = x;
    }
    void search(int x)
    {
        int i = x % P;
        while (hashTable[i] != x && hashTable[i] != 0)
        {
            i = (i + 1) % P;
        }
        if (hashTable[i] == x)
        {
            cout << "Found\n";
        }
        else
        {
            cout << "Not found\n";
        }
    }
    void remove(int x)
    {
        int i = x % P;
        while (hashTable[i] != x && hashTable[i] != 0)
        {
            i = (i + 1) % P;
        }
        if (hashTable[i] == x)
        {
            hashTable[i] = -1;
        }
    }
}

namespace chaining
{
    const int P = 97;
    struct Node
    {
        int data;
        Node *next;
    };
    Node *hashTable[P] = {NULL};
    void insert(int x)
    {
        int i = x % P;
        Node *newNode = new Node;
        newNode->data = x;
        newNode->next = hashTable[i];
        hashTable[i] = newNode;
    }
    void search(int x)
    {
        int i = x % P;
        Node *cur = hashTable[i];
        while (cur != NULL && cur->data != x)
        {
            cur = cur->next;
        }
        if (cur != NULL)
        {
            cout << "Found\n";
        }
        else
        {
            cout << "Not found\n";
        }
    }
    void remove(int x)
    {
        int i = x % P;
        Node *cur = hashTable[i];
        Node *prev = NULL;
        while (cur != NULL && cur->data != x)
        {
            prev = cur;
            cur = cur->next;
        }
        if (cur != NULL)
        {
            if (prev == NULL)
            {
                hashTable[i] = cur->next;
            }
            else
            {
                prev->next = cur->next;
            }
            delete cur;
        }
    }
}