/*
Problem:
You are given an array of n positive integers and an integer k (k >= 2).
Count the number of unordered pairs (i, j) such that ai * aj is a perfect k-th power.

Approach:
1. Precompute smallest prime factor (SPF) up to max(ai).
2. For each number, compute its prime factorization.
3. Reduce exponents modulo k to form a "signature".
4. Compute the complementary signature needed to make exponents divisible by k.
5. Use a map to count matching signatures seen so far.

Time Complexity: O(n log A)
Space Complexity: O(n)

Problem Link:
https://codeforces.com/problemset/problem/1225/D
*/

#include <bits/stdc++.h>
using namespace std;

static const int MAXA = 100000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Step 1: Compute Smallest Prime Factor (SPF)
    vector<int> spf(MAXA + 1);
    for (int i = 1; i <= MAXA; i++) spf[i] = i;

    for (int i = 2; i * i <= MAXA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXA; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }

    // Map to store frequency of signatures
    map<vector<pair<int,int>>, long long> freq;
    long long answer = 0;

    // Step 2–5: Process each number
    for (int x : a) {
        map<int,int> factorCount;

        // Factorize using SPF
        while (x > 1) {
            int p = spf[x];
            factorCount[p]++;
            x /= p;
        }

        vector<pair<int,int>> signature;
        vector<pair<int,int>> complement;

        for (auto &it : factorCount) {
            int prime = it.first;
            int exp = it.second % k;

            if (exp != 0) {
                signature.push_back({prime, exp});
                complement.push_back({prime, (k - exp) % k});
            }
        }

        // Count valid pairs
        answer += freq[complement];

        // Store current signature
        freq[signature]++;
    }

    cout << answer << "\n";
    return 0;
}
