/*
Problem: Sasha and the Apartment Purchase
Link: https://codeforces.com/problemset/problem/2098/B
Author: Krishna200608

Short Problem Statement:
Find the number of integer coordinates x that can be a median of the remaining bars after removing at most k bars.

Approach:
- Sort the bar positions.
- A median forms a range only if the subset size is even. If size is odd, it's a single point.
- To maximize positions, we aim for an even subset size 'm'.
- If (n-k) is even, m = n-k. If odd, m = n-k+1 (remove k-1 items).
- Exception: If k=0 and n is odd, we can't make it even, so ans = 1.
- For size m, the valid range of medians spans from index (m/2 - 1) to (n - m/2).

Time Complexity: O(N log N)
Space Complexity: O(N)
*/

/*
Submission Link:
https://codeforces.com/contest/2098/submission/356177931
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
typedef vector<ll> vll;
#define in(a) for(int i = 0; i<a.size(); i++) cin>>a[i];

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    
    vll a(n);
    in(a);
    
    sort(a.begin(), a.end());

    if (k == 0 && n % 2 != 0) {
        cout << "1\n";
        return;
    }

    int m = n - k;
    if (m % 2 != 0) m++; 
   
    int l = m / 2 - 1;
    int r = n - m / 2;

    cout << (a[r] - a[l] + 1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

