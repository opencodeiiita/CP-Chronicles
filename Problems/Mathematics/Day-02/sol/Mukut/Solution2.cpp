/*
Problem: 
Pick k bloggers from n to maximize total followers, and count how many ways we can do this. 
The answer should be modulo 10^9 + 7.

Approach:
To maximize the sum, we must pick bloggers with the highest follower counts. 
I sort the array in descending order. The "threshold" value will be the followers of the k-th blogger.
I then count how many bloggers in the entire list have this threshold value and how many 
we actually need to pick from them to complete our k-blogger selection.
The result is simply (total_with_threshold) Choose (needed_from_them).
I used Pascal's triangle to precompute combinations since n is small (up to 1000).

TimeComplexity: O(n^2) precompute + O(n log n) per test case
Spacecomplexity: O(nCr table size) approx O(n^2)

Submission Link: https://codeforces.com/contest/1475/submission/355409229
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long nCr[1005][1005];
const int MOD = 1e9 + 7;

void pre() {
    for (int i = 0; i <= 1000; i++) {
        nCr[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % MOD;
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end(), greater<int>());

    int target = a[k - 1]; 
    int cnt = 0;
    for (int x : a) {
        if (x == target) cnt++;
    }

    int take = 0;
    for (int i = 0; i < k; i++) {
        if (a[i] == target) take++;
    }

    cout << nCr[cnt][take] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    pre();
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
