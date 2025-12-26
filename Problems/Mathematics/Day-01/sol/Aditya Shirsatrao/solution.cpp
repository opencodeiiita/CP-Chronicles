#include <iostream>
#include <cmath>

using namespace std;

/**
 * Problem: Who's Opposite?
 * Logic: n = 2 * |a - b|. Valid if a, b, c <= n.
 */

void solve() {
    long long a, b, c;
    if (!(cin >> a >> b >> c)) return;

    long long n = 2LL * abs(a - b);

    if (a > n || b > n || c > n) {
        cout << -1 << "\n";
    } else {
        long long half = n / 2;
        if (c <= half) {
            cout << c + half << "\n";
        } else {
            cout << c - half << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
