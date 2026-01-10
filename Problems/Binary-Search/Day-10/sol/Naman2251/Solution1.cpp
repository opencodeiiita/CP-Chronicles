Submission Link: https://codeforces.com/contest/2169/submission/356458128

/*
I made a function 'check' to check if number of remaining element after performing x operation before any element z is greater than or
equal to k. Now by binary search I found out the smallest element that satisfy this condition. The smallest element to satisfy 
ths solution will be kth element itself. Also before performing this I found out if k element exist till 1e12, if no then printed -1.
TC:O(x*log(1e12))
*/

#include <bits/stdc++.h>
using namespace std;
 
long long x, y, k;
 
bool check(long long z) {
    for(long long i=0; i<x; i++) z=z-(z/y);
    return (z>=k);
}
 
int main() {
	long long t;
	cin>>t;
	while(t--) {
	    cin>>x>>y>>k;
	    long long l=1, r=1e12, ans=1e12;
	    if(!check(r)) {
	        cout<<-1<<endl;
	        continue;
	    }
	    while(l<=r) {
	        long long mid=(l+r)/2;
	        if(check(mid)) {
	            ans=min(ans, mid);
	            r=mid-1;
	        }
	        else l=mid+1;
	    }
	    cout<<ans<<endl;
	}
}
