#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

/*
Problem Statement:
There are n people standing in a circle (n is even). Each person looks at the person
standing exactly opposite them. Given that person a looks at person b, determine
the person that person c is looking at.

Approach:
- Determine the circle size n Since a and b are opp. the distance between them diameter
- If any of the given numbers a, b and c are greater than n the configuration 
is impossible. Output -1.
- Find opposite of c

Time Complexity: O(1)
Space Complexity: O(1)
*/


int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        ll t = 2 * abs(a - b);

        if (t >= a && t >= b && c <= t)
        {
            if (c > t / 2)
                cout << c - t / 2 << endl;
            else
                cout << t / 2 + c << endl;
        }
        else
            cout << -1 << endl;
    }

    return 0;
}