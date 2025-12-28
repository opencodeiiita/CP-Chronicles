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

void solve()
{
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int mx = *max_element(all(v)), mi = *min_element(all(v));
    int cnt = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == mx)
            cnt++;
        if (v[i] == mi)
            cnt2++;
    }
    if (mi == mx)
    {
        cout << (cnt * (cnt - 1)) << endl;
    }
    else
    {
        cout << 2 * (cnt * cnt2) << endl;
    }
}

signed main()
{
    FAST_IO
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
/*
    so basically we're asked in this question to compute the pairs whose diff is max(abs(ap-aq)) where p and q varies over all n
    now a simple thought would tell us that we need to count number of pairs such that one is max and other is min since max diff
    is only occured when substracting max - min

    time complexity is o(n);
    space complexity is o(1);

    submission id https://codeforces.com/contest/1771/submission/355258380

*/