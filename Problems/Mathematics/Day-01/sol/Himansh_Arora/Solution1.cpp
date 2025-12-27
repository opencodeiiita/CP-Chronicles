//https://codeforces.com/contest/1560/submission/355194892

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int n=2*abs(a-b);

    int opp=c+n/2;
    if(c>n||b>n||a>n){
        cout<<-1<<endl;
        return;
    }
    if(opp>n)opp=opp-n;
    
    cout<<opp<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
}
