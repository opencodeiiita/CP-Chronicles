//https://codeforces.com/submissions/paarth_arora link for submissions
#include <bits/stdc++.h>
using namespace std;
int main() {
     int t;
    cin >> t;
    while(t--) {
        long long  a,b,c;
        cin>>a>>b>>c;
        if((abs(b-a))*2<max(a,max(b,c))){
            cout << -1 <<'\n';
        }
        
        else if(c+(abs(b-a))>(abs(b-a)*2)){
            cout<<(c+(abs(b-a)))%(abs(b-a)*2)<<endl;
        }
        else{
            cout<<c+(abs(b-a))<<endl;
        }
    }

    return 0;
}
//time complexity-o(1)
//space complexity-o(1)
