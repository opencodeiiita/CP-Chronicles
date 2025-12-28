//https://codeforces.com/contest/1560/submission/355205808
//time complexity:O(t)
//space complexity:O(1)
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int len;
        if(a>b){
            len=a-b;
            len=2*len;
        }               // staring at opposite end means both of them divide the circle 
                        // in exact half so we substract them and multiply by 2 to get exact length
        else {
           
            len=b-a;
            len=2*len;
        
        }
        if(a<=len&&b<=len&&c<=len){//a,b,c ofcourse cannot be greater than length
            if(c+(len/2)>len){
                cout<<c-(len/2)<<endl;//c will either stare at +n/2 or -n/2
            }
            else{
                cout<<c+(len/2)<<endl;
            }
        }
        else{cout<<-1<<endl;}
    }

    return 0;
}
