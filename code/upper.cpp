#include <iostream>
#include <vector>

using namespace std;

int upper_bound(vector<int>& a, int target) {
    int l = 0;
    int r = a.size();
    while (l < r) {
        int m = l + (r - l) / 2;
        if (a[m] <= target) l = m + 1;
        else r = m;
    }
    return r;
}

int lower_bound(vector<int>& a, int target) {
    int l = 0;
    int r = a.size();
    while (l < r) {
        int m = l + (r - l) / 2;
        if (a[m] < target) l = m + 1;
        else r = m;
    }
    return r;
}

int main() {
    vector<int> a{1,2,3,3,4,4,5,6,6,7,9,10};
    for (auto x : a) cout << x << " "; cout << endl;
    for (int i = 0; i < a.size(); ++i) cout << i << " "; cout << endl;
    int up = upper_bound(a, 5);
    int lo = lower_bound(a, 5);
    cout << "up " << up << endl;
    cout << "lo " << lo << endl;
    return 0;
}
