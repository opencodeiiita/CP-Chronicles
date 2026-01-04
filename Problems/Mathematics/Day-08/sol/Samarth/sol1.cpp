#include <bits/stdc++.h>
#define endl '\n'
#define in(a) for(int i = 0; i<a.size(); i++) cin>>a[i];
typedef long long ll;

using namespace std;

/*
PROBLEM STATEMENT:
Sasha wants to buy an apartment on a street where the houses are numbered from 1 to 109

from left to right.

There are n
bars on this street, located in houses with numbers a1,a2,…,an

. Note that there might be multiple bars in the same house, and in this case, these bars are considered distinct.

Sasha is afraid that by the time he buys the apartment, some bars may close, but no more than k

bars can close.

For any house with number x
, define f(x) as the sum of |x−y| over all open bars y

(that is, after closing some bars).

Sasha can potentially buy an apartment in a house with number x
(where 1≤x≤109) if and only if it is possible to close at most k bars so that after that f(x)

becomes minimal among all houses.

Determine how many different houses Sasha can potentially buy an apartment in.


APPROACH:
the median is the answer(if n is even then elemnts btwn & including n/2 &n/2+1) if no bars are closed;
and we observe a pattern that if even bars are closed in even n the range increases to n/2-k/2 to n/2+1 +k/2;
and if odd bars are closed in odd n then range becomes (n+1)/2-(k+1)/2 to (n+1)/2 +(k+1)/2;
so we just implement the same ;


TIME COMPLEXITY:O(nlogn) (to sort);

Submission link:
https://codeforces.com/contest/2098/submission/356268443


*/




void solve(){
	int n,k;cin>>n>>k;vector<int>a(n);in(a);
	sort(a.begin(),a.end());
	if(n&1){
		cout<<a[(n+1)/2+(k+1)/2-1]-a[(n+1)/2-(k+1)/2-1]+1<<endl;
	}
	else{
		cout<<a[n/2+k/2]-a[n/2-k/2-1]+1<<endl;
	}
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	int t;cin>>t;
	while(t--)
		solve();
	
}
