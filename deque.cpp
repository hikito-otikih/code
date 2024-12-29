#include <iostream>

using namespace std;

struct Node
{   
    int data;
    Node *next, *prev;
    Node(int x = 0) : data(x), next(NULL), prev(NULL) {}
};

struct Deque
{
    Node *head, *tail;
    int curSize;
    Deque() : head(NULL), tail(NULL), curSize(0) {}
    void pushFront(int x)
    {
        Node *p = new Node(x);
        if (head == NULL) head = tail = p;
        else
        {
            p->next = head;
            head->prev = p;
            head = p;
        }
        curSize ++;
    }
    void pushBack(int x)
    {
        Node *p = new Node(x);
        if (head == NULL) head = tail = p;
        else
        {
            tail->next = p;
            p->prev = tail;
            tail = p;
        }
        curSize ++;
    }
    bool popFornt(int &x)
    {
        if (head == NULL) return 0;
        Node *p = head;
        x = p->data;
        if (head == tail) head = tail = NULL;
        else
        {
            head = head->next;
            head->prev = NULL;
        }
        delete p;
        curSize --;
        return 1;
    }
    bool popBack(int &x)
    {
        if (head == NULL) return 0;
        Node *p = tail;
        x = p->data;
        if (head == tail) head = tail = NULL;
        else
        {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete p;
        curSize --;
        return 1;
    }
    int getSize()
    {
        return curSize;
    }
    bool isEmpty()
    {
        return curSize == 0;
    }
};

int main()
{
    return 0;
}