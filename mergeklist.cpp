#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct cmp
{
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        for (auto list : lists)
        {
            if (list)
                pq.push(list);
        }
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        while (!pq.empty())
        {
            ListNode *top = pq.top();
            pq.pop();
            cur->next = top;
            cur = cur->next;
            if (top->next)
                pq.push(top->next);
        }
        return head->next;
    }
};