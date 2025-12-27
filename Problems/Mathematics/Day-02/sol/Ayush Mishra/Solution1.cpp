// Submission Link
// https://codeforces.com/contest/1771/submission/355396669
// Time complexity = O(n) + O(nlogn)
// Space Comlexity = O(n)





#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        vector<long long int>v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        long long int mini =0;
        long long int maxi= 0;
        int i=0;
        int j = n-1;
        if(v[0]!=v[n-1]){
        while(v[i]==v[0] && i<n){
            mini++;
            i++;
        }
        while(v[j]==v[n-1] && j>=0){
            maxi++;
            j--;
        }
        cout<<2*maxi*mini<<"\n";
    }
    else{
        cout<<(n*(n-1))<<"\n";
    }

    }
    return 0;
}
