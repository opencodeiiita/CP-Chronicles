/*
Submission Link:
https://codeforces.com/contest/61/submission/356381771
*/

/*
Problem: Enemy is weak
Link: https://codeforces.com/contest/61/problem/E
Author: Krishna200608

Short Problem Statement:
    Given distinct integers, count how many triplets (i, j, k) exist
    such that i < j < k and the values strictly decrease:
    a[i] > a[j] > a[k].

Approach:
        We first compress the values to handle large numbers easily.
        Treat each element as the middle of a triplet.
        For every position, count bigger elements on the left   .
        and count smaller elements on the right.
        A Fenwick Tree helps do these counts efficiently .
        The final answer is the sum of left multiplied by right for all positions.

Time Complexity: O(N log N)
Space Complexity: O(N)
*/


#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
const int M = 1e9 + 7;
const double PI = acos(-1.0);
#define INF 1e18
#define pb push_back
#define ppb pop_back
#define ll long long
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define ff first
#define ss second
#define inn(x) int x; cin >> x
#define ill(x) ll x; cin >> x
#define all(x) x.begin(), x.end()
#define in(a) for (int i = 0; i < (int)a.size(); i++) cin >> a[i]
#define out(a) for (int i = 0; i < (int)a.size(); i++) cout << a[i] << " "
typedef vector<int> vi;
typedef vector<ll> vll;
#define ceil_div(n, x) (((n) % (x) == 0) ? ((n) / (x)) : ((n) / (x) + 1))
#define debug(x) cout << "x -> " << x << endl
#define outt(x) cout << x << endl
#define endl "\n"

const int sz = 1000005;
int bit[sz];
int nn;

void upd(int i, int x) {
    for (; i <= nn; i += i & -i)
        bit[i] += x;
}

int qry(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i)
        res += bit[i];
    return res;
}

void solve() {
    inn(n);
    nn = n;

    vi a(n);
    in(a);

    vi b = a;
    sort(all(b));

    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(all(b), a[i]) - b.begin() + 1;
    }

    vll le(n), ri(n);

    for (int i = 0; i < n; i++) {
        int smaller = qry(a[i]);
        int total = i;
        le[i] = total - smaller;
        upd(a[i], 1);
    }

    memset(bit, 0, sizeof(bit));

    for (int i = n - 1; i >= 0; i--) {
        int smaller = qry(a[i] - 1);
        ri[i] = smaller;
        upd(a[i], 1);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += le[i] * ri[i];
    }

    outt(ans);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    auto begin = chrono::high_resolution_clock::now();

    int t = 1;
    while (t--) {
        solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-6 << "ms";

    return 0;
}
