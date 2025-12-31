//submission- https://codeforces.com/contest/1846/submission/356011684

/*
Approach:
- Precompute all valid snowflake sizes of the form:
  1 + k + k^2 + k^3 + ... (k > 1, at least 3 terms)
- Use __int128 to safely handle values up to 10^18
- Store all generated values in a set for fast lookup
- For large x, additionally check the special case:
  x = 1 + k + k^2 using quadratic formula
- Answer YES if x matches any valid construction

Complexity:
Precomputation: ~O(K * log n)
Query: O(log n)
Space: O(N)
*/

#include <bits/stdc++.h>
using namespace std;
 
set <__int128> s;
 
const __int128 INF = 1000000000000000000ll;
 
int main()	{
	for(long long i = 2; i <= 1000000; ++i)	{
		__int128 j = i + 1;
		__int128 l = i * i;
		while(j + l <= INF)	{
			j += l;
			l *= i;
			s.insert(j);
		}
  }
	int tt;
	cin >> tt;
	while(tt--)	{
		long long x;
		cin >> x;
		if(s.count(x))	{
			cout << "YES" << endl;
		}
		else if(x >= 1000000000000ll){
			long long delta = 1 - 4 * (1 - x);
			long long x1 = 0.5 * (-1 + sqrt(delta));
			if(x1 * x1 + x1 + 1 == x)	{
				cout << "YES" << endl;
			}
			else	{
				cout << "NO" << endl;
			}
		}
		else	{
			cout << "NO" << endl;
		}
	}
}
