#include <bits/stdc++.h>
using namespace std;

long long fact[1005];
const long long MOD = 1e9 + 7;
void init() {
    fact[0] = 1;
    for (int i = 1; i <= 1000; i++)
        fact[i] = fact[i - 1] * i % MOD;
}
long long modpow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    init();
     int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        long long a[n];
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        sort(a,a+n);
        reverse(a,a+n);
        long long repeat =a[k-1];
        int avl=0;
        unordered_map<long long,long long> m;
        for (int i = 0; i < k; ++i) {
            m[a[i]]++;
        }
        for (int i = 0; i < n; ++i) {
            if(a[i]==repeat){
                avl++;
            }
        }
        int ans=1;
        for(auto &[key,val]:m){
            if(key==repeat){
            ans = fact[avl] * modpow(fact[avl - val], MOD - 2) % MOD * modpow(fact[val], MOD - 2) % MOD;
            }
            else{
                ans*=1;
            }
        }
        cout << ans <<'\n';
    }
    
    return 0;
}
//time complexity - O(nlogn)
//https://codeforces.com/contest/1475/submission/355454659