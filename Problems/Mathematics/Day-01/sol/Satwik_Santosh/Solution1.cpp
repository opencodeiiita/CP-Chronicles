/*
Problem Statement:
There are n people standing in a circle (n is even). Each person looks at the person
standing exactly opposite them. Given that person a looks at person b, determine
the person that person c is looking at.

---------------------------------------
Approach:
1. Determine the circle size (n): Since 'a' and 'b' are opposite, the distance between them 
is half the circle. Thus, n = 2 * |a - b|.
2. Validation: If any of the given numbers (a, b, c) aregreater than n, the configuration 
is impossible. Output -1.
3. Find opposite of 'c': The person opposite to 'c' is at a distance of n/2 from 'c'.

----------------------------------------

Time Complexity: O(1)

Space Complexity: O(1)

----------------------------------------
Example:
Input:
a = 1, b = 3, c = 2

Process : 
1. Calculate diff = |1 - 3| = 2
2. Calculate n = 2 * diff = 4  
3. Since c = 2, calculate opposite:
   - c + diff = 2 + 2 = 4 (which is <= n)
   - So, the person opposite to c is 4.

Output:
4
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout << (x) << endl
#define outr(x)          \
    {                    \
        cout << x << endl; \
        return;          \
    }

void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll diff = abs(a - b);
    ll n = diff * 2;

    if (a > n || b > n || c > n)
    {
        outr(-1);
    }
    ll ans = c + diff;
    if (ans > n)
        ans -= n;
    out(ans);
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}