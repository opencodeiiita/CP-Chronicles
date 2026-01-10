/* submission: https://www.codechef.com/viewsolution/1224592781
P.S.: given two arrays A and B, each of length N.
Every number from 1 to 2N appears exactly once in either A or B.
A pair of subarrays A[L…R] and B[L…R] is called perfect if it is possible to build an array C[L…R] such that:
    For every index i in [L, R],
    C[i] = A[i] or C[i] = B[i]
The array C is strictly increasing. We need to count how many pairs (L, R) satisfy 1 ≤ L ≤ R ≤ N such that the subarrays A[L…R] and B[L…R] are perfect.
*/
//T.C.: O(N), S.C.: O(N)
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    // P[i] is the leftmost L such that [L, i] is perfect ending at a[i]
    // Q[i] is the leftmost L such that [L, i] is perfect ending at b[i]
    vector<int> p(n + 1), q(n + 1);

    // Base case: at index 1, you can always start a sequence
    p[1] = 1;
    q[1] = 1;

    long long total_perfect = 1; // Count for R=1

    for (int i = 2; i <= n; i++) {
        // Calculate P[i] (earliest start to reach a[i])
        int best_p = i; 
        if (a[i-1] < a[i]) best_p = min(best_p, p[i-1]);
        if (b[i-1] < a[i]) best_p = min(best_p, q[i-1]);
        p[i] = best_p;

        // Calculate Q[i] (earliest start to reach b[i])
        int best_q = i;
        if (a[i-1] < b[i]) best_q = min(best_q, p[i-1]);
        if (b[i-1] < b[i]) best_q = min(best_q, q[i-1]);
        q[i] = best_q;

        // For this R=i, any L from min(p[i], q[i]) to i is valid
        total_perfect += (i - min(p[i], q[i]) + 1);
    }

    cout << total_perfect << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
