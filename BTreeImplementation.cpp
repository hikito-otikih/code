#include <bits/stdc++.h>    

using namespace std;

class Node {
    public: 
        int *keys;
        int degree; // Maximum number of keys : degree - 1, minimum number of keys : degree / 2 - 1
        Node **C;
        int n; // Number of keys
        bool leaf;
        Node (int _degree, bool _leaf) {
            degree = _degree;
            leaf = _leaf;
            keys = new int[degree - 1 + 5];
            C = new Node *[degree + 5];
            n = 0;
        }
        void splitChild(int i, Node *y);
        void insertNonFull(int k);
        void Delete(int k);
        Node *leftMost();
        void traverse();
};

class BTree {
    public:
        Node *root;
        int degree;
        BTree(int _degree) {
            root = NULL;
            degree = _degree;
        }
        void insert(int k);
        void Delete(int k);
        void DeleteLeaf(Node *x, int k);
        Node* Search(int k);
        void traverse() {
            if (root != NULL) root -> traverse();
            cout << endl;
        }
};

int main()
{
    return 0;
}

void BTree::insert(int k) {
    if (root == NULL) {
        root = new Node(degree, true);
        root -> keys[0] = k;
        root -> n = 1;
    }
    else {
        root -> insertNonFull(k);
        if (root -> n == degree) {
            Node *s = new Node(degree, false);
            s -> C[0] = root;
            s -> splitChild(0, root);
            root = s;
        }
    }
}

void Node::insertNonFull(int k) {
    int i = n - 1;
    if (leaf) {
        while (i >= 0 && k < keys[i]) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
        n++;
    }
    else  {
        while (i >= 0 && k < keys[i]) i--; 
        C[i + 1] -> insertNonFull(k);
        if (C[i + 1] -> n == degree) {
            splitChild(i + 1, C[i + 1]);
        }
    }
}

void Node::splitChild(int i, Node *y) {
    /// curren y has degree keys
    /// one key is moved to this node
    /// new left child (Node y) has degree / 2 keys
    /// new right child (Node z) has (degree - 1) / 2 keys
    Node *z = new Node(y -> degree, y -> leaf);
    z -> n = (degree - 1) / 2;
    for (int j = 0; j < (degree - 1) / 2; j++) z -> keys[j] = y -> keys[j + degree / 2 + 1];
    if (!y -> leaf) {
        for (int j = 0; j < (degree - 1) / 2 + 1; j++) z -> C[j] = y -> C[j + degree / 2 + 1];
    }
    y -> n = degree / 2;
    for (int j = n; j >= i + 1; j--) C[j + 1] = C[j];
    C[i + 1] = z;
    for (int j = n - 1; j >= i; j--) keys[j + 1] = keys[j];
    keys[i] = y -> keys[degree / 2];
    n ++;
}

Node *Node::leftMost() {
    if (leaf) return this;
    return C[0] -> leftMost();
}

void BTree::Delete(int k) {
    Node *x = Search(k);
    if (!x) return;
    int i = 0;
    if (x->leaf == false) {
        while (i < x -> n && k > x -> keys[i]) i++;
        Node *y = x -> C[i + 1] -> leftMost();
        x -> keys[i] = y -> keys[0];
        DeleteLeaf(y, y -> keys[0]);
    }
    else DeleteLeaf(x, k);

}

void BTree::DeleteLeaf(Node *x, int k) {
}

Node *BTree::Search(int k) {
    if (!root) return NULL;
    Node *cur = root;
    while (true) {
        int i = 0;
        while (i < cur -> n && k > cur -> keys[i]) i++;
        if (i < cur -> n && k == cur -> keys[i]) return cur;
        if (cur -> leaf) return NULL;
        cur = cur -> C[i];
    }
}

void Node::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (!leaf) C[i] -> traverse();
        cout << " " << keys[i];
    }
    if (!leaf) C[i] -> traverse();
}