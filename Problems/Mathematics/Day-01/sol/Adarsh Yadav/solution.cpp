//https://codeforces.com/contest/1560/problem/C
//https://codeforces.com/contest/1560/submission/355210608
// TC : O(1) SC: O(1)
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int a,b,c;
	    cin>>a>>b>>c;
	    int k=abs(a-b);
	    if(a>2*k || b>2*k || c>2*k){
	        cout<<-1<<endl;
	    }
	    else{
	        if((c-k)>0){
	            cout<<c-k<<endl;
	        }
	        else{
	            cout<<c+k<<endl;
	        }
	    }
	}

}
