/*
====================================================
Problem: B. Who's Opposite? (Codeforces)
====================================================

Problem Statement:
There are n people standing in a circle (n is even).
They are numbered from 1 to n in clockwise order.

Each person looks at the person exactly opposite to them.

You are given three distinct integers a, b, and c:
- Person 'a' is looking at person 'b'.

Your task:
Find the person that person 'c' is looking at.

If no such circle is possible, print -1.

----------------------------------------------------
Approach:
- Since 'a' and 'b' are opposite, the distance between them is n/2.
- Hence, total number of people:
        n = 2 × |a − b|
- If any of a, b, or c > n → invalid circle → print -1
- Otherwise:
    - The opposite of c is:
        c + n/2  (if within n)
        else
        c − n/2

----------------------------------------------------
Time Complexity:  O(1) per test case
Space Complexity: O(1)

----------------------------------------------------
Example:
Input:
7
6 2 4
2 3 1
2 4 10
5 3 4
1 3 2
2 5 4
4 3 2

Output:
8
-1
-1
-1
4
1
-1
====================================================
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        // Total number of people in the circle
        int n = abs(a - b) * 2;

        // Invalid case
        if (a > n || b > n || c > n) {
            cout << -1 << "\n";
        } 
        else {
            int opposite = c + n / 2;

            if (opposite <= n)
                cout << opposite << "\n";
            else
                cout << c - n / 2 << "\n";
        }
    }

    return 0;
}
