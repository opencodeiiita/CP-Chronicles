#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

/*
if 2*(a-b) if c/d goes out of bound for this answer is -1
if d =a /b ans -1;
d = c+(a-b)or(b-a)
bohot sari conditions he
is there any easy way




*/




int  solve(){
	int a,b,c;cin>>a>>b>>c;
	int d=c+(a-b);int e=c+(b-a);
	int n=2*(abs(a-b));
	if(a>n||b>n||c>n)return -1;
	if((d==a||d>n||d==b||d<=0)&&(e==a||e==b||e>n||e<=0))return -1;

	if(d==a||d>n||d==b||d<=0)return e;
	if(e==a||e==b||e>n||e<=0)return d;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	int t;cin>>t;
	while(t--)
		cout<<(solve())<<endl;
	
}