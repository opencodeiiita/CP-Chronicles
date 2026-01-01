/*
====================================================
Problem: Robin Hood in Town (Codeforces 2014C)
Link: https://codeforces.com/contest/2014/problem/C
Author: Krishna Sikheriya (Krishna200608)
====================================================

-------------------------
Short Problem Statement
-------------------------
You are given the wealth of n people in a town.
You are allowed to give x gold coins to exactly one person
(the richest person).

After this operation, a person is considered "unhappy" if
their wealth is strictly less than half of the average wealth
of the town.

Your task is to find the minimum non-negative integer x such that
strictly more than half of the population becomes unhappy.
If it is impossible, output -1.

-------------------------
Approach (Binary Search)
-------------------------
Observations:
- If n <= 2, it is impossible to make strictly more than half
  of the population unhappy. So the answer is -1.
- Adding gold only increases the total sum, which increases the
  average, making it easier for people to fall below half of it.
  Hence, the condition is monotonic.

Steps:
1. Read n and the wealth array.
2. If n <= 2, directly output -1.
3. Sort the array to reason about the poorest half easily.
4. Let sum be the total initial wealth.
5. Binary search on x (the extra gold given to the richest person).
   - New total wealth = sum + x
   - New average = (sum + x) / n
   - Half average = (sum + x) / (2 * n)
6. To ensure strictly more than half are unhappy:
   - The person at index n/2 (0-based) must be unhappy.
   - Condition:
       a[n/2] < (sum + x) / (2 * n)
     To avoid floating point precision issues, use:
       2 * n * a[n/2] < sum + x
7. The smallest x satisfying the condition is the answer.

-------------------------
Time & Space Complexity
-------------------------
Time Complexity:
- Sorting: O(n log n)
- Binary Search: O(log 1e18)
- Overall: O(n log n)

Space Complexity:
- O(n) to store the wealth array

-------------------------
Example I/O (Optional)
-------------------------
Input:
2
1
1
3
2 3 3

Output:
-1
3

-------------------------
Submission Link
-------------------------
https://codeforces.com/contest/2014/submission/356082645
====================================================
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    // Not possible for n <= 2
    if (n <= 2) {
        cout << -1 << '\n';
        return;
    }

    sort(a.begin(), a.end());

    ll low = 0, high = 2e18;
    ll answer = -1;

    while (low <= high) {
        ll mid = low + (high - low) / 2;

        // Check if more than half become unhappy
        if (2LL * n * a[n / 2] < sum + mid) {
            answer = mid;
            high = mid - 1; // try smaller x
        } else {
            low = mid + 1;  // need larger x
        }
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
