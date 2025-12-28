//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#define int long long
#define fo(n) for (int i = 0; i < n; i++)
#define fo1(ii, n) for(int i=ii; i<n; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define fi first
#define se second
#define vec(a) vector<int> a
#define vecn(a,n) vector<int> a(n)
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
const int MOD = 1e9 + 7;
const int INF = 1e18;
using namespace std;

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    //a->b
    //c->?
    int total=abs(a-b)*2;
    int half=total/2;
    if(max({a,b,c})>total){
        cout<<-1<<endl;
        return;
    }
    else if(c<=total){
        if(c>half){
            cout<<c-half<<endl;
        }
        else cout<<c+half<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}