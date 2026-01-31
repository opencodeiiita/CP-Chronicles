submissioin link - https://codeforces.com/contest/813/submission/360906949

#include <bits/stdc++.h>
using namespace std;

// ---------- typedefs / small helpers ----------
typedef unordered_map<int, int> umii;
typedef unordered_map<long long, long long> umll;
typedef unordered_map<char, long long> umci;
typedef vector<pair<int, int>> vpi;
typedef vector<int> vi;
typedef long long ll;
typedef vector<long long> vll;
typedef unordered_map<int, bool> umib;

#define sum(v) accumulate((v).begin(), (v).end(), 0LL)
#define endl '\n'
#define f0(i, n) for(long long i = 0; i < n; i++)
#define f1(i, n) for(long long i = 1; i < n; i++)
#define as(v) sort((v).begin(), (v).end())
#define all(x) (x).begin(), (x).end()
#define pb push_back

// ------------------- CONSTANTS -------------------
const ll MOD = 1e9+7;
const int INF = (int)1e9;

// ------------------- FAST IO -------------------
static inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// ------------------- DEBUG (lightweight) -------------------
#ifdef LOCAL
  #define debug(x) cerr << "[DEBUG] " << #x << " = " << (x) << endl
#else
  #define debug(x) do {} while(0)
#endif

// ------------------- MATH UTILITIES (SAFE) -------------------
ll gcdll(ll a, ll b){ while(b){ a%=b; swap(a,b);} return llabs(a); }
ll lcmll(ll a, ll b){ return (a / gcdll(a,b)) * b; }

// Safe modular multiplication (Avoids __int128 errors on 32-bit systems)
ll modmul(ll a, ll b, ll m = MOD) {
    a %= m; b %= m;
    if (m <= 3037000499LL) return (a * b) % m;
    ll res = 0;
    while (b > 0) {
        if (b & 1) res = (res + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return res;
}

ll modpow(ll x, ll y, ll m = MOD){
    x %= m; ll res = 1;
    while(y>0){
        if(y & 1) res = modmul(res, x, m);
        x = modmul(x, x, m);
        y >>= 1;
    }
    return res;
}

ll modinv(ll a, ll m = MOD){ return modpow(a, m-2, m); }
ll moddiv(ll a, ll b, ll m = MOD){ return modmul(a, modinv(b, m), m); }

// ------------------- NUMBER THEORY / SIEVES -------------------
vector<int> sieve_primes(int n){
    vector<char> isprime(n+1, true);
    isprime[0] = isprime[1] = false;
    for(int i=2;i*i<=n;i++) if(isprime[i]){
        for(int j=i*i;j<=n;j+=i) isprime[j]=false;
    }
    vector<int> primes;
    for(int i=2;i<=n;i++) if(isprime[i]) primes.pb(i);
    return primes;
}

void linear_sieve(int n, vector<int>& primes, vector<int>& spf){
    primes.clear(); spf.assign(n+1, 0);
    for(int i=2;i<=n;i++){
        if(spf[i]==0){ spf[i]=i; primes.pb(i); }
        for(int p:primes){
            if(p>spf[i] || (long long)i*p>n) break;
            spf[i*p] = p;
        }
    }
}

vector<pair<ll,int>> factorize_with_spf(ll x, const vector<int>& spf){
    vector<pair<ll,int>> res;
    while(x>1){
        int p = spf[x]; if(p==0) p = x;
        int cnt=0; while(x%p==0){ x/=p; cnt++; }
        res.emplace_back(p,cnt);
    }
    return res;
}

// ------------------- COMBINATORICS -------------------
struct Comb {
    int maxN; ll mod;
    vector<ll> fact, ifact;
    Comb(int maxN=1, ll mod=MOD): maxN(maxN), mod(mod){
        fact.assign(maxN+1,1); ifact.assign(maxN+1,1);
        for(int i=1;i<=maxN;i++) fact[i] = (fact[i-1]*i) % mod;
        ifact[maxN] = modpow(fact[maxN], mod-2, mod);
        for(int i=maxN;i>0;i--) ifact[i-1] = (ifact[i]*i) % mod;
    }
    ll nCr(int n, int r){
        if(r<0 || r>n) return 0;
        return (((fact[n] * ifact[r]) % mod) * ifact[n-r]) % mod;
    }
};

// ------------------- BIT MANIPULATION -------------------


// ------------------- SOLVE -------------------

const int MAXN = 200005;
vector<int> adj[MAXN];
int alice_dist[MAXN];
int bob_dist[MAXN];
int leaf_depth[MAXN];

void find_alice_stats(int u, int p, int d) {
    alice_dist[u] = d;
    leaf_depth[u] = d;
    for (int v : adj[u]) {
        if (v != p) {
            find_alice_stats(v, u, d + 1);
            leaf_depth[u] = max(leaf_depth[u], leaf_depth[v]);
        }
    }
}

void find_bob_stats(int u, int p, int d) {
    bob_dist[u] = d;
    for (int v : adj[u]) {
        if (v != p) {
            find_bob_stats(v, u, d + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    if (!(cin >> n >> x)) return 0;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    find_alice_stats(1, 0, 0);
    find_bob_stats(x, 0, 0);

    int result = 0;
    for (int i = 1; i <= n; i++) {
        if (bob_dist[i] < alice_dist[i]) {
            result = max(result, 2 * leaf_depth[i]);
        }
    }

    cout << result << endl;

    return 0;
}
