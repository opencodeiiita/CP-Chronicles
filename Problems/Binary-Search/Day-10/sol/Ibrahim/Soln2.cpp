//https://www.codechef.com/viewsolution/1223970533

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int,int>>
#define all(x) (x).begin(), (x).end()


const long long MAXN = 2e6;
const long long MOD = 1e9 + 7;
const int INF = 1e18;
const ld EPS = 1e-9;


#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << " = " << x << "\n";
#else
    #define debug(x)
#endif

// Utility functions
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int mod_add(int a, int b, int m=MOD) { return ((a % m) + (b % m) + m) % m; }
int mod_sub(int a, int b, int m=MOD) { return ((a % m) - (b % m) + m) % m; }
int mod_mul(int a, int b, int m=MOD) { return ((a % m) * (b % m)) % m; }

//Binary Exponentiation
int binexp(int a, int b, int m=MOD) {
    int res = 1;
    a %= m;
    while(b > 0) {
        if(b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int mod_inv(int a, int m=MOD) {
    return binexp(a, m - 2, m);
}

long long fac[MAXN + 1];
long long inv[MAXN + 1];

long long exp(long long x, long long n, long long m) {
  x %= m;
  long long res = 1;
  while (n > 0) {
    if (n % 2 == 1) { res = res * x % m; }
    x = x * x % m;
    n /= 2;
  }
  return res;
}

void factorial() {
  fac[0] = 1;
  for (long long i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % MOD; }
}

void inverses() {
  inv[MAXN] = exp(fac[MAXN], MOD - 2, MOD);
  for (long long i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % MOD; }
}

long long choose(long long n, long long r) {
  if (r > n)return 0ll;
  return (fac[n] * inv[r] % MOD * inv[n - r] % MOD) % MOD;
}

long long catalan(long long n) {
  return (exp(n + 1, MOD - 2, MOD) % MOD * choose(2 * n, n) % MOD) % MOD;
}

//Returns all prime numbers <=N
vector<int> sieve(int n) {
    vector<bool> prime(n + 1, true);
    for (int p=2;p*p<=n;p++) {
        if (prime[p] == true) {
            
            for (int i=p*p;i<=n;i+=p)
                prime[i] = false;
        }
    }
    
    vector<int> res;
    for (int p = 2; p <= n; p++){
        if (prime[p]){ 
            res.push_back(p);
        }
    }
    return res;
}

//Prime factors of all numbers upto N
vector<vector<int>> primefactors(int N)
{
    vvi pfac(N + 1);
        for (int i=2;i<=N;i++){
        if (!pfac[i].empty())
            continue;

        for (int j = i; j <= N; j += i)
            pfac[j].push_back(i);
    }
            
    return pfac;
}

//smallest prime factor of a number
int spf(int n) {
    if (n % 2 == 0) return 2;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return i;
    }
    return n;
}

int power2(int p)
{
    int v=1ll<<p;
    return v;
}

//Sort functions

void sort(vector<int>&a)
{
    sort(a.begin(),a.end());
}

void psort(vector<pair<int,int>>&a)
{
    sort(a.begin(),a.end());
}

void rsort(vector<int>&a)
{
    sort(a.rbegin(),a.rend());
}

void rpsort(vector<pair<int,int>>&a)
{
    sort(a.rbegin(),a.rend());
}

//2-D Vector Declaration: 
//vvi mat(n,vi(m));     // nxm matrix, all initialized to 0


/***************Code***************/

void solve() {
    int n,i;
    cin>>n;
    vi a(n),b(n);
    for(i=0;i<n;i++) 
    cin>>a[i];

    for(i=0;i<n;i++)
    cin>>b[i];

    
    for(i=0;i<n;i++)
    {
        if(a[i]>b[i])
        {
            int t=a[i];
            a[i]=b[i];
            b[i]=t;
        }
    }

    vvi dp(n,vi(2));
    dp[0][0]=1;
    dp[0][1]=0;

    for(i=1;i<n;i++)
    {
        if(a[i]>b[i-1])
        {
            dp[i][0]=dp[i-1][0]+dp[i-1][1]+1;
            dp[i][1]=0;
        }
        else if(a[i]>a[i-1])
        {
            dp[i][0]=dp[i-1][0]+1;
            if(b[i]>b[i-1])
            dp[i][1]=dp[i-1][1];
        }
        else
        {
            dp[i][0]=1;
            if(b[i]>b[i-1])
            dp[i][1]=dp[i-1][0]+dp[i-1][1];
            else if(b[i]>a[i-1])
            dp[i][1]=dp[i-1][0];
        }
    }
    int ans=0;
    for(i=0;i<n;i++)
    ans+=dp[i][0]+dp[i][1];

    cout<<ans<<endl;
}


signed main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
