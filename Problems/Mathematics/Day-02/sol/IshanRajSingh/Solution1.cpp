/*
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    
    // Read first element to initialize min and max
    cin >> a[0];
    int min_val = a[0];
    int max_val = a[0];
    
    // Read remaining elements and update min/max
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        min_val = min(min_val, a[i]);
        max_val = max(max_val, a[i]);
    }
    
    // If all elements are same
    if (min_val == max_val) {
        cout << (long long)n * (n - 1) << "\n";
        return;
    }
    
    // Count min and max occurrences
    long long cnt_min = 0, cnt_max = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == min_val) cnt_min++;
        if (a[i] == max_val) cnt_max++;
    }
    
    // Answer is 2 * (number of max elements) * (number of min elements)
    cout << 2LL * cnt_max * cnt_min << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
