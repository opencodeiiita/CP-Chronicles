/* 1 to n people are standing in a circle. n is even.... a is looking at b. 
If given c is looking at some d person for given a,b then find that d. If such a combination
of circle does not exist then print -1*/

// Time complexity: O(1)
// Space complexity: O(1)
//My submission: https://codeforces.com/contest/1560/submission/355204246

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7; // 998244353
const ll INF = 1e18;

void solve() {
    int a,b,c;
    cin>>a>>b>>c;
    int n=2*abs(a-b);
    if(a>n || b>n ||c>n ) cout<<-1<<endl;
    else{
        int x=c-n/2,y=c+n/2;
        if(x>=1 && x<=n) cout<<x<<endl;
        else cout<<y<<endl;
    }
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
