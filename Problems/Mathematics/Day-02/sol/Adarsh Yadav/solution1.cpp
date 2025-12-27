//https://codeforces.com/contest/1771/submission/355283451
//TC : O(n)

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    long long n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    sort(a,a+n);
	    long long cl=0,cs=0;
	    for(int i=0;i<n;i++){
	        if(a[i]==a[0]) cs++;
	        if(a[i]==a[n-1]) cl++;
	    }
	    if(cs!=n) cout<<2*cs*cl<<endl;
	    else cout<<n*(n-1)<<endl;
	}

}
