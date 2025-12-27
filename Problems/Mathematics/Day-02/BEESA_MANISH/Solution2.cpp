/*
TC - O(N^2)
SC - O(N^2)
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
 
using namespace std;
long long C[1005][1005];
const int MOD = 1e9 + 7;
void precompute() {
    for (int i = 0; i <= 1000; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> total_freq;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total_freq[a[i]]++;
    }
 
    sort(a.rbegin(), a.rend());
 
    int v = a[k - 1]; 
    int needed_count = 0;
 
    for (int i = 0; i < k; i++) {
        if (a[i] == v) needed_count++;
    }
 
    int total_count = total_freq[v];
 
    cout << C[total_count][needed_count] << "\n";
}
 
int main() {
 
    precompute();
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}