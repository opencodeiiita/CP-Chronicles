#include <bits/stdc++.h>
using namespace std;

#define umpp(i, j) unordered_map<i, j, custom_hash>
#define mpp(i, j) map<i, j>
#define int long long
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pair<int,int>>
#define pb push_back
#define pob pop_back
#define sz(x) ((int)(x).size())
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define forx(x, n) for (int x = 0; x < (n); x++)
#define PI 3.1415926535897932384626
const int mod = 1e9 + 7;

void solve() {
    int a,b,c; cin >> a>>b>>c;
    int diff = abs(a - b);
    int t = 2 * diff;
    if(a>t || b>t||c>t){
        cout << -1 << endl;
    }
    else{
        int a1 = c - diff;
        int a2 = c + diff;
        if(a1>=1 && a1<=t){
            cout << a1 << endl;
            return;
        }
        cout << a2 << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
