#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long factorial(int n) {
    if (n <= 1) return 1;
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

long long power(long long a, long long b, long long m = MOD) {
    long long result = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) result = (result * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return result;
}

long long mod_inverse(long long a, long long m = MOD) {
    return power(a, m - 2, m);
}

long long nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    if (r == 0 || r == n) return 1;
    
    long long num = factorial(n);
    long long den = (factorial(r) * factorial(n - r)) % MOD;
    return (num * mod_inverse(den)) % MOD;
}

int main() {
    int ti;
    cin >> ti;
    
    while (ti--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        sort(a.begin(), a.end(), greater<int>());
        
        int kth = a[k - 1];
        
        int total = count(a.begin(), a.end(), kth);
        int selected = 0;
        
        for (int i = 0; i < k; i++) {
            if (a[i] == kth) {
                selected++;
            }
        }
        
        cout << nCr(total, selected) << endl;
    }
    
    return 0;
}