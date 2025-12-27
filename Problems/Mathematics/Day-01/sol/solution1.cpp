/*
Problem: 
Given an even number of people standing in a circle, numbered clockwise from 1, 
each person is looking at the person directly opposite. 
Given numbers a,b,c,find the number being looked at by c, 
if a is looking at b.Output -1 if no such circle exists.

Approach :
1. Let n be the total number of people in the circle.Since opposite person is at n/2 distance
    n=2*|a-b|
2. If a,b,c are greater than n,output -1.
3. The person opposite c is at position c + n/2.If this exceeds n,subtract n. 

Time Complexity: O(1) per test case
Space Complexity: O(1)

https://github.com/Tabassumasra05/CP-Chronicles/blob/main/Problems/Mathematics/Day-01/sol/solution1.cpp

*/


#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long a,b,c,d;
    cin>>a>>b>>c;
    long long n=2*abs(a-b);
    if(a>n||b>n||c>n){
        cout<<-1<<endl;
        return;
    }
    d=c+(n/2);
    if(d>n){
        d-=n;
    }
    cout<<d<<endl;
    return;
    

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
