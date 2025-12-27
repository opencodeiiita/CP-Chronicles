//Submission link: https://codeforces.com/problemset/submission/1225/355220477
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define rep(i,a,b) for (int i = a; i < b; ++i)
#define rrep(i,a,b) for (int i = a; i >= b; --i)
#define in(a,n) rep(i,0,n) cin>>a[i]
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define int long long

typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int N = 2e5 + 5;

ll gcd(ll a, ll b) {
    while (b) a %= b, swap(a, b);
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll power(ll a, ll b, ll mod = MOD) {
    ll res = 1; a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll invmod(ll a, ll mod = MOD) {
    return power(a, mod - 2, mod);
}

ll fact[N], invfact[N];
void precompute() {
    fact[0] = invfact[0] = 1;
    rep(i,1,N) fact[i] = fact[i-1]*i % MOD;
    invfact[N-1] = invmod(fact[N-1]);
    rrep(i,N-2,1) invfact[i] = invfact[i+1]*(i+1) % MOD;
}

ll nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

vector<bool> is_prime;
vi primes;
void sieve(int maxn = N) {
    is_prime.assign(maxn + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= maxn; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= maxn; j += i)
                is_prime[j] = false;
        }
    }
    rep(i, 2, maxn + 1) if (is_prime[i]) primes.pb(i);
}
tuple<ll, int, int> kadane_with_indices(const vl &a) {
    ll max_sum = a[0], cur = a[0];
    int start = 0, end = 0, temp_start = 0;

    rep(i, 1, a.size()) {
        if (a[i] > cur + a[i]) {
            cur = a[i];
            temp_start = i;
        } else {
            cur += a[i];
        }

        if (cur > max_sum) {
            max_sum = cur;
            start = temp_start;
            end = i;
        }
        if (cur == 0) {
            temp_start = i + 1;
        }
    }
    
    return {max_sum, start, end};
}

// Disjoint Set Union (DSU)
struct DSU {
    vi parent, size;
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        iota(all(parent), 0);
    }

    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        return true;
    }
};

// Grid Traversal (4 & 8 directions)
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ddx[8] = {0,0,1,-1,1,-1,1,-1};
int ddy[8] = {1,-1,0,0,1,-1,-1,1};

bool DEBUG = true;
#define debug(x) if(DEBUG) cout << "[DEBUG] " << #x << " = " << (x) << endl


#undef int
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long

using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Functions:
// s.find_by_order(k) ? k-th element
// s.order_of_key(x)  ? number of elements < x


template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) os << " "; 
        os << v[i];
    }
    return os;
}
template <typename T>
istream& operator>>(istream &is, vector<T> &v) {
    for (auto &x : v) is >> x;
    return is;
}
template <typename K, typename V>
ostream& operator<<(ostream &os, const map<K,V> &mp) {
    os << "{ ";
    for (auto &p : mp) {
        os << p.first << ":" << p.second << " ";
    }
    os << "}";
    return os;
}
#define debug(x) if(DEBUG){ cout << "[DEBUG] " << #x << " = "; cout << (x) << endl; }


int mex(vector<int>& v) {   // minimum excluded value
    unordered_set<int> s(v.begin(), v.end());
    int m = 0;
    while (s.count(m)) m++;
    return m;
}

int setbit(int n, int pos) { return n | (1LL << pos); }
int unsetbit(int n, int pos) { return n & ~(1LL << pos); }
int togglebit(int n, int pos) { return n ^ (1LL << pos); }
bool checkbit(int n, int pos) { return n & (1LL << pos); }

// Count set bits
int count_bits(int n) { return __builtin_popcountll(n); }

// Index of LSB/MSB
int lsb(int n) { return __builtin_ctzll(n); }   // least significant set bit index
int msb(int n) { return 63 - __builtin_clzll(n); } // most significant set bit index


