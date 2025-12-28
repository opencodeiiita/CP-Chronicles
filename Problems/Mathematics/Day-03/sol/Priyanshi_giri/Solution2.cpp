#include <bits/stdc++.h>
using namespace std;

/*
Problem:
Given two integers x and y, repeatedly add ⌊x / y⌋ to a counter,
replace x with x % y, swap x and y, and continue until y becomes 0.
Print the final counter value.

Approach:
The solution follows the Euclidean algorithm. At each step,
the value (x / y) contributes to the answer. These values are
added cumulatively, similar to a prefix-sum over iterations.

Complexity:
Time:  O(log(min(x, y)))
Space: O(1)

Example:
Input:  5 2
Output: 4



https://codeforces.com/contest/343/submission/355484926
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x, y;
    cin >> x >> y;

    long long ans = 0;
    while (y > 0) {
        ans += x / y;
        x %= y;
        swap(x, y);
    }

    cout << ans << '\n';
    return 0;
}
