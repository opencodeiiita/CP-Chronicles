/*
Problem Statement:
Given three distinct integers a, b, and c placed on a circle of even size,
numbered clockwise from 1. Person a is opposite to person b.
Find the number opposite to c. If no such circle exists, return -1.

Prefix Sums:
Not applicable since the problem is purely mathematical and does not involve
range queries or cumulative sums.

Time Complexity: O(1)
Space Complexity: O(1)

Submission Link:
https://codeforces.com/contest/1560/submission/355443029
*/
#include <bits/stdc++.h>
using namespace std;

int main(){

int t;
cin>>t;
while(t--){
int a,b,c,n;
cin>>a>>b>>c;
if(a>b) swap(a,b);    //naming the bigger number b and smaller one a

int SizeOfCircle= 2*(b-a); // thinking: b and a form the diameter of circle 

if(SizeOfCircle==2) cout<<-1<<endl; //edge case when a and b are adjacent
else{
if(c>SizeOfCircle|| b>SizeOfCircle) cout<<-1<<endl; // edge case when either c or the bigger number do not reside in the size
else{
int ans=0;
if(c>b) ans=(c-(b-a));      // because a and b form diameter then c lies in upper or lower half and opposite of c also lies based on that
else if(c<=b) ans=(c+(b-a));

if(ans<=0) ans+=SizeOfCircle;
else if(ans>SizeOfCircle) ans-=SizeOfCircle;   // fixing ans if it resides outside elements of circle

cout<< ans<<endl;
}


}
}
return 0;
}