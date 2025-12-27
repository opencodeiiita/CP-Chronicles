#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    map<vector<pair<int,int>>, long long> freq;
    long long ans = 0;

    for (int x : a) {
        int temp = x;
        vector<pair<int,int>> cur, need;

        for (int p = 2; p * p <= temp; p++) {
            if (temp % p == 0) {
                int cnt = 0;
                while (temp % p == 0) {
                    temp /= p;
                    cnt++;
                }
                cnt %= k;
                if (cnt) {
                    cur.push_back({p, cnt});
                    need.push_back({p, (k - cnt) % k});
                }
            }
        }

        if (temp > 1) {
            cur.push_back({temp, 1 % k});
            need.push_back({temp, (k - 1) % k});
        }

        ans += freq[need];
        freq[cur]++;
    }

    cout << ans << "\n";
    return 0;
}
