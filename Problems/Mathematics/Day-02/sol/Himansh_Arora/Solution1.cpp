//https://codeforces.com/problemset/submission/1771/355291252
//sorted and found the count of the max and min element (iC1)*(jC1)*2
//handled edge case where all the elements are identical
// Time complexity- O(nLogn)
#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector <int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    
    int i=1;
    while(i!=n&&a[i]==a[i-1])i++;

    if(i==n){
        cout<<((i-1)*(i))<<endl;
        return;
    }

    int j=1;
    while(j!=n&&a[n-j]==a[n-j-1])j++;

    cout<<i*j*2<<endl;

}

signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}