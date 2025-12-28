/*
Problem Statement:
There are n people standing in a circle (n is even). Each person looks at the person
standing exactly opposite them. Given that person a looks at person b, determine
the person that person c is looking at.

---------------------------------------
Approach:
If 'a' looks at 'b', then the distance between a and b must be exactly n/2.
Let dist = |a - b|. Then n = 2 * dist.
Once n is known, the person opposite to c is:
- c + dist, if it does not exceed n
- otherwise, c - dist

If c is greater than n, then the configuration is invalid.

----------------------------------------

Time Complexity: O(1)

Space Complexity: O(1)

----------------------------------------
Example:
Input:
a = 1, b = 3, c = 2

Process : 
1. Calculate dist = |1 - 3| = 2
2. Calculate n = 2 * dist = 4  
3. Since c = 2, calculate opposite:
   - c + dist = 2 + 2 = 4 (which is <= n)
   - So, the person opposite to c is 4.

Output:
4

--------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;


        int d = abs(a - b);
        int n = 2 * d;
        // 2*10^8 fits in int.

        // Invalid configuration, Answer does not exist
        if (d == 0 || c > n) {
            cout << -1 << "\n";
            continue;
        }

        int ans;
        if (c + d <= n)
            ans = c + d;
        else
            ans = c - d;

        cout << ans << "\n";
    }
    return 0;
}

//Submission Link: https://codeforces.com/problemset/submission/1560/355215212