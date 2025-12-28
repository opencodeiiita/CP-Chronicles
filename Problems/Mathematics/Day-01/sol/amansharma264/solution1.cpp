/*
====================================================
PROBLEM STATEMENT:
====================================================
There are n people standing in a circle (n is even).
Each person looks at the person exactly opposite to them.

You are given three distinct integers a, b, and c.
It is known that person 'a' is looking at person 'b'.

Determine the person that 'c' is looking at.
If multiple answers exist, print any.
If no valid answer exists, print -1.

----------------------------------------------------
PROBLEM LINK:
https://codeforces.com/problemset/problem/1560/B
====================================================
*/

/*
====================================================
APPROACH:
====================================================
If person 'a' is looking at person 'b', then:
- The distance between them is |a - b|
- Since they are opposite, total number of people:
      n = 2 * |a - b|

Steps:
1. Compute dist = |a - b|
2. Compute n = 2 * dist
3. If a, b, or c is greater than n → invalid → print -1
4. Otherwise, the person opposite to c is:
   - c + dist (if within n)
   - else c - dist

----------------------------------------------------
WHY THIS WORKS:
- In a circular arrangement, opposite positions differ
  by exactly n/2 positions.
====================================================
*/

/*
====================================================
TIME & SPACE COMPLEXITY:
====================================================
Time Complexity:  O(1) per test case
Space Complexity: O(1)
====================================================
*/

/*
====================================================
EXAMPLE:
====================================================
Input:
1
1 3 2

Output:
4

Explanation:
|1 - 3| = 2 → n = 4
Opposite of 2 is 2 + 2 = 4
====================================================
*/

/*
====================================================
SUBMISSION LINK:
====================================================
https://codeforces.com/contest/1560/submission/345095137
====================================================
*/

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    fastio();

    int t;
    cin >> t;

    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;

        long long dist = llabs(a - b);
        long long n = 2 * dist;

        if (a > n || b > n || c > n) {
            cout << -1 << '\n';
            continue;
        }

        if (c + dist <= n)
            cout << c + dist << '\n';
        else
            cout << c - dist << '\n';
    }

    return 0;
}
