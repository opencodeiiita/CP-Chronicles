/*
Problem:
People are standing in a circle numbered 1 to n (n is even).
Person a is opposite person b.
We must find who is opposite person c.
If impossible, print -1.

Key Observation:
If a is opposite b → distance between them is exactly n/2.
So:
    n = |a - b| * 2

Once we know n, we know half circle size = n / 2

Opposite of any person x is:
    x + n/2      (if <= n)
otherwise:
    x - n/2

Invalid Cases:
1.max(a, b, c) > n  → means c doesn't exist in circle
2.a == b or diff == 0   → opposite cannot be same
Output -1 in such cases.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--){
        long long a, b, c;
        cin >> a >> b >> c;

        // Distance between a and b
        long long diff = abs(a - b);

        // Total number of people in circle
        long long n = diff * 2;

        // Invalid cases
        if (diff == 0 || a > n || b > n || c > n) {
            cout << -1 << endl;
            continue;
        }

        // Halfway around the circle
        long long half = n / 2;

        // Opposite of c
        long long ans = c + half;

        // If goes beyond circle wrap around
        if (ans > n) ans -= n;

        cout << ans << endl;
    }
    return 0;
}
