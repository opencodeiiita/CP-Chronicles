#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int d= min(a,b)-1;
        //finds distance of min of a and b from 1
        int mid=max(a,b)-d;
        int total=2*(mid-1);
        if(c>total||mid<=min(a,b)){
            cout<<-1<<endl;
        }
        else if(c<mid)
        cout<<mid+c-1<<endl;
        else cout<<1+c-mid<<endl;
        
    }
}
