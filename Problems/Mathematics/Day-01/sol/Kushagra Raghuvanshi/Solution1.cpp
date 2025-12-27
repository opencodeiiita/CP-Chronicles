// https://codeforces.com/problemset/submission/1560/355220642

#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int n=2*abs(a-b);
        if(a>n||b>n||c>n){
            cout<<-1<<endl;
            continue;
        }
        int s=c+n/2;
        if(s>n) s-=n;
        cout<<s<<endl;
    }
}