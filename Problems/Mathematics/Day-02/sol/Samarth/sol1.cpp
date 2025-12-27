#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

/*
just count the freq of max &min elements and by basic combinotorics we get ans 2*fmax*fmin
but if all elements are equal i.e fmax ==fmin then ans is n*(n-1) by basic combinototics too.
*/




void solve(){
	int n;cin>>n;int a[n];int max=INT_MIN,min=INT_MAX,fmax=0,fmin=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>max){
			max=a[i];fmax=0;}
		if(a[i]<min){
			min=a[i];fmin=0;}
		if(a[i]==max)fmax++;
		if(a[i]==min)fmin++;
	}
	ll ans;
	if(max==min)ans=((long long)(n)*(long long)(n-1));
	else ans=2*(ll)fmax*(ll)fmin;
	cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	int t;cin>>t;
	while(t--)
		solve();
	
}