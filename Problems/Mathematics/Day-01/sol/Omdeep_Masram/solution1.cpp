#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        long long a,b,c;
        cin>>a>>b>>c;
        long long diff=abs(a-b);
        long long cir=2*diff;
        if(a>cir||b>cir||c>cir){
            cout<<-1<<endl;
        }
        else if(c<=diff){
            cout<<c+diff<<endl;
        }
        else{
            cout<<c-diff<<endl;
        }

    }
    return 0;
}