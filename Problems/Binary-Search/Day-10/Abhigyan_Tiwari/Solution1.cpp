/* P.S.: We've natural nos. from 1- 1e12. We decide to modify this sequence by performing the following action x
 times: Simultaneously remove all numbers at positions y, 2⋅y, 3⋅y, ..., m⋅y≤n, where n
is the length of the current sequence. After that, we want to find the k-th number in the remaining sequence or 
if the length of the resulting sequence is less than k print -1.
SUBMISSION: https://codeforces.com/contest/2169/submission/356948242

T.C: O(x*logA) , A=1e12
S.C.: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7; // 998244353
const ll INF = 1e12;

bool ok(ll p,ll x,ll y, ll k){
    while(x--){
        p-=p/y;
    }
    return p>=k;
}
void solve() {
    ll x,y,k; cin>>x>>y>>k;
    ll low=1,high=INF;
    ll ans=-1;
    while(low<=high){
        ll mid=(low+high)/2;
        if(ok(mid,x,y,k)){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    cout<<ans<<endl;
    
}

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
