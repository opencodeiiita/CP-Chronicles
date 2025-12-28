#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(b<a){
            int temp=a;
            a=b;
            b=temp;
        }
        if(a-1>b-a-1 || 2*b-2*a<c){
          cout<<"-1"<<endl;
        }
        else{
            if(c+b-a>2*b-2*a){
                cout<<c-b+a<<endl;
            }
            else{
                cout<<c+b-a<<endl;
            }
        }
    }
}
//Time complexity=O(n) Space complexity=O(1)
//https://codeforces.com/problemset/submission/1560/355410194