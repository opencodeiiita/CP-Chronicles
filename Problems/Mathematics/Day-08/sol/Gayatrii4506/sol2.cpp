/*Short Problem Statement

Given a binary array a of length n, consider all subsequences of odd length k.
For each subsequence, find its median.
Compute the sum of all medians modulo 10^9 + 7.

Key Observation
- Since the array is binary (0/1) and k is odd:
- The median is 1 iff the subsequence contains more than k/2 ones.
- Otherwise, the median is 0.

So the problem reduces to:
- Count how many subsequences of length k have at least (k+1)/2 ones.
- That count itself is the required sum.

Approach
- Let ones = total number of 1s in the array.
- For each valid number of ones i where
i ≥ (k+1)/2 and i ≤ min(k, ones):
- Choose i ones from ones
- Choose k-i zeros from (n - ones)
- Add  C(ones,i)×C(n−ones,k−i)
- Precompute factorials and inverse factorials for fast nCr.

Time & Space Complexity
- Time: O(n + k) per test case
- Space: O(n) (factorials)*/

#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1e9 + 7;
static const int MAXN = 200000;

long long fact[MAXN + 1], invfact[MAXN + 1];

long long power(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

long long C(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Precompute factorials
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) fact[i] = fact[i - 1] * i % MOD;
    invfact[MAXN] = power(fact[MAXN], MOD - 2);
    for (int i = MAXN; i > 0; i--) invfact[i - 1] = invfact[i] * i % MOD;

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int ones = 0;
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            ones += x;
        }

        int need = (k + 1) / 2;
        long long ans = 0;

        for (int i = need; i <= min(k, ones); i++) {
            ans = (ans + C(ones, i) * C(n - ones, k - i)) % MOD;
        }

        cout << ans << "\n";
    }
    return 0;
}
