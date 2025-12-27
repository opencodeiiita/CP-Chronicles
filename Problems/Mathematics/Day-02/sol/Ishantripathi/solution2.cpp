#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
// less makes it sorted greater makes it reverse sorted less equal makes it like multiset
// we can also change the data type of the pbds

// Fast I/O
#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);
#define pb push_back
#define in insert
#define int long long
#define all(x) (x).begin(), (x).end()

// Typedefs for convenience
typedef vector<int> vi;
typedef pair<int, int> pii;

// Constants
const int INF = 1e18;
const int MOD = 1e9 + 7;

// Debug (can be disabled in contests)
#ifdef DEBUG
#define dbg(x) cerr << #x << " = " << x << '\n';
#else
#define dbg(x)
#endif

// gcd
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

// lcm
int lcm(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;
    return abs(a * b) / gcd(a, b);
}

// Binary exponentiation (modular)
long long binexp(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
vi fac(1001);

void solve()
{
    int n, k;
    cin >> n >> k;
    vi v(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    sort(all(v));
    int j = n - k + 1;
    int ele = v[n - k + 1];
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        mp[v[i]]++;
    }

    int i;
    for (i = j; i <= n; i++)
    {
        if (v[i] != ele)
        {
            break;
        }
    }
    int left = i - j;
    int p = fac[mp[ele]];
    // cout<<p<<endl;
    int q = fac[left];
    int s = fac[mp[ele] - left];
    q = binexp(q, MOD - 2, MOD);
    s = binexp(s, MOD - 2, MOD);
    int res = (((p % MOD) * (q % MOD)) % MOD * (s % MOD)) % MOD;
    cout << res << endl;
}

signed main()
{
    FAST_IO
    fac[0] = 1;
    for (int i = 1; i <= 1000; i++)
    {
        fac[i] = (fac[i - 1] * i) % MOD;
    }

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
/*
    So basically we're asked to count number of ways we can take k elements such that there sum is maximum now
    if all elements were unique we could have just taken last k elements and answer would be 1
    but since they are unique
    we can have something like n= 6 ;k=5; 1 1 1 2 2 2 where we can choose any two of the three ones hence
    we need to take how many of those last elments we are taking as left and total now many elements of last are there are ele
    hence the answer would be mp[ele]Cleft which is easily solvable by using fermet's little theorem to find modulo inverse


    time complexity o(1000)
    space complexity o(1000)

    submission id :https://codeforces.com/contest/1475/submission/355268225



*/