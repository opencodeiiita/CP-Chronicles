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
static const int MAXN = 100000;


void solve(){

//-------------INPUT-------------
    ll n; 
    cin >> n;
    ll k;
    cin >> k;
    vll v(n);
    input(v);
    //We need to count the no of pairs such that their product makes some number k- power means the product of the two numbers should have
    //factors frequency that is divisible by k
    vll spf(MAXN+1);
    for(ll i=1;i<=MAXN;i++)
    {
        spf[i]=i;
    }
    for(ll i=2;i*i<=MAXN;i++)
    {
        if(spf[i] == i)
        {
            for(ll j=i*i;j<=MAXN;j+=i){
                if(spf[j]==j)
                {
                    spf[j] = i;
                }
            }
        }
    }
    map<vector<pair<ll,ll>>,ll>freq;

    ll ans=0;

    for(auto &x : v)
    {
        map<ll,ll>factor;
        while(x >1)
        {
            ll p = spf[x];
            ll cnt = 0;
            while(x%p ==0)
            {
                x = x/p;
                cnt++;
            }
            cnt=cnt%k;
            if(cnt>0)
            {
                factor[p] = cnt; 
            }
        }
        vector<pair<ll,ll>>key,need;
    
        for(auto &it : factor)
        {
            key.push_back(it);
            ll req = (k-it.second)%k;
            if(req>0)
            {
                need.push_back({it.first,req});
            }
        }
        ans+=freq[need];
        freq[key]++;
    }
    cout << ans << endl;


    //link submission :- https://codeforces.com/contest/1225/submission/355215715

//-------------CODE--------------
    


}


int main(){
    //int tt; cin >> tt; while(tt--)
{solve();};
}
