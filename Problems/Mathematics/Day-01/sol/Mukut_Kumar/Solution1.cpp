/*
 * Problem: Perfect k-th Power Pairs
 * We need to find how many pairs in the array multiply to form a perfect k-th power.
 * 
 * My Logic:
 * Basically, for any number 'x', its prime factorization is p1^e1 * p2^e2...
 * For a product to be a k-th power, all prime exponents in its factorization 
 * must be multiples of k. So I just track the "remainder" exponents (exp % k) 
 * for each number. Then, I look for a "partner" number that has exactly 
 * the complement exponents needed to reach the next multiple of k.
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

// this function breaks down the number and returns its "prime signature"
vector<pair<int, int>> get_signature(int num, int k) {
    vector<pair<int, int>> sig;
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            int p_count = 0;
            while (num % i == 0) {
                p_count++;
                num /= i;
            }
            if (p_count % k != 0) {
                sig.push_back({i, p_count % k});
            }
        }
    }
    
    if (num > 1) {
        sig.push_back({num, 1}); // last prime factor always has exponent 1
    }
    
    return sig;
}

int main() {
    // fast i/o for competitive programming
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    map<vector<pair<int, int>>, int> freq_map;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        
        auto current_sig = get_signature(val, k);
        
        // now find what we need to complete this to a k-th power
        vector<pair<int, int>> required;
        for (auto &p : current_sig) {
            required.push_back({p.first, k - p.second});
        }
        
        // check if we've seen the complement before
        if (freq_map.count(required)) {
            ans += freq_map[required];
        }
        
        // add current signature to map for future pairs
        freq_map[current_sig]++;
    }

    cout << ans << "\n";
    return 0;
}
