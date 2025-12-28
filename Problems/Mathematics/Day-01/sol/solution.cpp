#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;
        long long half = llabs(a - b);
        long long n = 2 * half;
        if (a > n || b > n || c > n) {
            cout << -1 << "\n";
            continue;
        }
        long long option1 = c + half;
        long long option2 = c - half;
        if (option1 >= 1 && option1 <= n) {
            cout << option1 << "\n";
        } else if (option2 >= 1 && option2 <= n) {
            cout << option2 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
