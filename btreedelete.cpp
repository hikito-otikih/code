#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

struct Val {
  bool ok;
  int max, min, sz, ans;
};

Val maxBST(Node *root) {
    if (root == NULL) {
        return {true, INT_MAX, INT_MIN, 0, 0};
    }

    Val left = maxBST(root->left);
    Val right = maxBST(root->right);

    if (left.ok && right.ok && root->data > left.max && root->data < right.min) {
        return {true, max(root->data, right.max), min(root->data, left.min), left.sz + right.sz + 1, left.sz + right.sz + 1};
    }

    return {false, INT_MAX, INT_MIN, left.sz + right.sz + 1, max(left.ans, right.ans)};
}

int main() {
    return 0;
}