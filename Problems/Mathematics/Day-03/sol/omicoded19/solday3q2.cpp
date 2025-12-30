#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long a,b;
	cin>>a>>b;

	long long ans=0;
	while(b){
		ans+=a/b;
		a%=b;
		long long t=a;
		a=b;
		b=t;
	}

	cout<<ans;
	return 0;
}
