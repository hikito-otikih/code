#include <bits/stdc++.h>    

using namespace std;

class Node {
    public: 
        int *keys;
        int degree; /// adapting to BTree with odd degree like 23Tree (BTree with degree 3)
        Node **C;
        int n; 
        bool leaf;
        Node (int _degree, bool _leaf) {
            degree = _degree; /// default degree is 3 for 23Tree
            leaf = _leaf;
            keys = new int[degree - 1 + 5];
            C = new Node *[degree + 5];
            n = 0;
        }
        void splitChild(int i, Node *y);
        void insertNonFull(int k);
        void traverse();
};

class BTree {
    public:
        Node *root;
        int degree;
        BTree(int _degree = 3) {
            root = NULL;
            degree = _degree;
        }
        void insert(int k);
        void search(int k);
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
    /// new right child (Node z) has degree / 2 keys
    Node *z = new Node(y -> degree, y -> leaf);
    z -> n = degree / 2;
    for (int j = 0; j < degree / 2; j++) z -> keys[j] = y -> keys[j + degree / 2 + 1];
    if (!y -> leaf) {
        for (int j = 0; j <= degree / 2; j++) z -> C[j] = y -> C[j + degree / 2 + 1];
    }
    y -> n = degree / 2;
    for (int j = n; j >= i + 1; j--) C[j + 1] = C[j];
    C[i + 1] = z;
    for (int j = n - 1; j >= i; j--) keys[j + 1] = keys[j];
    keys[i] = y -> keys[degree / 2];
    n ++;
}

void Node::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (!leaf) C[i] -> traverse();
        cout << " " << keys[i];
    }
    if (!leaf) C[i] -> traverse();
}

void BTree::search(int k) {
    if (root == NULL) {
        cout << "Empty tree\n";
        return;
    }
    Node *cur = root;
    while (cur != NULL) {
        int i = 0;
        while (i < cur -> n && k > cur -> keys[i]) i++;
        if (cur -> keys[i] == k) {
            cout << "Found\n";
            return;
        }
        if (cur -> leaf) {
            cout << "Not found\n";
            return;
        }
        cur = cur -> C[i];
    }
}