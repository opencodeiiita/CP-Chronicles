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

void solve()
{
    int n, k;
    cin >> n >> k;
    vi v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vi prime(1e5 + 1);
    map<int, vector<pair<int, int>>> facs;

    for (int i = 2; i <= 1e5; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i; j <= 1e5; j += i)
            {
                if (j != i)
                    prime[j] = 1;

                int temp = j;
                int cnt = 0;
                while (temp % i == 0)
                {
                    temp /= i;
                    cnt++;
                }

                cnt %= k;
                if (cnt > 0)
                    facs[j].pb({i, cnt});
            }
        }
    }
    int u = 0;
    int ans = 0;
    map<vector<pair<int, int>>, int> mp;
    for (int i = 0; i < n; i++)
    {
        vector<pair<int, int>> s = facs[v[i]];
        mp[s]++;
        // if (s.size() == 0)
        // {
        //     cout<<v[i]<<" "<<endl;
        //     u++;
        // }
    }
    for (auto &p : mp)
    {
        vector<pair<int, int>> s = p.first;
        for (int i = 0; i < s.size(); i++)
        {
            s[i].second = (k - s[i].second);
        }
        if (s != p.first)
            ans += mp[s] * p.second;
        else
            ans += (p.second) * (p.second - 1) / 2;
        p.second = 0;
    }

    cout << ans << endl;
}

signed main()
{
    FAST_IO
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
/*
    time complexity : 1e5*log1e5
    space complexity : 1e5 ish
    so basically what I did was I calculated prime factorization of each and every number till 1e5
    then I took modulo of each exponent with k since while multiplying the sum of exponent of each prime factor must be a multiple of k 

    so then I used a map of vector pair to store prime fac of each number
    then I just took into count those numeber which are present in the array using another map
    now in the end I just itereated the map and counted good pairs


    subbmission:
    https://codeforces.com/contest/1225/submission/355181685

*/
