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
            newRoot -> isLeaf = false;
            newRoot -> updateMBR();
            RN -> par = P.second -> par = newRoot;
        }
    }
}

