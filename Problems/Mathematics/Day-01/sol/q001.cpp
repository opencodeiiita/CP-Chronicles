/*
Problem Statement:
There are n people standing in a circle (n is even). Each person looks at the person
standing exactly opposite them. Given that person a looks at person b, determine
the person that person c is looking at.

---------------------------------------------------------------------------------------
Solution steps:-
-First calculate the total number of people by multiplying the diff of a and b
  n = abs(a-b)
- Then verify whether the diff of a and b is not zero because they stand opposite 
   to each other.
-Then check if a,b and c aare within the total people circle
- else print -1 in the output.

Time compelaxity is O(t):-
because the while loop traverses t times a specific operation

Space complexity is O(1):-
because no different any storage  container like set,vector etc;
*/

#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b,c;
        cin>>a>>b>>c;
        long long k=abs(a-b);
        long long total=2*k;
        if(k==0){
            cout<<-1<<endl;
            continue;
        }
        if(a>total||b>total||c>total){
            cout<<-1<<endl;
            continue;
        }
        if(c+k<=total){
            cout<<c+k<<endl;
        }
        else{
            cout<<c-k<<endl;
        }
    }
}
