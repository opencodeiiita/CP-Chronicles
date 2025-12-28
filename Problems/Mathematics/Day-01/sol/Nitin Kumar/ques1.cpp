/* Submission link: https://codeforces.com/contest/1560/submission/355246381 

Time Complexity : O(1);

*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int a,b,c;
         cin>>a>>b>>c;
         long long int maxval=2* abs(a-b);
         if(maxval>=a&&maxval>=b&&maxval>=c){
            long long int temp=2*abs(a-b);
            long long int ans=abs(a-b)+c;
            if(ans%temp==0){
                cout<<temp<<endl;
            }
            else{
                cout<<ans%temp<<endl;
            }
         }
         else{
            cout<<"-1\n";
         }
    }
}