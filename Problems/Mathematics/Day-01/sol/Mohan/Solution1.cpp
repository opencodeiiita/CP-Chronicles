/*
Problem : Who's Opposite 

Approach : n cannot be greater than 2*abs(a-b);
a,b,c should also be smaler than or equal to n

Time complexity - O(1)
Space complexity - O(1)


Submission Link : https://codeforces.com/contest/1560/submission/355221224

*/
#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vpi vector<pii>
#define vpl vector<pll>
#define vvi vector<vi>
#define mii map<int,int>
#define si set<int>
#define loop(i,n) for (int i = 0; i < n; i++)
#define rloop(i,n) for (int i = n - 1; i >= 0; i--)
#define loop1(i,a,b) for (int i = a; i <= b; i++)
#define rloop1(i,a,b) for (int i = a; i >= b; i--)
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define endl '\n'
#define printy cout<<"YES"<<endl
#define printn cout<<"NO"<<endl
#define vout(a) for (int i = 0; i < a.size(); i++) cout << a[i] << ' '; cout << endl;
#define vpout(a) loop(i,sz(a)) cout <<a[i].F<<' '<< a[i].S<< endl; cout << endl;
#define rt(x){ cout<<x<<endl; return; }


void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int size = abs(b-a)*2;
    if(a>size || b>size || c>size){ rt(-1)} 
    else cout << (c > size/2 ? c - size/2 : size/2 + c) << endl;
}


int32_t main(){ 
    fast_io; 
    int t=1;
    cin>>t; 
    while(t--){ 
        solve(); 
    } 
    return 0;
}