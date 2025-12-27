//https://codeforces.com/problemset/submission/1771/355389933

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        long long a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        long long mn = a[0], mx = a[0];
        for (int i = 1; i < n; i++) {
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }

        long long cmin = 0, cmax = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == mn) cmin++;
            if (a[i] == mx) cmax++;
        }

        if (mn == mx)
            cout << n * (n - 1) << "\n";
        else
            cout << 2 * cmin * cmax << "\n";
    }

    return 0;
}           