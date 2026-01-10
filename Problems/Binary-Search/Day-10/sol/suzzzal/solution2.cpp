//submission link - https://www.codechef.com/viewsolution/1224383853

/*
my approach:-
first we use binary search on the value mid.  
we keep two pointers left and right to decide the search range.  
for every mid, we calculate a value v starting from mid-1.  
then we repeat the operation x times using v = v - v/y.  
after this, we check if v + 1 > k is true or not.  
if it is true, we store mid in answer and move right to mid-1.  
if it is false, we move left to mid+1.  
we keep doing this until left becomes bigger than right.  
The data structure used is simple variables like left, right, mid and loops, and binary search makes the solution fast.
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) swap(a[i], b[i]);
        }

        vector<vector<long long>> dp(n, vector<long long>(2, 0));
        dp[0][0] = 1;
        dp[0][1] = 0;

        for (int i = 1; i < n; i++) {
            if (a[i] > b[i - 1]) {
                dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + 1;
                dp[i][1] = 0;
            } else if (a[i] > a[i - 1]) {
                dp[i][0] = dp[i - 1][0] + 1;
                if (b[i] > b[i - 1]) dp[i][1] = dp[i - 1][1];
            } else {
                dp[i][0] = 1;
                if (b[i] > b[i - 1]) dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
                else if (b[i] > a[i - 1]) dp[i][1] = dp[i - 1][0];
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) ans += dp[i][0] + dp[i][1];

        cout << ans << "\n";
    }

    return 0;
}
