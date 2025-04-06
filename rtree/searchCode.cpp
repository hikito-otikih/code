vector<Region *> RangeSearch(Node* RN, Region* Q) {
    if (RN == NULL) return ;
    vector<Region *> A;
    if (RN -> isLeaf()) {
        for (int i = 0; i < RN -> n; i++) {
            if (Q -> intersect(RN -> child[i] -> region)) 
                A.push_back(RN -> child[i] -> region);
        }
    }
    else 
        for (int i = 0; i < RN -> n; i++) {
            if (Q -> intersect(RN -> child[i] -> region))
                vector<Region *> Res = RangeSearch(RN -> child[i], Q);
                A.insert(A.end(), Res.begin(), Res.end());
        }
    return A;
}
