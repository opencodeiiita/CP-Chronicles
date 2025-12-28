#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    int diff = abs(a-b);
    if (a > 2*diff || b > 2*diff || c > 2*diff) {
        cout << -1 << endl;
        return;
    }

    int ans = c + diff;
    if (ans > 2*diff) {
        ans -= 2*diff;
    }

    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}