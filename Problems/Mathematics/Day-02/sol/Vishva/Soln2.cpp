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
void pvll(const vector<long long> &arr){for(auto it : arr){cout << it << " ";}cout << endl;}
void pvi(const vector<int> &arr){for(auto it : arr){cout << it << " ";}cout << endl;}
static const long long MOD = 1000000007;

ll total=0;
ll power(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)
        {
            res = res*a %MOD;
        }
        a = a*a % MOD;
        b>>=1LL;
    }
    return res;
}
vll fact(1001);
vll invfact(1001);
void precompute()
{
    fact[0] = 1LL;
    for(ll i=1;i<=1000;i++)
    {
        fact[i] = fact[i-1]*i%MOD;
    }
    invfact[1000] = power(fact[1000],MOD-2);
    for(ll i=1000-1;i>=0;i--)
    {
        invfact[i] = (invfact[i+1]%MOD)*((i+1)%MOD)%MOD;
    }
}
ll combination(ll n,ll r)
{
    if (r < 0 || r > n) return 0; // Safety check
        ll res = (fact[n] * invfact[r]) % MOD;
        res = (res * invfact[n - r]) % MOD;
        return res;}
void solve(){

//-------------INPUT-------------
    ll n; 
    cin >> n;
    ll k;
    cin >> k;
    vll v(n);
    input(v);
    map<ll,ll>mp;
    set<ll>st;
    for(ll i=0;i<n;i++)
    {
        mp[v[i]]++;
        st.insert(v[i]);
    }
    // for(auto i : mp)
    // {
    //     cout << i.first << " " << i.second << " ";
    // }
    //out << st.size() << " ";
    total=0;
    for (auto it = st.rbegin(); it != st.rend(); ++it) 
    {
        //cout << *it << " " << mp[*it] << " ";
        //cout << k << endl;

        if(mp[*it] >= k)
        {
            //cout << *it << " ";
            //cout << mp[*it] << " "<<  k << " ";
            total = (total + combination(mp[*it], k)) % MOD;
            cout << total << endl;
            return;
        }
        else
        {
            k = k-mp[*it];
        }
    }
    
    
    // explanation used normal greedy + combinatrics over here and also pdid precompure fact and invfact to precompute inverseface i used fermats liitle theorem where a-1%MOD= pow(a,m-2) and used binary power
    // time complexity o(n)
    // submission link :- https://codeforces.com/contest/1475/submission/355296956
    
    
    
    //-------------CODE--------------
    
    
    
}


int main(){
    precompute();
    int tt; cin >> tt; while(tt--)
    {solve();};
}
