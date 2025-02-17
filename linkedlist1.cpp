#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void remOdd(ListNode * &head)
{
    ListNode *ans = new ListNode(0), *res = ans;
    ListNode *current = head;
    while (current)
    {
        ListNode *temp = current;
        current = current->next;
        if (temp -> data % 2 == 0)
        {
            ans -> next = temp;
            ans = ans -> next;
        }
        else delete temp;
    }
    ans -> next = NULL;
    head = res->next;
    delete res;
}

void rem2NodeX(ListNode * &head, int x)
{
    int c = x / 2;
    ListNode *current = head;
    ListNode *prev = NULL;
    if (x & 1)
    {
        while (current && current -> data <= c)
        {
            prev = current;
            current = current -> next;
        }
        if (prev == NULL) return ;        
    }
    else
    {
        int cnt = 0;
        while (current)
        {
            cnt += current -> data == c;
            current = current -> next;
        }
        current = head;   
        int cnt2 = 0;
        while (current)
        {
            cnt2 += current -> data == c;
            if (cnt == 0)
                if (current -> data > c) break ;
            if (cnt2 == cnt / 2 + 1) break;
            prev = current; 
            current = current -> next;
        }
        if (prev == NULL) return ;
    }   
    ListNode *NEWEra = prev -> next;
    prev -> next = NULL;
    prev = NULL;
    while (NEWEra)
    {
        ListNode *temp = NEWEra -> next;
        NEWEra -> next = prev;
        prev = NEWEra;
        NEWEra = temp;
    }
    ListNode *c1 = new ListNode(0), *c2 = c1, *c3 = c1;
    ListNode *d1 = new ListNode(0), *d2 = d1, *d3 = d1;
    c2 -> next = head;
    d2 -> next = prev;
    c2 = c2 -> next;
    d2 = d2 -> next;
    while (c2 && d2)
    {
        int sum = c2 -> data + d2 -> data;
        if (sum == x)
        {
            c3 -> next = c2 -> next;
            d3 -> next = d2 -> next;

            ListNode *temp = c2;
            c2 = c2 -> next;
            delete temp;
            temp = d2;
            d2 = d2 -> next;
            delete temp;
        }
        else
            if (sum < x)
            {
                c3 = c2;
                c2 = c2 -> next;
            }
            else
            {
                d3 = d2;
                d2 = d2 -> next;
            }
    }

    head = c1 -> next;
    c3 -> next = d1 -> next;

    delete c1;
    delete d1;
}

int main()
{
    // 9 23 27 38 44 56
    ListNode *head = new ListNode(9);
    ListNode *second = new ListNode(23);
    ListNode *third = new ListNode(27);
    ListNode *fourth = new ListNode(38);
    ListNode *fifth = new ListNode(44);
    ListNode *sixth = new ListNode(56);
    ///
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    
    rem2NodeX(head, 65);
    //remOdd(head);

    ListNode *current = head;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
    return 0;
}