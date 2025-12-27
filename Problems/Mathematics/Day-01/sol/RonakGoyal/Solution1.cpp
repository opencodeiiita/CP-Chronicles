/*
Problem Statement:
Some number of people (this number is even) are standing evenly in a circle.
Each person looks directly at the person opposite to them.
Given that person a is looking at person b, determine whom person c
is looking at. If no such circle configuration exists, output -1.

Approach:
1. The distance between opposites (diff) is half the total population.
   N = 2 * |a - b|
2. Validity Check: a, b, and c must all be less than or equal to N.
3. To find the opposite of c:
   - If c <= N/2, its opposite is c + N/2.
   - If c > N/2, its opposite is c - N/2.

Time Complexity:
O(1) per test case

Space Complexity:
O(1)
Example:
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

Submission Link : https://codeforces.com/contest/1560/submission/355273828
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;

        long long diff = llabs(a - b);
        long long N = 2 * diff;

        if (a > N || b > N || c > N) {
            cout << -1 << endl;
        } else {
            long long half = N / 2;
            long long d;
            if (c <= half) {
                d = c + half;
            } else {
                d = c - half;
            }
            cout << d << endl;
        }
    }

    return 0;
}


