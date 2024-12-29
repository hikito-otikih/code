#include <iostream>

using namespace std;


struct Node
{   
    int data;
    Node *next;
    Node(int x = 0) : data(x), next(NULL) {}
};

struct Queue
{
    Node *head, *tail;
    int curSize;
    Queue() : head(NULL), tail(NULL), curSize(0) {}
    void enQueue(int x)
    {
        Node *p = new Node(x);
        if (head == NULL) head = tail = p;
        else
        {
            tail->next = p;
            tail = p;
        }
        curSize ++;
    }
    bool deQueue(int &x)
    {
        if (head == NULL) return 0;
        Node *p = head;
        x = p->data;
        if (head == tail) head = tail = NULL;
        else head = head->next;
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
    void clear()
    {
        while (head != NULL)
        {
            Node *p = head;
            head = head->next;
            delete p;
        }
        tail = NULL;
        curSize = 0;
    }
};

int main()
{
    return 0;
}