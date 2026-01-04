// submission: https://codeforces.com/contest/2098/submission/356344573

// we have houses numbered from 1 to 1e9 and n bars in houses a1,a2,.....,an (there can be multiple bars in single house)
//and also an int k: at max k bars can be closed
// For any house with number x, define f(x) as the sum of |x−y| over all open bars y (that is, after closing some bars).
// sasha can buy apartment in a house with no. x if f(x) is minimal among all houses considering k constraint
// Find the no. of different houses sasha can take apartment in


#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7; // 998244353
const ll INF = 1e18;
// It was simply finding the range of medians possible after removing the k elements. The range difference is the answer
void solve() {
    int n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(auto &x: a) cin>>x;
    //sort the array for finding median
    sort(all(a));
    // find the worst case median after removing k bars from right
    int idx=(n-k-1)/2;
    cout<<a[n-1-idx]-a[idx]+1<<endl; //range difference is the answer
}
//T.C: O(t*n*logn) ; S.C.: O(1)

int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
