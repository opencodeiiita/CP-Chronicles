//submission link- https://codeforces.com/contest/61/submission/356380170


#include <bits/stdc++.h>
using namespace std;

int bit[1000005];
int a[1000005];
long long left_greater[1000005];
int n;

void update(int idx, int val) {
    while (idx <= n) {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int main() {
    cin >> n;
    
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        temp.push_back(a[i]);
    }

    sort(temp.begin(), temp.end());

    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin() + 1;
    }

    for (int i = 0; i < n; i++) {
        left_greater[i] = i - query(a[i]);
        update(a[i], 1);
    }

    for (int i = 0; i <= n; i++) {
        bit[i] = 0;
    }

    long long ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        long long right_smaller = query(a[i] - 1);
        ans += left_greater[i] * right_smaller;
        update(a[i], 1);
    }

    cout << ans << endl;

    return 0;
}
