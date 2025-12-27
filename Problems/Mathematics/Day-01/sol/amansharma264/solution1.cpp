/*
Problem: A. Spell Check

Problem Statement:
Timur allows any permutation of the letters of his name "Timur" as a valid spelling,
but the spelling must contain exactly one uppercase 'T' and the remaining letters
('i', 'm', 'u', 'r') must be lowercase. Given a string s, check if it is a valid spelling
of Timur's name.

Approach:
1. If the length of the string is not 5, it cannot be "Timur".
2. Sort the given string.
3. Sort the reference string "Timur".
4. If both sorted strings are equal, then s is a valid permutation of "Timur".

Time Complexity:
O(n log n), where n = 5 (effectively constant).

Space Complexity:
O(1), uses only constant extra space.

Example:
Input:
1
5
miurT

Output:
YES

Question Link:
https://codeforces.com/problemset/problem/1722/A

Submission Link:
https://codeforces.com/contest/1722/submission/345095137
*/

#include <iostream>
#include <algorithm>
using namespace std;

void spellCheck() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    if (n != 5) {
        cout << "NO\n";
        return;
    }

    string name = "Timur";

    sort(s.begin(), s.end());
    sort(name.begin(), name.end());

    if (s == name) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        spellCheck();
    }

    return 0;
}
