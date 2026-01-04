/*
Submission Link:
https://cses.fi/paste/df31068806cfc4bef186a9/
*/

/*
Problem: Salary Queries
Link: https://cses.fi/problemset/task/1144/
Author: Krishna200608

Short Problem Statement:
Maintain an array of salaries. Process queries to update a salary or count employees
with salaries in a range [a, b]. Values up to 10^9 require coordinate compression.

Approach:
    Coordinate Compression: Collect all initial salaries and update values.
    Sort and remove duplicates to map large values to indices.
    Use a Fenwick Tree (BIT) over compressed indices.
    Point updates for salary changes.
    Range queries using prefix sums on BIT.

Time : O(Q log(N+Q))
Space Complexity: O(N+Q)
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

const int MAX_M = 600005;
int bit[MAX_M];
int max_val;

void update(int idx, int val) {
    for (; idx <= max_val; idx += idx & -idx)
        bit[idx] += val;
}

int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx)
        sum += bit[idx];
    return sum;
}

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;

    vi p(n);
    vi vals;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        vals.pb(p[i]);
    }

    struct Qry {
        char type;
        int k, x;
    };

    vector<Qry> qs(q);

    for (int i = 0; i < q; i++) {
        cin >> qs[i].type >> qs[i].k >> qs[i].x;
        if (qs[i].type == '!') vals.pb(qs[i].x);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    max_val = vals.size();

    auto get_idx = [&](int v) {
        return lower_bound(all(vals), v) - vals.begin() + 1;
    };

    for (int x : p) {
        update(get_idx(x), 1);
    }

    for (int i = 0; i < q; i++) {
        if (qs[i].type == '!') {
            int k = qs[i].k - 1;
            int x = qs[i].x;
            update(get_idx(p[k]), -1);
            p[k] = x;
            update(get_idx(x), 1);
        } else {
            int a = qs[i].k;
            int b = qs[i].x;

            int r = upper_bound(all(vals), b) - vals.begin();
            int l = lower_bound(all(vals), a) - vals.begin();

            outt(query(r) - query(l));
        }
    }
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
