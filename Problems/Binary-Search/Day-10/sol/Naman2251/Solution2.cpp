//Submission Link: https://www.codechef.com/viewsolution/1224571831

/*
-> I made a dp matrix in which first part indicate the longest length of array till that index and second index represent if element belong to a or b
with all value initialized to 1 as always one (L,R) pair is possible that is L=R=i.
-> We first did ans++ as our loop cannot count L=R=0.
-> We check greatness of a[i] from a[i-1] and b[i-1] :-
    ->if (a[i]>a[i-1] && a[i]<=b[i-1]) then dp[i][0]=dp[i-1][0]+1;
    ->if (a[i]>b[i-1] && a[i]<=a[i-1]) then dp[i][0]=dp[i-1][1]+1;
    ->if (a[i]>b[i-1] && a[i]>[i-1]) then dp[i][0]=max(dp[i-1][1]+1, dp[i-1][1])
    ->else a[i] would remain 1.
    The length of longest perfect prefix subrange at i give the number of pair that can be made with R=i.
-> Similarly for checking greatness of b[i] from a[i-1] and b[i-1] and updating dp[i][1]
-> We add maximum of dp[i][0] and dp[i][1] for each i as element could be choosen from either a or b.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t;
	cin>>t;
	while(t--) {
	    long long n;
	    cin>>n;
	    vector <long long> a(n), b(n);
	    for(long long i=0; i<n; i++) cin>>a[i];
	    for(long long i=0; i<n; i++) cin>>b[i];
	    vector<vector<long long>> dp(n, vector<long long>(2, 1));
	    long long ans=0;
	    ans++;
	    for(long long i=1; i<n; i++) {
	        if(a[i]>a[i-1]) dp[i][0]=dp[i-1][0]+1;
	        if(a[i]>b[i-1]) dp[i][0]=max(dp[i][0], dp[i-1][1]+1);
	        if(b[i]>b[i-1]) dp[i][1]=dp[i-1][1]+1;
	        if(b[i]>a[i-1]) dp[i][1]=max(dp[i][1], dp[i-1][0]+1);
	        ans+=max(dp[i][0], dp[i][1]);
	    }
	    cout<<ans<<endl;
	}
}
