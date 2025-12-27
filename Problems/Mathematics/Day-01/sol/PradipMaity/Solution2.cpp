/*
We count pairs (i, j) such that ai * aj is a perfect k-th power.

Idea:
For each number, compute its prime factorization.
Reduce each exponent modulo k because only residue matters.
This forms a "signature".

Example (k = 3)
24 = 2^3 * 3^1  → exponents mod 3 → 2^0 * 3^1

To pair with another number to form perfect k-th power,
for each prime exponent 'e', we need (k - e) % k.

So for each number, we compute:
  signature        = reduced exponents
  neededSignature  = complementary exponents

We store counts of signatures in a map.
For each number, answer += count[neededSignature].

Time Complexity:
O(n * sqrt(max(ai)))

Space Complexity:
O(n)
*/

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
        int num = x;
        map<int,int> cnt;

        // Prime factorize
        for (int p = 2; p * p <= num; p++) {
            while (num % p == 0) {
                cnt[p]++;
                num /= p;
            }
        }
        if (num > 1) cnt[num]++;

        vector<pair<int,int>> sig;   // reduced signature
        vector<pair<int,int>> need;  // complementary signature

        for (auto &it : cnt) {
            int prime = it.first;
            int e = it.second % k;
            if (e != 0) {
                sig.push_back({prime, e});
                need.push_back({prime, (k - e) % k});
            }
        }

        ans += freq[need];
        freq[sig]++;
    }

    cout << ans << "\n";
    return 0;
}
