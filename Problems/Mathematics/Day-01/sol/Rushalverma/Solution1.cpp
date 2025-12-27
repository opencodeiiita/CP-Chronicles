

/*
submission link: https://codeforces.com/contest/1560/submission/355218206
Time complexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    int t ; cin >> t;
    while(t--){
        ll a,b,c; cin >> a >> b >> c;
        ll n = abs(b-a)*2;
        if(a>n||b>n||c>n){
            cout << -1 << endl;
        }else{
            ll d = n/2 +c;
            if(d>n){ d -= n;}
            cout << d << endl;
        }
    }
}