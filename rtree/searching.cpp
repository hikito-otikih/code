#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data, n;
    bool isLeaf;
    Node *child[10];
    Region* region;
    Node *par;
    int calcArea() ;
    int calcAreaExtend(Region* R) ;
    void updateMBR() ;
    Node(Region* R) {
        region = R;
        isLeaf = true;
        n = 0;
        for (int i = 0; i < 10; i++) child[i] = NULL;
    }
    pair<Node *, Node *> splitNode();
    void remove(Region *E) ;
};

struct Region
{
    int low;
    int high;
    bool intersect(Region* Q) {
        return (low <= Q -> high && high >= Q -> low);
    }
    bool contain(Region* Q) {
        return (low <= Q -> low && high >= Q -> high);
    }
};


int m, M;

void Insert(Region *E, Node *RN) {
    if (RN -> isLeaf) {
        RN -> child[RN -> n ++] = new Node(E);
    }
    else {
        Node *target = NULL;
        int minArea = INT_MAX;
        for (int i = 0; i < RN -> n; i++)  
            if (minArea > RN -> child[i] -> calcAreaExtend(E)) {
                minArea = RN -> child[i] -> calcAreaExtend(E);
                target = RN -> child[i];
            }
            else
                if (minArea == RN -> child[i] -> calcAreaExtend(E) && target -> calcArea() > RN -> child[i] -> calcArea()) {
                    target = RN -> child[i];
                }
        Insert(E, target);
    }
    if (RN -> n > M) {
        pair<Node *, Node *> P = RN -> splitNode();
        RN = P.first;
        if (RN -> par) {
            RN -> par -> child[RN -> par -> n ++] = P.second;
            RN -> par -> updateMBR();
        }
        else {
            Node *newRoot = new Node(NULL);
            newRoot -> child[0] = RN;
            newRoot -> child[1] = P.second;
            newRoot -> n = 2;
            newRoot -> updateMBR();
            RN -> par = P.second -> par = newRoot;
        }
    }
}


Node* FindNode(Region *E, Node *RN) {
    if (RN -> isLeaf) {
        for (int i = 0; i < RN -> n; i ++)
            if (E == RN -> child[i] -> region) return RN;
        return NULL;
    }
    Node *temp = NULL;
    for (int i = 0; i < RN -> n; i ++)
        if (RN -> child[i] -> region -> contain(E)) {
            temp = FindNode(E, RN -> child[i]);
            if (temp) return temp;
        }
}

void removeChild(Node *E, vector<Region*> &N) {
    if (E -> isLeaf) {
        for (int i = 0; i < E -> n; i ++)
            N.push_back(E -> child[i] -> region);
    }
    else
        for (int i = 0; i < E -> n; i ++)
            E -> child[i] -> removeChild(E -> child[i], N);
    delete E;
}

void delete(Region *E) {
    Node *L = FindNode(E, root);
    if (L == NULL) return;
    L -> remove(E);
    vector<Region *E> N;
    while (L != root) {
        if (L -> n < m) {
            Node *P = L -> par;
            removeChild(L, N);
        }
        else {
            L -> updateMBR();
            L = L -> par;
        }
    }
    for (int i = 0; i < N.size(); i ++)
        Insert(N[i], root);
    if (root -> n == 1) {
        Node *temp = root;
        root = root -> child[0];
        delete temp;
    }
}