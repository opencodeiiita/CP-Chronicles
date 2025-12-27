#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int half = abs(a - b);
        int n = 2 * half;

        if (c > n) {
            cout << -1 << "\n";
        } else {
            int opposite = (c + half <= n) ? (c + half) : (c - half);
            cout << opposite << "\n";
        }
    }
    return 0;
}
