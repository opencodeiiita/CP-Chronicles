// submission link
// https://codeforces.com/contest/1560/submission/355180160

// Space Complexity = O(1)
// Time Complexity = O(1) for main solution code O(t) for overall code



// The if condition checks if the circle is valid and if the inputs exist within that circle.
// abs(b-a)<=1: Ensures a and b are not adjacent or the same.
// 2*(abs(b-a)-1)+2 < c || 2*(abs(b-a)-1)+2 < a || 2*(abs(b-a)-1)+2 < b.  checks that the input numbers a, b, and c are not larger than the total size of the circle.
// If any of these are true, it prints -1 .

// The line int k = 2*(abs(b-a)-1) + 2 calculates the total number of items in the circle.

// If the inputs are valid, it calculates the number opposite to c.
// The halfway distance is k / 2.
// If c is in the first half (c<= k/2), the opposite is c + k/2.
// If c is in the second half (c > k/2), the opposite is c - k/2.




#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(abs(b-a)<=1 || 2*(abs(b-a)-1)+2 < c || 2*(abs(b-a)-1)+2 < a || 2*(abs(b-a)-1)+2 < b ){
            cout<<-1<<"\n";
        }
        else {
            int k =  2*(abs(b-a)-1) + 2;
            if(c<=k/2) cout<<c+k/2 <<"\n";
            else cout<<c-k/2<<"\n";
        }

    }
    return 0;
}
