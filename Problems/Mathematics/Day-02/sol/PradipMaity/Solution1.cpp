/*
We need pairs (i, j), i != j such that 
|ai - aj| equals maximum absolute difference in array.

Maximum absolute difference = max(a) - min(a)

Two cases:

1) If all values equal:
   All pairs are valid → n * (n - 1)

2) Otherwise:
   Valid pairs must be (min, max) or (max, min)
   Count frequency of min and max:
   Answer = 2 * count(min) * count(max)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        long long mn = *min_element(a.begin(), a.end());
        long long mx = *max_element(a.begin(), a.end());

        if (mn == mx) {
            // all elements same
            cout << 1LL * n * (n - 1) << "\n";
            continue;
        }

        long long cntMin = 0, cntMax = 0;
        for (auto x : a) {
            if (x == mn) cntMin++;
            if (x == mx) cntMax++;
        }

        cout << 2LL * cntMin * cntMax << "\n";
    }

    return 0;
}
