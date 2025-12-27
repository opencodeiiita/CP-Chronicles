/*
n = number of elements (≤ 100,000)

A = maximum value of ai (≤ 100,000)

Space Complexity - 𝑂(𝐴+𝑛)

Time Complexity - O(nlogA)​


*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // Smallest Prime Factor sieve
    const int MAXA = 100000;
    vector<int> spf(MAXA + 1);
    for (int i = 1; i <= MAXA; i++) spf[i] = i;
    for (int i = 2; i * i <= MAXA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXA; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }

    map<vector<pair<int,int>>, long long> freq;
    long long ans = 0;

    for (int x : a) {
        map<int,int> cnt;

        // factorization
        while (x > 1) {
            int p = spf[x];
            int c = 0;
            while (x % p == 0) {
                x /= p;
                c++;
            }
            cnt[p] += c;
        }

        vector<pair<int,int>> sig, need;

        for (auto &it : cnt) {
            int p = it.first;
            int e = it.second % k;
            if (e != 0) {
                sig.push_back({p, e});
                need.push_back({p, (k - e) % k});
            }
        }

        sort(sig.begin(), sig.end());
        sort(need.begin(), need.end());

        ans += freq[need];
        freq[sig]++;
    }

    cout << ans << "\n";
    return 0;
}
