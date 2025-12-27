
/*
TC -O(N)
SC-O(N)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int min_val = 1e9, max_val = -1e9;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < min_val) min_val = a[i];
        if (a[i] > max_val) max_val = a[i];
    }
    if (min_val == max_val) {
        cout << 1LL * n * (n - 1) << endl;
        return;
    }
    long long count_min = 0;
    long long count_max = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == min_val) count_min++;
        if (a[i] == max_val) count_max++;
    }
    cout << 2 * count_min * count_max << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}