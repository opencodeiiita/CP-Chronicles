#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
	long long t;
	cin>>t;
	while(t--) {
		long long a,b,c;
        cin>>a>>b>>c;
        long long d=(a-b)+c;
        long long n=2*(abs(a-b));
        if (max(a, max(b, c))>n) cout<<-1<<endl;
        else {
            if(d<0) d+=n;
            d=d%n;
            if(d==0) d=n;
            cout<<d<<endl;
        }
	}
}
