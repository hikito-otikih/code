#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *next;
};

void asi(node *x)
{
    node *newNode = new node;
    newNode->data = 2;
    newNode->next = NULL;
    x->next = newNode;
    cout << x->next->data;
}

int main()
{
    node *head = new node;
    head->data = 1;
    head->next = NULL;
    asi(head);
    cout << head->next->data;
    return 0;
}