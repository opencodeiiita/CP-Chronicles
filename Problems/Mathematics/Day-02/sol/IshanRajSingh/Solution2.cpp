/*
 * Problem: Codeforces 1475E - Advertising Agency
 * 
 * Problem Statement:
 * Given n bloggers with ai followers each, select k bloggers such that
 * the total number of followers is maximized. Count the number of ways
 * to make this selection.
 * 
 * Approach:
 * 1. To maximize followers, we must select the k bloggers with the most followers
 * 2. Sort the array in descending order and take the first k elements
 * 3. The k-th element (smallest in our selection) might have duplicates
 * 4. Count how many bloggers have the same follower count as the k-th blogger:
 *    - cnt_in_top_k = count in top k positions
 *    - cnt_total = total count with this value (in entire array)
 * 5. Answer = C(cnt_total, cnt_in_top_k) = ways to choose cnt_in_top_k from cnt_total
 * Time Complexity: O(n log n) for sorting + O(n) for counting = O(n log n)
 * Space Complexity: O(n) for storing array and O(n) for factorial precomputation
 * 
 * Mathematical Formula:
 * nCr = n! / (r! * (n-r)!)
 * In modular arithmetic (mod 10^9+7):
 * nCr = (n! * modInverse(r!) * modInverse((n-r)!)) % MOD
 */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1005;

long long fact[MAXN];
long long inv_fact[MAXN];

long long power(long long a, long long b, long long mod) {
    long long result = 1;
    a %= mod;
    
    while (b > 0) {
        if (b & 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    
    return result;
}

void precompute() {
    fact[0] = 1;
    
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    
    inv_fact[MAXN - 1] = power(fact[MAXN - 1], MOD - 2, MOD);
    
    for (int i = MAXN - 2; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

long long nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    if (r == 0 || r == n) return 1;
    

    long long result = fact[n];
    result = (result * inv_fact[r]) % MOD;
    result = (result * inv_fact[n - r]) % MOD;
    
    return result;
}

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> followers(n);
    for (int i = 0; i < n; i++) {
        cin >> followers[i];
    }
    
    sort(followers.begin(), followers.end(), greater<int>());
    
    int kth_value = followers[k - 1];
    
    int cnt_total = 0;
    int cnt_in_top_k = 0;
    
    for (int i = 0; i < n; i++) {
        if (followers[i] == kth_value) {
            cnt_total++;
            if (i < k) {
                cnt_in_top_k++;
            }
        }
    }
    
    long long answer = nCr(cnt_total, cnt_in_top_k);
    
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
