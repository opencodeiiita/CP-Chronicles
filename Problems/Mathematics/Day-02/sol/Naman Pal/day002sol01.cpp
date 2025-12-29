#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
        int t;
        cin>>t;
        while(t--) {
                long long n;
                cin>>n;
                int a[n];
                for(long long i=0; i<n; i++) cin>>a[i];
                sort(a, a+n);
                long long minn=0,maxx=0;
                for(long long i=0; i<n;i++) {
                        if(a[i]==a[0]) minn++;
                        if(a[i]==a[n-1]) maxx++; 
                }
                if(a[0]==a[n-1]) cout<<n*(n-1)<<endl;
                else cout<<minn*maxx*2<<endl;
        }
}
