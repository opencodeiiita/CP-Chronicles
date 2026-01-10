#include<bits/stdc++.h>
#include<queue>
using namespace std;
typedef unordered_map<int, int> umii;
typedef unordered_map<long long, long long> umll;
typedef unordered_map<char, long long> umci;
typedef vector<pair<int, int>> vpi;
typedef vector<int> vi;
typedef long long ll;
typedef vector<long long> vll;
typedef unordered_map<int , bool> umib;
#define sum(v) accumulate(v.begin(), v.end(), 0)
#define endl '\n'
#define f0(i, n) for(long long i = 0; i < n; i++)
#define f1(i, n) for(long long i = 1; i < n; i++)
#define as(v) sort(v.begin(), v.end())
#define all(x) (x).begin(), (x).end()
#define pb push_back
template<class T> umll frequency(vector<T> &v) {umll freq;for(auto &x:v) freq[x]++; return freq;}
template<class T> umci S_frequency(vector<T> &v) {umci freq;for(auto &x:v) freq[x]++; return freq;}
template <class T> void input(vector<T> &v){for(auto &x:v)cin>>x;}
ll power(ll x, ll y){ ll res = 1; while (y > 0){ if (y & 1) res = (ll)(res*x); y = y>>1; x = (ll)(x*x); } return res; }
void pvll(const vector<long long> &arr){for(auto it : arr){cout << it << " ";}cout << endl;}
void pvi(const vector<int> &arr){for(auto it : arr){cout << it << " ";}cout << endl;}


// submission link :-
//https://codeforces.com/contest/580/submission/347582553


void dfs(ll node,ll parent, ll cats,ll m,vector<vector<ll>>&g, vll&v,ll& ans)
{
    if(v[node]==1)
    {
        cats++;
    }
    else
    {
        cats=0;
    }
    if(cats>m)
    {
        return;
    }
    bool isLeaf = true;

    for(auto child : g[node])
    {
        if(child==parent)
        {
            continue;
        }
        isLeaf = false;
        dfs(child,node,cats,m,g,v,ans);
    }
    if(isLeaf==true)
    {
        ans++;
    }
}
// approach:- 
// used dfs over here 
//Approach :- 
// we will do dfs traversal and keep track of the number of consecutive cats in the path
// if the number of consecutive cats exceeds m, we stop exploring that path
// if we reach a leaf node, we increment the answer

void solve(){

//-------------INPUT-------------
    ll n; 
    cin >> n;
    ll m;
    cin >> m;
    vll v(n+1);
    for(ll i=1;i<=n;i++)
    {
        cin >> v[i];
    }
    vector<vector<ll>>g(n+1);

    for(ll i=0;i<n-1;i++)
    {
        ll a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll ans=0;
    dfs(1,-1,0,m,g,v,ans);

    cout << ans << endl;

//-------------CODE--------------
    


}


int main(){
    //int tt; cin >> tt; while(tt--)
{solve();};
}
