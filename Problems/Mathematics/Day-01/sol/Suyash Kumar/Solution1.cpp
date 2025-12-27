#include <bits/stdc++.h>
using namespace std;

#define int long long

/*
PROBLEM
- We have n people sitting circularly where n is even
- We are given a, b, c where a is opposite to b 
- Find who is sitting opposite to c
*/

/*

APPROACH

- As a is opposite to b, between a and b we will have 2*(a-b-1)+2 = 2abs(a-b)
This  determines the size of the circle (sz)

- Now we verify if the given a, b, c are valid or not which can be done by checking a,b,c <= sz

- If valid, the neighborr of c will be (c + sz/2) % SIZE OF CIRCLE (convert to 0 based to prevent a % a == 0)

*/

/*
TIME COMPLEXITY - O(1)
SPACE COMPLEXITY - O(1)
*/

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int sz = 2*abs(a-b);
  if (a <= sz && b <= sz && c <= sz) {
    int d = (c + sz/2 - 1) % sz + 1;
    cout << d << '\n';
  }
  else {
    cout << -1 << '\n';
  }
}


signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
