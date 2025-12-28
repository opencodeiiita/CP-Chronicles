#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
void resolve() {
    int a,b,c,d=0;
    cin>>a>>b>>c;
    int n = 2*abs(b-a);
    if(b>n || c>n || a>n)
    d = -1;
    else
    {
        if(c<=(n/2))
        d = c + n/2;
        else
        d = c - n/2;

        if(d==a || d==b || d>n || d<1)
        d=-1;
    }
    cout<<d<<endl;
}
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	 int t;
	 cin >> t;
	 while(t--) 
        resolve();
	return 0;
}