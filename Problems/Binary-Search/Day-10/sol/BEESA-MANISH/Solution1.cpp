/*
Submission link : https://codeforces.com/contest/2169/submission/356537822

Tc -O(X)
Sc - O(1)
Approach:
If y = 1, growth is impossible, so output -1.
Start with cur = k and repeat the process x times.
In each step, compute how much can be added using (cur − 1) / (y − 1).
If the value exceeds the limit (10¹²), stop and output -1; otherwise print the final value.
*/


#include <iostream>

using namespace std;

typedef long long ll;

void solve() {
    ll x, y, k;
    cin >> x >> y >> k;

    if (y == 1) {
        cout << -1 << "\n";
        return;
    }

    ll cur = k;
    const ll Limit = 1000000000000LL;

    for (int i = 0; i < x; ++i) {
        ll add = (cur - 1) / (y - 1);
        
        if (Limit - add < cur) {
            cur = Limit + 1;
            break;
        }
        
        cur += add;
    }

    if (cur > Limit) {
        cout << -1 << "\n";
    } else {
        cout << cur << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}