// https://codeforces.com/contest/1560/submission/355221108
/*
 * Problem: Who is Opposite?
 * There are n people in a circle (n is even). Person a is looking at person b.
 * We need to find who person c is looking at.
 * 
 * My Logic:
 * If person 'a' is looking at person 'b', they must be exactly opposite.
 * So the circle size n = 2 * |a - b| (distance between them times 2).
 * 
 * For person 'c' to exist in this circle, c must be <= n.
 * If c is in the first half (c <= n/2), they look at c + n/2.
 * Otherwise, they look at c - n/2.
 */

#include <iostream>
#include <cmath>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        ll a, b, c;
        cin >> a >> b >> c;
        
        // calculate circle size
        ll diff = abs(a - b);
        ll n = 2 * diff;
        
        // check if a, b, c are all valid positions in this circle
        if (a <= n && b <= n && c <= n) {
            // find who c is looking at
            if (c > diff) {
                cout << c - diff << "\n";
            } else {
                cout << c + diff << "\n";
            }
        } else {
            cout << "-1\n";
        }
    }
    
    return 0;
}
