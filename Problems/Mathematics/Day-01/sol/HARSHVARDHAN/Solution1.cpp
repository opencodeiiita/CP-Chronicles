/*PROBLEM STATEMENT :

There are n people standing in a circle. They are numbered from 1 to n in a clockwise order. The circle is even (i.e. n is even).

Each person is looking at the person standing exactly opposite him in the circle.

You are given three distinct integers a, b, and c. It is known that person a is looking at person b.

Determine the number of the person that person c is looking at.
If there are multiple answers, print any of them.
If there is no answer, print -1.

Approach : Total(i.e. n) = 2*(difference of a and b), so if any of the a,b,c is greater than total, it will return -1. Else we should return c + |a-b| or c-|a-b| (only one of them will be feasible)

Time Complexity: O(1) because we have created a formula directly.
Space Complexity : O(1) because no. of inputs is fixed 

Input
7
6 2 4
2 3 1
2 4 10
5 3 4
1 3 2
2 5 4
4 3 2
Output
8
-1
-1
-1
4
1
-1 

Submission link : https://codeforces.com/contest/1560/submission/355191015
*/

#include<bits/stdc++.h>
#include<array>
#include<unordered_set>
using namespace std;
typedef long long ll;
#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define vin(a) for(int i = 0; i< a.size();i++) cin>>a[i]
#define vout(a) {for(auto x : a) cout << x << " "; cout << endl;}
#define pp(a) for(auto x : a) cout << x.F << " " << x.S << endl
#define print(a,x,y) {for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl}

inline int power(int a, int b){int x = 1;while (b){if (b & 1) x *= a;a *= a;b >>= 1;}return x;}
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

bool isPrime(int n){ if(n <= 1) return false; for(int i=2;i*i<=n;i++) if(n % i == 0) return false; return true; }
ll gcd(ll a, ll b){ return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b){ return a / gcd(a,b) * b; }
ll modpow(ll a, ll b, ll m){ ll r=1; while(b){ if(b&1) r=r*a%m; a=a*a%m; b>>=1;} return r; }

bool getBit(ll x, int k){ return (x >> k) & 1; }
ll setBit(ll x, int k){ return x | (1LL << k); }
ll clearBit(ll x, int k){ return x & ~(1LL << k); }
ll toggleBit(ll x, int k){ return x ^ (1LL << k); }
int countBits(ll x){ return __builtin_popcountll(x); }
bool isPowerOfTwo(ll x){ return x && !(x & (x - 1)); }

vector<int> sieve(int n){ vector<int> p(n+1,1), primes; p[0]=p[1]=0; for(int i=2;i*i<=n;i++) if(p[i]) for(int j=i*i;j<=n;j+=i) p[j]=0; for(int i=2;i<=n;i++) if(p[i]) primes.pb(i); return primes; }

const int N = 200005;

void solve() {
    int a,b,c;
    cin >> a >> b >> c;

    int total = 2*abs(a-b);
    if (max(max(a,b),c)>total)
    {
      cout << -1 << endl;return;
    }
    else
    {
      int ans = ((c-abs(a-b))>0 )? c-abs(a-b) : c+ abs(a-b) ;
      cout << ans << endl;return;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
