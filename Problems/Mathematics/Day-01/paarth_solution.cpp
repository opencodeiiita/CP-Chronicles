#include <iostream>
#include <cmath>
using namespace std;
int check(int A, int B, int C) {
    if(2*abs(B-A)<C||2*abs(B-A)<B||2*abs(B-A)<A) return -1;
    else return 1;
}
int main() {
    int T;
    cin>>T;
    while(T--) {
        int a, b, c, diff, result;
        cin>>a>>b>>c;
        diff = abs(a-b);
        if(check(a,b,c)>0) {
            if(c>diff) cout<<c-diff<<"\n";
            else cout<<c+diff<<"\n";
        }
        else cout<<-1;
    }
    return 0;
}