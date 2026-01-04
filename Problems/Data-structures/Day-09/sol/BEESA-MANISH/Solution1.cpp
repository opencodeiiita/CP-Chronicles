/*
Submission link - https://cses.fi/problemset/result/15829712/

TC - o((N + Q) log(N+Q) )
SC - O(N + Q)

Approach (Simple & Short):

Compress salary values since they can be as large as 10^9.
Use a Fenwick Tree to store and manage salary frequencies.
On updates, reduce the count of the old salary and increase the new one.
For range queries, get the answer using prefix sums from the Fenwick Tree.

*/


#include <bits/stdc++.h>
using namespace std;
const int N = 600005;
int n, q;
int cur_p[200005];
int t[N];
struct Query {
    int type, a, b;
} qs[200005];
 
void add(int i, int v) {
    for (; i < N; i += i & -i) t[i] += v;
}
 
int sum(int i) {
    int s = 0;
    for (; i > 0; i -= i & -i) s += t[i];
    return s;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    vector<int> coords;
    for (int i = 1; i <= n; i++) {
        cin >> cur_p[i];
        coords.push_back(cur_p[i]);
    }
    for (int i = 0; i < q; i++) {
        char op; cin >> op;
        cin >> qs[i].a >> qs[i].b;
        if (op == '!') {
            qs[i].type = 1;
            coords.push_back(qs[i].b);
        } else {
            qs[i].type = 2;
            coords.push_back(qs[i].a);
            coords.push_back(qs[i].b);
        }
    }
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
 
    auto get_idx = [&](int x) {
        return lower_bound(coords.begin(), coords.end(), x) - coords.begin() + 1;
    };
 
    for (int i = 1; i <= n; i++) add(get_idx(cur_p[i]), 1);
 
    for (int i = 0; i < q; i++) {
        if (qs[i].type == 1) {
            add(get_idx(cur_p[qs[i].a]), -1);
            cur_p[qs[i].a] = qs[i].b;
            add(get_idx(cur_p[qs[i].a]), 1);
        } else {
            cout << sum(get_idx(qs[i].b)) - sum(get_idx(qs[i].a) - 1) << "\n";
        }
    }
    return 0;
}