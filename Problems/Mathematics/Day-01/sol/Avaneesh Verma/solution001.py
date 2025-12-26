#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int diff = abs(a - b);
        int n = 2 * diff;
        if (diff == 0 || a > n || b > n || c > n) {
            cout << -1 << '\n';
            continue;
        }
        int half = n / 2;
        int d;
        if (c + half <= n)
            d = c + half;
        else
            d = c - half;
        cout << d << '\n';
    }

    return 0;
}
