/* Submission Link - https://codeforces.com/problemset/submission/1560/355259349
Problem: Codeforces 1560B - Who's Opposite?

Explanation:

People are standing on a circle, numbered from 1 to n (n is even).
Each person looks at the person exactly opposite them on the circle.

Key observation:
If a person at position x looks at position y, then the distance between
them along the circle must be exactly n/2.

Given:
a looks at b
=> |a - b| = n/2

So the total number of people in the circle must be:
n = 2 * |a - b|

Validity check:
All positions a, b, and c must lie within the range [1, n].
If max(a, b, c) > n, then such a circle is impossible → output -1.

Finding who c looks at:
The opposite position of c is c + (n/2).
If this exceeds n, we wrap around the circle by subtracting n.

Edge case:
If a == b, then |a - b| = 0 → invalid (no circle possible).

Algorithm:
1. Compute diff = |a - b|
2. Set n = 2 * diff
3. If diff == 0 or max(a, b, c) > n → print -1
4. Else compute d = c + diff
   If d > n, d -= n
5. Print d

Time Complexity: O(1) per test case
Space Complexity : O(1) as number of test cases are fixed */

#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        long long a, b, c;
        cin >> a >> b >> c;
 
        long long diff = llabs(a - b);
        long long n = 2 * diff;
 
        if(diff == 0 || max({a, b, c}) > n){
            cout << -1 << "\n";
        } else {
            long long d = c + diff;
            if(d > n) d -= n;
            cout << d << "\n";
        }
    }
    return 0;
}
