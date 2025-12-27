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


void solve(){

//-------------INPUT-------------
    ll a;
    cin >> a;
    ll b,c;
    cin >> b >> c;
    if(b<a)
    {
        swap(a,b);
    }
    // n is total number 
    ll n = 2*(b-a);
    //cout << n << " ";
        if(a>n || b>n || c>n)
        {
            // this states that given constraints are not forming a proper circle
            cout << -1 << endl;
            return;
        }

        if(c-n/2 != a && c-n/2 != b)
        {
            if(c-n/2 <=n && c-n/2>=1)
            {

                // looking exactly opposite of the c if c-n/2 meetss the condition
                cout << c - n/2 << endl;
                
                return;
            }
        }
    

        if(c+n/2 != a && c+n/2 != b)
        {

            if(c+n/2 <=n && c+n/2>=1)
            {
                // looking exactly opposite of the c if c+n/2 meets the condition
                cout << c + n/2 << endl;
                
                return;
            }
        }
        
    
    cout << -1 << endl;


//-------------CODE--------------
    


}


int main(){
    int tt; cin >> tt; while(tt--)
{solve();};
}


// SUBMISSION LINK
//https://codeforces.com/contest/1560/submission/355199870
