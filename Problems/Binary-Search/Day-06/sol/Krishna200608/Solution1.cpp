/*
Problem: Robin Hood in Town
Link: https://codeforces.com/contest/2014/problem/C
Author: Krishna Sikheriya (Krishna200608)

Short Problem Statement:
We have a population of n people with given wealths. We want to give x gold to one person 
(the richest) such that strictly more than half of the population becomes "unhappy".
A person is unhappy if their wealth is strictly less than half of the average wealth.
Find the minimum non-negative integer x to achieve this. If impossible, output -1.

Approach:
We need to find the minimum integer x such that the count of people with wealth < (new_average / 2) is > n / 2.
1. If n <= 2, it is impossible to have strictly more than half the population satisfy the condition (since the max wealth will always be >= average). Output -1.
2. Sort the wealth array to easily count or check conditions.
3. The condition is monotonic: adding more gold increases the average, making it easier for existing wealths to fall below half the average.
4. We can Binary Search for x in the range [0, 1e18].
   - Calculation: New Sum = Current Sum + mid.
   - Check: We need strictly more than n/2 people to be poor. 
     In a sorted array, this means the person at index n/2 (0-indexed) must be poor.
     Condition: a[n/2] < (Sum + mid) / (2 * n)
     To avoid floating point errors, we use cross-multiplication:
     2 * n * a[n/2] < Sum + mid
5. The smallest valid 'mid' is our answer.

Time Complexity: O(n log n) due to sorting. Binary search takes O(log(1e18)) steps, each check is O(1).
Space Complexity: O(n) to store the wealths.

Example I/O:
Input:
2
1
1
3
2 3 3

Output:
-1
3
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Use long long to prevent overflow
using ll = long long;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    // If n is 1 or 2, it's impossible to have >50% population strictly less than half average
    if (n <= 2) {
        cout << -1 << "\n";
        return;
    }

    sort(a.begin(), a.end());

    // We binary search for x. Range [0, 2e18] is sufficient.
    ll low = 0, high = 2e18;
    ll ans = -1;

    while (low <= high) {
        ll mid = low + (high - low) / 2;

        // Check condition: a[n/2] < (sum + mid) / (2 * n)
        // Equivalent to: 2 * n * a[n/2] < sum + mid
        if (2LL * n * a[n/2] < sum + mid) {
            ans = mid;
            high = mid - 1; // Try smaller x
        } else {
            low = mid + 1;  // Need larger x
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

/*
SUBMISSION LINK:
https://codeforces.com/contest/2014/submission/356082645
*/