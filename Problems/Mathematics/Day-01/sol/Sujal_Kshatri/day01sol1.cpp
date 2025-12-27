// submisiion linl - https://codeforces.com/problemset/submission/1560/355296237

#include<bits/stdc++.h>
using namespace std;

/*
Problem:
There are n people standing in a circle (n is even).
Each person looks at the person exactly opposite to him.

Three different numbers are given: p, q, r.
Person p is looking at person q.

Find the person that r is looking at.
If it is not possible, print -1.
If there are multiple answers, print any one.

Approach:
If p is opposite to q, then the distance between them is n/2.
So, the total number of people in the circle is:
n = 2 * |p - q|

First, calculate the distance between p and q.
From that, find the size of the circle.

If any of the values p, q, or r is greater than the circle size,
or if p and q are the same, then the answer is not possible.

To find the opposite of r:
- If r is in the second half of the circle, subtract n/2.
- Otherwise, add n/2.
*/

int main(){
    int z;
    cin>>z;
    while(z--){
        int p,q,r;
        cin>>p>>q>>r;

        int x=abs(p-q);
        int y=2*x;

        if(x==0||max({p,q,r})>y){
            cout<<-1<<"\n";
            continue;
        }

        if(r>y/2){
            cout<<r-y/2<<"\n";
        }else{
            cout<<r+y/2<<"\n";
        }
    }
}

/*
Time Complexity: O(t)
Space Complexity: O(1)
*/
