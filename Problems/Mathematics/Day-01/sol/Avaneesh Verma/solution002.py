#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, k;
    cin >> n >> k;
 
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
 
    map<vector<pair<int,int>>, long long> freq;
    long long ans = 0;
 
    for (int i = 0; i < n; i++) {
        int x = a[i];
        vector<pair<int,int>> cur, need;
 
        for (int p = 2; p * p <= x; p++) {
            if (x % p == 0) {
                int cnt = 0;
                while (x % p == 0) {
                    x /= p;
                    cnt++;
                }
                cnt %= k;
                if (cnt > 0) {
                    cur.push_back({p, cnt});
                    need.push_back({p, (k - cnt) % k});
                }
            }
        }
 
        if (x > 1) {
            cur.push_back({x, 1});
            need.push_back({x, (k - 1) % k});
        }
        sort(cur.begin(), cur.end());
        sort(need.begin(), need.end());
 
        ans += freq[need];
        freq[cur]++;
    }
    cout << ans << "\n";
    return 0;
}
