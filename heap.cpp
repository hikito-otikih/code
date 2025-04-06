#include <iostream>
#include <vector>
using namespace std;

struct Heap {
    vector<int> heap;
    int n;
    Heap() {
        heap.clear();
        n = 0;
    }
    void insert(int x) {
        heap.push_back(x);
        n ++;
        int i = n - 1;
        while ((i - 1) >= 0) {
            if (heap[(i - 1) / 2] < heap[i]) {
                swap(heap[(i - 1) / 2], heap[i]);
                i = (i - 1) / 2;
            } else {
                break;
            }
        }
    }
    int top() {
        swap(heap[0], heap[n - 1]);
        int i = 0;
        while (i < n) {
            int target = 2 * i + 1;
            if (target >= n) {
                break;
            }
            if (heap[target] < heap[target + 1]) {
                target ++;
            }   
            if (heap[i] < heap[target]) {
                swap(heap[i], heap[target]);
                i = target;
            } else {
                break;
            }
        }
        int ret = heap[n - 1];
        heap.pop_back();
        n --;
        return ret;
    }
};