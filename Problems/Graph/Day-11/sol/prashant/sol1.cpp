// ----------------------------------------------------------------------
//                   ██████╗ ██████╗ ██████╗ ███████╗
//                  ██╔════╝██╔═══██╗██╔══██╗██╔════╝
//                  ██║     ██║   ██║██║  ██║█████╗
//                  ██║     ██║   ██║██║  ██║██╔══╝
//                  ╚██████╗╚██████╔╝██████╔╝███████╗
//                   ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝
// ----------------------------------------------------------------------
//                       Prashant'S CP TEMPLATE
//                             praxxnnt06
//                       "Think. Code. Conquer."
// ----------------------------------------------------------------------
// AVAILABLE FUNCTIONS AND TIME COMPLEXITIES:
// - nCr(n, r): Combination calculator                    | O(r)
// - sieve(n): Sieve of Eratosthenes (prime finder)       | O(n log log n)
// - rf(n): Factors in a range                            | O(√n)
// - primeFactor(n): Prime factorization of n             | O(√n * log n)
// - gcd(a, b): Greatest Common Divisor                   | O(log(min(a, b)))
// - factorial(n): Modular factorial                      | O(n)
// - MEX(arr): Minimum Excluded Value                     | O(n log n)
// - ps(arr): Prefix Sum                                   | O(n)
// - inp: Input function for array                        | O(n)
// - print: Output function for array                     | O(n)
// ----------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <bit>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <iterator>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cstdint>
#include <cstdlib>
using namespace std;
#define ll long long
#define int long long
#define MOD 1000000007
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) (int)(x).size()
#define srt(v) sort(v.begin(), v.end())
#define Rsrt(v) sort(v.begin(), v.end(), greater<int>())
#define yes cout << "YES" << endl; return;
#define no cout << "NO" << endl; return;
#define endl "\n"
#define F first
#define S second
#define vi vector<int>
#define vc vector<char>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define umap unordered_map
#define mii map<int, int>
#define fr(i, a, b) for (int i = a; i < b; i++)
#define frr(i, a, b) for (int i = a; i > b; i--)
#define mxe(v) *max_element(v.begin(), v.end())
#define mne(v) *min_element(v.begin(), v.end())
vvi g;
vi cat;
int n, m, res;
void dfs(int node, int par, int cnt) {
    if(cnt > m) return;
    if(sz(g[node]) == 1 && node != 1) {
        res++;
        return;
    }
    for(int child : g[node]) {
        if(child != par) {
            dfs(child, node, cat[child] ? cnt + 1 : 0);
        }
    }
}
int32_t main() {
    cin >> n >> m;
    g.resize(n + 1);
    cat.resize(n + 1);
    fr(i, 1, n + 1) cin >> cat[i];
    fr(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    res = 0;
    dfs(1, -1, cat[1]);
    cout << res << endl;
    return 0;
}
