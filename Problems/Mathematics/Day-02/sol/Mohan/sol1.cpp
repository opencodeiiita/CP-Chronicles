/*
Problem : Hossam and Combinotorics, Need to find no of pairs that have max absolute difference

Time Complexity : O(nlogn)
Space Complexity : O(n)

Submission Link : https://codeforces.com/problemset/submission/1771/355274496
*/
#include <bits/stdc++.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vpi vector<pii>
#define vpl vector<pll>
#define vvi vector<vi>
#define mii map<int,int>
#define si set<int>
#define osi ordered_set<int>
#define loop(i,n) for (int i = 0; i < n; i++)
#define rloop(i,n) for (int i = n - 1; i >= 0; i--)
#define loop1(i,a,b) for (int i = a; i <= b; i++)
#define rloop1(i,a,b) for (int i = a; i >= b; i--)
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define findbo(x) find_by_order(x) // returns iterator to the k-th largest element (0-based)
#define orderbk(x) order_of_key(x) // returns number of items strictly smaller than x
#define endl '\n'
#define printy cout<<"YES"<<endl
#define printn cout<<"NO"<<endl
#define vout(a) for (int i = 0; i < a.size(); i++) cout << a[i] << ' '; cout << endl;
#define vpout(a) loop(i,sz(a)) cout <<a[i].F<<' '<< a[i].S<< endl; cout << endl;
#define rt(x){ cout<<x<<endl; return; }
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // less_equal<T> for multiset, greater<T> for decreasing order

const int MOD = 1e9 + 7;
const int INF = 1e9;

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" = "; _print(x); cerr<<endl;
template<typename T> void _print(const T& x){ cerr<<x; }
template<typename T,typename U> void _print(const pair<T,U>& p){ cerr<<"("; _print(p.first); cerr<<", "; _print(p.second); cerr<<")"; }
template<typename T> void _print(const vector<T>& v){ cerr<<"["; for(size_t i=0;i<v.size();++i){ _print(v[i]); if(i+1!=v.size()) cerr<<", "; } cerr<<"]"; }
template<typename T> void _print(const set<T>& s){ cerr<<"{"; for(auto it=s.begin(); it!=s.end(); ++it){ _print(*it); if(next(it)!=s.end()) cerr<<", "; } cerr<<"}"; }
template<typename T,typename U> void _print(const map<T,U>& m){ cerr<<"{"; for(auto it=m.begin(); it!=m.end(); ++it){ _print(it->first); cerr<<": "; _print(it->second); if(next(it)!=m.end()) cerr<<", "; } cerr<<"}"; }
#else
#define debug(x)
#endif

#define sumV(a) accumulate(all(a), 0LL)
#define minV(a) min_element(all(a))
#define maxV(a) max_element(all(a))

int log2f(long long n) {
    if (n==0) return -1;
    int res = 0;
    while (n > 1){
        n >>= 1;
        res++;
    }
    return res;
}

int binpow(int a, int n) {
    int result = 1;
    a %= MOD;
    while (n > 0) {
        if (n & 1)
            result = (result * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return result;
}

void solve(){
    int n;
    cin>>n;
    vi a(n);
    mii mp;
    loop(i,n){
        cin>>a[i];
        mp[a[i]]++;
    }

    if(mp.size()==1) cout<<n*(n-1)<<endl;
    else cout<< 2 * mp.begin()->S * mp.rbegin()->S<<endl;
}

int32_t main(){ 
    fast_io; 
    int t=1;
    cin>>t; 
    while(t--){ 
        solve(); 
    } 
    return 0;
}