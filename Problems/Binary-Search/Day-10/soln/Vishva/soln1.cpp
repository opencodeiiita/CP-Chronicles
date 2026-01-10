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

// apply binary search

// logic:- like pick a number and then decide whether this number would be kth element or not after performing x steps

// like suppose if we perform one step then len will be reduced by len/y and in this way we will know how many elements are left after performing x steps if the number of elements left >k then we would reduce the r else we will increase l;

//time complexity = o(xlogN)

//submission link:- https://codeforces.com/contest/2169/submission/356552442


void solve(){

//-------------INPUT-------------
    ll x;
    cin >> x;

    ll y,k;
    cin >> y >> k;

    ll l=1,r=1000000000000LL + 1;
    while(l<=r)
    {
        ll m = l+(r-l)/2;

        ll ans = m-1;

        for(ll i=0;i<x;i++)
        {
            ans = ans - ans/y;
        }

        if(ans> k-1)
        {
            r = m-1;
        }
        else
        {
            l = m+1;
        }
    }

    if(r==1000000000000LL + 1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << r << endl;
    }


//-------------CODE--------------
    


}


int main(){
    int tt; cin >> tt; while(tt--)
{solve();};
}
