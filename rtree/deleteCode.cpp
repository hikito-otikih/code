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