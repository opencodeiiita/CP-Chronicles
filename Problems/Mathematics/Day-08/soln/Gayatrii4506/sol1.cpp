/*Problem Statement

Given positions of n bars on a street, Sasha can close at most k bars.
A house x is valid if the sum of distances to remaining bars is minimum.
Find how many such houses are possible.

Approach
- Distance sum is minimized at the median.
- After closing bars, at least n−k bars remain.
- For every sorted subarray of size n−k, find its median (or median range).
- Merge all median ranges and count valid integer positions.

Time & Space Complexity
Time: O(n log n)
Space: O(n)*/

//Submission Link: https://codeforces.com/contest/2098/submission/356146967

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int m = n - k;   // bars that must remain
        vector<pair<long long, long long>> v;

        // consider all possible remaining bar groups
        for (int i = 0; i + m - 1 < n; i++) {
            if (m % 2 == 1) {
                long long x = a[i + m / 2];
                v.push_back({x, x});
            } else {
                long long l = a[i + m / 2 - 1];
                long long r = a[i + m / 2];
                v.push_back({l, r});
            }
        }

        // merge intervals
        sort(v.begin(), v.end());

        long long ans = 0;
        long long L = v[0].first, R = v[0].second;

        for (int i = 1; i < v.size(); i++) {
            if (v[i].first > R + 1) {
                ans += (R - L + 1);
                L = v[i].first;
                R = v[i].second;
            } else {
                R = max(R, v[i].second);
            }
        }

        ans += (R - L + 1);
        cout << ans << "\n";
    }

    return 0;
}
 