#include <iostream>
#include <vector>

using namespace std;

void adjustHeap(vector<int>& a, int idx, int length) {
    int tmp = a[idx];
    for (int i = idx * 2 + 1; i < length; i = i * 2 + 1) {
        if (i + 1 < length && a[i] < a[i + 1])  ++i;
        if (a[i] > tmp) {
            a[idx] = a[i];
            idx = i;
        } else break;
    }
    a[idx] = tmp;
}

void heapSort(vector<int>& a) {
    // build
    for (int i = a.size() / 2 - 1; i >= 0; --i)
        adjustHeap(a, i, a.size());
    // adjust
    for (int i = a.size() - 1; i > 0; i--) {
        swap(a[0], a[i]);
        adjustHeap(a, 0, i);
    }
}

int main() {
    vector<int> arr{6,3,2,4,7,5,1};
    heapSort(arr);
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
