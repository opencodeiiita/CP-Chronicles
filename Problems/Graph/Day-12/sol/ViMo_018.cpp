
// submission link :- https://codeforces.com/contest/769/submission/360905808


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
static inline ll set_bit(ll x, int i){ return x | (1LL<<i); }
static inline ll unset_bit(ll x, int i){ return x & ~(1LL<<i); }
static inline ll toggle_bit(ll x, int i){ return x ^ (1LL<<i); }
static inline bool is_set(ll x, int i){ return (x >> i) & 1LL; }
static inline int popcountll(ll x){ return __builtin_popcountll((unsigned long long)x); }
static inline ll set_upto_i(int i){ if(i>=63) return (ll)-1; return (1LL << (i+1)) - 1; }
static inline void swap_xor(ll &a, ll &b){ if(&a==&b) return; a ^= b; b ^= a; a ^= b; }

// ------------------- GRAPHS & TREES -------------------
struct Graph {
    int n; vector<vector<int>> adj;
    Graph(int n=0){ init(n); }
    void init(int _n){ n=_n; adj.assign(n+1, {}); }
    void add_edge(int u, int v, bool undirected=true){
        adj[u].push_back(v); if(undirected) adj[v].push_back(u);
    }
};




// ------------------- SOLVE -------------------

void solve() {
    int n, m, k;
    if (!(cin >> n >> m >> k)) return;

    if (k % 2 != 0) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vector<string> grid(n);
    int sx, sy;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'X') {
                sx = i;
                sy = j;
            }
        }
    }

    vector<vector<int>> dists(n, vector<int>(m, INF));
    queue<pair<int, int>> q;
    
    dists[sx][sy] = 0;
    q.push({sx, sy});

    int dx[] = {1, 0, 0, -1}; 
    int dy[] = {0, -1, 1, 0};
    char moves[] = {'D', 'L', 'R', 'U'};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '*' && dists[nx][ny] == INF) {
                dists[nx][ny] = dists[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    bool stuck = true;
    for (int i = 0; i < 4; i++) {
        int nx = sx + dx[i], ny = sy + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '*') {
            stuck = false;
        }
    }

    if (stuck) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    string path = "";
    int cx = sx, cy = sy;
    for (int step = 1; step <= k; step++) {
        bool ok = false;
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '*') {
                if (dists[nx][ny] <= k - step) {
                    path += moves[i];
                    cx = nx;
                    cy = ny;
                    ok = true;
                    break;
                }
            }
        }
        if (!ok) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    cout << path << endl;
}

int main(){
    fast_io();
    int tt=1;
    // if(!(cin>>tt)) return 0;
    // while(tt--) 
    solve();
    return 0;
}
