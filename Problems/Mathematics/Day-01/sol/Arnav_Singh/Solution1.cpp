//adding submission link as suggested earlier
//https://codeforces.com/problemset/submission/1560/355167404

#include <bits/stdc++.h>
using namespace std;
 
int main() {
     int t;
    cin >> t;
    while(t--) {
        int a,b,c;
        cin>>a>>b>>c;
        if((abs(b-a))*2<max(a,max(b,c))){
            cout << -1 <<'\n';
            continue;
        }
        if(c+(abs(b-a))>(abs(b-a)*2)){
            cout<<(c+(abs(b-a)))%(abs(b-a)*2)<<'\n';
        }
        else{
            cout<<c+(abs(b-a))<<'\n';
        }
    }
    
    return 0;
}