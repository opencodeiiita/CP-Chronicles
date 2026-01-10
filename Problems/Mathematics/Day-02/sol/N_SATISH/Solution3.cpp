#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const int MAXN = 1000005;

int gcd_val[MAXN];
long long sum_gcd[MAXN];
long long result = 0;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= i; k++) {
            sum_gcd[i] = (sum_gcd[i] + gcd(k, i)) % MOD;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int g = gcd(i, j);
            long long contrib = (sum_gcd[i] * sum_gcd[j]) % MOD;
            
            long long inv_g = 1;
            for (int x = 0; x < g; x++) {
                inv_g = (inv_g * g) % MOD;
            }
            
            long long g_inv = 1;
            long long base = g;
            long long exp = MOD - 2;
            while (exp > 0) {
                if (exp % 2 == 1) {
                    g_inv = (g_inv * base) % MOD;
                }
                base = (base * base) % MOD;
                exp /= 2;
            }
            
            contrib = (contrib * g_inv) % MOD;
            result = (result + contrib) % MOD;
        }
    }
    
    cout << result << endl;
    
    return 0;
}