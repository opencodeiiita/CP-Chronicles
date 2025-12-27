/*
We must choose k bloggers maximizing total followers.
This always means choosing the k largest elements.

Let x = value of the k-th largest element.
Let:
  total_x = how many times x appears in whole array
  need_x  = how many times x appears among chosen top k

Answer = C(total_x, need_x)  (mod 1e9+7)
*/

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
long long fact[1005], invfact[1005];

// fast exponentiation
long long power(long long a, long long b){
    long long res = 1;
    while(b){
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

// nCr using factorial + modular inverse
long long nCr(int n, int r){
    if(r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // precompute factorials
    fact[0] = 1;
    for(int i = 1; i <= 1000; i++) fact[i] = fact[i-1] * i % MOD;
    invfact[1000] = power(fact[1000], MOD-2);
    for(int i = 999; i >= 0; i--) invfact[i] = invfact[i+1] * (i+1) % MOD;

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for(int &x : a) cin >> x;

        sort(a.begin(), a.end(), greater<int>());

        int x = a[k-1]; // kth largest
        int need_x = 0, total_x = 0;

        for(int i = 0; i < k; i++)
            if(a[i] == x) need_x++;

        for(int i = 0; i < n; i++)
            if(a[i] == x) total_x++;

        cout << nCr(total_x, need_x) << "\n";
    }
}
