/*We have:

An even number of people n standing in a circle, numbered 1 to n clockwise.

Each person looks directly opposite in the circle.

You are given three numbers: a, b, c.

a is looking at b.

We want to know who c is looking at.

If no circle is possible → return -1.

*/

typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	   ll a, b, c;
        cin >> a >> b >> c;

        ll diff = abs(a - b);
        ll n = 2 * diff;

        if (diff==0 || max({a,b,c})> n){
            cout << -1 << endl;
        } else {
            ll d = c + diff;
            if (d > n) d -= n;
            cout << d << endl;
	}
	}
  return 0;
}

//O(1) per test case
//My SUBMISSION : https://codeforces.com/contest/1560/submission/355307599