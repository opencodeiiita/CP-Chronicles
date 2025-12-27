/*
Q2 You are given 𝑛
 positive integers 𝑎1,…,𝑎𝑛
, and an integer 𝑘≥2
. Count the number of pairs 𝑖,𝑗
 such that 1≤𝑖<𝑗≤𝑛
, and there exists an integer 𝑥
 such that 𝑎𝑖⋅𝑎𝑗=𝑥𝑘
.*/

#include <bits/stdc++.h>
using namespace std;
 
// Function to factorize a number and return prime exponents modulo k
map<int, int> factorizeMod(long long x, int k) {
    map<int, int> factors;
    for (long long p = 2; p * p <= x; ++p) {
        int count = 0;
        while (x % p == 0) {
            x /= p;
            count++;
        }
        if (count % k != 0) {
            factors[p] = count % k; // only store modulo k
        }
    }
    if (x > 1) factors[x] = 1 % k; // remaining prime factor
    return factors;
}
 
// Function to compute the complement signature modulo k
map<int, int> complementSignature(const map<int, int>& sig, int k) {
    map<int, int> comp;
    for (auto &[prime, exp] : sig) {
        comp[prime] = (k - exp) % k;
    }
    return comp;
}
 
int main() {
 
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
 
    // Map to count how many times each signature has occurred
    map<map<int,int>, long long> signatureCount;
    long long totalPairs = 0;
 
    for (int i = 0; i < n; ++i) {
        map<int,int> sig = factorizeMod(a[i], k);
        map<int,int> comp = complementSignature(sig, k);
 
        // Add pairs that match the complement
        totalPairs += signatureCount[comp];
 
        // Increment count of current signature
        signatureCount[sig]++;
    }
 
    cout << totalPairs << "\n";
    return 0;
}

/*
My submission : https://codeforces.com/problemset/submission/1225/355325134
*/