long long sumOfDigits(long long n) {
    if (n < 10) return n * (n + 1) / 2;  // direct sum
    
    long long d = log10(n);  // number of digits - 1
    long long p = pow(10, d); // largest power of 10 <= n
    long long msd = n / p;    // most significant digit
    
    // formula:
    // sum of digits from 1..n =
    //  (msd * sumOfDigits(p-1))               [complete blocks before]
    //+ (msd * (msd - 1) / 2) * p              [contribution of MSD itself]
    //+ (msd * (1 + n % p))                    [MSD contribution in current block]
    //+ sumOfDigits(n % p)                     [recurse on remaining suffix]
    
    return (msd * sumOfDigits(p - 1)) +
           (msd * (msd - 1) / 2) * p +
           (msd * (1 + n % p)) +
           sumOfDigits(n % p);
}

vector<long long> digitCount(long long n) {
    vector<long long> cnt(10, 0);
    for (long long pos = 1; pos <= n; pos *= 10) {
        long long higher = n / (pos * 10);
        long long cur = (n / pos) % 10;
        long long lower = n % pos;

        // count for each digit
        for (int d = 0; d <= 9; d++) {
            cnt[d] += higher * pos;  // full cycles

            if (d < cur) cnt[d] += pos;
            else if (d == cur) cnt[d] += lower + 1;
        }

        // fix leading zero problem
        cnt[0] -= pos;
    }
    return cnt;
}

vector<int> prime_factors(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.pb(i);
            n /= i;
        }
    }
    if (n > 1) factors.pb(n);
    return factors;
}
vector<int> divisors(int n) {
    vector<int> divs;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.pb(i);          
            if (i != n / i)      
                divs.pb(n / i);  
        }
    }
    sort(all(divs));
    return divs;
}
// Graph Utilities
// --------------------------
vector<vector<int>> adj;
vector<int> vis;

void dfs(int u) {
    vis[u] = 1;
    for (auto v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
}

vector<int> bfs(int start, int n) {
    vector<int> dist(n+1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}


long long nextNonDividingPrime(long long n) {
    // Small primes list (enough for all practical n ? 1e18)
    static const int primes[] = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
        31, 37, 41, 43, 47, 53, 59, 61, 67,
        71, 73, 79, 83, 89, 97
    };

    for (int p : primes) {
        if (n % p != 0)
            return p; // found the smallest prime not dividing n
    }

    // In the (practically impossible) case n is divisible by all above,
    // find the next prime manually
    auto isPrime = [](long long x) {
        if (x < 2) return false;
        for (long long i = 2; i * i <= x; i++)
            if (x % i == 0) return false;
        return true;
    };

    long long candidate = 101; // next after our list
    while (true) {
        if (isPrime(candidate) && n % candidate != 0)
            return candidate;
        candidate++;
    }
}


//*********************************************************************************//


vector<pair<int,int>> tomap(int a, int k){
    vector<pair<int,int>> key;
    for (ll i = 2; i * i <= a; i++) {
        if(a % i == 0){
            int cnt = 0;
            while (a % i == 0) {
                a /= i;
                cnt++;
            }
            cnt %= k;
            if (cnt != 0)
                key.pb({(int)i, cnt});
        }
    }
    if(a > 1){
        key.pb({(int)a, 1 % k});
    }
    return key;
}

vector<pair<int,int>> need(const vector<pair<int,int>>& key, int k){
    vector<pair<int,int>> res;
    for(auto [p, r] : key){
        res.pb({p, (k - r) % k});
    }
    return res;
}

void solve() { 
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    in(v, n);
    int ans = 0;
    map<vector<pair<int,int>>, int> freq;
    for(int i = 0; i < n; i++){
        auto cur = tomap(v[i], k);
        auto rem = need(cur, k);
        ans += freq[rem];
        freq[cur]++;
    }
    cout << ans << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    // precompute();
    // sieve();
    DEBUG = false;
    // ll t;
    // cin >> t;
    // while (t--) {
        solve();
    // }
    return 0;
}
