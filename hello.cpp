#include <bits/stdc++.h>
using namespace std;

struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    }
};

int main() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    pq.push({1, 2});
    return 0;
}