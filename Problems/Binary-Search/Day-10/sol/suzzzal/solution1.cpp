/*
Submission link : https://codeforces.com/contest/2169/submission/356909170


TC : O(X log N)
SC : O(1)

Approach:
If y == 1, growth is impossible, so we directly print -1.

We use binary search to find the minimum value of mid that satisfies the condition.
We keep left = 1 and right = 10^12 as the search range.

For every mid, we start with cur = mid - 1.
Then we repeat the process x times:
    cur = cur - cur / y

After x steps, we check if cur + 1 > k.
If yes, this mid is valid, so we store it and move to the left part of binary search.
If no, we move to the right part.

We continue this until binary search ends.
If we never find a valid mid, we print -1.
Otherwise, we print the smallest valid mid found.

The data structures used are simple variables only.
Binary search helps reduce the time from linear to logarithmic.
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
