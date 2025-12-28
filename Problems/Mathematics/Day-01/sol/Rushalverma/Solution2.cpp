/*
https://codeforces.com/contest/1225/submission/355245357

time complexity: Factorization of each number using seive primes O(log maxA)
                 total factorization cost - O(nlog maxA)
                 Each number produces a vector of prime–exponent pairs mod k -> O(log maxA)
                 total map work - O(nlong maxA)
                 total complexity = O(nlog maxA)
                 


*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll k;
    cin >> n >> k;

    vector<ll> a(n);
    ll mx = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }


    ll LIM = sqrt(mx) + 2;
    vector<int> primes;
    vector<bool> is_prime(LIM+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= LIM; i++){
        if(is_prime[i]){
            primes.push_back(i);
            for(ll j = 1LL * i * i; j <= LIM; j += i)
                is_prime[j] = false;
        }
    }

    unordered_map<string, long long> cnt;
    long long ans = 0;

    for(int idx = 0; idx < n; idx++){
        ll x = a[idx];

        vector<pair<ll,ll>> v; 

        for(int p: primes){
            if(1LL * p * p > x) break;
            if(x % p == 0){
                ll c = 0;
                while(x % p == 0){
                    x /= p;
                    c++;
                }
                c %= k;
                if(c) v.push_back({p, c});
            }
        }

        if(x > 1) v.push_back({x, 1 % k}); 

        string key = "";
        for(auto &pr: v){
            key += to_string(pr.first) + "#" + to_string(pr.second) + "|";
        }

        vector<pair<ll,ll>> u;
        for(auto &pr: v){
            ll need = (k - pr.second) % k;
            if(need) u.push_back({pr.first, need});
        }

        string key2 = "";
        for(auto &pr: u){
            key2 += to_string(pr.first) + "#" + to_string(pr.second) + "|";
        }

        ans += cnt[key2];


        cnt[key]++;
    }

    cout << ans << "";
    return 0;
}