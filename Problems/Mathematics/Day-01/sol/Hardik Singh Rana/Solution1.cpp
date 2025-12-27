#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define f(i,a,b) for (ll i = a; i < b; i++)
#define fb(i,a,b) for (ll i = a; i >= b; i--)
#define all(v) (v).begin(), (v).end()

typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

ll binexp(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve() {
    int a,b,c;
    cin>>a>>b>>c;
    if(c>2*abs(a-b) or a>2*abs(a-b) or b>2*(abs(a-b))){
        cout<<-1<<endl;
    }
    else{
        if(c>abs(a-b)) cout<<c-abs(a-b)<<endl;
        else cout<<c+abs(a-b)<<endl;
    }
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) solve();
}
