/*
 * Problem: Count pairs (i, j) where a[i] * a[j] is a perfect k-th power
 * 
 * Approach using prime factorization and modular exponents:
 * - For a product to be a perfect k-th power, all prime exponents must be divisible by k
 * - For each number, compute its "signature" = prime factors with exponents mod k
 * - Two numbers form a valid pair if their signatures are "complementary" (sum to k for each prime)
 * 
 * Time Complexity: O(n * sqrt(max_a) * log(max_a))
 * Space Complexity: O(n)
 * 
 * Submission Link:https://codeforces.com/contest/1225/submission/355203315
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    map<map<int, int>, long long> cnt;
    long long ans = 0;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        
        // Get prime factorization with exponents mod k
        map<int, int> sig;  // signature of current number
        map<int, int> need; // complementary signature needed
        
        for (int p = 2; p * p <= a; p++) {
            int exp = 0;
            while (a % p == 0) {
                a /= p;
                exp++;
            }
            exp %= k;
            if (exp > 0) {
                sig[p] = exp;
                need[p] = k - exp;
            }
        }
        
        // If a > 1, it's a prime factor
        if (a > 1) {
            int exp = 1 % k;
            if (exp > 0) {
                sig[a] = exp;
                need[a] = k - exp;
            }
        }
        
        // Count pairs with complementary signature
        ans += cnt[need];
        
        // Add current signature to map
        cnt[sig]++;
    }
    
    cout << ans << endl;
    
    return 0;
}

/*
 * Example I/O:
 * Input:
 * 6 3
 * 1 3 9 8 24 1
 * 
 * Output:
 * 5
 * 
 * Explanation:
 * Valid pairs: (1,1), (1,8), (1,1), (8,1), (3,9,24 combinations that form cubes)
 */
