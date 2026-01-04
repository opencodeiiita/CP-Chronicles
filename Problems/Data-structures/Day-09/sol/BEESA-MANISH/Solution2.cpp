/*

Submission link: https://codeforces.com/contest/61/submission/356395307

TC- o(n log n)
SC - o(n)

Approach:
Convert large numbers into smaller ranks so they are easy to work with.
Treat each element as the middle of a triplet.
Count bigger elements on the left and smaller elements on the right.
Multiply these counts and sum for all positions to get the answer.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1000005;
int n;
int a[N], t[N];
int l_big[N], r_small[N];

void add(int i, int v) {
    for (; i <= n; i += i & -i) t[i] += v;
}

int sum(int i) {
    int s = 0;
    for (; i > 0; i -= i & -i) s += t[i];
    return s;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        int rk = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        l_big[i] = i - sum(rk);
        add(rk, 1);
    }

    memset(t, 0, sizeof(t));

    for (int i = n - 1; i >= 0; i--) {
        int rk = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        r_small[i] = sum(rk - 1);
        add(rk, 1);
    }

    ll total = 0;
    for (int i = 0; i < n; i++) {
        total += (ll)l_big[i] * r_small[i];
    }
    cout << total << endl;

    return 0;
}