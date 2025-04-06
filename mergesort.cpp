#include <bits/stdc++.h>
using namespace std;

#include "abc.h"

void merge(vector<int> &arr, int l, int r) {
    if (l == r) return; // Base case: single element
    int mid = (l + r) / 2;
    merge(arr, l, mid); // Sort left half
    merge(arr, mid + 1, r); // Sort right half

}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size();
    abc::print_a(); // Call function from abc.h
    return 0;
}