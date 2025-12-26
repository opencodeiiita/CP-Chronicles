#include <bits/stdc++.h>
using namespace std;
int main(){
          int t;
          cin>>t;
          while(t--){
                    int a,b,c;
                    cin>>a>>b>>c;
                    int d=abs(b-a);
                    if(b>2*d || a>2*d || c>2*d){
                              cout<<-1<<endl;
                    }else{
                              if(c<=d){
                                        cout<<c+d;
                              }else{
                                        cout<<c-d;
                              }
                              cout<<endl;
                    }
          }
}